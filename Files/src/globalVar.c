#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

#include "../include/globalVar.h"


//put your function headers here

// Global variables
    int itemID;
    int spellID;
    int combatEnd;          // sets combat flag on/off
    char name[51];
    int daze;               // responsible for applying daze penalty to monsters
    int MGC;                // global for Magic stat for characters
    int camping = 0;        // sets flag if player would run to camp
    int campVisit;          // sets flag if player was at a camp
    char* lastLocation;     // pinter to string for manual control where combat had been placed
    int regenerated = 0;    // sets flag if player regenerated in camp to not regenerate again after combat ends

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
    int playerDmgTakenLog;  // log testing to skip dmg logs if dmg = 0
    int SelectedSpellMinDMG;
    int SelectedSpellMaxDMG;

    // for declaring initial MAX HP and calculating current HP (player)
    int playerMaxHP;
    int playerCurrentHP;

    // NEW: monster HP & DMG
    int monsterID;
    int monsterCurrentHP;
    int monsterAmbushHP;
    int monsterDmgDone;     // NEW
    int monsterDmgTaken;    // NEW
    // NEW  // required for monster to only use special attack once
    int specialMonsterAttack = 0;
    // NEW  // required for monster Run check
    char* monsterRun = "Run";
    int monsterDmgTakenLog;   // log testing to skip dmg logs if dmg = 0

    // ITEM Shortcuts
    int potion = 11;


void randomize() {
    srand(time(NULL));
    // randomNumber = rand() % X
    // random number from {0, X-1} as counting starts from 0 and array has X elements
    // rand() % 20 + 21 = random number from {20, 40}
}

//  Clear Buffer  ////////////////////////////////////////////////////

void clearBuffer() {
    // Clear the input buffer
    int clearBuffer;
    while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
    // I don't get the above yet but:
    // The while loop with getchar()
        // reads and discards characters until it encounters a newline ('\n')
        // or end-of-file (EOF), effectively clearing the buffer.
}