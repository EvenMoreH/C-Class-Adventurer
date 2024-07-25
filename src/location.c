#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


#include "../include/location.h"

#include "../include/globalStruct.h"
#include "../include/globalVar.h"

#include "../include/intro.h"


//  Locations  ///////////////////////////////////////////////////////

void discoveredLocation(int location) {
    for (int i = 0; i < 100; i++)
    {
        if (location == locations[i].locationID)
        {
            Sleep(1000);
            printf("----------------------------------------");
            newLine(1);
            printf("> You discovered [%s]", locations[i].locationName);
            newLine(1);
            printf("----------------------------------------");
            newLine(1);
            Sleep(1000);
            break;
        }
    }
}

void enterLocation(int location) {
    for (int i = 0; i < 100; i++)
    {
        if (location == locations[i].locationID)
        {
            Sleep(2000);
            printf("----------------------------------------");
            newLine(1);
            printf("> You enter the [%s]", locations[i].locationName);
            newLine(1);
            printf("----------------------------------------");
            newLine(1);
            Sleep(2000);
            break;
        }
    }
}