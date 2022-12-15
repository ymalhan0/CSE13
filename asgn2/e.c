#include "mathlib.h"

#include <stdio.h>

static int count;
// define static int for number of computed terms

// function to calculate e
double e(void) {
    int tracker = 1;
    // counter for terms set to 1 to account for 1+... in formula
    double e = 1.0, factorial = 1, prev = 0;
    // set e to 1 to account for ...+ 1/1 +...
    // then factorial to 1 for multiplying and prev as 0 to use as the "previous e" later on
    int k = 1;
    while ((absolute(e - prev)) > EPSILON) {
        // while the difference between the current and previous e is > that epsilon: loop
        factorial *= k++;
        // get k! by multiplying factorial by k and incrementing for next loop
        prev = e;
        // save previous e in prev to use in while loop condition
        e += 1.0 / factorial;
        // add 1/k! to e for the next e term
        tracker++;
        // increment times we go through the loop
    }
    // set num of terms to count
    count = tracker;
    return e;
}

// function to return number of terms it took to calculate e
int e_terms(void) {
    return count;
}
