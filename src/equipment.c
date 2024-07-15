#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


#include "../include/equipment.h"

#include "../include/globalStruct.h"
#include "../include/globalVar.h"

#include "../include/decisions.h"
#include "../include/playerActions.h"



void whatsInTheBag() {
    printf("> Current contents of your backpack: ");
    for (int i = 0; i < 10; i++)
    {
        Sleep(100);
        printf("[%s] ", backpack[i].iname);
    }
    printf("\n");
    Sleep(1000);
}

int addToBag(int itemID) {
    int tempBackpack = 0;

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(backpack[i].iname, items[0].iname) == 0)
        {
            backpack[i] = items[itemID];
            printf("> [%s] was added to your bag.", items[itemID].iname);
            newLine(1);
            break;
        }
        else
        {
            tempBackpack++;
        }
        if (tempBackpack == 10)
        {
            customText("Your backpack is full.", 10, 10);
            backpackFull(itemID);
        }
    }

    return tempBackpack;
}

void backpackFull(int itemID) {
    printf("> Would you like to replace one of the items?\n");
    decision();
    if (result == 1)
    {
        printf("> These are your items:");
        newLine(1);
        printf("> ");

        for (int i = 0; i < 10; i++)
        {
            Sleep(100);
            printf(" [%i]. [%s]", i, backpack[i].iname);
        }
        newLine(1);
        printf("> Select one of the items to replace.\n> ");

        int replacer;
        while (1)
        {
            scanf(" %i", &replacer);

            int replaceThis = backpack[replacer].id;

            if (replacer >= 0 && replacer <= 10)
            {
                removeFromBag(replaceThis);
                addToBag(itemID);
                break;
            }
            else
            {
                Sleep(1000);
                printf("Choose an actual item from the backpack!\n> ");
                clearBuffer();
            }
        }
    }
    else
    {
        if (itemID == potion)
        {
            customText("You decide to drink it anyway to avoid wasting it...", 10, 500);
            instantHealingPotion();
        }
        else
        {
            customText("You leave the item where it was.", 250, 250);
        }
    }
}

void removeFromBag(int itemID) {
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(backpack[i].iname, items[itemID].iname) == 0)
        {
            backpack[i] = items[0];
            break;
        }
    }
}

void foundItem(int itemID) {
    newLine(1);
    Sleep(1000);
    printf("-----------------------------------\n");
    printf("> You found [%s]\n", items[itemID].iname);
    printf("-----------------------------------\n");
    Sleep(1000);

    if (itemID == potion && playerCurrentHP < playerMaxHP)
    {
        printf("> Currently you have [%i/%i] Health.", playerCurrentHP, playerMaxHP);
        newLine(1);
        customText("Would you like to drink it immediately?", 500, 50);

        decision();

        if (result == 1)
        {
            instantHealingPotion();
        }
        else if (result == 0)
        {
            customText("You put it in the backpack for later use.", 500, 50);
            addToBag(itemID);
        }
    }
    else
    {
        addToBag(itemID);
    }
}

void equipItem(int itemID) {
    char* mainItem = "Main";
    char* offItem = "Off";
    char* armorItem = "Armor";

    if (strcmp(items[itemID].description, mainItem) == 0)
    {
        equipItemMain(itemID);
    }
    else if (strcmp(items[itemID].description, offItem) == 0)
    {
        equipItemOff(itemID);
    }
    else if (strcmp(items[itemID].description, armorItem) == 0)
    {
        equipItemArmor(itemID);
    }
}

void equipItemMain(int itemID) {
    held[0] = items[itemID];

    printf("> You found [%s], it will greatly improve your combat prowess!", items[itemID].iname);
    newLine(1);
    Sleep(1000);
    formattedText("Your damage with main weapon increase!");
    newLine(1);
}

void equipItemOff(int itemID) {
    held[1] = items[itemID];

    printf("> You found [%s], it will greatly improve your combat prowess!", items[itemID].iname);
    newLine(1);
    Sleep(1000);
    formattedText("Your damage off hand weapon increase!");
    newLine(1);
}

void equipItemArmor(int itemID) {
    int resistanceIncrease = items[itemID].minDMG - held[2].minDMG;
    int healthIncrease = items[itemID].maxDMG - held[2].maxDMG;
    globalResistance = resistanceIncrease;

    held[2] = items[itemID];

    printf("> You found [%s], it will greatly improve your combat prowess!", items[itemID].iname);
    newLine(1);
    Sleep(1000);
    printf("> Your resistance increases by [%i].", resistanceIncrease);
    newLine(1);
    Sleep(1000);
    printf("> Your health increases by [%i].", healthIncrease);
    newLine(1);
    Sleep(1000);

    playerCurrentHP = playerCurrentHP + healthIncrease;
    playerMaxHP = playerMaxHP + healthIncrease;

    if (playerCurrentHP > playerMaxHP)
    {
        playerCurrentHP = playerMaxHP;
    }
    printf("> Your current health is [%i]/[%i].", playerCurrentHP, playerMaxHP);
    newLine(2);
}