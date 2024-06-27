#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

// Global variables
int itemID;
int result;

// Locations - global
    // Location IDs = 200-210
int location;
int currentLocation;    // Used in decision trees to move between locations
struct location {
    int locationID;
    char locationName[40];
    char locationDescription[200];
};
    struct location locations[] = {
       {200, "City", ""},
       {201, "Mountain Road", ""},
       {202, "Tomb of the Forsaken", ""},
       {203, "Mountain Pass", ""},
       {204, "Mines", ""},
       {205, "Graveyard", ""},
    };

// Global item management
struct item {
    int id;
    char iname[25];
    char description[100];
};
    // item IDs = 0-99
    struct item items[] = {
       {0, "", ""},     // <- something to mimic empty slots
       {1, "Bow", ""},
       {2, "Dagger", ""},
       {3, "Leather Armor", ""},
       {4, "Stoneskull Key", "Required to open Stone Gates located at [Mountain Road]"},
    };

// Global backpack management
    // backpack IDs = 100-110
    struct item backpack[] = {
        {100, "", ""},
        {101, "", ""},
        {102, "", ""},
        {103, "", ""},
        {104, "", ""},
        {105, "", ""},
        {106, "", ""},
        {107, "", ""},
        {108, "", ""},
        {109, "", ""},
        {110, "", ""},
    };


// Functions
void whatsInTheBag();
void addToBag(int itemID);
void removeFromBag(int itemID);
void decision();
void foundItem(int itemID);
void discoveredLocation(int location);      // Argument here is called location and should match one of the predefined location IDs
void enterLocation(int location);           // Argument here is called location and should match one of the predefined location IDs



int main() {            // Main function

    printf("> Would you like to enter this cave?\n");

    decision();

    if (result == 1)
    {
        printf("> You entered a cave.\n");
        Sleep(1000);

        discoveredLocation(204);

        printf("> Would you like to go deeper?\n");

        decision();

        if (result == 1)
        {
            Sleep(1000);
            printf("> You go deeper and find a treasure!\n");

            foundItem(4);
            addToBag(4);
            whatsInTheBag();

        }
        else
        {
            Sleep(1000);
            printf("> You turn back and head home to rest.\n");
        }
    }
    else
    {
        printf("> You went back to town.\n");
        Sleep(1000);
        printf("> Would you like to go to the tavern?\n");
        
        decision();

        if (result == 1)
        {
            Sleep(1000);
            printf("> You drink till you pass out...\n");
        }
        else
        {
            Sleep(1000);
            printf("> You go home and rest for the day.\n");
        }
        
        
    }
    
    
    return 0;               // Ends main function
}

// Fuctions - code

void whatsInTheBag() {
    printf("> Current contents of your backpack: "); 
    for (int i = 0; i < 10; i++)
    {
        Sleep(100);
        printf("[%s] ", backpack[i].iname);
    }
    printf("\n");
    Sleep(1000);
}

void addToBag(int itemID) {
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(backpack[i].iname, items[0].iname) == 0)
        {
            backpack[i] = items[itemID];
            break;
        }
    }
}

void removeFromBag(int itemID) {
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(backpack[i].iname, items[itemID].iname) == 0)
        {
            backpack[i] = items[0];
            break;
        }
    }
}

void decision() {
    int q;
    Sleep(500);
    printf("> [Y/N]: ");
    scanf(" %c", &q);
    if (q == 'Y' || q == 'y')
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    
}

void foundItem(int itemID) {
    Sleep(1000);
    printf("-----------------------------------\n");
    Sleep(500);
    printf("> You found [%s]\n", items[itemID].iname);
    Sleep(500);
    printf("-----------------------------------\n");
    Sleep(2000);
}

void discoveredLocation(int location) {
    currentLocation = location;
    for (int i = 0; i < 10; i++)
    {
        if (location == locations[i].locationID)
        {
            Sleep(1000);
            printf("-----------------------------------\n");
            Sleep(500);
            printf("> You discovered [%s]\n", locations[i].locationName);
            Sleep(500);
            printf("-----------------------------------\n");
            Sleep(2000);
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
            Sleep(1000);
            printf("-----------------------------------\n");
            Sleep(500);
            printf("> You enter [%s]\n", locations[i].locationName);
            Sleep(500);
            printf("-----------------------------------\n");
            Sleep(2000);
            break;
        }
    }
}