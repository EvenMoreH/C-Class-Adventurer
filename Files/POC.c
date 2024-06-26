#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

void intro();       // outputs welcome screen

int main() {

    intro();


    return 0;
}

void intro() {
    for (int intro = 0; intro < 1; intro++)
    {
        printf("************************************************\n");
        Sleep(250);
        printf("****************                ****************\n");
        Sleep(250);
        printf("**************     WELCOME TO     **************\n");
        Sleep(250);
        printf("***********    C-CLASS ADVENTURER    ***********\n");
        Sleep(250);
        printf("*********                              *********\n");
        Sleep(250);
        printf("******    Journey Through Memory Leaks    ******\n");
        Sleep(250);
        printf("****                                        ****\n");
        Sleep(300);
        printf("************************************************\n\n\n");
        Sleep(300);
    }
}
