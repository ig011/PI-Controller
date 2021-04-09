# PI-Controller

This is a simple **PI-Controller** library for microcontrollers written in C.

## Equations

```sh
 pi->output = Kp * error + Ki * integrator
```

where **integrator** is defined as

```sh
pi->integrator += pi->Ki * pi->dt * (error + pi->previous_error);
```

## Description

In discrete field that depends on sample time value of our measurements in control systems mostly the PI Controller is used. It's possible to use PID Controller that contains additional derivative part in order to control some objects, but it works great in continous time domain. The fact is when we use discrete time domain like we're measuring some kind of data in specified sample time period it may contains some noise on its signal values. That may make the derivative d/dt part introduces unstable states to our controller.

PI-Controller structure contains anti-wind-up and output limiting.
