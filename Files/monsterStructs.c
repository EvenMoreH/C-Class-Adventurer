#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

////  GLOBAL VARIABLES  ////////////////////////////////////////////////////////////////////////////
int monsterID;
int monsterDmgDone;
int monsterDmgTaken;    // New
int monsterCurrentHP;   // NEW
int playerDmgTaken;
int playerCurrentHP;
int specialMonsterAttack = 0;   // NEW  // required for monster to only use special attack once
char monsterRun[] = "Run";      // NEW  // required for monster Run check

struct monster {
    int monsterID;
    char monsterName[25];
    char monsterDescription[100];
    int monsterBaseHP;          // required to initialize struct, will have a random value added to it to calculate MonsterMaxHP
    char monsterAttack1[20];
    int monsterAttack1minDMG;
    int monsterAttack1maxDMG;
    char monsterAttack2[20];
    int monsterAttack2minDMG;
    int monsterAttack2maxDMG;
    char monsterAttack3[20];    // if treshold is triggered
    int monsterAttack3minDMG;
    int monsterAttack3maxDMG;
    int monsterThreshold; // (if monsterCurrentHP <= monsterTreshold use special attack once and break;)
};

// monsterIDs = 400 - 499
struct monster monsters[] = {
    {400, "", "", 0, "", 0, 0, "", 0, 0, "", 0, 0, 0}, // empty monster to initialize the list
    {401, "Giant Rat", "", 18, "Bite", 2, 7, "Scratch", 2, 5, "Run", 0, 0, 5},
    {402, "Goblin", "", 28, "Knife", 2, 5, "Kick", 1, 4, "", 0, 0, 0},
    {403, "Hobgoblin", "", 48, "Greatclub", 6, 14, "Headbutt", 4, 10, "Skullcrsher", 12, 24, 10},
    {404, "", "", 0, "", 0, 0, "", 0, 0, "", 0, 0, 0},
    {405, "", "", 0, "", 0, 0, "", 0, 0, "", 0, 0, 0},
};

////  FUNCTION DECLARATION  ////////////////////////////////////////////////////////////////////////

int playerHP(int playerDmgTaken);
int monsterDamage1(int monsterID);
int monsterDamage2(int monsterID);
int monsterDamage3(int monsterID);

void monsterAction(int monsterID);  // NEW

int main() {
    /////////////////////////////////////////////////
        srand(time(NULL));  // declaring randomize //
    /////////////////////////////////////////////////

    playerCurrentHP = 40;       // for testing manual declaration
    
    monsterCurrentHP = 3;


    monsterAction(1);
    Sleep(1000);
    playerHP(playerDmgTaken);
    Sleep(1000);

    monsterAction(3);
    Sleep(1000);
    playerHP(playerDmgTaken);
    Sleep(1000);
    monsterAction(3);
    Sleep(1000);
    playerHP(playerDmgTaken);
    Sleep(1000);
    monsterAction(3);
    Sleep(1000);
    playerHP(playerDmgTaken);
    Sleep(1000);
    monsterAction(3);
    Sleep(1000);
    playerHP(playerDmgTaken);
    Sleep(1000);


    printf("\nEOF\n");
    Sleep(30000);


    return 0;               // Ends main function
}
////  FUNCTION DEFINITION  /////////////////////////////////////////////////////////////////////////

    // function to random roll which attack was used and prints what attack was used should be here

int monsterDamage1(int monsterID) {
    int x = monsters[monsterID].monsterAttack1minDMG;
    int y = monsters[monsterID].monsterAttack1maxDMG;

    int randomDmgRoll = x + rand() % y;

    monsterDmgDone = randomDmgRoll;

    printf("> [%s] used [%s] and deals [%i] damage!\n", monsters[monsterID].monsterName, monsters[monsterID].monsterAttack1, monsterDmgDone);

    playerDmgTaken = monsterDmgDone;

    return randomDmgRoll;
}

int monsterDamage2(int monsterID) {
    int x = monsters[monsterID].monsterAttack2minDMG;
    int y = monsters[monsterID].monsterAttack2maxDMG;

    int randomDmgRoll = x + rand() % y;

    monsterDmgDone = randomDmgRoll;

    printf("> [%s] used [%s] and deals [%i] damage!\n", monsters[monsterID].monsterName, monsters[monsterID].monsterAttack2, monsterDmgDone);

    playerDmgTaken = monsterDmgDone;

    return randomDmgRoll;
}

int monsterDamage3(int monsterID) {
    int x = monsters[monsterID].monsterAttack2minDMG;
    int y = monsters[monsterID].monsterAttack2maxDMG;

    int randomDmgRoll = x + rand() % y;

    monsterDmgDone = randomDmgRoll;

    printf("> [%s] used [%s] and deals [%i] damage!\n", monsters[monsterID].monsterName, monsters[monsterID].monsterAttack3, monsterDmgDone);

    playerDmgTaken = monsterDmgDone;

    specialMonsterAttack = 1;

    return randomDmgRoll;
}

////////////////////////////////

int playerHP(int playerDmgTaken) {
    playerCurrentHP = playerCurrentHP - playerDmgTaken;

    Sleep(1000);
    printf("> You have taken: [%i] damage.\n", playerDmgTaken);

    if (playerCurrentHP <= 0)
    {
        playerCurrentHP = 0;
        Sleep(1000);
        printf("----------------------------------------\n");
        printf("> You have died. You journey ends here.\n");
        printf("----------------------------------------\n");
        Sleep(2000);
    }
    else
    {
        printf("> Your current HP: [%i]\n", playerCurrentHP);
    }
}

void monsterAction(int monsterID) {
    playerDmgTaken = 0;
    
    int randomActionRoll = 1 + rand() % 100;
    int monsterAttackRoll = 1 + rand() % 20;
    
    if (monsterCurrentHP > monsters[monsterID].monsterThreshold)
    {
        if (monsterAttackRoll < 4)
        {
            printf("> [%s] tries to attack you but misses!\n", monsters[monsterID].monsterName);
            playerDmgTaken = 0;
        }
        else
        {
            if (randomActionRoll >= 40)
            {
                monsterDamage1(monsterID);
            }
            else
            {
                monsterDamage2(monsterID);
            }
        }
    }
    else
    {
        if (specialMonsterAttack > 0)
        {
            playerDmgTaken = 0;

            randomActionRoll = 1 + rand() % 100;
            monsterAttackRoll = 1 + rand() % 20;

            if (monsterAttackRoll < 4)
            {
                printf("> [%s] tries to attack you but misses!\n", monsters[monsterID].monsterName);
                playerDmgTaken = 0;
                printf("\nTEST: MAR = %i\n", monsterAttackRoll);

            }
            else
            {
                if (randomActionRoll >= 40)
                {
                    monsterDamage1(monsterID);
                }
                else
                {
                    monsterDamage2(monsterID);
                }
            }
        }
        else
        {
            if (strcmp(monsters[monsterID].monsterAttack3, monsterRun) == 0)
            {
                playerDmgTaken = 0;
                printf("> [%s] Runs away in terror!\n", monsters[monsterID].monsterName);
                int combatEnd = 1;  // TEMP Variable to end the combat without using break; outside of while loop
            }
            else
            {
            monsterDamage3(monsterID);
            }
        }
    }
}