#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <getopt.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTIONS "aeisqr:n:p:h"

// this test harness is based off of Eugene's example code from section on 10/12, the lab document, and the assignment 2 test harness
typedef enum { HEAP, SHELL, INSERTION, QUICK, NUM_SORTS } Sorts;
// enumeration for sort types, from Eugene's section
int main(int argc, char **argv) {
    Stats stats;
    stats.moves = 0;
    stats.compares = 0;
    Set s = empty_set();
    // initializing all stats to 0 and creating an empty set for the sorts, from Eugene's section
    uint32_t seed = 13371453;
    // default seed
    uint32_t size = 100;
    // default size of array
    uint32_t printer = 100;
    // default number of elements to print
    int opt = 0;
    // while loop to determine each entered option
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            s = insert_set(HEAP, s);
            s = insert_set(INSERTION, s);
            s = insert_set(SHELL, s);
            s = insert_set(QUICK, s);
            // if all choses, add all the sort types to the set
            break;
        case 'e':
            s = insert_set(HEAP, s);
            break;
            // if e chosen, add heap to set
        case 'i':
            s = insert_set(INSERTION, s);
            break;
            // if i chosen add insertion sort to set
        case 's':
            s = insert_set(SHELL, s);
            break;
            // if s chosen add shell sort to set
        case 'q':
            s = insert_set(QUICK, s);
            break;
            // if q chosen add quick sort to set
        case 'r':
            seed = atoi(optarg);
            break;
            // if user changes seed from default, set the seed to what they entered using atoi(optarg)
        case 'n':
            size = atoi(optarg);
            break;
            // if user changes the number of elements then set size to new size
        case 'p':
            printer = atoi(optarg);
            break;
            // print number of elements user wants, the default is 0
        case 'h':
            // print help page and end program --> as per reference binary
            printf("SYNOPSIS\n  A collection of comparison-based sorting algorithms.\n\n");
            printf("USAGE\n   ./sorting [-haeisqn:p:r:] [-n length] [-p elements] [-r seed]");
            printf(
                "\n\nOPTIONS\n   -h              display program help and usage.\n   -a            "
                "  enable all sorts.\n   -e              enable Heap Sort.\n   -i              "
                "enable Insertion Sort.\n   -s              enable Shell Sort.\n   -q              "
                "enable Quick Sort.\n   -n length       specify number of array elements "
                "(default: 100).\n   -p elements     specify number of elements to print (default: "
                "100).\n   -r seed         specify random seed (default: 13371453).\n");
            return 0;
        }
    }
    // setting the seed using srandom
    srandom(seed);
    uint32_t *A = (uint32_t *) calloc(size, sizeof(uint32_t));
    for (uint32_t i = 0; i < size; i++) {
        A[i] = random() & 0x3FFFFFFF; // apply bitmask
    }
    // dynamic memory allocation --> create array of pseudorandom elements, from Eugene's section
    if (printer > size) {
        printer = size;
    }
    // if the number elements to be printed is greater than the size of the array, set the printer to size of array
    // ex: size = 20, print = 100 --> there arent 100 elements to print so set it to size of array

    for (Sorts x = HEAP; x < NUM_SORTS; x++) {
        // loop through the sorts and call on each sort accordingly
        reset(&stats);
        // reset the stats before calling each sort
        if (member_set(x, s) && x == HEAP) {
            // if heap is a member of the sort then use heap sort
            heap_sort(&stats, A, size);
            printf("Heap Sort, %d elements, %lu moves, %lu compares\n", size, stats.moves,
                stats.compares);
            // print the stats from heap sort
            for (uint32_t i = 0; i < printer; i++) {
                // format for the elements printed (5 columns)
                if (i == size - 1 || ((i + 1) % 5 == 0 && i > 0)) {
                    printf("%13" PRIu32, A[i]);
                    printf("\n");
                } else {
                    printf("%13" PRIu32, A[i]);
                }
            }
        } else if (member_set(x, s) && x == SHELL) {
            // if shell is member of set then use shell sort
            shell_sort(&stats, A, size);
            printf("Shell Sort, %d elements, %lu moves, %lu compares\n", size, stats.moves,
                stats.compares);
            // print shell sort stats --> much larger than example binary output
            for (uint32_t i = 0; i < printer; i++) {
                // format for the elements printed (5 columns)
                if (i == size - 1 || ((i + 1) % 5 == 0 && i > 0)) {
                    printf("%13" PRIu32, A[i]);
                    printf("\n");
                } else {
                    printf("%13" PRIu32, A[i]);
                }
            }
        } else if (member_set(x, s) && x == INSERTION) {
            // if insertion is member of set then use insertion sort
            insertion_sort(&stats, A, size);
            printf("Insertion Sort, %d elements, %lu moves, %lu compares\n", size, stats.moves,
                stats.compares);
            // print insertion sort stats
            for (uint32_t i = 0; i < printer; i++) {
                // format for the elements printed (5 columns)
                if (i == size - 1 || ((i + 1) % 5 == 0 && i > 0)) {
                    printf("%13" PRIu32, A[i]);
                    printf("\n");
                } else {
                    printf("%13" PRIu32, A[i]);
                }
            }
        } else if (member_set(x, s) && x == QUICK) {
            // if quick sort is member of sort then use it
            quick_sort(&stats, A, size);
            printf("Quick Sort, %d elements, %lu moves, %lu compares\n", size, stats.moves,
                stats.compares);
            // print stats for quick sort
            for (uint32_t i = 0; i < printer; i++) {
                // format for the elements printed (5 columns)
                if (i == size - 1 || ((i + 1) % 5 == 0 && i > 0)) {
                    printf("%13" PRIu32, A[i]);
                    printf("\n");
                } else {
                    printf("%13" PRIu32, A[i]);
                }
            }
        }
    }

    return 0;
}
