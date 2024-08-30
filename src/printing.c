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

int a = 14;
int b = 20;
int c = 40;
int d = 50;

char textBuffer[256];

char textOutput[256];

char testLocation1[] = "Village";
char testLocation2[] = "City";


void storyText(char textToWrite[]);

void toString(char *input, const char *format, ...);

int main() {            // Main function

    sprintf(textBuffer, "Your current HP: [%i/%i].", a, b);
    storyText(textBuffer);

    sprintf(textBuffer, "You reached your destination: [%s].", testLocation1);
    storyText(textBuffer);

    printf("\n\n");

    toString(textOutput, "Player health is %i/%i. Player mana is %i/%i. You reached: %s. Your next stop is: %s.", a, b, c, d, testLocation1, testLocation2);

    a = 2;
    c = 21;

    strcpy(textBuffer, testLocation2);
    strcpy(testLocation2, testLocation1);
    strcpy(testLocation1, textBuffer);


    toString(textOutput, "Player health is %i/%i. Player mana is %i/%i. You reached: %s. Your next stop is: %s.", a, b, c, d, testLocation1, testLocation2);


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

// 'destination' is a string that holds final output
    // 'prompt' is a formatted text with arguments to be printed (same format as with printf)
    // For example: "Your current HP: [%d/%d].", a, b
void toString(char *destination, const char *prompt, ...) {
    va_list args;
    va_start(args, prompt);

    vsprintf(destination, prompt, args);

    va_end(args);

    storyText(textOutput);
}