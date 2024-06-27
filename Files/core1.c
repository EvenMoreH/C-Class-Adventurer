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

    // for yes or no questions
    int q;
    int result;

    // for A or B decisions
    int ab;
    int abResult;

    // for A or B or C decisions
    int abc;
    int abcResult;

    // for dealing and receiving damage (player)
    int dmg;
    int dmgTaken;

    // for declaring initial MAX HP and calculating current HP (player)
    int playerMaxHP;
    int playerCurrentHP;

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
       {200, "Town", ""},
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
    int minDMG;
    int maxDMG;
};
    // item IDs = 0-99
    struct item items[] = {
       {0, "", "", 0, 0},     // <- something to mimic empty slots
       {1, "Bow", "", 1, 6},
       {2, "Dagger", "", 1, 4},
       {3, "Leather Armor", "", 0, 0},
       {4, "Stoneskull Key", "Required to open Stone Gates located at [Mountain Road]", 0, 0},
    };

// Global backpack management
    // backpack IDs = 100-110
    struct item backpack[] = {
        {100, "", "", 0, 0},
        {101, "", "", 0, 0},
        {102, "", "", 0, 0},
        {103, "", "", 0, 0},
        {104, "", "", 0, 0},
        {105, "", "", 0, 0},
        {106, "", "", 0, 0},
        {107, "", "", 0, 0},
        {108, "", "", 0, 0},
        {109, "", "", 0, 0},
        {110, "", "", 0, 0},
    };


// Functions
void whatsInTheBag();
void addToBag(int itemID);
void removeFromBag(int itemID);
void decision();
void foundItem(int itemID);
void discoveredLocation(int location);      // Argument here is called location and should match one of the predefined location IDs
void enterLocation(int location);           // Argument here is called location and should match one of the predefined location IDs

int damage(int itemID);
int hp(int dmgTaken);

int playerMaxHealth(int vitality, int classHPX);


int main() {            // Main function

    printf("> Would you like to enter this cave?\n");

    decision();

    if (result == 0)
    {
        printf("> You entered a cave.\n");
        Sleep(1000);

        discoveredLocation(204);

        printf("> Would you like to go deeper?\n");

        decision();

        if (result == 0)
        {
            Sleep(1000);
            printf("> You go deeper and find a giant rat!\n");
            
            Sleep(1000);
            printf("> You hit it with your [%s].\n", items[2].iname);

            dmg = damage(2);
            
            Sleep(1000);
            printf("> You deal %d damage to it.\n", dmg);

            Sleep(1000);
            printf("> It runs away leaving an old backpack unattended in the corner.\n");

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

        enterLocation(200);

        printf("> Would you like to go to the tavern?\n");
        
        decision();

        if (result == 0)
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
        result = 0;
    }
    else
    {
        result = 1;
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

int damage(int itemID) {
    int x = items[itemID].minDMG;
    int y = items[itemID].maxDMG;

    return x + rand() % y;
}

int hp(int dmgTaken) {
    playerCurrentHP = playerMaxHP - dmgTaken;

    Sleep(1000);
    printf("> You have taken: [%i] damage.\n", dmgTaken);

    if (playerCurrentHP < 0)
    {
        playerCurrentHP = 0;
        Sleep(1000);
        printf("----------------------------------------\n");
        Sleep(500);
        printf("> You have died. You journey ends here.\n");
        Sleep(500);
        printf("----------------------------------------\n");
        Sleep(2000);
    }
    else
    {
        printf("> Your current HP: [%i]", playerCurrentHP);
    }
}

// character sheet when printed sets stats like VIT and sets classHPX
int playerMaxHealth(int VIT, int classHPX) {
    playerMaxHP = VIT * classHPX;
    return playerMaxHP;
}