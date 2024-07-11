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
            printf("> [%s] was added to your bag.\n", items[itemID].iname);
            break;
        }
        else
        {
            tempBackpack++;
        }
        if (tempBackpack == 10)
        {
            printf("> Your backpack is full.\n");
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
        printf("> These are your items:\n");
        printf("> ");

        for (int i = 0; i < 10; i++)
        {
            Sleep(100);
            printf(" [%i]. [%s]", i, backpack[i].iname);
        }

        printf("\n> Select one of the items to replace.\n> ");

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
            printf("> You decide to drink it anyway to avoid wasting it...\n");
            Sleep(500);
            instantHealingPotion();
        }
        else
        {
            printf("> You leave the item where it was.\n");
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
    Sleep(1000);
    printf("\n");
    printf("-----------------------------------\n");
    printf("> You found [%s]\n", items[itemID].iname);
    printf("-----------------------------------\n");
    Sleep(1000);

    if (itemID == potion && playerCurrentHP < playerMaxHP)
    {
        printf("> Currently you have [%i/%i] Health.\n", playerCurrentHP, playerMaxHP);
        Sleep(500);
        printf("> Would you like to drink it immediately?\n");

        decision();

        if (result == 1)
        {
            instantHealingPotion();
        }
        else if (result == 0)
        {
            Sleep(500);
            printf("> You put it in the backpack for later use.\n");
            // addToBag(itemID);
            // TRIVIA: I could comment out above addToBag cause having it in if worked
                //  output all data in said function

            // if (addToBag(itemID) == 10)
            // {
            //     printf("> You decide to drink it anyway to avoid wasting it...\n");
            //     Sleep(500);
            //     instantHealingPotion();
            // }

            // code was changed here to reflect replacing items / drinking potions
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

    printf("> You found [%s], it will greatly improve your combat prowess!\n", items[itemID].iname);
    Sleep(1000);
    printf("> Your damage with main weapon increases!\n\n");
    Sleep(1000);
}

void equipItemOff(int itemID) {
    held[1] = items[itemID];

    printf("> You found [%s], it will greatly improve your combat prowess!\n", items[itemID].iname);
    Sleep(1000);
    printf("> Your damage with off hand weapon increases!\n\n");
    Sleep(1000);
}

void equipItemArmor(int itemID) {
    int resistanceIncrease = items[itemID].minDMG - held[2].minDMG;
    int healthIncrease = items[itemID].maxDMG - held[2].maxDMG;
    globalResistance = resistanceIncrease;

    held[2] = items[itemID];

    printf("> You found [%s], it will greatly improve your combat prowess!\n", items[itemID].iname);
    Sleep(1000);
    printf("> Your resistance increases by [%i].\n", resistanceIncrease);
    Sleep(1000);
    printf("> Your health increases by [%i].\n", healthIncrease);
    Sleep(1000);

    playerCurrentHP = playerCurrentHP + healthIncrease;
    playerMaxHP = playerMaxHP + healthIncrease;

    if (playerCurrentHP > playerMaxHP)
    {
        playerCurrentHP = playerMaxHP;
    }
    printf("> Your current health is [%i]/[%i].\n\n", playerCurrentHP, playerMaxHP);
}