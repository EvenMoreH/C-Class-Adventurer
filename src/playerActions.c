#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


#include "../include/playerActions.h"

#include "../include/globalStruct.h"
#include "../include/globalVar.h"

#include "../include/decisions.h"
#include "../include/equipment.h"
#include "../include/monsters.h"



void combatAction(int monsterID) {
    monsterAmbushHP = 0;
    monsterDmgTaken = 0;

    customText("Choose your action:", 10, 700);
    customText("A. Attack.", 10, 250);
    customText("B. Use Item.", 10, 250);
    customText("C. Run Away.", 10, 10);

    selectionABC();

    if (abcResult == 1)
    {
        customText("Attack with:", 10, 700);
        if (currentChar == 902)
        {
            customText("A. Spell.", 10, 250);
        }
        else
        {
            customText("A. Main hand weapon.", 10, 250);
        }

        customText("B. Off hand weapon.", 10, 50);

        selectionAB();

        if (abResult == 1)  // attack
        {
            if (currentChar == 902)
            {
                attackRollSpell(bonusDMGspell);
            }
            else
            {
                attackRollMain(mainWeapon, bonusDMG);
            }
        }
        else if (abResult == 0)
        {
            attackRollOff(offWeapon, bonusDMG);
        }

    }
    else if (abcResult == 2)    // use item
    {
        whatsInTheBag();
        clearBuffer();
        itemSelect();
    }
    else if (abcResult == 3)    // run!
    {
        customText("You run for your life!", 500, 500);

        printf("> [%s] catches your skin with its attack while you run away!", monsters[monsterID].monsterName);
        newLine(1);
        Sleep(500);
        monsterDmgTakenLog = 0;
        combatEnd = 0;  // Variable to end the combat without using break; outside of loop
        monsterAmbushHP = monsterCurrentHP;
        camping = 1;
    }
}

void combatActionAmbush(int monsterID) {
    monsterDmgTaken = 0;

    customText("Choose your action:", 10, 700);
    customText("A. Attack.", 10, 250);
    customText("B. Use Item.", 10, 250);

    selectionAB();

    if (abResult == 1)
    {
        customText("Attack with:", 10, 700);
        if (currentChar == 902)
        {
            customText("A. Spell.", 10, 250);
        }
        else
        {
            customText("A. Main hand weapon.", 10, 250);
        }

        customText("B. Off hand weapon.", 10, 50);

        selectionAB();

        if (abResult == 1)  // attack
        {
            if (currentChar == 902)
            {
                attackRollSpell(bonusDMGspell);
            }
            else
            {
                attackRollMain(mainWeapon, bonusDMG);
            }
        }
        else if (abResult == 0)
        {
            attackRollOff(offWeapon, bonusDMG);
        }

    }
    else if (abResult == 0)    // use item
    {
        whatsInTheBag();
        clearBuffer();
        itemSelect();
    }
}

void attackRollMain(int mainWeapon, int bonusDMG) {
    itemID = mainWeapon;

    int random = 1 + rand() % 6;

    int attackMODmain;
    int attackMOD = attackMODmain;
    int attackRoll = 7 + attackMOD + random;

    Sleep(1000);
    newLine(1);
    printf("> You attack with your [%s].", held[itemID].itemName);
    newLine(1);
    Sleep(1000);

    if (attackRoll < 11)
    {
        monsterDmgTakenLog = 0;
        formattedText("MISS!");
    }
    else
    {
        formattedText("HIT!");
        playerDamage(itemID, bonusDMG);
    }
}

void attackRollOff(int offWeapon, int bonusDMG) {
    itemID = offWeapon;

    int random = 1 + rand() % 6;

    int attackMODoff;
    int attackMOD = attackMODoff;
    int attackRoll = 7 + attackMOD + random;

    Sleep(1000);
    newLine(1);
    printf("> You attack with your [%s].", held[itemID].itemName);
    newLine(1);
    Sleep(1000);

    if (attackRoll < 11)
    {
        monsterDmgTakenLog = 0;
        formattedText("MISS!");
    }
    else
    {
        formattedText("HIT!");

        int isDazed = 1 + rand() % 100;
        if (isDazed > 50)
        {
            daze = 100;
            switch (currentChar)
            {
            case 900:
                customText("You strike deep, opening a big wound in your opponents guts rendering the creature shocked.", 10, 10);
                break;

                case 901:
                customText("You strike with force so great that you daze your enemy.", 10, 10);
                break;

                case 902:
                customText("You strike with such precision that your adversary is stunned.", 10, 10);
                break;
            }
        }
        playerDamage(itemID, bonusDMG);
    }
}

void attackRollSpell(int bonusDMGspell) {

    newLine(1);
    printf("> Spells in your [%s]:", held[0].itemName);
    newLine(1);
    Sleep(500);
    printf("> A. [%s].", spells[held[0].value1].spellName);
    newLine(1);
    Sleep(200);
    printf("> B. [%s].", spells[held[0].value2].spellName);
    newLine(1);
    Sleep(200);

    printf("> Select which spell to use.");
    newLine(1);
    selectionAB();

    if (abResult == 1)
    {
        SelectedSpellMinDMG = spells[held[0].value1].spellMinDMG;
        SelectedSpellMaxDMG = spells[held[0].value1].spellMaxDMG;
        newLine(1);
        printf("You attack with [%s].", spells[held[0].value1].spellName);
        newLine(1);
        Sleep(500);
    }
    else if (abResult == 0)
    {
        SelectedSpellMinDMG = spells[held[0].value2].spellMinDMG;
        SelectedSpellMaxDMG = spells[held[0].value2].spellMaxDMG;
        newLine(1);
        printf("You attack with [%s].", spells[held[0].value2].spellName);
        newLine(1);
        Sleep(500);
    }

    int random = 1 + rand() % 6;

    int attackMODspell;
    int attackMOD = attackMODspell;
    int attackRoll = 7 + attackMOD + random;

    if (attackRoll < 11)
    {
        monsterDmgTakenLog = 0;
        formattedText("MISS!");
    }
    else
    {
        formattedText("HIT!");
        playerSpellDamage(SelectedSpellMinDMG, SelectedSpellMaxDMG, bonusDMGspell);
    }
}

void itemSelect() {
    int backpackEmpty1 = 0;

    int backpackArray[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    printf("> Your consumable items:");
    newLine(1);
    for (int i = 0; i < 10; i++)
    {
        Sleep(100);
        if (strcmp(backpack[i].type, "Consumable") != 0)
        {
            backpackEmpty1 += 1;
            backpackArray[i] = 99;
            continue;
        }
        else
        {
            backpackArray[i] = i;

            Sleep(100);
            printf("%i. [%s]", i, backpack[i].itemName);
            newLine(1);
        }
    }
    Sleep(1000);
    if (backpackEmpty1 == 10)
    {
        monsterDmgTakenLog = 0;

        customText("Backpack is either empty or these are not consumable items...", 10, 250);
        printf("> Dont waste your turns [%s].", playerName);
        newLine(1);
        Sleep(1000);
    }
    else
    {
        printf("> Select one of below numbers and press Enter:\n> ");
        for (int i = 0; i < 10; i++)
        {
            if (backpackArray[i] != 99)
            {
                Sleep(50);
                printf("[%i] ", backpackArray[i]);
            }
        }
        newLine(1);
        printf("> ");

        int chosenItem;
        while (1)
        {
            scanf(" %i", &chosenItem);

            if (
            chosenItem == backpackArray[0] ||
            chosenItem == backpackArray[1] ||
            chosenItem == backpackArray[2] ||
            chosenItem == backpackArray[3] ||
            chosenItem == backpackArray[4] ||
            chosenItem == backpackArray[5] ||
            chosenItem == backpackArray[6] ||
            chosenItem == backpackArray[7] ||
            chosenItem == backpackArray[8] ||
            chosenItem == backpackArray[9])
            {
                for (int i = 0; i < 10; i++)
                {
                    if (chosenItem != backpackArray[i])
                    {
                        continue;
                    }
                    else
                    {
                        if (strcmp(backpack[chosenItem].additionalProperty, "Deals Damage") == 0)
                        // items[12].additionalProperty IS Damage Rune
                        {
                            Sleep(1000);
                            printf("You have used [%s].", backpack[chosenItem].itemName);
                            newLine(1);
                            Sleep(1000);
                            damageConsumable(backpack[chosenItem].id);
                            removeFromBag(backpack[chosenItem].id);
                            whatsInTheBag();
                        }
                        else
                        {
                            break;
                        }

                    }
                }
                for (int i = 0; i < 10; i++)
                {
                    if (chosenItem != backpackArray[i])
                    {
                        continue;
                    }
                    else
                    {
                        if (strcmp(backpack[chosenItem].additionalProperty, "Heals") == 0)
                        // items[11].additionalProperty IS healingPotion
                        {
                            Sleep(1000);
                            printf("You have used [%s].", backpack[chosenItem].itemName);
                            newLine(1);
                            healingPotion();
                            removeFromBag(backpack[chosenItem].id);
                            whatsInTheBag();
                        }
                        else
                        {
                            break;
                        }
                    }
                }
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
}

void healingPotion() {
    while (1)
    {
        for (int  i = 0; i < 10; i++)
        {
            if (strcmp(backpack[i].additionalProperty, "Heals") == 0)
            {
                if (playerCurrentHP >= playerMaxHP)
                {
                    customText("You drink the potion but feel no effect.", 1000, 10);

                    monsterDmgTakenLog = 0;

                    break;
                }
                else
                {
                    playerCurrentHP = playerCurrentHP + (10 + MGC + potionScaling(lvl));

                    if (playerCurrentHP > playerMaxHP)
                    {
                        playerCurrentHP = playerMaxHP;
                    }

                    Sleep(1000);
                    printf("> You restore [%i] Health.", 10 + MGC + potionScaling(lvl));
                    newLine(1);
                    Sleep(1000);
                    printf("> You current health is: [%i/%i].", playerCurrentHP, playerMaxHP);
                    newLine(1);

                    monsterDmgTakenLog = 0;

                    break;
                }
            }
        }
        break;
    }
}

void instantHealingPotion() {

    playerCurrentHP = playerCurrentHP + (10 + MGC + potionScaling(lvl));

    if (playerCurrentHP > playerMaxHP)
    {
        playerCurrentHP = playerMaxHP;
    }

    Sleep(1000);
    printf("> You restore [%i] Health.", 10 + MGC + potionScaling(lvl));
    newLine(1);
    Sleep(1000);
    printf("> You current health is: [%i/%i].", playerCurrentHP, playerMaxHP);
    newLine(1);
}

void regenerate() {
    int tempPotion = 0;

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(backpack[i].itemName, "Healing Potion") != 0)
        {
            continue;
        }
        else
        {
            tempPotion++;
        }
    }
    if (playerCurrentHP < playerMaxHP)
    {
        if (tempPotion > 0)
        {
            newLine(1);
            printf("> Your current Health is: [%i/%i]", playerCurrentHP, playerMaxHP);
            newLine(1);
            printf("> You have [%i]x [Healing Potion] in your backpack.", tempPotion);
            newLine(1);

            customText("Would you like to use one?", 10, 10);
            decision();

            if (result == 1)
            {
                healingPotion();
                removeFromBag(potion);
                whatsInTheBag();
            }
            else
            {
                customText("> Sure! Better to save it for later.", 10, 10);
            }
        }
        else
        {
            newLine(1);
            customText("Wounded, you think about drinking a [Healing Potion].", 500, 10);
            customText("but there is none in your backpack... Maybe next time.", 500, 10);
        }
    }
}


//  Player HP & Damage Roll  /////////////////////////////////////////

void playerHP(int playerDmgTaken) {
    playerCurrentHP = playerCurrentHP - playerDmgTaken;

    if (playerDmgTakenLog == 0)
    {
        // do nothing
    }
    else
    {
        Sleep(1000);
        printf("> You have taken: [%i] damage.", playerDmgTaken);
        newLine(1);

        if (playerCurrentHP <= 0)
        {
            playerCurrentHP = 0;
            Sleep(1000);
            printf("> You have died. You journey ends here.");
            newLine(1);
            Sleep(5000);
            exit(0);
        }
        else
        {
            printf("> Your current HP: [%i/%i]", playerCurrentHP, playerMaxHP);
            newLine(1);
        }
    }
}

int playerMaxHealth(int VIT, int classHPX) {
    playerMaxHP = VIT * classHPX;
    return playerMaxHP;
}

int playerDamage(int itemID, int bonusDMG) {
    int x = held[itemID].value1;
    int y = held[itemID].value2;
    int randomDmgRoll = x + rand() % y;

    dmg = bonusDMG + randomDmgRoll;

    printf("> You Deal [%i] damage!", dmg);
    newLine(1);

    monsterDmgTaken = dmg;

    monsterDmgTakenLog = dmg;

    return bonusDMG + randomDmgRoll;
}

int playerSpellDamage(int SelectedSpellMinDMG, int SelectedSpellMaxDMG, int bonusDMGspell) {
    int x = SelectedSpellMinDMG;
    int y = SelectedSpellMaxDMG;
    int randomDmgRoll = x + rand() % y;

    dmg = bonusDMG + randomDmgRoll;

    printf("> You Deal [%i] damage!", dmg);
    newLine(1);

    monsterDmgTaken = dmg;

    monsterDmgTakenLog = dmg;

    return bonusDMG + randomDmgRoll;
}

int damageConsumable(int itemID) {
    idFinder(itemID);
    int x = temp[0].value1;
    int y = temp[0].value2;

    dmg = x + rand() % y;

    printf("> You Deal [%i] damage!", dmg);
    newLine(1);

    monsterDmgTaken = dmg;

    monsterDmgTakenLog = dmg;

    return dmg;
}