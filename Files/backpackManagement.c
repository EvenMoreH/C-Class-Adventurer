#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


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


int main() {            // Main function
    char q;

    struct item items[3];
    items[0].id = 0;
    strcpy(items[0].description, "");       // <- empty slot

    items[1].id = 1;
    strcpy(items[1].description, "Super sharp knife");

    items[2].id = 2;
    strcpy(items[2].description, "Stone Key");

    // backpack[0] = items[0]; works!!
    struct item backpack[21];
    backpack[0] = items[0];         // <- initialization of an empty backpack where 1st slot is empty
    for (int i = 1; i < 21; i++)
    {
        backpack[i].id;
        strcpy(backpack[i].description, "");    // to fill backpack struct with empty space which then can be replaced by actual items
    }
    
    // current items:
    // Equipment is given to player
    backpack[0] = items[1];

 
    // ENCOUNTER: Stone key on the ground
    printf("> You encounter [%s] on the ground.\n", items[2].description);
    Sleep(1000);

    printf("> Current contents of your backpack: "); 
    for (int i = 0; i < 21; i++)
    {
        printf("[%s] ", backpack[i].description);
    }
    printf("\n");
    Sleep(1000);

    printf("> Would you like to pick up this item? Y/N\n");
    scanf(" %c", &q);      // adding space before %c forces programme to remove white spaces and now scanf can be stacked
    Sleep(1000);

    if (q == 'Y' || q == 'y')
    {
        backpack[1] = items[2];
        printf("> Updated backpack contents: ");
        for (int j = 0; j < 21; j++)
        {
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

    printf("> Do you want to insert [%s] into the opening? Y/N\n", items[2].description);
    scanf(" %c", &q);
    if (q == 'Y' || q == 'y')
    {      
        int k = items[2].id;
        int result;
        for (int j = 0; j < 21; j++)
        {
            if (backpack[j].id == items[k].id)
            {
                result = 1;
                break;
            } 
            else
            {
                result = 0;
            }   
        } 

        if (result == 0)
        {
            location = 2;
            printf("> You don't have a necessary item in your bag.\n");
            Sleep(1000);
            printf("> You wonder off to find another route...\n");
            Sleep(1000);
        }
        else
        {
            location = 1;
            backpack[1] = backpack[0];
            printf("> You have used [%s]. These are your current backpack contents: ", items[2].description);
            for (int i = 0; i < 21; i++)
            {
                printf("%s ", backpack[i].description);
            }
            printf("\n");
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