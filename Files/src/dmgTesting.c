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
    int bonusDMG;

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
       {1, "Bow", "Piercing", 1, 8},
       {2, "Shortsword", "Slashing", 1, 6},
       {3, "Longsword", "Slashing", 1, 8},
       {4, "Shield", "Bludgeoning", 1, 6},
       {5, "Staff", "Bludgeoning", 1, 6},
       {6, "Leather Armor", "", 0, 0},
       {7, "Plate Armor", "", 0, 0},
       {8, "Robes", "", 0, 0},
       {9, "Stoneskull Key", "Required to open Stone Gates located at [Mountain Road]", 0, 0},
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


int damage(int itemID, int bonusDMG);
void attackRollMain(int equippedWeaponMain, int bonusDMG);
void attackRollOff(int equippedWeaponOff, int bonusDMG);
void attackRollSpell(int equippedSpell, int bonusDMGspell);

int damageSpell(int spellID, int bonusDMGspell);


int main() {
    srand(time(NULL));  // declaring randomize

    int lvl = 1;
    int STR = 5;
    int DEX = 7;
    int VIT = 5;
    int MGC = 1;
    int classHPX = 10;

    int bonusDMG = (((DEX / 2) - 2) + lvl);
    
    int attackMOD;
    int attackMODmain = ((DEX / 2) - 2);
    int attackMODoff = (attackMODmain - 1);

    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Level: [1]        |\n");
    printf("|  Your Class: [Archer]   |\n");
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [5]     |\n");
    printf("|     - Dexterity: [7]    |\n");
    printf("|     - Vitality: [5]     |\n");
    printf("|     - Magic: [1]        |\n");
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - Bow               |\n");
    printf("|     - Dagger            |\n");
    printf("|     - Leather Armor     |\n");
    printf("|     - Backpack          |\n");
    printf("---------------------------\n");

    int equippedWeaponMain = 1;     // Placeholder before held item management is built

    attackRollMain(equippedWeaponMain, bonusDMG);
    


    return 0;               // Ends main function
}

int damage(int itemID, int bonusDMG) {
    int x = items[itemID].minDMG;
    int y = items[itemID].maxDMG;

    dmg = bonusDMG + x + rand() % y;

    printf("> You Deal [%i] damage!\n", dmg);

    return bonusDMG + x + rand() % y;
}

int damageSpell(int spellID, int bonusDMGspell) {
    // int x = items[itemID].minDMG;
    // int y = items[itemID].maxDMG;

    // dmg = bonusDMG + x + rand() % y;

    // printf("> You Deal [%i] damage!\n", dmg);

    // return bonusDMG + x + rand() % y;
}

void attackRollMain(int equippedWeaponMain, int bonusDMG) {
    itemID = equippedWeaponMain;
    
    int random = 1 + rand() % 6;

    int hit;
    int attackMODmain;
    int attackMOD = attackMODmain;
    int attackRoll = 7 + attackMOD + random;

    if (attackRoll < 11)
    {
        hit = 1;
        printf("> MISS!\n");
        Sleep(1000);
    }
    else
    {
        hit = 0;
        printf("> HIT!\n");
        Sleep(1000);
        damage(itemID, bonusDMG);
    }
}

void attackRollOff(int equippedWeaponOff, int bonusDMG) {
    itemID = equippedWeaponOff;
    int random = 1 + rand() % 6;
    
    int hit;
    int attackMODoff;
    int attackMOD = attackMODoff;
    int attackRoll = 7 + attackMOD + random;

    if (attackRoll < 11)
    {
        hit = 1;
        printf("> MISS!\n");
        Sleep(1000);
    }
    else
    {
        hit = 0;
        printf("> HIT!\n");
        Sleep(1000);
    }
}

void attackRollSpell(int equippedSpell, int bonusDMGspell) {
    int spellID; // <- placeholder befor I will built grimoirs
    
    spellID = equippedSpell;
    
    int random = 1 + rand() % 6;
    
    int hit;
    int attackMODspell;
    int attackMOD = attackMODspell;
    int attackRoll = 7 + attackMOD + random;

    if (attackRoll < 11)
    {
        hit = 1;
        printf("> MISS!\n");
        Sleep(1000);
    }
    else
    {
        hit = 0;
        printf("> HIT!\n");
        Sleep(1000);
    }
}