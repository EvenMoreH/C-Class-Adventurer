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
#include "../include/printing.h"

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

    customText("Throughout this game you will be making a lot of decisions.", 1, 500);
    customText("To control your actions you will be answering prompts by typing:", 1, 250);
    customText("Y for Yes.", 1, 250);
    customText("N for No.", 1, 250);
    customText("A to select 1st option.", 1, 250);
    customText("B to select 2nd option.", 1, 250);
    customText("C to select 3rd option.", 1, 250);
    customText("When managing your backpack you will be selecting items by pressing correct number.", 1, 250);
    customText("You can confirm all your inputs by pressing Enter.", 1, 250);
    newLine(1);
    customText("When attacking there is a chance to miss your opponents.", 1, 250);
    customText("Attacking with off hand weapon has even lower chance to hit but can daze your enemy forcing them to miss.", 1, 250);
    customText("When your bag is empty and you would try to use items in combat you will waste your turn so beware.", 1, 250);
    customText("Anyway!", 1, 1500);
    newLine(1);
    customText("Good Luck!", 1, 250);
}

void chooseCharacter() {
        formattedText("Who are you, brave adventurer?");
        customText("A. [Archer]", 1, 500);
            customText("\tNimble and agile fighter relying on Bows, Shortswords and light armor.", 1, 500);
            customText("\tArchers have average resiliency, and their combat capabilities rely on Dexterity.", 1, 500);
        customText("B. [Crusader]", 1, 500);
            customText("\tStrong and durable fighter relying on Swords, Shields and heavy armor.", 1, 500);
            customText("\tCrusaders have high resiliency, and their combat capabilities rely on Strength.", 1, 500);
        customText("C. [Sorcerer]", 1, 500);
            customText("\tMaster of the dark arts, relying on Grimoires filled with spells, Staves and robes.", 1, 500);
            customText("\tSorcerers have low resiliency, and their combat capabilities rely on Magic and Dexterity.", 1, 1250);

    char characterSelect;
    char currentCharacter[10];
    char* archer = "Archer";
    char* crusader = "Crusader";
    char* sorcerer = "Sorcerer";

    while (1)
    {
        newLine(1);
        printf("> Select your class by pressing A, B or C and confirm with Enter: ");
        scanf(" %1c", &characterSelect);
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
                printf("> So you are an [%s]", currentCharacter);
                newLine(1);
            }
            else
            {
                printf("> So you are a [%s]", currentCharacter);
                newLine(1);
            }
            break;
        }
        else
        {
            printf("> A, B or C. Please try again.");
            newLine(1);

            clearBuffer();
        }
    }
    Sleep(500);
    clearBuffer();
    printf("> What is your Name Adventurer?\n> ");
    scanf(" %50[^\n]", &playerName);
    Sleep(500);
    playerName[0] = toupper(playerName[0]);
    newLine(1);
    printf("> And thus your journey begins, brave [%s].", playerName);
    newLine(2);
    Sleep(1000);
    clearBuffer();
}

void printCharacterSheet(int currentChar) {
    customText("This is you and your equipment:", 1000, 1000);

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
    float ms = s * 1000;
    newLine(1);
    float msDivided = ms / 13;
    char textToWrite[13] = "...LOADING...";
    for (int i = 0; i < 13; i++)
    {
        printf("%c", textToWrite[i]);
        Sleep(msDivided);
    }
    newLine(2);
}

void archerSheet() {
    lvl = 1;
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
    printf("|  Your Level: [%i]        |\n", lvl);
    printf("|  Your Class: [Archer]   |\n");
    printf("|  Your Max Health: [%i]  |\n", playerMaxHP);
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [%i]     |\n", STR);
    printf("|     - Dexterity: [%i]    |\n", DEX);
    printf("|     - Vitality: [%i]     |\n", VIT);
    printf("|     - Magic: [%i]        |\n", MGC);
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - %s               |\n", held[0].itemName);
    printf("|     - %s        |\n", held[1].itemName);
    printf("|     - %s     |\n", held[2].itemName);
    printf("|     - Backpack[10]      |\n");
    printf("---------------------------\n");
    newLine(1);
}

void crusaderSheet() {
    lvl = 1;
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
    printf("|  Your Level: [%i]        |\n", lvl);
    printf("|  Your Class: [Crusader] |\n");
    printf("|  Your Max Health: [%i]  |\n", playerMaxHP);
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [%i]     |\n", STR);
    printf("|     - Dexterity: [%i]    |\n", DEX);
    printf("|     - Vitality: [%i]     |\n", VIT);
    printf("|     - Magic: [%i]        |\n", MGC);
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - %s         |\n", held[0].itemName);
    printf("|     - %s            |\n", held[1].itemName);
    printf("|     - %s        |\n", held[2].itemName);
    printf("|     - Backpack[10]      |\n");
    printf("---------------------------\n");
    newLine(1);
}

void sorcererSheet() {
    lvl = 1;
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
    printf("|  Your Level: [%i]        |\n", lvl);
    printf("|  Your Class: [Sorcerer] |\n");
    printf("|  Your Max Health: [%i]  |\n", playerMaxHP);
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [%i]     |\n", STR);
    printf("|     - Dexterity: [%i]    |\n", DEX);
    printf("|     - Vitality: [%i]     |\n", VIT);
    printf("|     - Magic: [%i]        |\n", MGC);
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - %s          |\n", held[0].itemName);
    printf("|     - %s             |\n", held[1].itemName);
    printf("|     - %s             |\n", held[2].itemName);
    printf("|     - Backpack[10]      |\n");
    printf("---------------------------\n");
    newLine(1);
}