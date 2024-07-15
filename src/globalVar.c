#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities
#include <ctype.h>      // allows for tolower() funtion


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
    char* lastLocation;     // pointer to string for manual control where player is (basically a save point)
    int regenerated = 0;    // sets flag if player regenerated in camp to not regenerate again after combat ends
    int s;

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

void pressC() {
    Sleep(500);
    printf("\n[Press C to continue...] ");
    char ch2;
    while (1)
    {
        scanf(" %c", &ch2);
        ch2 = tolower(ch2);
        if (ch2 == 'c')
        {
            printf("\n");
            break;
        }
        else
        {
            clearBuffer();
            int quip1 = rand() % 130;
            if (quip1 > 30 && quip1 < 40)
            {
                printf("[Oops, it seems like your fingers took a detour. They must be sightseeing!]\n");
            }
            else if (quip1 > 40 && quip1 < 50)
            {
                printf("[Looks like you discovered the hidden Easter egg. Congrats!]\n");
            }
            else if (quip1 > 50 && quip1 < 60)
            {
                printf("[Well, someone is feeling a bit rebellious today, huh?]\n");
            }
            else if (quip1 > 60 && quip1 < 70)
            {
                printf("[C is for cookie, but it seems you are craving a different flavor!]\n");
            }
            else if (quip1 > 70 && quip1 < 80)
            {
                printf("[Your fingers have a mind of their own. They must be geniuses!]\n");
            }
            else if (quip1 > 80 && quip1 < 90)
            {
                printf("[Ah, an accidental jazz note! You're improvising already.]\n");
            }
            else if (quip1 > 90 && quip1 < 100)
            {
                printf("[Is that a creative interpretation of the letter C I see?]\n");
            }
            else if (quip1 > 100 && quip1 < 110)
            {
                printf("[Looks like your keyboard has a mischievous streak. I like it!]\n");
            }
            else if (quip1 > 110 && quip1 < 120)
            {
                printf("[I see you have found the scenic route on the keyboard. Nice one!]\n");
            }
            else if (quip1 > 120 && quip1 < 130)
            {
                printf("[C? Who needs C when you have got your own unique style!]\n");
            }
            else
            {
                printf("[It supposed to be C but anyway...]\n");
            }
            printf("\n");
            break;
        }
    }
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

void typeWriter(char textToWrite[]) {
    int len = strlen(textToWrite);

    printf("> ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", textToWrite[i]);
        Sleep(35);
    }
    printf("\n");
    Sleep(1000);
}