#include "names.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER } Position;
const Position pig[7] = { SIDE, SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER, JOWLER };

#define SEED 2021

int main(void) {
    // first scan input for number of players
    int numPlayers = 0;
    printf("How many players? ");
    scanf("%d", &numPlayers);

    // check if valid
    if (numPlayers < 2 || numPlayers > 10) {
        fprintf(stderr, "Invalid number of players. Using 2 instead.\n");
        numPlayers = 2;
    }
    // have user enter seed
    int userSeed;
    printf("Random seed: ");
    scanf("%d", &userSeed);

    // check if seed is valid
    if (userSeed < 0 || userSeed > INT_MAX) {
        //if invalid then print next line
        fprintf(stderr, "Invalid random seed. Using 2021 instead.\n");
        srandom(SEED);
        //use 2021 seed as default
    } else {
        srandom(userSeed);
        //if valid then use user's seed
    }

    // set players points to zero using array
    int scorePlayer[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    int endGame = 0;
    while (!endGame) {
        // keep looping through game

        // go through each player
        for (int i = 0; i < numPlayers; i++) {

            // if someone won then end game
            if (scorePlayer[i] >= 100) {
                printf("%s wins with %d points!\n", names[i], scorePlayer[i]);
                endGame = 1;
                break;
            } else if (scorePlayer[i - 1] >= 100) {
                printf("%s wins with %d points!\n", names[i - 1], scorePlayer[i - 1]);
                endGame = 1;
                break;
            } else if (scorePlayer[i + 1] >= 100) {
                printf("%s wins with %d points!\n", names[i + 1], scorePlayer[i + 1]);
                endGame = 1;
                break;
            }

            // otherwise print player name
            printf("%s rolls the pig...", names[i]);
            // print player name
            int roll = 0;
            int endTurn = 0;

            while (!endTurn) {
                // keep looping switch till side rolled or 100 points reached

                // switch case to roll random dice and print corresponding side
                switch (roll = random() % 7) {
                case 0:
                case 1:
                    // cases for side

                    printf(" pig lands on side\n");
                    endTurn = 1;
                    //end the roll for player if side is rolled

                    break;
                case 2:
                    // case for back

                    printf(" pig lands on back");

                    scorePlayer[i] += 10;
                    // increment score by 10

                    // if player got 100 points then exit switch
                    if (scorePlayer[i] >= 100) {
                        endTurn = 1;
                        printf("\n");
                    }
                    break;
                case 3:
                    // case for upright
                    printf(" pig lands upright");

                    scorePlayer[i] += 10;
                    // increment score by 10

                    // if player got 100 points then exit switch
                    if (scorePlayer[i] >= 100) {
                        endTurn = 1;
                        printf("\n");
                    }
                    break;
                case 4:
                    // case for snout
                    printf(" pig lands on snout");

                    scorePlayer[i] += 15;
                    // increment score by 15

                    // if player got 100 points then exit switch
                    if (scorePlayer[i] >= 100) {
                        endTurn = 1;
                        printf("\n");
                    }
                    break;
                case 5:
                case 6:
                    // cases for ear
                    printf(" pig lands on ear");

                    scorePlayer[i] += 5;
                    // increment score by 5

                    // if player got 100 points then exit switch
                    if (scorePlayer[i] >= 100) {
                        endTurn = 1;
                        printf("\n");
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
