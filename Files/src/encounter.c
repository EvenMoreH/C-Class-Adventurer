#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

#include "../include/globalVar.h"
#include "../include/globalStruct.h"
#include "../include/encounter.h"
#include "../include/playerActions.h"
#include "../include/equipment.h"
#include "../include/monsters.h"
#include "../include/decisions.h"


void encounter(int monsterID) {
    monsterCurrentHP = monsterMaxHP(monsterID);
    camping = 0;
    regenerated = 0;

    int r = 0;
    combatEnd = 1;

    printf("\n> ---------------------------------------------\n");
    printf("> You face [%s]. Get ready [%s]!\n", monsters[monsterID].monsterName, name);
    printf("> ---------------------------------------------\n");
    printf("> Your current HP is [%i/%i].\n", playerCurrentHP, playerMaxHP);
    whatsInTheBag();

    Sleep(1000);

    while (monsterCurrentHP > 0 && playerCurrentHP > 0 && combatEnd > 0)
    {
        r++;
        printf("\nRound %i:\n", r);
        Sleep(500);

        combatAction(monsterID);
        Sleep(500);

        monsterHP(monsterDmgTaken, monsterID);
        Sleep(500);
            // have to put this IF here for player to not get hit after killing monster
            if (combatEnd == 0 && monsterCurrentHP <= 0)
            {
                break;
            }
        monsterAction(monsterID);
        Sleep(500);

        playerHP(playerDmgTaken);

        if (camping == 1 && playerCurrentHP > 0)
        {
            camp();
        }
    }

    if (playerCurrentHP > 0 && combatEnd == 0 && regenerated == 0)
    {
        regenerate();
    }
}

void camp() {
    printf("\n> You run away to find a safe place to set up a camp to rest and heal.\n");
    int campHP = floor(playerMaxHP * 0.7);
    campVisit = 1;
    combatEnd = 0;
    Sleep(1000);

    if (playerCurrentHP > campHP)
    {
        printf("> You catch a breath away from danger.\n");
        Sleep(500);
        printf("> You ready yourself to go back on the road.\n");
    }
    else
    {
        playerCurrentHP = campHP;
        printf("> You catch a breath away from danger.\n");
        Sleep(500);
        printf("> You tend to your wounds and manage to regain some health.\n");
        Sleep(500);
        printf("> You feel ready to go back on the road.\n");
    }
    Sleep(250);
    printf("> Your current HP: [%i/%i]\n", playerCurrentHP, playerMaxHP);
    camping = 0;

    if (playerCurrentHP < playerMaxHP)
    {
        regenerate();
        regenerated = 1;
    }
    Sleep(1000);
}

void ambushEncounter(int monsterID) {
    regenerated = 0;

    if (campVisit == 1)
    {
        int randomEncounter = 1 + rand() % 100;

        if (randomEncounter > 1) // base 50
        {
            monsterCurrentHP = monsterAmbushHP;

            int r = 0;
            combatEnd = 1;

            printf("\n> ---------------------------------------------\n");
            printf("> It is an ambush! There is no way to run!\n");
            printf("> You face [%s]. Get ready [%s]!\n", monsters[monsterID].monsterName, name);
            printf("> ---------------------------------------------\n");
            printf("> Your current HP is [%i/%i].\n", playerCurrentHP, playerMaxHP);
            whatsInTheBag();
            Sleep(1000);
            while (monsterCurrentHP > 0 && playerCurrentHP > 0 && combatEnd > 0)
            {
                r++;
                printf("\nRound %i:\n", r);
                monsterAction(monsterID);
                Sleep(500);
                playerHP(playerDmgTaken);
                Sleep(500);
                printf("\n");
                combatActionAmbush(monsterID);
                Sleep(500);
                monsterHP(monsterDmgTaken, monsterID);
                Sleep(500);
            }
            if (playerCurrentHP > 0 && combatEnd == 0)
            {
                regenerate();
            }
        }
        else
        {
            printf("> It seems that [%s] moved away from this location.\n", monsters[monsterID].monsterName);
            Sleep(250);
            printf("> It feels safe and you start to look around for any leftover supplies\n");
            Sleep(250);
            printf("> getting ready to continue your journey...\n");
        }
    }
    campVisit = 0;
    monsterAmbushHP = 0;
}

void fromCamp() {
    if (campVisit == 1)
    {
        // printf("\n> You pack up your camp and return to [%s]\n\n", lastLocation);
        printf("\n> You pack up your camp and go back...\n");
        Sleep(500);
        printf("-----------------------------------\n");
        printf("> You enter the [%s]\n", lastLocation);
        printf("-----------------------------------\n");
        Sleep(1000);
    }
}