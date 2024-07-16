#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities
#include <ctype.h>      // allows for tolower() funtion


#include "../include/decisions.h"

#include "../include/globalStruct.h"
#include "../include/globalVar.h"


//  Decision Trees  //////////////////////////////////////////////////

// Y/N Selection
void decision() {
    char q;
    Sleep(500);
    while (1)
    {
        printf("> [Y/N]: ");
        scanf(" %c", &q);
        q = tolower(q);

        if (q == 'y')
        {
            result = 1;
            break;
        }
        else if (q == 'n')
        {
            result = 0;
            break;
        }
        else
        {
            customText("Y or N. Please try again.", 10, 10);
            clearBuffer();
        }
    }
}

void selectionAB() {
    char ab;
    Sleep(500);
    while (1)
    {
        printf("> [A/B]: ");
        scanf(" %c", &ab);
        ab = tolower(ab);

        if (ab == 'a')
        {
            abResult = 1;
            break;
        }
        if (ab == 'b')
        {
            abResult = 0;
            break;
        }
        else
        {
        customText("A, B. Please try again.", 10, 10);
        clearBuffer();
        }
    }
}

void selectionABC() {
    char abc;
    int loop = 0;
    Sleep(500);
    do {
        printf("> [A/B/C]: ");
        scanf(" %c", &abc);
        abc = tolower(abc);

        switch (abc)
        {
        case 'a':
            abcResult = 1;
            loop = 1;
            break;
        case 'b':
            abcResult = 2;
            loop = 1;
            break;
        case 'c':
            abcResult = 3;
            loop = 1;
            break;
        default:
            customText("A, B, C. Please try again.", 10, 10);
            clearBuffer();
            break;
        }
    } while (loop != 1);
}