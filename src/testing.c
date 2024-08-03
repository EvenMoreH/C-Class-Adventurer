#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities
#include <ctype.h>      // allows for tolower() funtion


#include "../include/globalStruct.h"
#include "../include/globalVar.h"

#include "../include/decisions.h"
#include "../include/encounter.h"
#include "../include/equipment.h"
#include "../include/intro.h"
#include "../include/location.h"
#include "../include/monsters.h"
#include "../include/playerActions.h"

// TRUE/FALSE flag to ON/OFF testing related functions in [testing.c] file
void testing(bool test) {
    if (test == 1)
    {
        printf("\n\t# TESTING STARTED #\n\n");

        foundItem(12);
        foundItem(potion);
        foundItem(11);

        mainWeaponTier1();
        offWeaponTier1();
        armorTier1();

        printf("\n\t# TESTING FINISHED #\n");
    }
    else
    {
        // No testing //
    }
}