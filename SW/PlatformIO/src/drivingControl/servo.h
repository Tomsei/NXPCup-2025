namespace DrivingControl {

    //ToDo determine the correct values!
    //ToDo Mapping needed!
    #define MAX_STEERING_ANGLE 130
    #define MIN_STEERING_ANGLE 50

    namespace SteeringServo {
        void setup();
        void setSteeringAngle(int steeringAngle);
    };
}