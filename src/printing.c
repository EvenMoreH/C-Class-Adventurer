#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities
#include <ctype.h>      // allows for tolower() funtion


#include "../include/printing.h"

#include "../include/globalStruct.h"
#include "../include/globalVar.h"

int a = 14;
int b = 20;

char textBuffer[256];


char testLocation[] = "Village";

void storyText(char textToWrite[]);

int main() {            // Main function

    sprintf(textBuffer, "Your current HP: [%i/%i].", a, b);
    storyText(textBuffer);

    sprintf(textBuffer, "You reached your destination: [%s].", testLocation);
    storyText(textBuffer);


    return 0;               // Ends main function
}

void storyText(char textToWrite[]) {
    int len = strlen(textToWrite);

    printf("> ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", textToWrite[i]);
        Sleep(35);
    }
    printf("\n");
    Sleep(350);
}