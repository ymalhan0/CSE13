#include "insert.h"

#include "stats.h"

#include <stdio.h>

// I referenced th3 python pseudocode and Professor Long's code in C on lecture slides 9 for this function as well as Eugene's Bubblesort code from section on 10/12
void insertion_sort(Stats *stats, uint32_t *A, uint32_t n) {
    for (uint32_t i = 0; i < n; i++) {
        // use a for loop to loop through the size of the list (n)
        int j = i;
        // set j to position
        uint32_t temp = move(stats, A[i]);
        // move A[i] into a temporary value
        if (n == 1) {
            return;
        }
        // if the size of the array is 1, its already sorted so exit the program

        // using a temporary value to save A[i]
        while (j > 0 && cmp(stats, A[j - 1], temp) > 0) {
            // go through list while the previous values are greater than current value and compare using stats.c compare function - provided in resources
            A[j] = move(stats, A[j - 1]);
            // move previous value to A[j] if previous is greater
            j--;
        }
        A[j] = move(stats, temp);
        // move temp value to A[j]
    }
}
