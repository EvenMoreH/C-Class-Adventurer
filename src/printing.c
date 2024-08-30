#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities
#include <ctype.h>      // allows for tolower() funtion
#include <stdarg.h>     // to operate on unknown number of arguments


#include "../include/printing.h"

#include "../include/globalStruct.h"
#include "../include/globalVar.h"

// Requires: <stdarg.h>
    // 'destination' is a string that holds final output (I will use global textOutput[256])
    // 'prompt' is a formatted text with arguments to be printed (same format as with printf)
    // For example: "Your current HP: [%d/%d].", a, b
void toString(char *destination, const char *prompt, ...) {
    va_list args;
    va_start(args, prompt);

    vsprintf(destination, prompt, args);

    va_end(args);

    storyText(textOutput);
}