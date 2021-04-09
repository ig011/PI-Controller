#include "PI.h"

void PIController_Init(PIController *pi)
{
    // Clearing PI-Controller variables at initialization
    pi->integrator = 0.0;
    pi->previous_error = 0.0;
    pi->output = 0.0;
}

float PIController_Update(PIController *pi, float set_point, float measurement)
{
    // Calculating error value
    float error = set_point - measurement;

    // Proportional part
    float proportional = pi->Kp * error;

    // Integral part of PI-Controller
    pi->integrator += pi->Ki * pi->dt * (error + pi->previous_error);

    // Anti-wind-up with dynamics of itegrator clamping
    float limit_min_integrator;
    float limit_max_integrator;

    // Compute limits
    if (pi->limit_max > proportional)
    {
        limit_max_integrator = pi->limit_max - proportional;
    }
    else
    {
        limit_max_integrator = 0.0;
    }

    if (pi->limit_min < proportional)
    {
        limit_min_integrator = pi->limit_min - proportional;
    }
    else
    {
        limit_min_integrator = 0.0;
    }

    // Setting limits on current integral value
    if (pi->integrator > limit_max_integrator)
        pi->integrator = limit_max_integrator;
    else if (pi->integrator < limit_min_integrator)
        pi->integrator = limit_min_integrator;

    // PI-Controller output
    pi->output = proportional + pi->integrator;

    if (pi->output > pi->limit_max)
        pi->output = pi->limit_max;
    else if (pi->output < pi->limit_min)
        pi->output = pi->limit_min;

    // Update memory variables of PI-Controller
    pi->previous_error = error;

    // Return output value
    return pi->output;
}