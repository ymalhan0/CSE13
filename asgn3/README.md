# Assignment 3 - Sorting

This program implements different sorting algorithms and compares the time complexity of each by comparing the moves and compares each takes for a number of elements.

## Building

Build this program by running ```make```, ```make all```, or ```make sorting``` which will compile the main function, sorting.c, and produce sorting with the required compiler flags. Use ```make clean``` in order to remove all .o files and binaries. Use ```make format``` in order to format all files.

## Running

Use ./sorting in order to run the program, followed by ```[-aeisqr:n:p:h]``` in order to run the following options:

-a: run all tests

-e: run Heapsort

-i: run Insertion Sort

-s: run Shell Sort

-q: run Quick Sort

-r: Set the random seed, the default is 13371453

-n: Set the array size, the default array size is 100

-p: print elements of the array, the default is 100

-h: print out the program usage


### Bugs and Errors

No errors produced by scan-build but when entering -a --> the output of each stats from the sorts differs from the example binary but not when each sort is printed otherwise (using the other options, not -a).
