#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

// NOTES:
    // standard sleep: 1000ms
    // action sleep: 2000ms
    // discovery sleep: 3000ms
    // backpack iteration sleep: 200ms

// Global variables
int location;
// location 1 - tomb
// location 2 - mountain pass

// List of structs:
struct item {
    int id;
    char description[100];
};

// list of fuctions:
void loading(int s);
void currentLocation(int location);
void combatStarts();


int main() {
    char q;     // variable to store Y/N answers for players decisions

    // items hold IDs between 0-99
    struct item items[3];
    items[0].id = 0;
    strcpy(items[0].description, "");       // <- empty slot

    items[1].id = 1;
    strcpy(items[1].description, "Super sharp knife");

    items[2].id = 2;
    strcpy(items[2].description, "Stone Key");

    // backpack[0] = items[0]; works!!
    struct item backpack[10];
    for (int i = 0; i < 10; i++)
    {
        backpack[i].id = i + 100;   // backpack slots have 100-110 IDs
        strcpy(backpack[i].description, "");    // to fill backpack struct with empty space which then can be replaced by actual items
    }
    
    // current items:
    // Equipment is given to player
    backpack[0] = items[1];

 
    // ENCOUNTER: Stone key on the ground
    printf("> You encounter [%s] on the ground.\n", items[2].description);
    Sleep(1000);

    printf("> Current contents of your backpack: "); 
    for (int i = 0; i < 10; i++)
    {
        Sleep(100);
        printf("[%s] ", backpack[i].description);
    }
    printf("\n");
    Sleep(1000);

    printf("> Would you like to pick up this item? [Y/N]\n");
    scanf(" %c", &q);      // adding space before %c forces programme to remove white spaces and now scanf can be stacked
    Sleep(1000);

    if (q == 'Y' || q == 'y')
    {
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(backpack[i].description, items[0].description) == 0)
            {
                backpack[i] = items[2];
                break;
            }
        }
        printf("> Updated backpack contents: ");
        for (int j = 0; j < 10; j++)
        {
            Sleep(100);
            printf("[%s] ", backpack[j].description);
        }
        printf("\n");
    }
    else
    printf("> You leave the [%s] be and move along.\n", items[2].description);
    Sleep(1000);

    // ENCOUNTER: Stone door and stone key
    printf("> You see a massive stone door, instead of knob you see an opening that resembles [%s].\n", items[2].description);
    Sleep(3000);

    printf("> Do you want to insert [%s] into the opening? [Y/N]\n", items[2].description);
    scanf(" %c", &q);
    if (q == 'Y' || q == 'y')
    {      
        int k = items[2].id;
        int result;
        for (int j = 0; j < 10; j++)
        {
            if (strcmp(backpack[j].description, items[k].description) == 0)
            {
                result = 0;
                break;
            } 
            else
            {
                result = 1;
            }   
        } 

        if (result == 1)
        {
            location = 2;
            printf("> You don't have a necessary item in your bag.\n");
            Sleep(1000);

            printf("> Would you like to go back to find the [%s] if not, you will have to look for a different passage? [Y/N] ", items[2].description);
            scanf(" %c", &q);
            if (q == 'Y' || q == 'y')
            {
                printf("> You go back to the crossroads where you encountered this strange item.\n");
                Sleep(1000);
                printf("> You manage to find it and put it in your backpack.\n");
                Sleep(1000);
                
                for (int i = 0; i < 10; i++)
                {
                    if (strcmp(backpack[i].description, items[0].description) == 0)
                    {
                        backpack[i] = items[2];
                        break;
                    }
                }
                printf("> Updated backpack contents: ");
                for (int j = 0; j < 10; j++)
                {
                    Sleep(100);
                    printf("[%s] ", backpack[j].description);
                }
                printf("\n");

                Sleep(2000);
                printf("> You start jogging towards great stone gates to use the [%s].\n", items[2].description);
                Sleep(1000);
                printf("> A club hits your head... You fall to the ground...\n");
                Sleep(1000);
                printf("> You muster all the strength you have and pick yourself up.\n");
                Sleep(1000);
                printf("> Hobgoblin stand before you and is ready to strike!\n");
                Sleep(3000);
                combatStarts();
                Sleep(3000);

                printf("> You manged to defeat the adversary! You continue the journey towards stone gates.\n");
                Sleep(3000);

                {
                    location = 1;
                    for (int j = 0; j < 10; j++)
                    {
                        if (strcmp(backpack[j].description, items[k].description) == 0)
                        {
                            backpack[j] = items[0];
                            break;
                        }
                    }
                    Sleep(2000); 
                    printf("> You have used [%s].\n", items[2].description);
                    Sleep(1000);
                    printf("> These are your current backpack contents: ");
                    for (int i = 0; i < 10; i++)
                    {
                        Sleep(100);
                        printf("[%s] ", backpack[i].description);
                    }
                    printf("\n");
                    Sleep(2000);
                    printf("> Stone gates slowly open and dark cave stands before you...\n");
                }

            }
            else
            {
                printf("> You wonder off to find another route...\n");
                Sleep(1000);
            }
        }
        else
        {
            location = 1;
            for (int j = 0; j < 10; j++)
            {
                if (strcmp(backpack[j].description, items[k].description) == 0)
                {
                    backpack[j] = items[0];
                    break;
                }
            }
            Sleep(2000); 
            printf("> You have used [%s].\n", items[2].description);
            Sleep(1000);
            printf("> These are your current backpack contents: ");
            for (int i = 0; i < 10; i++)
            {
                Sleep(100);
                printf("[%s] ", backpack[i].description);
            }
            printf("\n");
            Sleep(2000);
            printf("> Stone gates slowly open and dark cave stands before you...\n");
        }
    }
    else
    {
        location = 2;
        printf("> You leave the door and search for different route...\n");
        Sleep(1000);
    }

    loading(5);
    currentLocation(location);

    Sleep(60000);
    return 0;               // Ends main function
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

void currentLocation(int location) {
    if (location == 1)
    {
        printf("---------------------------\n");
        printf("|                         |\n");
        printf("|        You Enter        |\n");
        printf("|                         |\n");
        printf("|  Tomb of the Forsaken   |\n");
        printf("|                         |\n");
        printf("---------------------------\n");
    }
    if (location == 2)
    {
        printf("---------------------------\n");
        printf("|                         |\n");
        printf("|        You Enter        |\n");
        printf("|                         |\n");
        printf("|      Mountain Pass      |\n");
        printf("|                         |\n");
        printf("---------------------------\n");
    }   
}

void combatStarts() {
    printf("---------------------------\n");
    printf("|                         |\n");
    printf("|          Fight!         |\n");
    printf("|                         |\n");
    printf("|        Round One        |\n");
    printf("|                         |\n");
    printf("---------------------------\n");
}