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
        Sleep(1500);

        printf("> Throughout this game you will be making a lot of decisions\n");
        Sleep(500);
        printf("> To control your actions you will be answering prompts by typing:\n");
        Sleep(250);
        printf("> Y for Yes\n");
        Sleep(250);
        Sleep(250);
        printf("> N for No\n");
        Sleep(250);
        printf("> A to select 1st option\n");
        Sleep(250);
        printf("> B to select 2nd option\n");
        Sleep(250);
        printf("> C to select 3rd option\n");
        Sleep(250);
        printf("> All of your inputs you can confirm by pressing Enter\n");
        Sleep(1000);
        printf("> Good Luck!\n\n");
}
