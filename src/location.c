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
    currentLocation = location;
    for (int i = 0; i < 10; i++)
    {
        if (location == locations[i].locationID)
        {
            Sleep(1000);
            printf("\n-----------------------------------\n");
            printf("> You discovered [%s]\n", locations[i].locationName);
            printf("-----------------------------------\n\n");
            Sleep(1000);
            break;
        }
    }
}

void enterLocation(int location) {
    currentLocation = location;
    for (int i = 0; i < 10; i++)
    {
        if (location == locations[i].locationID)
        {
            Sleep(2000);
            printf("-----------------------------------\n");
            printf("> You enter the [%s]\n", locations[i].locationName);
            printf("-----------------------------------\n");
            Sleep(2000);
            break;
        }
    }
}