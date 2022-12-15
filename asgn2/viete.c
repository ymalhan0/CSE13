#include "mathlib.h"

#include <stdio.h>

static int cou;
// define static int for number of computed terms

// function to approximate pi using viete formula
double pi_viete(void) {
    int tracker = 0;
    double an = sqrt_newton(2);
    // first term is root 2 --> an
    double pie = an, prev = 0;
    // set pie to first term
    while ((absolute(pie - prev)) > EPSILON) {
        an = sqrt_newton(2 + an);
        // calculate a_n each time loop runs
        prev = pie;
        // save previous value of pi
        pie *= an / 2.0;
        // complete multiplication to find each pi approximation term
        tracker++;
    }
    pie = 2.0 / (pie / 2.0);
    // 2 divided by calculation to get final po
    cou = tracker;
    return pie;
}

// function returns number of terms from viete
int pi_viete_factors(void) {
    return cou;
}
