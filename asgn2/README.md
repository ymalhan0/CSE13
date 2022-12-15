# Assignment 2 - A Little Slice of Pi

This program implements a small number of mathematical functions that mimics ```<math.h>``` then using them to compute the constants e and pi.

## Building

To build this program use the Makefile by entering ```make``` or ```make all``` or ```make mathlib-test``` which will compile the main function, mathlib-test.c, and produce mathlib-test with the required compiler flags. Use ```make clean``` in order to remove all .o files and binaries. Use ```make format``` in order to properly format all files. 

## Running

Use ```./mathlib-test``` in order to run the program, followed by ```[-aebmrvnsh]``` in order to run the following options:

**-a**: run all tests

**-e**: run e approximation test

**-b**: run bbp pi test

**-m**: run madhava pi test

**-r**: run euler pi test

**-v**: run viete pi test

**-n**: run newton sqrt test

**-s**: enable printing of statistics to see computed terms and factors for each tested function

**-h**: display help message detailing program usage


### Bugs and Errors

No known errors for this program, and no errors produced by scan-build
