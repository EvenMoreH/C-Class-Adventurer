#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


#include "../include/intro.h"

#include "../include/globalStruct.h"
#include "../include/globalVar.h"

#include "../include/decisions.h"
#include "../include/playerActions.h"


void intro() {
        printf("************************************************\n");
        Sleep(250);
        printf("****************                ****************\n");
        Sleep(250);
        printf("**************     WELCOME TO     **************\n");
        Sleep(250);
        printf("***********    C-CLASS ADVENTURER    ***********\n");
        Sleep(250);
        printf("*********                              *********\n");
        Sleep(250);
        printf("******    Journey Through Memory Leaks    ******\n");
        Sleep(250);
        printf("****                                        ****\n");
        Sleep(300);
        printf("************************************************\n\n\n");
        Sleep(1500);

        printf("> Throughout this game you will be making a lot of decisions\n");
        Sleep(500);
        printf("> To control your actions you will be answering prompts by typing:\n");
        Sleep(250);
        printf("> Y for Yes\n");
        Sleep(250);
        printf("> N for No\n");
        Sleep(250);
        printf("> A to select 1st option\n");
        Sleep(250);
        printf("> B to select 2nd option\n");
        Sleep(250);
        printf("> C to select 3rd option\n");
        Sleep(250);
        printf("> When managing your backpack you will be selecting items by pressing correct number\n");
        Sleep(250);
        printf("> You can confirm all your inputs by pressing Enter\n\n");

        printf("> When attacking there is a chance to miss your opponents.\n");
        Sleep(250);
        printf("> Attacking with off hand weapon has even lower chance to hit but can daze your enemy forcing them to miss.\n");
        Sleep(250);
        printf("> When your bag is empty and you would try to use items in combat you will waste your turn so beware.\n");
        Sleep(250);
        printf("> Anyway!\n\n");
        Sleep(250);

        Sleep(1000);
        printf("> Good Luck!\n");
}

void chooseCharacter() {
        printf("> Who are you, brave adventurer?\n");
        Sleep(1000);
        printf("> A. Archer\n");
            Sleep(500);
            printf("\tNimble and agile fighter relying on Bows, Shortswords and light armor.\n");
            Sleep(500);
            printf("\tArchers have average resiliency, and their combat capabilities rely on Dexterity\n");
            Sleep(500);
        printf("> B. Crusader\n");
            Sleep(500);
            printf("\tStrong and durable fighter relying on Swords, Shields and heavy armor.\n");
            Sleep(500);
            printf("\tCrusaders have high resiliency, and their combat capabilities rely on Strength\n");
            Sleep(500);
        printf("> C. Sorcerer\n");
            Sleep(500);
            printf("\tMasters of the dark arts, relying on Grimoires filled with spells, Staves and robes.\n");
            Sleep(500);
            printf("\tSorcerers have low resiliency, and their combat capabilities rely on Magic and Dexterity\n");
        Sleep(1000);

    char characterSelect;
    char currentCharacter[10];
    char* archer = "Archer";
    char* crusader = "Crusader";
    char* sorcerer = "Sorcerer";

    while (1)
    {
        printf("\n> Select your class by pressing A, B or C and confirm with Enter: ");
        scanf(" %c", &characterSelect);
        characterSelect = tolower(characterSelect);

        if (characterSelect == 'a' || characterSelect == 'b' || characterSelect == 'c')
        {
            if (characterSelect == 'a')
            {
                strcpy(currentCharacter, archer);
                currentChar = 900;
            }
            if (characterSelect == 'b')
            {
                strcpy(currentCharacter, crusader);
                currentChar = 901;
            }
            if (characterSelect == 'c')
            {
                strcpy(currentCharacter, sorcerer);
                currentChar = 902;
            }
            // output depending first letter a/an
            if (characterSelect == 'a')
            {
                printf("> So you are an [%s]\n", currentCharacter);
            }
            else
            {
                printf("> So you are a [%s]\n", currentCharacter);
            }
            break;
        }
        else
        {
            printf("> A, B or C. Please try again.\n");

            clearBuffer();
        }
    }
    Sleep(500);
    clearBuffer();
    printf("> What is your name Adventurer?\n> ");
    scanf(" %50s", &name);
    Sleep(500);
    printf("\n> And thus your journey begins, brave [%s].\n\n", name);
    Sleep(1000);
    clearBuffer();
}

void printCharacterSheet(int currentChar) {
    Sleep(1000);
    printf("> This is you and your equipment:\n");
    Sleep(1000);

    if (currentChar == 900)
    {
        archerSheet();
    }
    else if (currentChar == 901)
    {
        crusaderSheet();
    }
    else if (currentChar == 902)
    {
        sorcererSheet();
    }
}

// 10 element loading bar
    // takes the argument in seconds to display this amount of loading time
void loading(float s) {
    float ms = s * 100;
    printf("\n> Loading: [");
    for (int i = 0; i < 10; i++)
    {
        printf("+");
        Sleep(ms);
    }
    printf("]\n\n");
}

void archerSheet() {
    int lvl = 1;
    int STR = 5;
    int DEX = 7;
    int VIT = 5;
    MGC = 3;
    int classHPX = 10;

    playerMaxHP = playerMaxHealth(VIT, classHPX);
    playerCurrentHP = playerMaxHP;

    bonusDMG = (((DEX / 2) - 2) + lvl);

    int attackMOD;
    int attackMODmain = ((DEX / 2) - 2);
    int attackMODoff = (attackMODmain - 1);

    // lets equip starting items:
    held[0] = items[1];
    held[1] = items[2];
    held[2] = items[6];

    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Level: [1]        |\n");
    printf("|  Your Class: [Archer]   |\n");
    printf("|  Your Max Health: [%i]  |\n", playerMaxHP);
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [5]     |\n");
    printf("|     - Dexterity: [7]    |\n");
    printf("|     - Vitality: [5]     |\n");
    printf("|     - Magic: [3]        |\n");
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - Bow               |\n");
    printf("|     - Shortsword        |\n");
    printf("|     - Leather Armor     |\n");
    printf("|     - Backpack[10]      |\n");
    printf("---------------------------\n");
    printf("\n");
}

void crusaderSheet() {
    int lvl = 1;
    int STR = 7;
    int DEX = 4;
    int VIT = 6;
    MGC = 3;
    int classHPX = 12;

    playerMaxHP = playerMaxHealth(VIT, classHPX);
    playerCurrentHP = playerMaxHP;

    bonusDMG = (((STR / 2) - 2) + lvl);

    int attackMOD;
    int attackMODmain = ((STR / 2) - 2);
    int attackMODoff = (attackMODmain - 1);

    // lets equip starting items:
    held[0] = items[3];
    held[1] = items[4];
    held[2] = items[7];

    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Level: [1]        |\n");
    printf("|  Your Class: [Crusader] |\n");
    printf("|  Your Max Health: [%i]  |\n", playerMaxHP);
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [7]     |\n");
    printf("|     - Dexterity: [4]    |\n");
    printf("|     - Vitality: [6]     |\n");
    printf("|     - Magic: [3]        |\n");
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - Longsword         |\n");
    printf("|     - Shield            |\n");
    printf("|     - Plate Armor       |\n");
    printf("|     - Backpack[10]      |\n");
    printf("---------------------------\n");
    printf("\n");
}

void sorcererSheet() {
    int lvl = 1;
    int STR = 3;
    int DEX = 6;
    int VIT = 4;
    MGC = 7;
    int classHPX = 8;

    playerMaxHP = playerMaxHealth(VIT, classHPX);
    playerCurrentHP = playerMaxHP;

    bonusDMGspell = (((MGC / 2) - 2) + lvl);
    bonusDMG = (((DEX / 2) - 2) + lvl);

    int attackMOD;
    int attackMODoff = (((DEX / 2) - 2) - 1);
    int attackMODspell = ((DEX / 2) - 2);

    // lets equip starting items:
    held[0] = items[9]; // grimoires are main hand
    held[1] = items[5];
    held[2] = items[8];

    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Level: [1]        |\n");
    printf("|  Your Class: [Sorcerer] |\n");
    printf("|  Your Max Health: [%i]  |\n", playerMaxHP);
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [3]     |\n");
    printf("|     - Dexterity: [6]    |\n");
    printf("|     - Vitality: [4]     |\n");
    printf("|     - Magic: [7]        |\n");
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - Grimoire          |\n");
    printf("|     - Staff             |\n");
    printf("|     - Robes             |\n");
    printf("|     - Backpack[10]      |\n");
    printf("---------------------------\n");
    printf("\n");
}