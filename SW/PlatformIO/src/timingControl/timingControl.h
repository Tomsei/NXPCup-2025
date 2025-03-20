#include "configuration/globalConfig.h"
#include "Arduino.h"


namespace TimingControl {

    #define MAX_TASK_COUNT 5

    //forward declaration
    struct Task;

    //typdef for callback
    typedef void (*CallbackFunction)(Task* self); //is self needed? yes this give the callback function to the strackt

    struct Task
    {
        bool isFree;
        bool active;
        uint32_t timeInterval;
        uint32_t nextCallAt;

        CallbackFunction functionToCall;
    };

    void setup();

    void runTasks();
    void runTasks();

    Task* createTask(CallbackFunction functionToCall, uint32_t timeInterval, bool active = true, bool imidiate = true);
    void setTaskActiveState(Task* taskToSet, bool active, bool imidiate);

}