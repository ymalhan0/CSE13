#include "shell.h"

#include "stats.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// used python code in assignment doc for shell sort, did not use helper function like the pseudocode

void shell_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t k = floor((log(3 + 2 * n)) / log(3));
    // largest gap or k

    for (uint32_t gap = k; gap > 0; gap--) {
        // loop through largest gap (k)
        for (uint32_t i = floor((pow(3, gap) - 1) / 2); i < n; i++) {
            // use the gaps
            uint32_t j = i;
            int tmp = move(stats, A[i]);
            // move A[i] to a temp value
            while (j >= gap && cmp(stats, tmp, A[j - gap]) < 0) {
                // compare tmp with value that is gap away
                A[j] = move(stats, A[j - gap]);
                // move to put in increasing order
                j -= gap;
            }
            A[j] = move(stats, tmp);
            // set to temp value
        }
    }
}
