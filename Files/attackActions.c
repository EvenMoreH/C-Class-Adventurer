#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

// Global variables
    int itemID;
    
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
    int q;
    int result;

    // for A or B decisions
    int ab;
    int abResult;

    // for A or B or C decisions
    int abc;
    int abcResult;

    // for dealing and receiving damage (player)
    int dmg;
    int dmgTaken;
    int bonusDMG;
    int bonusDMGspell;

    // for declaring initial MAX HP and calculating current HP (player)
    int playerMaxHP;
    int playerCurrentHP;

// Locations - global
    // Location IDs = 200-210
int location;
int currentLocation;    // Used in decision trees to move between locations
struct location {
    int locationID;
    char locationName[40];
    char locationDescription[200];
};
    struct location locations[] = {
       {200, "Town", ""},
       {201, "Mountain Road", ""},
       {202, "Tomb of the Forsaken", ""},
       {203, "Mountain Pass", ""},
       {204, "Mines", ""},
       {205, "Graveyard", ""},
    };

// Global item management
struct item {
    int id;
    char iname[25];
    char description[100];  // For weapons it will be used to specify damage type
    int minDMG;
    int maxDMG;
};
    // item IDs = 0-99
    struct item items[] = {
       {0, "", "", 0, 0},     // <- something to mimic empty slots
       {1, "Bow", "Piercing", 1, 8},            // base item do not alter (Archer)
       {2, "Shortsword", "Slashing", 1, 6},     // base item do not alter (Archer)
       {3, "Longsword", "Slashing", 1, 8},      // base item do not alter (Crusader)
       {4, "Shield", "Bludgeoning", 1, 6},      // base item do not alter (Crusader)
       {5, "Staff", "Bludgeoning", 1, 6},       // base item do not alter (Sorcerer)
       {6, "Leather Armor", "", 0, 0},          // base item do not alter (Archer)
       {7, "Plate Armor", "", 0, 0},            // base item do not alter (Crusader)
       {8, "Robes", "", 0, 0},                  // base item do not alter (Sorcerer)
       {9, "Grimoire", "", 0, 0},                // base item do not alter (Sorcerer)

       // story items:
       {10, "Stoneskull Key", "Required to open Stone Gates located at [Mountain Road]", 0, 0},

       // consumables
       {11, "Healing Potion", "Heals for 10 Health", 0, 0},
       {12, "Avalanche Rune", "Deals Damage", 5, 15},
       {13, "Fireball Rune", "Deals Damage", 10, 25},
       {14, "Magic Missile Rune", "Deals Damage", 1, 8},
    };

// Global backpack management
    // backpack IDs = 100-110
    struct item backpack[] = {
        {100, "", "", 0, 0},
        {101, "", "", 0, 0},
        {102, "", "", 0, 0},
        {103, "", "", 0, 0},
        {104, "", "", 0, 0},
        {105, "", "", 0, 0},
        {106, "", "", 0, 0},
        {107, "", "", 0, 0},
        {108, "", "", 0, 0},
        {109, "", "", 0, 0},
        {110, "", "", 0, 0},
    };

// Global held items management
    // held IDs = 130-133
    struct item held[] = {
        {130, "", "", 0, 0},    // Main Weapon
        {131, "", "", 0, 0},    // Off hand weapon
        {132, "", "", 0, 0},    // Armor
        {133, "", "", 0, 0},    // ??
    };

// /////////////////////////////////////////////////////////////////
void clearBuffer();

void archerSheet();

void selectionABC();
void selectionAB();

// attack and damage
void attackRollMain(int mainWeapon, int bonusDMG);
void attackRollOff(int equippedWeaponOff, int bonusDMG);
void attackRollSpell(int equippedSpell, int bonusDMGspell);
int damage(int itemID, int bonusDMG);
int damageConsumable(int itemID);

void healingPotion();

void whatsInTheBag();
void itemSelect();

void combatAction();



int main() {            // Main function

    // |------------------------------------------|
        srand(time(NULL));  // declaring randomize|
    // |------------------------------------------|

    archerSheet();

    playerMaxHP = 50;
    playerCurrentHP = 20;
    backpack[5] = items[11];
    backpack[7] = items[12];
    backpack[3] = items[13];


    printf("> Round one:\n");

    combatAction();

    printf("\n\nEOF\n");
    Sleep(30000);

    return 0;               // Ends main function
}

void clearBuffer() {
    // Clear the input buffer
    int clearBuffer;
    while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
    // I don't get the above yet but:
    // The while loop with getchar() reads and discards characters until it encounters a newline ('\n') or end-of-file (EOF), effectively clearing the buffer.
}

void selectionABC() {
    int abc;
    Sleep(500);
    while (1)
    {
        printf("> [A/B/C]: ");
        scanf(" %c", &abc);

        if (abc == 'A' || abc == 'a')
        {
            abcResult = 0;
            break;
        }
        if (abc == 'B' || abc == 'b')
        {
            abcResult = 1;
            break;
        }
        if (abc == 'C' || abc == 'c')
        {
            abcResult = 2;
            break;
        }
        else 
        {
        printf("> A, B. Please try again.\n");
        
        clearBuffer();
        }
    }
}

void selectionAB() {
    int ab;
    Sleep(500);
    while (1)
    {
        printf("> [A/B]: ");
        scanf(" %c", &ab);

        if (ab == 'A' || ab == 'a')
        {
            abResult = 0;
            break;
        }
        if (ab == 'B' || ab == 'b')
        {
            abResult = 1;
            break;
        }
        else 
        {
        printf("> A, B. Please try again.\n");

        clearBuffer();
        }
    }
}

int damageConsumable(int itemID) {
    int x = items[itemID].minDMG;
    int y = items[itemID].maxDMG;

    dmg = x + rand() % y;

    printf("> You Deal [%i] damage!\n", dmg);

    return  x + rand() % y;
}

int damage(int itemID, int bonusDMG) {
    int x = held[itemID].minDMG;
    int y = held[itemID].maxDMG;

    dmg = bonusDMG + x + rand() % y;

    printf("> You Deal [%i] damage!\n", dmg);

    return bonusDMG + x + rand() % y;
}

void attackRollMain(int mainWeapon, int bonusDMG) {
    itemID = mainWeapon;
    
    int random = 1 + rand() % 6;

    int hit;
    int attackMODmain;
    int attackMOD = attackMODmain;
    int attackRoll = 7 + attackMOD + random;

    Sleep(1000);
    printf("> You attack with your [%s].\n", held[itemID].iname);
    Sleep(1000);

    if (attackRoll < 11)
    {
        hit = 1;
        printf("> MISS!\n");
        Sleep(1000);
    }
    else
    {
        hit = 0;
        printf("> HIT!\n");
        Sleep(1000);
        damage(itemID, bonusDMG);
    }
}

void attackRollOff(int offWeapon, int bonusDMG) {
    itemID = offWeapon;

    int random = 1 + rand() % 6;
    
    int hit;
    int attackMODoff;
    int attackMOD = attackMODoff;
    int attackRoll = 7 + attackMOD + random;
    
    Sleep(1000);
    printf("> You attack with your [%s].\n", held[itemID].iname);
    Sleep(1000);

    if (attackRoll < 11)
    {
        hit = 1;
        printf("> MISS!\n");
        Sleep(1000);
    }
    else
    {
        hit = 0;
        printf("> HIT!\n");
        Sleep(1000);
        damage(itemID, bonusDMG);
    }
}

void attackRollSpell(int equippedSpell, int bonusDMGspell) {
    int spellID; // <- placeholder befor I will built grimoirs
    
    // missing text prompt

    spellID = equippedSpell;
    
    int random = 1 + rand() % 6;
    
    int hit;
    int attackMODspell;
    int attackMOD = attackMODspell;
    int attackRoll = 7 + attackMOD + random;

    if (attackRoll < 11)
    {
        hit = 1;
        printf("> MISS!\n");
        Sleep(1000);
    }
    else
    {
        hit = 0;
        printf("> HIT!\n");
        Sleep(1000);
    }
}

void archerSheet() {
    int lvl = 1;
    int STR = 5;
    int DEX = 7;
    int VIT = 5;
    int MGC = 1;
    int classHPX = 10;

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
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [5]     |\n");
    printf("|     - Dexterity: [7]    |\n");
    printf("|     - Vitality: [5]     |\n");
    printf("|     - Magic: [1]        |\n");
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - Bow               |\n");
    printf("|     - Shortsword        |\n");
    printf("|     - Leather Armor     |\n");
    printf("|     - Backpack          |\n");
    printf("---------------------------\n");
    printf("\n");
}

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

void itemSelect() {
    int backpackArray[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    printf("> Your consumable items:\n");
    for (int i = 0; i < 10; i++)
    {
        Sleep(100);
        if (strcmp(backpack[i].iname, items[11].iname) != 0)
        {
            backpackArray[i] = 99;
            continue;
        }
        else
        {   
            backpackArray[i] = i;

            Sleep(100);
            printf("%i. [%s]\n", i, backpack[i].iname);
        }
    }
                
    for (int i = 0; i < 10; i++)
    {
        Sleep(100);
        if (strcmp(backpack[i].description, items[12].description) != 0)
        {
            if (backpackArray[i] == -1)
            {
                backpackArray[i] = 99;
            }
            else
            {
                continue;
            }
        }
        else
        {   
            backpackArray[i] = i;

            Sleep(100);
            printf("%i. [%s]\n", i, backpack[i].iname);
        }
    }

    printf("\n");
    Sleep(1000);

    printf("> Select one of below numbers and press Enter:\n> ");
    for (int i = 0; i < 10; i++)
    {
        if (backpackArray[i] != 99)
        {
            Sleep(100);
            printf("[%i] ", backpackArray[i]);
        }
    }

    printf("\n> ");
    
    int chosenItem;
    while (1)
    {
        scanf(" %i", &chosenItem);
        
        if (chosenItem == backpackArray[0] || chosenItem == backpackArray[1] || chosenItem == backpackArray[2] || chosenItem == backpackArray[3] ||
         chosenItem == backpackArray[4] || chosenItem == backpackArray[5] || chosenItem == backpackArray[6] ||
         chosenItem == backpackArray[7] || chosenItem == backpackArray[8] || chosenItem == backpackArray[9])
        {
            for (int i = 0; i < 10; i++)
            {
                if (chosenItem != backpackArray[i])
                {
                    continue;
                }
                else
                {
                    if (strcmp(backpack[chosenItem].description, items[12].description) == 0)   // items[12].description IS Damage Rune
                    {
                        Sleep(1000);
                        printf("You have used [%s]\n", backpack[chosenItem].iname);
                        Sleep(1000);
                        damageConsumable(backpack[chosenItem].id);
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
                    
                    if (strcmp(backpack[chosenItem].description, items[11].description) == 0)   // items[11].description IS healingPotion
                    {
                        Sleep(1000);
                        printf("You have used [%s]\n", backpack[chosenItem].iname);
                        healingPotion();
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

void healingPotion() {
    while (1)
    {
        for (int  i = 0; i < 10; i++)
        {
            if (strcmp(backpack[i].description, items[11].description) == 0)
            {
                if (playerCurrentHP >= playerMaxHP)
                {
                    Sleep(1000);
                    printf("> You can't use that you are at full health.\n");
                    break;
                }
                else
                {
                    playerCurrentHP = playerCurrentHP + 10;
                    
                    if (playerCurrentHP > playerMaxHP)
                    {
                        playerCurrentHP = playerMaxHP;
                    }

                    Sleep(1000);
                    printf("> You restore [10 Health].\n");
                    Sleep(1000);
                    printf("> You current health is: [%i].\n", playerCurrentHP);
                    break;
                }
            }
        }
        break;
    }
}

void combatAction() {
    printf("> Choose your action:\n");
    Sleep(1000);
    printf("A. Attack\n");
    Sleep(500);
    printf("B. Use Item\n");
    Sleep(500);
    printf("C. Run Away\n");

    selectionABC();

    if (abcResult == 0)
    {
        printf("> Attack with:\n");
        Sleep(1000);
        printf("> A. Main hand weapon.\n");
        Sleep(500);
        printf("> B. Off hand weapon.\n");

        selectionAB();

        if (abResult == 0)  // attack
        {
            attackRollMain(mainWeapon, bonusDMG);
        }
        else if (abResult == 1)
        {
            attackRollOff(offWeapon, bonusDMG);
        }
        
    }
    else if (abcResult == 1)    // use item
    {
        whatsInTheBag();
        itemSelect(); 
    }
    else if (abcResult == 2)    // run!
    {
        Sleep(500);
        printf("> You retreat and run back to the Town!\n");
        Sleep(500);
        printf("{TEMP}> [Monster] catches your skin with its [Weapon]!\n");
        Sleep(500);
        printf("{TEMP}> You receive XYZ damage!\n");
        Sleep(500);
        printf("{TEMP}> You current HP is: ABC!\n");
        Sleep(500);
    }
}