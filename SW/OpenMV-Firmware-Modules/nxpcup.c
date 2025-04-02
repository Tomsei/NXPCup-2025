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
#define VIS_SOBEL 40
#define VIS_EDGE 120
#define VIS_TRACKCENTER 255
#define VIS_FINISHLINE 200
#define VIS_STEERING_LINES 255

//variables
uint16_t* width;
uint16_t* height;
uint16_t* lastTrackCenter;
uint16_t* lastFrameTrackCenter;
int8_t* camOffset;
uint8_t* trackCenters;
uint8_t* possibleCrossCountLeft;
uint8_t* possibleCrossCountRight;
uint8_t* maxCrossCount;
uint8_t* crossMinHeight;
bool* runTrackCenterCalculation;
bool* crossStraightEnabledLeft;
bool* crossStraightEnabledRight;

uint16_t* finishLineScanOffset;
uint16_t* finishLineScanStart;
uint16_t* finishLineScanLength;
uint16_t* finishLineCenter;
uint8_t* minEdgeWidth;



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
    width = fb_alloc(2, FB_ALLOC_NO_HINT);
    height = fb_alloc(2, FB_ALLOC_NO_HINT);
    camOffset = fb_alloc(1, FB_ALLOC_NO_HINT);
    runTrackCenterCalculation = fb_alloc(1, FB_ALLOC_NO_HINT);
    lastTrackCenter = fb_alloc(2, FB_ALLOC_NO_HINT);
    lastFrameTrackCenter = fb_alloc(2, FB_ALLOC_NO_HINT);
    finishLineScanOffset = fb_alloc(2, FB_ALLOC_NO_HINT);
    finishLineScanStart = fb_alloc(2, FB_ALLOC_NO_HINT);
    finishLineScanLength = fb_alloc(2, FB_ALLOC_NO_HINT);
    finishLineCenter = fb_alloc(2, FB_ALLOC_NO_HINT);
    possibleCrossCountLeft = fb_alloc(2, FB_ALLOC_NO_HINT);
    possibleCrossCountRight = fb_alloc(2, FB_ALLOC_NO_HINT);
    minEdgeWidth = fb_alloc(1, FB_ALLOC_NO_HINT);
    maxCrossCount = fb_alloc(1, FB_ALLOC_NO_HINT);
    crossMinHeight = fb_alloc(1, FB_ALLOC_NO_HINT);
    crossStraightEnabledLeft = fb_alloc(1, FB_ALLOC_NO_HINT);
    crossStraightEnabledRight = fb_alloc(1, FB_ALLOC_NO_HINT);

    *width = mp_obj_get_int(args[0]);
    *height = mp_obj_get_int(args[1]);
    *camOffset = mp_obj_get_int(args[2]);
    *finishLineScanOffset = mp_obj_get_int(args[3]);
    *finishLineScanStart = mp_obj_get_int(args[4]);
    *finishLineScanLength = mp_obj_get_int(args[5]);
    *minEdgeWidth = mp_obj_get_int(args[6]);
    *maxCrossCount = mp_obj_get_int(args[7]);
    *crossMinHeight = mp_obj_get_int(args[8]);

    *runTrackCenterCalculation = true;
    *lastTrackCenter = (*width/2);
    *lastFrameTrackCenter = (*width/2);
    *finishLineCenter = (*width/2);
    *possibleCrossCountLeft = 0;
    *possibleCrossCountRight = 0;
    *crossStraightEnabledLeft = true;
    *crossStraightEnabledRight = true;

    //set first flag (first value is flag)
    trackCenters[0] = 255;
    trackCenters[1] = 0;

    return mp_obj_new_int(*width);
}
static MP_DEFINE_CONST_FUN_OBJ_KW(setup_obj, 9, setup); //number defindes the amoutn of arguments



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
    uint8_t leftCount = 0;
    uint8_t rightCount = 0;

    uint16_t trackCenter = *width/2;
    uint32_t rowOffset = row * (*width);

    bool addOffset = true;

    //tracking the first edge found in left direction
    for(int i = startSearch; i > -1; i--) {
        if(imgData[i + rowOffset] == VIS_SOBEL) {
            
            leftCount++;

            //min edge width
            if(leftCount > (*minEdgeWidth)) {
                leftEdge = i;
                for(uint8_t j = leftCount; j > 0; j--) {
                    imgData[i + rowOffset + j - 1] = VIS_EDGE;
                }
                break;
            }
        }
        else {
            leftCount = 0;
        }
        if(i == 0) {
            //make it a bit more left (it is the edge of the image)
            addOffset = false;
        }
    }

    //tracking the first edge found in right direction
    for (int i = startSearch; i <= (*width); i++) {
        if(imgData[i + rowOffset] == VIS_SOBEL) {
            
            rightCount++;
            
            if(rightCount > (*minEdgeWidth)) {
                rightEdge = i;
                for(uint8_t j = rightCount; j > 0; j--) {
                    imgData[i + rowOffset - j - 1] = VIS_EDGE;
                }
                
                break;
            }
        }
        else {
            rightCount = 0;
        }
    }

    trackCenter = ((leftEdge + rightEdge) / 2);

    if(lowestLine - row  > (*crossMinHeight)) {

        /* Working*/
        //crossing detection
        if(leftEdge == 0 && (trackCenter > (*lastTrackCenter))) {
            *possibleCrossCountLeft += 1;
        }
        else {
            *possibleCrossCountLeft = 0;
        }
        
        if(rightEdge == (*width) && (trackCenter < (*lastTrackCenter))) {
            *possibleCrossCountRight += 1;
        }
        else {
            *possibleCrossCountRight = 0;
        }
        
        /* new Test - enable one equal  for detection
        if(leftEdge == 0) {
            if (trackCenter > (*lastTrackCenter)) {
                *possibleCrossCountLeft += 1;
            }
            else if(trackCenter == (*lastTrackCenter) && crossStraightEnabledLeft) {
                *possibleCrossCountLeft += 1;
                *crossStraightEnabledLeft = false;
            }
            else {
                *possibleCrossCountLeft = 0;
            }
        }
        else {
            *possibleCrossCountLeft = 0;
            *crossStraightEnabledLeft = true;
        }

        if(rightEdge == (*width)) {
            if(trackCenter < (*lastTrackCenter)) {
                *possibleCrossCountRight += 1;
            }
            else if(trackCenter == (*lastTrackCenter) && crossStraightEnabledRight) {
                *possibleCrossCountRight += 1;
                *crossStraightEnabledRight = false;
            }
            else {
                *possibleCrossCountRight = 0;
            }
        }
        else {
            *possibleCrossCountRight = 0;
            *crossStraightEnabledRight = true;
        }*/
    }

    //track center on edge - stop calculating
    if((imgData[rowOffset + trackCenter] == VIS_EDGE) || (*possibleCrossCountLeft > *maxCrossCount ) || (*possibleCrossCountRight > *maxCrossCount)) {
        *runTrackCenterCalculation = false;
    }
    else {
        //normal track center calculation
        imgData[rowOffset + trackCenter] = VIS_TRACKCENTER;

        if(row+1 == lowestLine ) {
            *lastFrameTrackCenter = trackCenter;
        }
        *lastTrackCenter = trackCenter;

        if(row == lowestLine - 50) {
            *finishLineCenter = trackCenter;
        }

        //add track center Offset if nessesary
        if(addOffset) {
            trackCenter = trackCenter + (*camOffset);
        }
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
bool finishLineDetected(uint8_t* imgData, uint16_t centerLine) {

    bool left = false;
    bool right = false;
    uint16_t startFinishLineSearch = (*finishLineScanStart);
    uint16_t finishLineSearchLength = (*finishLineScanLength);

    //check left line
    int rowOffset = startFinishLineSearch * (*width) + (centerLine - (*finishLineScanOffset));
    for (int i = 0; i < finishLineSearchLength; i++) {
        if(imgData[rowOffset + (i * (*width))] == VIS_SOBEL) {
            left = true;
        }
        imgData[rowOffset + (i * (*width))] = VIS_FINISHLINE;
    }
    //stop if no left edge found
    if(!left) {
        return false;
    }

    //check right line
    rowOffset = startFinishLineSearch * (*width) + (centerLine + (*finishLineScanOffset));
    for (int i = 0; i < finishLineSearchLength; i++) {
        if(imgData[rowOffset + (i * (*width))] == VIS_SOBEL) {
            right = true;
        }
        imgData[rowOffset + (i * (*width))] = VIS_FINISHLINE;
    }
    
    //check if middle line is clear
    if((left && right)) {
        startFinishLineSearch -= 5; //move a bit down
        rowOffset = startFinishLineSearch * (*width) + (centerLine);
        for (int i = 0; i < finishLineSearchLength + 5; i++) {
            if(imgData[rowOffset + (i * (*width))] == VIS_SOBEL) {
                imgData[rowOffset + (i * (*width))] = VIS_FINISHLINE;
                return false; //no finish line (mid detected)
            }
        }
        return true; //left and right but not in the middle
    
    }
    return false; //no left / right
}


/**
 * method to visualize the area of the choosen steering lines
 * @todo: comment
 */
static mp_obj_t visualizeSteeringLines(uint n_args, const mp_obj_t *args, mp_map_t *kw_args) {

    image_t *arg_img = py_helper_arg_to_image(args[0], ARG_IMAGE_GRAYSCALE);
    uint8_t* imageData = arg_img->data;
    uint16_t lowestLine = mp_obj_get_int(args[1]);
    uint16_t firstLine = mp_obj_get_int(args[2]);
    uint16_t secondLine = mp_obj_get_int(args[3]);
    uint16_t thirdLine = mp_obj_get_int(args[4]);

    uint32_t rowOffset = (lowestLine * (*width)) - (firstLine * (*width));
    
    for (uint16_t i = 0; i < (*width); i++) {
        imageData[rowOffset + i] = VIS_STEERING_LINES;
    }
    
    rowOffset = (lowestLine * (*width)) - (secondLine * (*width));
    for (uint16_t i = 0; i < (*width); i++) {
        imageData[rowOffset + i] = VIS_STEERING_LINES;
    }

    rowOffset = (lowestLine * (*width)) - (thirdLine * (*width));
    for (uint16_t i = 0; i < (*width); i++) {
        imageData[rowOffset + i] = VIS_STEERING_LINES;
    }

    return args[0];
}
static MP_DEFINE_CONST_FUN_OBJ_KW(visualizeSteeringLines_obj, 5, visualizeSteeringLines); //number defindes the amoutn of arguments


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
            arg_img->data[i] = VIS_SOBEL;
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

    
    //skip frame if no track Center was found
    if(amountOfCalculatetTrackCenters > 1) {
        //set every track Center thats not calculatet to 254
        for(uint16_t i = amountOfCalculatetTrackCenters + 1; i < SPI_BUFFER_WIDTH-1; i++) {
            trackCenters[i] = 254;
        }
    } 

    //check if finishLine is possible
    if(amountOfCalculatetTrackCenters > 60) {
        if(finishLineDetected(imageData, *finishLineCenter)) { //check the used finish line!
            trackCenters[SPI_BUFFER_WIDTH - 1] = 255;
        }
        else {
            trackCenters[SPI_BUFFER_WIDTH - 1] = 0;
        }
    }
    
    //reset variables
    *runTrackCenterCalculation = true;
    *lastTrackCenter = *lastFrameTrackCenter;
    *finishLineCenter = (currentWidth/2);
    *possibleCrossCountLeft = 0;
    *possibleCrossCountRight = 0;
    
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
    { MP_ROM_QSTR(MP_QSTR_visualizeSteeringLines), MP_ROM_PTR(&visualizeSteeringLines_obj) }, 
};
static MP_DEFINE_CONST_DICT(nxpcup_module_globals, nxpcup_globals_table);

// Define module object.
const mp_obj_module_t nxpcup_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *) &nxpcup_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_nxpcup, nxpcup_cmodule);