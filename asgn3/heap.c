#include "heap.h"

#include "stats.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// all functions for heap.c are from the python code in the assignment document provided by professor Long
int max_child(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    uint32_t left = 2 * first;
    uint32_t right = left + 1;
    // using formula, left = 2k and right = 2k + 1
    if (right <= last && cmp(stats, A[right - 1], A[left - 1]) > 0) {
        return right;
        // if right is < last and from comparing left and right, right is larger then return right as the max child of the parent node else return left
    }
    // using A[right-1] cuz C uses 0 based indexing and we run heapsort assuming 1 based indexing
    return left;
}

void fix_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    bool found = false;
    uint32_t mother = first;
    uint32_t great = max_child(stats, A, mother, last);
    // get max child of parent node and save to great
    while (mother <= (last / 2) && !found) {
        // while parent index of k/2 and found is false (!false = true)
        if (cmp(stats, A[mother - 1], A[great - 1]) < 0) {
            // compare parent node and max child
            swap(stats, &A[mother - 1], &A[great - 1]);
            //swap em if parent < child
            mother = great;
            // save prev max child to parent
            great = max_child(stats, A, mother, last);
            // get next max child node
        } else {
            found = true;
        }
    }
}

void build_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    for (uint32_t father = last / 2; father > first - 1; father--) {
        fix_heap(stats, A, father, last);
        // fix heap after removing largest element from heap
    }
}

void heap_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t first = 1;
    uint32_t last = n;
    build_heap(stats, A, first, last);
    // build heap
    for (uint32_t leaf = last; leaf > first; leaf--) {
        swap(stats, &A[first - 1], &A[leaf - 1]);
        // swap first with leaf if leaf is greater than first, removing large element
        fix_heap(stats, A, first, leaf - 1);
        // fix heap
    }
}
