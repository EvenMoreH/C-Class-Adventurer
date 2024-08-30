#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities
#include <ctype.h>      // allows for tolower() funtion
#include <unistd.h>     // for getpid() entropy source


#include "../include/globalVar.h"
#include "../include/globalStruct.h"
#include "../include/printing.h"


//put your function headers here

// Global variables
    int itemID;
    int spellID;
    int combatEnd;          // sets combat flag on/off
    char playerName[51];
    int daze;               // responsible for applying daze penalty to monsters
    int MGC;                // global for Magic stat for characters
    int lvl;
    int camping = 0;        // sets flag if player would run to camp
    int campVisit;          // sets flag if player was at a camp
    char* lastLocation;     // pointer to string for manual control where player is (basically a save point)
    int regenerated = 0;    // sets flag if player regenerated in camp to not regenerate again after combat ends
    int s;

    char parsed[51];
    char textOutput[256];


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
    char q;
    int result;

    // for A or B decisions
    char ab;
    int abResult;

    // for A or B or C decisions
    char abc;
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
    int globalResistance = 0;

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
    int potion = 10;


void randomize() {
    // randomNumber = rand() % X
    // random number from {0, X-1} as counting starts from 0 and array has X elements
    // rand() % 20 + 21 = random number from {20, 40}
    int entropy_source1 = 32;
    unsigned int seed = (unsigned int)time(NULL)
    ^ (unsigned int)getpid()
    ^ (unsigned int)(uintptr_t)&entropy_source1;

    srand(seed);
}

//  Clear Buffer  ////////////////////////////////////////////////////

void clearBuffer() {
    // Clear the input buffer
    int clearBuffer;
    while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF)
    { }
    // I don't get the above yet but:
    // The while loop with getchar()
        // reads and discards characters until it encounters a newline ('\n')
        // or end-of-file (EOF), effectively clearing the buffer.
}

void pressC() {
    Sleep(500);
    newLine(1);
    system("pause");
    newLine(1);
    Sleep(500);
}

// Text only, no variables
    // Sleep(1000) included
void formattedText(char* printout) {
    printf("> %s\n", printout);
    Sleep(1000);
}

// \n
void newLine (int lines) {
    for (int i = 0; i < lines; i++)
    {
        printf("\n");
    }
}

// "Formatted Text"
    // INT 1: sleepBefore(in ms)
    // INT 2: sleepAfter(in ms)
void customText(char* printout, int sleepBefore, int sleepAfter) {
    Sleep(sleepBefore);
    printf("> %s\n", printout);
    Sleep(sleepAfter);
}

// Streams letter-by-letter with:
    // Start line '>'
    // End line '\n'
    // Sleep(350)
void storyText(char *textToWrite) {
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

// Streams letter-by-letter without any formatting
void storyTextUnformatted(char textToWrite[]) {
    int len = strlen(textToWrite);

    for (int i = 0; i < len; i++)
    {
        printf("%c", textToWrite[i]);
        Sleep(35);
    }
}

// outputs variable named parsed
    // adds padding and brackets
void parser(char string[]) {
    char padL[54] = " [";
    char padR[54] = "] ";
    sprintf(parsed, "%s", string);
    strcat(padL, parsed);
    strcat(padL, padR);
    strcpy(parsed, padL);
}

// Takes string variable and converts to unformatted letter-by-letter format
void storyTextToString(char variableToParse[]) {
    parser(variableToParse);
    char textToWrite[54];
    strcpy(textToWrite, parsed);
    storyTextUnformatted(textToWrite);
}

void idFinder(int itemID) {
    for (int i = 0; i < 1000; i++)
    {
        if (items[i].id == itemID)
        {
            temp[0] = items[i];
            break;
        }
    }
}

int potionScaling(int lvl) {
    switch (lvl)
    {
    case 1:
        return 1;
        break;
    default:
        return lvl * 3;
        break;
    }
}