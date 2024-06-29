#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

//  GLOBAL VARIABLES  //////////////////////////////////////////////////////////////////////////////
int itemID;

// selected character
    // 900 - Archer
    // 901 - Crusader
    // 902 - Sorcerer
int currentChar;

// for managing items that are held(equipped)
int mainWeapon = 0;
int offWeapon = 1;
int equippedArmor = 2;

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
int bonusDMG;
int bonusDMGspell;
int playerDmgTaken;     // NEW


// for declaring initial MAX HP and calculating current HP (player)
int playerMaxHP;
int playerCurrentHP;

// NEW: monster HP & DMG
int monsterMaxHP;
int monsterCurrentHP;
int monsterDmgDone;     // NEW
int monsterDmgTaken;    // NEW

// Global item management
struct item {
    int id;
    char iname[25];
    char description[100];  // For weapons it will be used to specify damage type
    int minDMG;
    int maxDMG;
};
    // item IDs = 0-99
    struct item items[] = {
       {0, "", "", 0, 0},     // <- something to mimic empty slots
       {1, "Bow", "Piercing", 1, 8},            // base item do not alter (Archer)
       {2, "Shortsword", "Slashing", 1, 6},     // base item do not alter (Archer)
       {3, "Longsword", "Slashing", 1, 8},      // base item do not alter (Crusader)
       {4, "Shield", "Bludgeoning", 1, 6},      // base item do not alter (Crusader)
       {5, "Staff", "Bludgeoning", 1, 6},       // base item do not alter (Sorcerer)
       {6, "Leather Armor", "", 0, 0},          // base item do not alter (Archer)
       {7, "Plate Armor", "", 0, 0},            // base item do not alter (Crusader)
       {8, "Robes", "", 0, 0},                  // base item do not alter (Sorcerer)
       {9, "Grimoire", "", 0, 0},                // base item do not alter (Sorcerer)

       // story items:
       {10, "Stoneskull Key", "Required to open Stone Gates located at [Mountain Road]", 0, 0},
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

// Global held items management
    // held IDs = 130-133
    struct item held[] = {
        {130, "", "", 0, 0},    // Main Weapon
        {131, "", "", 0, 0},    // Off hand weapon
        {132, "", "", 0, 0},    // Armor
        {133, "", "", 0, 0},    // ??
    };



//  STRUCTURES  ////////////////////////////////////////////////////////////////////////////////////



//  FUNCTION DECLARATION  //////////////////////////////////////////////////////////////////////////
int monsterHP(int monsterDmgTaken);
int playerDamage(int itemID, int bonusDMG);



////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

    /////////////////////////////////////////////////
        srand(time(NULL));  // declaring randomize //
    /////////////////////////////////////////////////

    playerMaxHP = 50;
    playerCurrentHP = 34;

    monsterMaxHP = 25;
    monsterCurrentHP = 23;

    monsterDmgDone = 6;
    playerDmgTaken = monsterDmgDone;

    held[0] = items[1];

    int r = 0;
    while (monsterCurrentHP > 0 && playerCurrentHP > 0)
    {   
        r++;
        printf("\nRound %i:\n", r);
        Sleep(500);
        
        playerCurrentHP = playerCurrentHP - playerDmgTaken;
        printf("Player current HP: %i\n", playerCurrentHP); // PLACEHOLDER
        
        // to track monsterHP and playerDamage:
        // playerDamage function will assign rolled dmg value to monsterDmgTaken variable
        playerDamage(0, 2);
        monsterHP(monsterDmgTaken);
        Sleep(500);
    }

    return 0;
}

////  FUNCTION DEFINITION  /////////////////////////////////////////////////////////////////////////
int monsterHP(int monsterDmgTaken) {
    monsterCurrentHP = monsterCurrentHP - monsterDmgTaken;

    Sleep(1000);
    printf("> Monster have taken: [%i] damage.\n", monsterDmgTaken);

    if (monsterCurrentHP <= 0)
    {
        monsterCurrentHP = 0;
        Sleep(1000);
        printf("-------------------\n");
        Sleep(200);
        printf("> [Enemy] defeated.\n");
        Sleep(200);
        printf("-------------------\n");
        Sleep(2000);
    }
    else
    {
        printf("> [Monster] current HP: [%i]\n", monsterCurrentHP);
    }
}

int playerDamage(int itemID, int bonusDMG) {
    int x = held[itemID].minDMG;
    int y = held[itemID].maxDMG;
    int randomDmgRoll = x + rand() % y;

    dmg = bonusDMG + randomDmgRoll;

    printf("> You Deal [%i] damage!\n", dmg);

    monsterDmgTaken = dmg;

    return bonusDMG + randomDmgRoll;
}