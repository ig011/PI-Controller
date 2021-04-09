# PI-Controller

This is a simple **PI-Controller** library for microcontrollers written in C.

## Equations

Output signal of PI-Controller equals

```sh
 pi->output = Kp * error + Ki * integrator
```

where **integrator** is defined as

```sh
pi->integrator += pi->Ki * pi->dt * (error + pi->previous_error)
```

## Description

In discrete field that depends on sample time value of our measurements in control systems mostly the PI Controller is used. 

PI-Controller structure contains anti-wind-up and output limiting.
