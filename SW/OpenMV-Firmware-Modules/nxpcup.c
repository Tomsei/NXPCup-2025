// Include MicroPython API.
#include "py/runtime.h"
#include "py_helper.h"
#include "objarray.h"

//#include "../../lib/micropython/ports/mimxrt/modmachine.h"
#include "ports/mimxrt/modmachine.h"
#include "extmod/modmachine.h"
//#include "mimxrt/modmachine.h"
//#include "py/runtime.h"
//#include "extmod/modmachine.h"
//ToDo: Explain why here an other styleguide is used


void calculate_edge(image_t *arg_img, int16_t* track_centers, int row, int start_search) {
    int left_edge = 0;
    int right_edge = arg_img->w;
    int track_center = arg_img->w / 2;
    int row_offset = row * arg_img->w;

    //tracking the first edge found in left direction
    for(int i = start_search; i >= 0; i--) {
        if(arg_img->data[i + row_offset] == 255) {
            left_edge = i;
            break;
        }
    }
    //visual repräsentation: set all other to black
    /*for(int i = left_edge - 1; i >= 0; i--) {
        arg_img->data[i + row_offset] = 0;
    }*/

    //tracking the first edge found in right direction
    for (int i = start_search; i <= arg_img->w; i++) {
        if(arg_img->data[i + row_offset] == 255) {
            right_edge = i;
            break;
        }
    }
    //visual repräsentation: set all other to black
    /*for(int i = right_edge + 1; i <= arg_img->w; i++) {
        arg_img->data[i + row_offset] = 0;
    }*/

    track_center = (left_edge + right_edge)/2; //ToDo: add Offset to Camera - also possbile at Teensy 
    arg_img->data[row_offset + track_center] = 120;
    track_centers[row] = track_center;
}

int16_t* track_centers;

static mp_obj_t calculate_sobel(uint n_args, const mp_obj_t *args, mp_map_t *kw_args) {
    image_t *arg_img = py_helper_arg_to_image(args[0], ARG_IMAGE_GRAYSCALE);
    int width = arg_img->w;
    int hight = arg_img->h;
    int last_two_rows = width * hight - (2 * width) -1;
    int number_of_lines = mp_obj_get_int(args[1]);
    int threshold = mp_obj_get_int(args[2]);

    //store track-Centers + initiate the first one
    track_centers[hight-3] = width/2;

    //ToDo: test what happens here when the array is static #
    //+ try to figure out array allocation (im Forum) 

    //ToDo: Die Version ausprobieren, bei der Python die Speicherverwaltung des Arrays übernimmt

    for (int i = 0; i < number_of_lines * width ; i++) {

        //cut the last two lines and the last two pixel of each line - don´t calculate sobel with pixels of new line
        if(((i % width) > width - 3) ||  (i > last_two_rows)) {
            arg_img->data[i] = 50;
            continue;
        } 

        /* original matric calculation - complex: takes to much time

        //sobel with original matrix
        int g_x =   (-1 * arg_img->data[i]) +           (0 * arg_img->data[i+1]) +              (1 * arg_img->data[i+2]) +
                    (-2 * arg_img->data[i+width]) +     (0 * arg_img->data[i+1+width]) +        (2 * arg_img->data[i+2+width]) +
                    (-1 * arg_img->data[i+(width*2)]) + (0 * arg_img->data[i+1+(width*2)]) +    (1 * arg_img->data[i+2+(width*2)]);

        int g_y =   (-1 * arg_img->data[i]) +           (-2 * arg_img->data[i+1]) +             (-1 * arg_img->data[i+2]) +
                    (0 * arg_img->data[i+width]) +     (0 * arg_img->data[i+1+width]) +        (0 * arg_img->data[i+2+width]) +
                    (1 * arg_img->data[i+(width*2)]) + (2 * arg_img->data[i+1+(width*2)]) +    (1 * arg_img->data[i+2+(width*2)]);
        

        //sobel without the multiplications with 0 needed 
        int g_x =   (-1 * arg_img->data[i]) +           (1 * arg_img->data[i+2]) +
                    (-2 * arg_img->data[i+width]) +     (2 * arg_img->data[i+2+width]) +
                    (-1 * arg_img->data[i+(width*2)]) + (1 * arg_img->data[i+2+(width*2)]);

        int g_y =   (-1 * arg_img->data[i]) +           (-2 * arg_img->data[i+1]) +             (-1 * arg_img->data[i+2]) +
                    (1 * arg_img->data[i+(width*2)]) +  (2 * arg_img->data[i+1+(width*2)]) +    (1 * arg_img->data[i+2+(width*2)]);

        int g = (int) fast_sqrtf((g_x*g_x) + (g_y*g_y));

        if(g > threshold || g < -threshold) {
            arg_img->data[i] = 255;
        } else {
            arg_img->data[i] = 0;
        }
        */
        
        
        /*easy calculation - "single row for left and right"*/
        int g_x = ((arg_img->data[i] * 2) + (arg_img->data[i+2] * -2));
        int g_y = ((arg_img->data[i + 1 + width] * 2) + (arg_img->data[i + 1 + (width*2)] * -2));

        int g = (int) fast_sqrtf((g_x*g_x) + (g_y*g_y));

        if(g > threshold || g < -threshold) {
            arg_img->data[i] = 255;
        } else {
            arg_img->data[i] = 0;
        }
    }
    
    //calculate edges and track_centers | ToDo: -2 bei hight anpassen!
    for (int i = hight - 4; i > 0; i--) {
        calculate_edge(arg_img, track_centers, i, track_centers[i+1]);
    }

    //just testing the array values
    //for (int i = 0; i < hight -3; i++) {
    //    track_centers[i] = 100 + i%5;
    //}
    
    //return mp_obj_new_int(1);
    return mp_obj_new_memoryview('h', hight, track_centers);
}
static MP_DEFINE_CONST_FUN_OBJ_KW(calculate_sobel_obj, 3, calculate_sobel); //number defindes the amoutn of arguments


static void mp_machine_spi_transfer(mp_obj_t self, size_t len, const void *src, void *dest) {
    mp_obj_base_t *s = (mp_obj_base_t *)MP_OBJ_TO_PTR(self);
    mp_machine_spi_p_t *spi_p = (mp_machine_spi_p_t *)MP_OBJ_TYPE_GET_SLOT(s->type, protocol);
    spi_p->transfer(s, len, src, dest);
}

static mp_obj_t nxp_machine_spi_write(mp_obj_t self) {
    //mp_obj_t wr_buf;
    //mp_buffer_info_t src;
    //mp_get_buffer_raise(wr_buf, &src, MP_BUFFER_READ);
    mp_machine_spi_transfer(self, 256, (const uint16_t *)track_centers, NULL);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(nxp_machine_spi_write_obj, nxp_machine_spi_write);


static mp_obj_t nxp_spi_write() {   
    track_centers = fb_alloc(256*2, FB_ALLOC_NO_HINT);
    return mp_obj_new_int(1);
}
static MP_DEFINE_CONST_FUN_OBJ_KW(nxp_spi_write_obj, 0, nxp_spi_write); //number defindes the amoutn of arguments



// This is the function which will be called from Python as cexample.add_ints(a, b).
static mp_obj_t test_sum(mp_obj_t a_obj, mp_obj_t b_obj) {
    // Extract the ints from the micropython input objects.
    int a = mp_obj_get_int(a_obj);
    int b = mp_obj_get_int(b_obj);

    // Calculate the addition and convert to MicroPython object.
    return mp_obj_new_int(a + b);
}
// Define a Python reference to the function above.
static MP_DEFINE_CONST_FUN_OBJ_2(test_sum_obj, test_sum);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
static const mp_rom_map_elem_t nxpcup_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_nxpcup) },
    { MP_ROM_QSTR(MP_QSTR_test_sum), MP_ROM_PTR(&test_sum_obj) },
    { MP_ROM_QSTR(MP_QSTR_calculate_sobel), MP_ROM_PTR(&calculate_sobel_obj) },
    { MP_ROM_QSTR(MP_QSTR_nxp_spi_write), MP_ROM_PTR(&nxp_spi_write_obj) },
    { MP_ROM_QSTR(MP_QSTR_nxp_machine_spi_write), MP_ROM_PTR(&nxp_machine_spi_write_obj) },
};
static MP_DEFINE_CONST_DICT(nxpcup_module_globals, nxpcup_globals_table);

// Define module object.
const mp_obj_module_t nxpcup_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *) &nxpcup_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_nxpcup, nxpcup_cmodule);
