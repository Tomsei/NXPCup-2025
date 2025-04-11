/**
 * timing control - declaration
 * 
 * timing system of the car to controll timed task
 * gives the opportunity to call Methods each x seconds 
 * 
 * For use, a task must be defined and set on active.
 * After the time is up the task gets call and calculate
 * the new time to call the task again
 * 
 * @author Tom Seiffert
 */
#include "configuration/globalConfig.h"
#include "Arduino.h"


namespace TimingControl {

    #define MAX_TASK_COUNT 5

    //forward declaration
    struct Task;

    //typdef for callback
    typedef void (*CallbackFunction)(Task* self);

    struct Task
    {
        bool isFree;
        bool active;
        uint32_t timeInterval;
        uint32_t nextCallAt;

        CallbackFunction functionToCall;
    };

    /**
     * setup timing modul (free the task array - no task is defined at start)
     */
    void setup();

    /**
     * run all active tasks
     * check all defined task and call them if the tim is up
     */
    void runTasks();

    /**
     * create task with the given parameters
     * @param functionToCall: callback function to call
     * @param timeInterval: time after the function get called
     * @param active: ative state of task
     * @param imidiate: flag to decied if first call is imidate or after interfall
     * @return: pointer to createt Task (sucess) | 0 no task free!
     */
    Task* createTask(CallbackFunction functionToCall, uint32_t timeInterval, bool active = true, bool imidiate = true);
    
    /**
     * set the active state of a Task
     * @param taskToSet: the tast to change active stat
     * @param active: the choosen active state
     * @param imidiate: flag to decied if first call is imidate or after interfall
     */
    void setTaskActiveState(Task* taskToSet, bool active, bool imidiate);

}