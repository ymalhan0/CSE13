#include "mathlib.h"

#include <stdio.h>

static int co;
// define static int for number of computed terms

// function to approximate pi using madhava series
double pi_madhava(void) {
    int tracker = 0;
    double pow = 1;
    double pie = 1.0, prev = 0;
    double k = 1;
    // set pow to 1 to account for k=1 (-3^1 = -3)
    while ((absolute(pie - prev)) > EPSILON) {
        pow *= -3;
        // pow solves -3^k by multiplying -3 with -3 each time (only first time is -3*1 cuz k=1 gives -3)
        prev = pie;
        pie += 1.0 / (pow * (2 * k + 1));
        // add -3^-k * 1/2k+1 to pie to complete summation formula given by madhava series
        k++;
        tracker++;
    }
    pie = sqrt_newton(12) * pie;
    // multiply pie by square root of 12 for final solution
    co = tracker;
    return pie;
}
// function to return number of terms it took to solve madhava pi
int pi_madhava_terms(void) {
    return co;
}
