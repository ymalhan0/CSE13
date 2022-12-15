#include "mathlib.h"

#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#define OPTIONS "aebmrvnsh"

// main function / test harness that runs all tests
int main(int argc, char **argv) {
    int opt = 0;
    // bools for each test
    bool do_terms = false;
    bool run_mad = false;
    bool run_all = false;
    bool run_e = false;
    bool run_euler = false;
    bool run_viete = false;
    bool run_bbp = false;
    bool run_newt = false;
    bool run_help = false;

    // while loop to determine each entered option, setting bools to true if option selected
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': run_all = true; break;
        case 'e': run_e = true; break;
        case 'b': run_bbp = true; break;
        case 'm': run_mad = true; break;
        case 'r': run_euler = true; break;
        case 'v': run_viete = true; break;
        case 'n': run_newt = true; break;
        case 's': do_terms = true; break;
        case 'h': run_help = true; break;
        default: run_help = true; break;
        }
    }

    // if a selected then run all tests
    if (run_all) {
        // e() test
        printf("e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf\n", e(), M_E, absolute(e() - M_E));
        if (do_terms) {
            // if s selected then print terms as well
            printf("e_terms() = %d\n", e_terms());
        }
        // bbp test
        printf("pi_bbp() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_bbp(), M_PI,
            absolute(pi_bbp() - M_PI));
        if (do_terms) {
            // if s selected then print terms as well
            printf("pi_bbp_terms() = %d\n", pi_bbp_terms());
        }
        // madhava test
        printf("pi_madhava() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_madhava(), M_PI,
            absolute(pi_madhava() - M_PI));
        if (do_terms) {
            // if s selected then print terms as well
            printf("pi_madhava_terms() = %d\n", pi_madhava_terms());
        }
        // viete test
        printf("pi_viete() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_viete(), M_PI,
            absolute(pi_viete() - M_PI));
        if (do_terms) {
            // if s selected then print terms as well
            printf("pi_viete_factors() = %d\n", pi_viete_factors());
        }
        // sqrt newton test - prints sqrt of i from 0 to 10 in increments of 0.1
        for (double i = 0.0; i <= 10.0; i += 0.1) {
            printf("sqrt_newton(%7.6lf) = %16.15lf, sqrt(%7.6lf) = %16.15lf, diff = %16.15lf\n", i,
                sqrt_newton(i), i, sqrt(i), absolute(sqrt_newton(i) - sqrt(i)));
            if (do_terms) {
                // if s selected then print terms as well
                printf("sqrt_newton_iters() = %d\n", sqrt_newton_iters());
            }
        }
        return 0;
        // end program
    }
    // run help option that describes test harness usage, and options
    if (run_help) {
        printf("SYNOPSIS\n   A test harness for the small numerical library.\n\n");
        printf("USAGE\n   ./mathlib-test [-aebmrvnsh]\n\n");
        printf(
            "OPTIONS\n  -a   Runs all tests.\n  -e    Runs e test.\n  -b   Runs BBP pi test.\n  "
            "-m   Runs Madhava pi test.\n  -r   Runs Euler pi test.\n  -v   Runs Viete pi "
            "test.\n  -n   Runs Newton square root tests.\n  -s   Print verbose statistics.\n  -h "
            "  Display program synopsis and usage.\n");
        return 0;
        // end program
    }

    // run only e test
    if (run_e) {
        printf("e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf\n", e(), M_E, absolute(e() - M_E));
        if (do_terms) {
            // if s selected then print terms as well
            printf("e_terms() = %d\n", e_terms());
        }
    }
    // run only bbp test
    if (run_bbp) {
        printf("pi_bbp() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_bbp(), M_PI,
            absolute(pi_bbp() - M_PI));
        if (do_terms) {
            // if s selected then print terms as well
            printf("pi_bbp_terms() = %d\n", pi_bbp_terms());
        }
    }
    // run only madhava test
    if (run_mad) {
        printf("pi_madhava() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_madhava(), M_PI,
            absolute(pi_madhava() - M_PI));
        if (do_terms) {
            // if s selected then print terms as well
            printf("pi_madhava_terms() = %d\n", pi_madhava_terms());
        }
    }
    // run only euler test
    if (run_euler) {
        printf("pi_euler() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_euler(), M_PI,
            absolute(pi_euler() - M_PI));
        if (do_terms) {
            // if s selected then print terms as well
            printf("pi_euler_terms() = %d\n", pi_euler_terms());
        }
    }
    // run only viete test
    if (run_viete) {
        printf("pi_viete() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_viete(), M_PI,
            absolute(pi_viete() - M_PI));
        if (do_terms) {
            // if s selected then print terms as well
            printf("pi_viete_factors() = %d\n", pi_viete_factors());
        }
    }
    // run only sqrt newton, printing sqrt(i) from 0<=i<=10 in increments of 0.1
    if (run_newt) {
        for (double i = 0.0; i <= 10.0; i += 0.1) {
            printf("sqrt_newton(%7.6lf) = %16.15lf, sqrt(%7.6lf) = %16.15lf, diff = %16.15lf\n", i,
                sqrt_newton(i), i, sqrt(i), absolute(sqrt_newton(i) - sqrt(i)));
            if (do_terms) {
                // if s selected then print terms as well
                printf("sqrt_newton_iters() = %d\n", sqrt_newton_iters());
            }
        }
    }
    // run help option if nothing entered
    if (!run_all && !run_help && !run_e && !run_euler && !run_viete && !run_mad && !run_newt
        && !run_bbp) {
        printf("SYNOPSIS\n   A test harness for the small numerical library.\n\n");
        printf("USAGE\n   ./mathlib-test [-aebmrvnsh]\n\n");
        printf(
            "OPTIONS\n  -a   Runs all tests.\n  -e    Runs e test.\n  -b   Runs BBP pi test.\n  "
            "-m   Runs Madhava pi test.\n  -r   Runs Euler pi test.\n  -v   Runs Viete pi "
            "test.\n  -n   Runs Newton square root tests.\n  -s   Print verbose statistics.\n  -h "
            "  Display program synopsis and usage.\n");
        return 0;
    }
    return 0;
}
