#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


#include "../include/globalStruct.h"
#include "../include/globalVar.h"
#include "../include/printing.h"

#include "../include/testing.h"

#include "../include/decisions.h"
#include "../include/encounter.h"
#include "../include/equipment.h"
#include "../include/intro.h"
#include "../include/location.h"
#include "../include/monsters.h"
#include "../include/playerActions.h"

#include "../include/act1.h"


int main() {
    randomize();

    intro();
    pressC();
    chooseCharacter();
    printCharacterSheet(currentChar);
    pressC();

    testing(false);

    actOne();

////////////////////////////////////////////
    newLine(2);
    formattedText("EOF");
    Sleep(15000);

    return 0;               // Ends main function
}