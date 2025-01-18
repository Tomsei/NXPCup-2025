/**
 * Single component - camera declaration
 * 
 * Basic code to test the function of the spi connection to the camera
 * The script "Control_Engine_Accespoint" should run on the openMV cam 
 * to control the global engine state via spi data
 * 
 * using the Library: SPISlave_T4.h
 * https://github.com/tonton81/SPISlave_T4
 * 
 * improved by tjaekel
 * 
 * @author Tom Seiffert
 */
namespace SingleComponent {
    void setupCamera();
    void runCamera();  
} 


