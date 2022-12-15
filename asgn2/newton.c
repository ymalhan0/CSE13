#include "mathlib.h"

#include <stdio.h>

static int iters;
// declare static int to return amount of iterations
double sqrt_newton(double x) {
    // this function code in python was provided by Professor Long in the asgn2 lab doc
    double z = 0.0;
    double y = 1.0;
    int counter = 0;

    // save y - z in variable to use in absolute value
    while (absolute(y - z) > EPSILON) {
        // use absolute value function and EPSILON from mathlib.h
        z = y;
        y = 0.5 * (z + x / z);
        // calculate approximation of square root
        ++counter;
        // increment counter
    }
    iters = counter;
    // set static variable to the counter amount
    return y;
    // return the sqrt value of x
}

int sqrt_newton_iters(void) {
    // function to return amount of iterations
    return iters;
}
