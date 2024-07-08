#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


#include "../include/globalVar.h"
#include "../include/globalStruct.h"
#include "../include/decisions.h"


//  Decision Trees  //////////////////////////////////////////////////

void decision() {
    clearBuffer();

    char q;

    Sleep(500);

    while (1)
    {
        printf("> [Y/N]: ");
        scanf(" %c", &q);
        if (q == 'Y' || q == 'y')
        {
            result = 1;
            break;
        }
        else if (q == 'N' || q == 'n')
        {
            result = 0;
            break;
        }
        else
        {
            printf("> Y or N. Please try again.\n");

            clearBuffer();
        }
    }
}

void selectionAB() {

    clearBuffer();

    int ab;

    Sleep(500);
    while (1)
    {
        printf("> [A/B]: ");
        scanf(" %c", &ab);

        if (ab == 'A' || ab == 'a')
        {
            abResult = 1;
            break;
        }
        if (ab == 'B' || ab == 'b')
        {
            abResult = 0;
            break;
        }
        else
        {
        printf("> A, B. Please try again.\n");

        clearBuffer();
        }
    }
}

void selectionABC() {
    clearBuffer();

    int abc;

    Sleep(500);

    while (1)
    {
        printf("> [A/B/C]: ");
        scanf(" %c", &abc);

        if (abc == 'A' || abc == 'a')
        {
            abcResult = 1;
            break;
        }
        if (abc == 'B' || abc == 'b')
        {
            abcResult = 2;
            break;
        }
        if (abc == 'C' || abc == 'c')
        {
            abcResult = 3;
            break;
        }
        else
        {
        printf("> A, B. Please try again.\n");

        clearBuffer();
        }
    }
}