#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

void loading(int s);

int main() {            // Main function

    for (int i = 0; i < 1; i++)
    {
        printf("> Who are you, brave adventurer?\n");
        Sleep(700);
        printf("> A. Archer\n");
        Sleep(300);
        printf("> B. Crusader\n");
        Sleep(300);
        printf("> C. Sorcerer\n");
        Sleep(700);
    }
    
    char characterSelect;
    char currentCharacter[20];
    char archer[10] = "Archer";
    char crusader[10] = "Crusader";
    char sorcerer[10] = "Sorcerer";

    while (1)
    {
        printf("\n> Select your class by pressing A, B or C and confirm with Enter: ");
        scanf("%c", &characterSelect);
        
        if (characterSelect == 'a' || characterSelect == 'A' || characterSelect == 'b' || characterSelect == 'B' || characterSelect == 'c' || characterSelect == 'C')
        {
            if (characterSelect == 'a' || characterSelect == 'A')
            {
                strcpy(currentCharacter, archer);
                // printf("%s", currentCharacter);
            }
            if (characterSelect == 'b' || characterSelect == 'B')
            {
                strcpy(currentCharacter, crusader);
                // printf("%s", currentCharacter);
            }
            if (characterSelect == 'c' || characterSelect == 'C')
            {
                strcpy(currentCharacter, sorcerer);
                // printf("%s", currentCharacter);
            }
            
            loading(1);

            if (characterSelect == 'a' || characterSelect == 'A')
            {
                printf("> So you are an [%s]\n\n", currentCharacter);
            }
            else
            {
                printf("> So you are a [%s]\n\n", currentCharacter);    
            }
            break;
        }
        else 
        {
            printf("> A, B or C. Please try again.\n");

            // Clear the input buffer
            int clearBuffer;
            while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
            // I don't get the above yet but:
            // The while loop with getchar() reads and discards characters until it encounters a newline ('\n') or end-of-file (EOF), effectively clearing the buffer.
        }
    }
    char name[50];
    char surname[50];

    while (1)
    {
        Sleep(500);
        printf("> What is your name Adventurer? ");
        scanf("%s", &name);
        // scanf("%s", &surname);
        Sleep(500);
        printf("\n> And thus your journey begins, brave [%s]\n", name);
        Sleep(60000);
        break;
    }
    

    return 0;
}

// 10 element loading bar which takes the argument in seconds to display this amount of loading time
void loading(int s) {
    int ms = s * 100;
    printf("\n> Loading: [");
    for (int i = 0; i < 10; i++)
    {
        printf("+");
        Sleep(ms);
    }
    printf("]\n");
}