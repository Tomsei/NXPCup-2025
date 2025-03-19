/**
 * style guide: everything of this module is consistent to the definded stylguide.
 * but everything that is used from the original firmware has another style!
 */
// Include MicroPython API.
#include "py/runtime.h"
#include "py_helper.h"
#include "objarray.h"

#include "ports/mimxrt/modmachine.h"
#include "extmod/modmachine.h"


//variables
int16_t* width;
int16_t* height;
int16_t* lastTrackCenter;
int8_t* camOffset;
uint8_t* trackCenters;
bool* runTrackCenterCalculation;



/**
 * setup the nxp cup module
 * allocate the memory for the needed variables and initiate them
 * @param imgWidth: width of the image
 * @param imgHeight: height of the image
 * @param imgCamOffset: cam offset that schoul be added to the track centers
 * @return: width to check if value is corret
 */
static mp_obj_t setup(mp_obj_t imgWidth, mp_obj_t imgHeight, mp_obj_t imgCamOffset) {   
    trackCenters = fb_alloc(256*2, FB_ALLOC_NO_HINT);
    height = fb_alloc(2, FB_ALLOC_NO_HINT);
    width = fb_alloc(2, FB_ALLOC_NO_HINT);
    camOffset = fb_alloc(1, FB_ALLOC_NO_HINT);
    runTrackCenterCalculation = fb_alloc(1, FB_ALLOC_NO_HINT);
    lastTrackCenter = fb_alloc(1, FB_ALLOC_NO_HINT);

    *width = mp_obj_get_int(imgWidth);
    *height = mp_obj_get_int(imgHeight);
    *camOffset = mp_obj_get_int(imgCamOffset);
    *runTrackCenterCalculation = true;
    *lastTrackCenter = (*width/2);

    //set first flag (first two rows not calculated)
    trackCenters[0] = 255;
    //set first track center to the center of the image
    trackCenters[1] = (*width)/2;

    return mp_obj_new_int(*width);
}
static MP_DEFINE_CONST_FUN_OBJ_3(setup_obj, setup); //number defindes the amoutn of arguments



/**
 * calculate the track center of a single row
 * it start at the start search and calculate the first edge left and right
 * with both edges it calculate the track center and stores it into track centers
 * @param argImg: a pointer to the image to analyse
 * @param trackCenters: a pointer to the trackCenters Array
 * @param row: row to calculate the track center
 * @param startSearch: start pixel for the anlyses (get first edge to each direaction from this point)
 */
void calculateTrackCenters(uint8_t* argImg, int row, int startSearch, int numberOfLines) {
    
    int leftEdge = 0;
    int rightEdge = *width;
    int trackCenter = *width/2;
    int rowOffset = row * (*width);

    //tracking the first edge found in left direction
    for(int i = startSearch; i >= 0; i--) {
        if(argImg[i + rowOffset] == 255) {
            leftEdge = i;
            break;
        }
    }

    //tracking the first edge found in right direction
    for (int i = startSearch; i <= (*width); i++) {
        if(argImg[i + rowOffset] == 255) {
            rightEdge = i;
            break;
        }
    }
    //visual repräsentation: set all other to black
    // for(int i = leftEdge - 1; i >= 0; i--) {
    //     argImg[i + rowOffset] = 0;
    // }
    // for(int i = rightEdge + 1; i <= (*width); i++) {
    //     argImg[i + rowOffset] = 0;
    // }

    trackCenter = ((leftEdge + rightEdge) / 2);

    if(argImg[rowOffset + trackCenter] == 255) {
        //track center on edge - stop calculating
        *runTrackCenterCalculation = false;
        argImg[rowOffset + trackCenter] = 255;
        trackCenter = 255;
    }
    else {
        //normal track center calculation
        argImg[rowOffset + trackCenter] = 120;

        *lastTrackCenter = trackCenter;
        trackCenter = trackCenter + *camOffset;
        trackCenter = (trackCenter > 0) ? trackCenter : 0; //make sure trackCenter is not negativ
        
        //if high resolution: map values to range of 0 - 254
        if (*width == 320) {
            trackCenter = (trackCenter * 254) / (*width);
        }

        //make sure 255 could be used as unique marker
        if(trackCenter == 255) { 
            trackCenter = 254;
        }
    }

    trackCenters[numberOfLines - row - 1] = trackCenter; //change the order (lowest row is the first in Array)
}




/**
 * method to analyse the picture
 * all configurations of the analysis are read
 * a sobel filter is applied over the entire image
 * call method to calculate the track center for each row
 * @param args: the different parameters are used to get the arg parameter
 * @return the new calculatet image
 */
static mp_obj_t analyseImage(uint n_args, const mp_obj_t *args, mp_map_t *kw_args) {
    
    image_t *arg_img = py_helper_arg_to_image(args[0], ARG_IMAGE_GRAYSCALE);
    int width = arg_img->w;
    int height = arg_img->h;
    uint8_t* imageData = arg_img->data;
    
    int lastTwoRows = width * height - (2 * width) -1;
    int numberOfLines = mp_obj_get_int(args[1]);
    int threshold = mp_obj_get_int(args[2]);
    threshold *= threshold; //avoiding the root later



    for (int i = 0; i < numberOfLines * width ; i++) {

        //cut the last two lines and the last two pixel of each line - don´t calculate sobel with pixels of new line
        if(((i % width) > width - 3) ||  (i > lastTwoRows)) {
            imageData[i] = 0;
            continue;
        }         
        
        /*easy calculation - "single row for left and right"*/
        //int g_x = ((imageData[i] * 2) + (imageData[i+2] * -2));
        //int g_y = ((imageData[i + 1 + width] * 2) + (imageData[i + 1 + (width*2)] * -2));

        /* complexer but better calculation with matrix*/
        int g_x =   (-1 * arg_img->data[i]) +           (1 * arg_img->data[i+2]) +
                    (-2 * arg_img->data[i+width]) +     (2 * arg_img->data[i+2+width]) +
                    (-1 * arg_img->data[i+(width*2)]) + (1 * arg_img->data[i+2+(width*2)]);

        int g_y =   (-1 * arg_img->data[i]) +           (-2 * arg_img->data[i+1]) +             (-1 * arg_img->data[i+2]) +
                    (1 * arg_img->data[i+(width*2)]) +  (2 * arg_img->data[i+1+(width*2)]) +    (1 * arg_img->data[i+2+(width*2)]);


        int g = (g_x * g_x) + (g_y * g_y);
        //takes long because of root int g = (int) fast_sqrtf((g_x * g_x) + (g_y * g_y));

        if(g > threshold || g < -threshold) {
            arg_img->data[i] = 255;
        } else {
            arg_img->data[i] = 0;
        }
    }
    
    //calculate edges and track_centers
    for (int i = numberOfLines - 3; i >= 0; i--) {
        if(*runTrackCenterCalculation) {
            //calculateTrackCenters(imageData, i, trackCenters[height-i-2]); //height-i-2 to get the last row before this
            calculateTrackCenters(imageData, i, *lastTrackCenter, numberOfLines); 
        }
        else {
            trackCenters[height - i - 1] = 255; //change the order (lowest row is the first in Array)
        }
    }

    *runTrackCenterCalculation = true;
    *lastTrackCenter = trackCenters[2]; 

    //return mp_obj_new_memoryview('h', height, trackCenters);
    return args[0];
}
static MP_DEFINE_CONST_FUN_OBJ_KW(analyseImage_obj, 3, analyseImage); //number defindes the amoutn of arguments



/**
 * machine spi transfer method
 * copy of the original firmware method (lib/micropython/extmod/machine_spi.c)
 */
static void mp_machine_spi_transfer(mp_obj_t self, size_t len, const void *src, void *dest) {
    mp_obj_base_t *s = (mp_obj_base_t *)MP_OBJ_TO_PTR(self);
    mp_machine_spi_p_t *spi_p = (mp_machine_spi_p_t *)MP_OBJ_TYPE_GET_SLOT(s->type, protocol);
    spi_p->transfer(s, len, src, dest);
}


/**
 * spi write to write the calculatet track centers
 * copy of the neede stuff from the original firmware method (lib/micropython/extmod/machine_spi.c)
 * just modified so it can transfer the calculatet track centers
 */
static mp_obj_t spiWrite(mp_obj_t self) {
    mp_machine_spi_transfer(self, 256, (const uint8_t *)trackCenters, NULL);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(spiWrite_obj, spiWrite);


/**
 * Define all properties of the module.
 * Table entries are key/value pairs of the attribute name (a string)
 * and the MicroPython object reference.
 * All identifiers and strings are written as MP_QSTR_xxx and will be
 * optimized to word-sized integers by the build system (interned strings).
 */
static const mp_rom_map_elem_t nxpcup_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_nxpcup) },
    { MP_ROM_QSTR(MP_QSTR_analyseImage), MP_ROM_PTR(&analyseImage_obj) },
    { MP_ROM_QSTR(MP_QSTR_setup), MP_ROM_PTR(&setup_obj) },
    { MP_ROM_QSTR(MP_QSTR_spiWrite), MP_ROM_PTR(&spiWrite_obj) },
};
static MP_DEFINE_CONST_DICT(nxpcup_module_globals, nxpcup_globals_table);

// Define module object.
const mp_obj_module_t nxpcup_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *) &nxpcup_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_nxpcup, nxpcup_cmodule);