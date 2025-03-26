/**
 * style guide: everything of this module is consistent to the definded stylguide.
 * but everything that is used from the original firmware has another style!
 * 
 * SPI-Transfer Structure:
 * Höhe des Bildes (240 Pixel)
 * - Wert 0: nicht beschrieben (leer) - Start mit 255
 * - Wert 1-238: track centers
 *      track center values are mapped from 0 to 253
 *      no track center calculatet: 254
 * - Wert 239: finish line detected (255) if detected!
 */
// Include MicroPython API.
#include "py/runtime.h"
#include "py_helper.h"
#include "objarray.h"

#include "ports/mimxrt/modmachine.h"
#include "extmod/modmachine.h"

#define SPI_BUFFER_WIDTH 240 //change to optimize if resolution get changed

//variables
uint16_t* width;
uint16_t* height;
uint16_t* lastTrackCenter;
int8_t* camOffset;
uint8_t* trackCenters;
bool* runTrackCenterCalculation;

uint16_t* finishLineLeft;
uint16_t* finishLineRight;
uint16_t* finishLineMid;



/**
 * setup the nxp cup module
 * allocate the memory for the needed variables and initiate them //ToDo change comment
 * @param imgWidth: width of the image
 * @param imgHeight: height of the image
 * @param imgCamOffset: cam offset that schoul be added to the track centers
 * @param args: the different parameters are used to get the arg parameter
 *  0: image width
 *  1: image height
 *  2: camera offset for track centers
 *  3: left line to check for finish line
 *  4: mid line to check for finish line
 *  5: right line to check for finish line
 * @return: width to check if value is corret
 */
static mp_obj_t setup(uint n_args, const mp_obj_t *args, mp_map_t *kw_args) {   
    trackCenters = fb_alloc(SPI_BUFFER_WIDTH, FB_ALLOC_NO_HINT);
    height = fb_alloc(2, FB_ALLOC_NO_HINT);
    width = fb_alloc(2, FB_ALLOC_NO_HINT);
    camOffset = fb_alloc(1, FB_ALLOC_NO_HINT);
    runTrackCenterCalculation = fb_alloc(1, FB_ALLOC_NO_HINT);
    lastTrackCenter = fb_alloc(2, FB_ALLOC_NO_HINT);
    finishLineLeft = fb_alloc(2, FB_ALLOC_NO_HINT);
    finishLineRight = fb_alloc(2, FB_ALLOC_NO_HINT);
    finishLineMid = fb_alloc(2, FB_ALLOC_NO_HINT);

    *width = mp_obj_get_int(args[0]);
    *height = mp_obj_get_int(args[1]);
    *camOffset = mp_obj_get_int(args[2]);
    *finishLineLeft = mp_obj_get_int(args[3]);
    *finishLineMid = mp_obj_get_int(args[4]);
    *finishLineRight = mp_obj_get_int(args[5]);

    *runTrackCenterCalculation = true;
    *lastTrackCenter = (*width/2);

    //set first flag (first value is flag)
    trackCenters[0] = 255;
    trackCenters[1] = 0;

    return mp_obj_new_int(*width);
}
static MP_DEFINE_CONST_FUN_OBJ_KW(setup_obj, 6, setup); //number defindes the amoutn of arguments



/**
 * calculate the track center of a single row
 * it start at the start search and calculate the first edge left and right
 * with both edges it calculate the track center and stores it into track centers
 * @param imgData: a pointer to the image to analyse
 * @param row: row to calculate the track center
 * @param startSearch: start pixel for the anlyses (get first edge to each direaction from this point)
 * @param lowestLine: the line to start analysis
 */
void calculateTrackCenters(uint8_t* imgData, uint16_t row, uint16_t startSearch, uint16_t lowestLine) {
    
    uint16_t leftEdge = 0;
    uint16_t rightEdge = *width;
    uint16_t trackCenter = *width/2;
    uint32_t rowOffset = row * (*width);

    //tracking the first edge found in left direction
    for(int i = startSearch; i > -1; i--) {
        if(imgData[i + rowOffset] == 255) {
            
            //ToDo check amount of Pixel (min edge width)
            leftEdge = i;
            break;
        }
    }

    //tracking the first edge found in right direction
    for (int i = startSearch; i <= (*width); i++) {
        if(imgData[i + rowOffset] == 255) {
            
        //ToDo check amount of pixel (min edge width!)
            rightEdge = i;
            break;
        }
    }

    trackCenter = ((leftEdge + rightEdge) / 2);

    if(imgData[rowOffset + trackCenter] == 255) {
        //track center on edge - stop calculating
        *runTrackCenterCalculation = false;
        imgData[rowOffset + trackCenter] = 255;
        trackCenter = 254; //no track Center found
    }
    else {
        //normal track center calculation
        imgData[rowOffset + trackCenter] = 120;

        *lastTrackCenter = trackCenter;
        trackCenter = trackCenter + *camOffset;
        trackCenter = (trackCenter > 0) ? trackCenter : 0; //make sure trackCenter is not negativ
        
        //if high resolution: map values to range of 0 - 253 (254 - no Track Center) - 255 other states
        if (*width == 320) {
            trackCenter = (trackCenter * 253) / (*width);
        }

        //make sure 255 could be used as unique marker
        if(trackCenter > 253) { 
            trackCenter = 253;
        }
    }

    //change the order (lowest row is the first in Array)
    trackCenters[lowestLine - row + 1] = trackCenter; 
}



/**
 * detect finishline
 * checks two constant rows of image if there is an edge.
 * If bothe track an edge check that the middle is cleare (no turn)
 * if left and right track an edge and the middle is clear it is a finisch line
 * @param imgData: a pointer of the image to analyse
 */
bool finishLineDetected(uint8_t* imgData) {

    bool left = false;
    bool right = false;
    uint16_t startFinishLineSearch = 180;
    uint16_t finishLineSearchLength = 60;

    //check left line
    int rowOffset = startFinishLineSearch * (*width) + (*finishLineLeft);
    for (int i = 0; i < finishLineSearchLength; i++) {
        if(imgData[rowOffset + (i * (*width))] == 255) {
            left = true;
            imgData[rowOffset + (i * (*width))] = 100;
        }
    }
    //stop if no left edge found
    if(!left) {
        return false;
    }

    //check right line
    rowOffset = startFinishLineSearch * (*width) + (*finishLineRight);
    for (int i = 0; i < finishLineSearchLength; i++) {
        if(imgData[rowOffset + (i * (*width))] == 255) {
            right = true;
            imgData[rowOffset + (i * (*width))] = 100;
        }
    }
    
    //check if middle line is clear
    if(left && right) {
        rowOffset = startFinishLineSearch * (*width) + (*finishLineMid);
        for (int i = 0; i < finishLineSearchLength; i++) {
            if(imgData[rowOffset + (i * (*width))] == 255) {
                imgData[rowOffset + (i * (*width))] = 100;
                return false; //no finish line (mid detected)
            }
        }
        return true; //left and right but not in the middle
    
    }
    return false; //no left / right
}


/**
 * method to analyse the picture
 * all configurations of the analysis are read
 * a sobel filter is applied over the entire image
 * call method to calculate the track center for each row
 * @param args: the different parameters are used to get the arg parameter
 *  0: image
 *  1: lowestLine (where analysis should start)
 *  2: Sobel Threshold 
 * @return the new calculatet image
 */
static mp_obj_t analyseImage(uint n_args, const mp_obj_t *args, mp_map_t *kw_args) {
    
    image_t *arg_img = py_helper_arg_to_image(args[0], ARG_IMAGE_GRAYSCALE);
    
    static uint16_t currentWidth;
    currentWidth = arg_img->w;

    uint8_t* imageData = arg_img->data;
    
    uint16_t lowestLine = mp_obj_get_int(args[1]);
    int64_t threshold = mp_obj_get_int(args[2]);
    threshold *= threshold; //avoiding the root later

    uint16_t amountOfCalculatetTrackCenters = 0;


    //new calculation of sobel - just for the one that are needed! (stop if track Center is on edge)
    for (int i = lowestLine*currentWidth-1; i > -1; i--) {

        //remove left rows
        if((i % currentWidth) < 2) { 
            imageData[i] = 0;
            continue;
        }

        //remove top lines
        if((i < currentWidth*2)) {
            amountOfCalculatetTrackCenters = lowestLine - (i/currentWidth); //analysis worked complete (to the end!)
            imageData[i] = 0;
            break;
        }

        /*calculate sobel matrix*/
        int g_x =   (-1 * arg_img->data[i - 2 - (currentWidth*2)]) +    (1 * arg_img->data[i - (currentWidth*2)]) +
                    (-2 * arg_img->data[i - 2 - currentWidth]) +        (2 * arg_img->data[i - (currentWidth)]) +
                    (-1 * arg_img->data[i - 2]) +                       (1 * arg_img->data[i]);

        int g_y =   (-1 * arg_img->data[i - 2 - (currentWidth*2)]) +    (-2 * arg_img->data[i - 1 - (currentWidth*2)]) +    (-1 * arg_img->data[i - (currentWidth*2)]) +
                    (1 * arg_img->data[i-2]) +                          (2 * arg_img->data[i-1]) +                          (1 * arg_img->data[i]);

        /*calculate complete sobel*/
        int g = (g_x * g_x) + (g_y * g_y);

        //calculate sobel threshold
        if(g > threshold || g < -threshold) {
            arg_img->data[i] = 255;
        } else {
            arg_img->data[i] = 0;
        }

        //check if row finished, continue if not (start loop new)
        if((i % currentWidth) != 2 ) {
            continue;
        }

        calculateTrackCenters(imageData, i/currentWidth, *lastTrackCenter, lowestLine);
        if(!(*runTrackCenterCalculation)) {
            amountOfCalculatetTrackCenters = lowestLine - (i/currentWidth);
            break;
        }
    }

    
    //set every track Center thats not calculatet to 254
    for(uint16_t i = amountOfCalculatetTrackCenters + 1; i < SPI_BUFFER_WIDTH-1; i++) {
        trackCenters[i] = 254;
    }
    
    *runTrackCenterCalculation = true;
    *lastTrackCenter = trackCenters[2] * 320 / 253; 


    if(finishLineDetected(imageData)) {
        trackCenters[SPI_BUFFER_WIDTH - 1] = 255;
    }
    else {
        trackCenters[SPI_BUFFER_WIDTH - 1] = 0;
    }
    //return mp_obj_new_memoryview('h', height, trackCenters); //just to check track Centers in micro pyton
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
    mp_machine_spi_transfer(self, (*height), (const uint8_t *)trackCenters, NULL);
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