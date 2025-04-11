/**
 * timing control - definition
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
#include "timingControl/timingControl.h"
namespace TimingControl {

    uint8_t numberOfTasks = 2;

    Task myTasks[MAX_TASK_COUNT];

    
    //comment in .h
    void setup() {
        for (uint8_t i = 0; i < MAX_TASK_COUNT; i++) {
            myTasks[i].isFree = true;
        }
    }

    //comment in .h
    void runTasks() {
        for (uint8_t i = 0; i < MAX_TASK_COUNT; i++) {
            //check if there is an active task and the time is reached
            if((!myTasks[i].isFree) && myTasks[i].active && myTasks[i].nextCallAt < millis()) { 
                myTasks[i].functionToCall(&myTasks[i]);
                myTasks[i].nextCallAt = myTasks[i].nextCallAt + myTasks[i].timeInterval; //new time
            }
        }
    }
    
    //comment in .h
    Task* createTask(CallbackFunction functionToCall, uint32_t timeInterval, bool active /*= true*/, bool imidiate /*= true*/) {
        for (uint8_t i = 0; i < MAX_TASK_COUNT; i++) {
            if (myTasks[i].isFree) {
                myTasks[i].isFree = false;
                myTasks[i].active = active;
                myTasks[i].timeInterval = timeInterval;
                myTasks[i].functionToCall = functionToCall;
                myTasks[i].nextCallAt = millis() + (imidiate ? 0 : timeInterval);
                CONSOLE.println("Task Createt");
                return &myTasks[i];
            }
        }
        return 0; //no task free
    }

    //comment in .h
    void setTaskActiveState(Task* taskToSet, bool active, bool imidiate) {
        taskToSet->nextCallAt = millis() + (imidiate ? 0 : taskToSet->timeInterval);
        taskToSet->active = active;
    }


}