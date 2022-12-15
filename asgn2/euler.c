#include "mathlib.h"

#include <stdio.h>

static int c;
// define static int for number of computed terms

// function for approximating pi using the euler formula
double pi_euler(void) {
    int tracker = 0;
    double sum = 0;
    double pie = 1.0, prev = 0;
    double k = 1;
    // set pie and k to 1 for multiplying by 1 in first loop run
    while ((absolute(pie - prev)) > EPSILON) {
        // same condition as all formulas, while current-prev term is > epsilon
        sum += 1.0 / (k * k);
        // summation of 1/k^2
        k++;
        prev = pie;
        pie = sqrt_newton(6.0 * sum);
        // sqyare root of 6*sum
        tracker++;
    }
    c = tracker;
    return pie;
}
// function to return number of terms it took to calculate euler pi
int pi_euler_terms(void) {
    return c;
}
