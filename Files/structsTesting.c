#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


// structs in global scope:
struct item {
    int id;
    char description[100];
};
    struct item items2[3] = {
       {1, ""},
       {2, "Knife"},
       {3, "Stone"},
    };
    

int main() {            // Main function

    printf("\n-> %s\n", items2[0].description);
    printf("\n-> %s\n", items2[1].description);
    printf("\n-> %s\n", items2[2].description);

    struct item items[6];
    items[0].id = 0;
    strcpy(items[0].description, "");       // <- empty slot

    items[1].id = 1;
    strcpy(items[1].description, "Knife");

    items[2].id = 2;
    strcpy(items[2].description, "Stone");

    items[3].id = 3;
    strcpy(items[3].description, "Stone2");

    items[4].id = 4;
    strcpy(items[4].description, "Stone3");

    items[5].id = 5;
    strcpy(items[5].description, "Stone4");


    // backpack[0] = items[0]; works!!
    struct item backpack[21];
    backpack[0] = items[0];         // <- initialization of an empty backpack where 1st slot is empty
    for (int i = 1; i < 21; i++)
    {
        backpack[i].id;
        strcpy(backpack[i].description, "");    // to fill backpack struct with empty space which then can be replaced by actual items
    }


    backpack[0] = items[2];
    backpack[1] = items[3];
    backpack[2] = items[4];
    backpack[6] = items[5];
    backpack[9] = items[5];



    for (int i = 1; i < 21; i++)
    {
        printf("backpack slot id: %d // ", backpack[i].id);
        if (strcmp(backpack[i].description, items[0].description) == 0)
        {
            backpack[i] = items[1];
            break;
        }
    }

    printf("\n\n\n");
    
    printf("Backpack contents: ");

    for (int i = 0; i < 21; i++)
    {
        printf("[%s] ", backpack[i].description);
    }
    printf("\n");


    

    // not declaring exact id creates them randomly which is a disaster

    return 0;               // Ends main function
}