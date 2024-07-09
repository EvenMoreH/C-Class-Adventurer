#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


#include "../include/monsters.h"

#include "../include/globalStruct.h"
#include "../include/globalVar.h"

#include "../include/equipment.h"



// MONSTERS //////////////////////////////////////////////////////////

int monsterHP(int monsterDmgTaken, int monsterID) {
    monsterCurrentHP = monsterCurrentHP - monsterDmgTaken;

    if (monsterDmgTakenLog == 0)
    {
        // do nothing
    }
    else
    {
        Sleep(1000);
        printf("> [%s] have taken: [%i] damage.\n", monsters[monsterID].monsterName, monsterDmgTaken);

        if (monsterCurrentHP <= 0)
        {
            monsterCurrentHP = 0;
            playerDmgTaken = 0;
            playerDmgTakenLog = 0;
            combatEnd = 0;
            Sleep(1000);
            printf("-----------------------------\n");
            Sleep(200);
            printf("> [%s] defeated.\n", monsters[monsterID].monsterName);
            Sleep(200);
            printf("-----------------------------\n");
            Sleep(1000);

            printf("\n> You tend to your wounds and start looking around for any leftover items.\n");
            Sleep(1000);
        }
        else
        {
            printf("> [%s] current HP: [%i]\n", monsters[monsterID].monsterName, monsterCurrentHP);
        }
    }
}

int monsterMaxHP(int monsterID) {
    int MHPRoll = 1 + rand() % 8;
    int monsterHpRoll = monsters[monsterID].monsterBaseHP + MHPRoll;

    return monsterHpRoll;
}

int monsterDamage1(int monsterID) {
    int x = monsters[monsterID].monsterAttack1minDMG;
    int y = monsters[monsterID].monsterAttack1maxDMG;

    int randomDmgRoll = x + rand() % y;

    monsterDmgDone = randomDmgRoll;

    printf("\n> [%s] used [%s] and deals [%i] damage!\n", monsters[monsterID].monsterName, monsters[monsterID].monsterAttack1, monsterDmgDone);

    playerDmgTaken = monsterDmgDone;

    playerDmgTakenLog = monsterDmgDone;

    return randomDmgRoll;
}

int monsterDamage2(int monsterID) {
    int x = monsters[monsterID].monsterAttack2minDMG;
    int y = monsters[monsterID].monsterAttack2maxDMG;

    int randomDmgRoll = x + rand() % y;

    monsterDmgDone = randomDmgRoll;

    printf("\n> [%s] used [%s] and deals [%i] damage!\n", monsters[monsterID].monsterName, monsters[monsterID].monsterAttack2, monsterDmgDone);

    playerDmgTaken = monsterDmgDone;

    playerDmgTakenLog = monsterDmgDone;

    return randomDmgRoll;
}

int monsterDamage3(int monsterID) {
    int x = monsters[monsterID].monsterAttack2minDMG;
    int y = monsters[monsterID].monsterAttack2maxDMG;

    int randomDmgRoll = x + rand() % y;

    monsterDmgDone = randomDmgRoll;

    printf("\n> [%s] used [%s] and deals [%i] damage!\n", monsters[monsterID].monsterName, monsters[monsterID].monsterAttack3, monsterDmgDone);

    playerDmgTaken = monsterDmgDone;

    specialMonsterAttack = 1;

    playerDmgTakenLog = monsterDmgDone;

    return randomDmgRoll;
}

int monsterDamageOpportunity(int monsterID) {
    int x = monsters[monsterID].monsterAttack1minDMG;
    int y = monsters[monsterID].monsterAttack1maxDMG;

    int randomDmgRoll = x + rand() % y;

    monsterDmgDone = randomDmgRoll;

    playerDmgTaken = monsterDmgDone;

    return randomDmgRoll;

    playerDmgTakenLog = monsterDmgDone;
}

void monsterAction(int monsterID) {
    playerDmgTaken = 0;

    int randomActionRoll = 1 + rand() % 100;
    int monsterAttackRoll = (1 + rand() % 20) - daze;

    if (monsterCurrentHP > monsters[monsterID].monsterThreshold)
    {
        if (monsterAttackRoll < 4)
        {
            printf("\n> [%s] tries to attack you but misses!\n", monsters[monsterID].monsterName);
            playerDmgTaken = 0;
            playerDmgTakenLog = 0;
            if (daze == 100)
            {
                printf("\n> [%s] is no longer dazed!\n", monsters[monsterID].monsterName);

            }
            daze = 0;
        }
        else
        {
            if (randomActionRoll >= 40)
            {
                monsterDamage1(monsterID);
                daze = 0;
            }
            else
            {
                monsterDamage2(monsterID);
                daze = 0;
            }
        }
    }
    else
    {
        if (specialMonsterAttack > 0)
        {
            playerDmgTaken = 0;
            playerDmgTakenLog = 0;

            randomActionRoll = 1 + rand() % 100;
            monsterAttackRoll = 1 + rand() % 20;

            if (monsterAttackRoll < 4)
            {
                printf("> [%s] tries to attack you but misses!\n", monsters[monsterID].monsterName);
                playerDmgTaken = 0;
                playerDmgTakenLog = 0;
                daze = 0;
            }
            else
            {
                if (randomActionRoll >= 40)
                {
                    monsterDamage1(monsterID);
                    daze = 0;
                }
                else
                {
                    monsterDamage2(monsterID);
                    daze = 0;
                }
            }
        }
        else
        {
            if (monsterCurrentHP > 0)
            {
                if (strcmp(monsters[monsterID].monsterAttack3, monsterRun) == 0)
                {
                    playerDmgTaken = 0;
                    printf("> [%s] Runs away in terror!\n", monsters[monsterID].monsterName);
                    Sleep(500);
                    printf("-----------------------------\n");
                    Sleep(200);
                    printf("> [%s] defeated.\n", monsters[monsterID].monsterName);
                    Sleep(200);
                    printf("-----------------------------\n");
                    Sleep(500);

                    printf("\n> You tend to your wounds and start looking around for any leftover items.\n");
                    Sleep(500);
                    playerDmgTakenLog = 0;
                    monsterCurrentHP = 0;
                    combatEnd = 0;
                    daze = 0;
                }
                else
                {
                monsterDamage3(monsterID);
                daze = 0;
                }
            }
            else
            {
                // skip cause "Enemy Defeated was already displayed"
                daze = 0;
            }
        }
    }
}