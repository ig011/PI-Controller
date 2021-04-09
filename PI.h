#ifndef PI_CONTROLLER_H
#define PI_CONTROLLER_h

typedef struct
{
    // PI-Controller gains
    float Kp;
    float Ki;

    // PI-Controller sampling rate
    float dt;

    // PI-Controller memory for integrator
    float integrator;
    float previous_error;

    // PI-Controller output limits
    float limit_min;
    float limit_max;

    // PI-Controller output
    float output;
} PIController;

void PIController_Init(PIController *pi);
float PIController_Update(PIController *pi, float set_point, float measurement);

#endif