/**
 * car logic - declaration
 * 
 * car logic is the mergin point of all other working ears (for example cameraAnalysis, drivingControl...)
 * it connect the different areas to each other and controls the driving Behaviour of the car (stop, driving...).
 * 
 * Main parts are:
 * - controling car state (engine run...)
 * - reading data (cameraAnalysis, sensors, boardinput)
 * - use the input data to decide behavior
 * - control car witch drivingControl and Data Vizualisation
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"
namespace CarLogic {

    extern bool engineEnabled;
    extern bool steeringEnabled;

    /**
     * control the complete behavior by checking car state, 
     * reading data and use it to control the car
     */
    void runCarLogic();

    /**
     * define time task thas should run in specific time intervals
     */
    void defineTimedTasks();
}
