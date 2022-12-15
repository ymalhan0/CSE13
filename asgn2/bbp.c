#include "mathlib.h"

#include <stdio.h>

static int cou;
// define static int for number of computed terms

// function to solve pi approximation using BBP formula
double pi_bbp(void) {
    int tracker = 1;
    double base = 1;
    // variable for base (16 in 16^-k)
    double pie = 47.0 / 15, prev = 0;
    // set pie to the first term when k = 0
    double k = 1.0, numer, denom;
    while ((absolute(pie - prev)) > EPSILON) {
        // while the difference between computed terms is > epsilon
        base *= 16.0;
        // multiply base by 16 to compute 16^k
        prev = pie;
        // save previous pi term
        numer = k * (120.0 * k + 151.0) + 47.0;
        // using given formula, calculate the numerator of the approximation formula
        denom = k * (k * (k * (512.0 * k + 1024.0) + 712.0) + 194.0) + 15.0;
        // do the same but for the denominator
        pie += (1.0 * numer) / (base * denom);
        // since we want 16^-k, multiply base by denominator
        k++;
        tracker++;
    }
    cou = tracker;
    return pie;
}

// function to return the number of terms from pi approximation
int pi_bbp_terms(void) {
    return cou;
}
