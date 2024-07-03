#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // Copilot links it as required for randomizers
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

// Global variables
    int itemID;
    int combatEnd;
    char name[50];
    int daze;


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
    int bonusDMG;
    int bonusDMGspell;
    int playerDmgTaken;     // NEW
    int playerDmgTakenLog;  // log testing to skip dmg logs if dmg = 0


    // for declaring initial MAX HP and calculating current HP (player)
    int playerMaxHP;
    int playerCurrentHP;

    // NEW: monster HP & DMG
    int monsterID;
    int monsterCurrentHP;
    int monsterDmgDone;     // NEW
    int monsterDmgTaken;    // NEW
    // NEW  // required for monster to only use special attack once
    int specialMonsterAttack = 0;
    // NEW  // required for monster Run check
    char monsterRun[] = "Run";
    int monsterDmgTakenLog;   // log testing to skip dmg logs if dmg = 0

    // ITEM Shortcuts
    int potion = 11;


//// STRUCTS /////////////////////////////////////////////////////////

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

// Monster structs
    struct monster {
        int monsterID;
        char monsterName[25];
        char monsterDescription[100];
        // required to initialize struct,
            // will have a random value added to it to calculate MonsterMaxHP
        int monsterBaseHP;
        char monsterAttack1[20];
        int monsterAttack1minDMG;
        int monsterAttack1maxDMG;
        char monsterAttack2[20];
        int monsterAttack2minDMG;
        int monsterAttack2maxDMG;
        // if threshold is triggered
        char monsterAttack3[20];
        int monsterAttack3minDMG;
        int monsterAttack3maxDMG;
        // (if monsterCurrentHP <= monsterThreshold use special attack once and break;)
        int monsterThreshold;
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


////  FUNCTION DECLARATION  //////////////////////////////////////////

//  Intro & Character Selection  /////////////////////////////////////
void intro();
// Function used to kick off randomize
void randomize();
void loading(int s);
void chooseCharacter();
void printCharacterSheet(int currentChar);
void archerSheet();
void crusaderSheet();
void sorcererSheet();

//  Clear Buffer  ////////////////////////////////////////////////////
void clearBuffer();

// Encounters ////////////////////////////////////////////////////////
void encounter(int monsterID);

//  Backpack & Item Management  //////////////////////////////////////
void whatsInTheBag();
int addToBag(int itemID);
void removeFromBag(int itemID);
void foundItem(int itemID);

//  Locations  ///////////////////////////////////////////////////////
// Argument here is called location
// and should match one of the predefined location IDs
void discoveredLocation(int location);
// Argument here is called location
// and should match one of the predefined location IDs
void enterLocation(int location);

//  Player HP & Damage Roll  /////////////////////////////////////////
int playerDamage(int itemID, int bonusDMG);
int damageConsumable(int itemID);
int playerHP(int playerDmgTaken);
int playerMaxHealth(int vitality, int classHPX);

//  Player Actions in Combat  ////////////////////////////////////////
void combatAction(int monsterID);
void attackRollMain(int mainWeapon, int bonusDMG);
void attackRollOff(int equippedWeaponOff, int bonusDMG);
void attackRollSpell(int equippedSpell, int bonusDMGspell);
void itemSelect();
void healingPotion();
// if player founds a potion and has less than full HP it asks if drink immediately
void instantHealingPotion();
// asks if potion should be used after combat
void regenerate();

//  Decision Trees  //////////////////////////////////////////////////
void decision();
void selectionAB();
void selectionABC();

// Monsters //////////////////////////////////////////////////////////
int monsterHP(int monsterDmgTaken, int monsterID);
int monsterMaxHP(int monsterID);
int monsterDamage1(int monsterID);
int monsterDamage2(int monsterID);
int monsterDamage3(int monsterID);
int monsterDamageOpportunity(int monsterID);    // NEW
void monsterAction(int monsterID);  // NEW


int main() {
    randomize();

    intro();

    chooseCharacter();
    printCharacterSheet(currentChar);

    // lets give some items for testing
    addToBag(13);
    // addToBag(potion);
    // addToBag(potion);
    addToBag(9);
    addToBag(9);
    addToBag(9);
    addToBag(9);
    addToBag(9);




    printf("> Would you like to enter this cave?\n");

    decision();

    if (result == 0)
    {
        printf("> You entered a cave.\n");
        Sleep(1000);

        discoveredLocation(204);

        printf("> Would you like to go deeper?\n");

        decision();

        if (result == 0)
        {
            Sleep(1000);
            printf("> You go deeper and find something lurking in the shadows!\n");
            Sleep(1000);

            encounter(1);

            Sleep(1000);
            if (monsterCurrentHP > 0)   // ergo monster still alive
            {
                printf("{TEMP}> You escaped and returned to the cave entrance in [Location].\n");
            }
            else
            {
                foundItem(4);  // shortcut for potions as int potions = 11
                foundItem(11);  // shortcut for potions as int potions = 11
                whatsInTheBag();
            }
        }
        else
        {
            Sleep(1000);
            printf("> You turn back and head home to rest.\n");
        }
    }
    else
    {
        printf("> You went back to town.\n");
        Sleep(1000);

        enterLocation(200);

        printf("> Would you like to go to the tavern?\n");
        decision();

        if (result == 0)
        {
            Sleep(1000);
            printf("> You drink till you pass out...\n");
        }
        else
        {
            Sleep(1000);
            printf("> You go home and rest for the day.\n");
        }
    }

    printf("\n> EOF\n");
    Sleep(30000);

    return 0;               // Ends main function
}

////  FUNCTION DEFINITION  ///////////////////////////////////////////

//  Intro & Character Selection  /////////////////////////////////////
void randomize() {
    srand(time(NULL));
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
    char currentCharacter[20];
    char archer[10] = "Archer";
    char crusader[10] = "Crusader";
    char sorcerer[10] = "Sorcerer";

    while (1)
    {
        printf("\n> Select your class by pressing A, B or C and confirm with Enter: ");
        scanf("%c", &characterSelect);
                if (characterSelect == 'a' || characterSelect == 'A' ||
                characterSelect == 'b' || characterSelect == 'B' ||
                characterSelect == 'c' || characterSelect == 'C')
        {
            if (characterSelect == 'a' || characterSelect == 'A')
            {
                strcpy(currentCharacter, archer);
                currentChar = 900;
            }
            if (characterSelect == 'b' || characterSelect == 'B')
            {
                strcpy(currentCharacter, crusader);
                currentChar = 901;
            }
            if (characterSelect == 'c' || characterSelect == 'C')
            {
                strcpy(currentCharacter, sorcerer);
                currentChar = 902;
            }

            if (characterSelect == 'a' || characterSelect == 'A')
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

            // Clear the input buffer
            int clearBuffer;
            while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
            // I don't get the above yet but:
            // The while loop with getchar()
                // reads and discards characters until it encounters a newline ('\n')
                // or end-of-file (EOF), effectively clearing the buffer.
        }
    }
    // char name[50];
    char surname[50];

    while (1)
    {
        Sleep(500);
        clearBuffer();
        printf("> What is your name Adventurer? ");
        scanf(" %s", &name);
        // scanf("%s", &surname);
        Sleep(500);
        printf("\n> And thus your journey begins, brave [%s].\n\n", name);
        Sleep(1000);
        break;
    }
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
        printf("> All of your inputs you can confirm by pressing Enter\n\n");

        printf("> When attacking there is a chance to miss your opponents.\n");
        Sleep(250);
        printf("> Attacking with off hand weapon has even lower chance to hit but can daze your enemy forcing it to miss.\n");
        Sleep(250);
        printf("> When your bag is empty and you would try to use items in combat you will waste your turn so beware.\n");
        Sleep(250);
        printf("> Anyway!\n\n");
        Sleep(250);

        Sleep(1000);
        printf("> Good Luck!\n\n");
}

// 10 element loading bar
    // takes the argument in seconds to display this amount of loading time
void loading(int s) {
    int ms = s * 100;
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
    int MGC = 1;
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

void crusaderSheet() {
    int lvl = 1;
    int STR = 5;
    int DEX = 7;
    int VIT = 5;
    int MGC = 1;
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
    printf("|     - Dexterity: [3]    |\n");
    printf("|     - Vitality: [7]     |\n");
    printf("|     - Magic: [1]        |\n");
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - Longsword         |\n");
    printf("|     - Shield            |\n");
    printf("|     - Plate Armor       |\n");
    printf("|     - Backpack          |\n");
    printf("---------------------------\n");
    printf("\n");
}

void sorcererSheet() {
    int lvl = 1;
    int STR = 5;
    int DEX = 7;
    int VIT = 5;
    int MGC = 1;
    int classHPX = 8;

    playerMaxHP = playerMaxHealth(VIT, classHPX);
    playerCurrentHP = playerMaxHP;

    bonusDMGspell = (((MGC / 2) - 2) + lvl);
    bonusDMG = (((DEX / 2) - 2) + lvl);

    int attackMOD;
    int attackMODoff = (((DEX / 2) - 2) - 1);
    int attackMODspell = (attackMODoff - 1);

    // lets equip starting items:
    held[0] = items[5];
    held[1] = items[9];
    held[2] = items[8];

    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Level: [1]        |\n");
    printf("|  Your Class: [Sorcerer] |\n");
    printf("|  Your Max Health: [%i]  |\n", playerMaxHP);
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [3]     |\n");
    printf("|     - Dexterity: [5]    |\n");
    printf("|     - Vitality: [3]     |\n");
    printf("|     - Magic: [7]        |\n");
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - Staff             |\n");
    printf("|     - Grimoire          |\n");
    printf("|     - Robes             |\n");
    printf("|     - Backpack          |\n");
    printf("---------------------------\n");
    printf("\n");
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

//  Encounter  ///////////////////////////////////////////////////////

void encounter(int monsterID) {
    monsterCurrentHP = monsterMaxHP(monsterID);

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

        monsterAction(monsterID);
        Sleep(500);

        playerHP(playerDmgTaken);
    }

    if (playerCurrentHP > 0 && combatEnd == 0)
    {
        regenerate();
    }

}

//  Backpack & Item Management  //////////////////////////////////////

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
        }
    }

    return tempBackpack;
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

        if (result == 0)
        {
            instantHealingPotion();
        }
        else if (result = 1)
        {
            Sleep(500);
            printf("> You put it in the backpack for later use.\n");
            // addToBag(itemID);
            // TRIVIA: I could comment out above addToBag cause having it in if worked
                //  output all data in said function
            if (addToBag(itemID) == 10)
            {
                printf("> You decide to drink it anyway to avoid wasting it...\n");
                Sleep(500);
                instantHealingPotion();
            }
        }
    }
    else
    {
        addToBag(itemID);
    }
}

//  Locations  ///////////////////////////////////////////////////////

void discoveredLocation(int location) {
    currentLocation = location;
    for (int i = 0; i < 10; i++)
    {
        if (location == locations[i].locationID)
        {
            Sleep(1000);
            printf("\n-----------------------------------\n");
            printf("> You discovered [%s]\n", locations[i].locationName);
            printf("-----------------------------------\n\n");
            Sleep(1000);
            break;
        }
    }
}

void enterLocation(int location) {
    currentLocation = location;
    for (int i = 0; i < 10; i++)
    {
        if (location == locations[i].locationID)
        {
            Sleep(2000);
            printf("-----------------------------------\n");
            printf("> You enter [%s]\n", locations[i].locationName);
            printf("-----------------------------------\n");
            Sleep(2000);
            break;
        }
    }
}

//  Player HP & Damage Roll  /////////////////////////////////////////

int playerHP(int playerDmgTaken) {
    playerCurrentHP = playerCurrentHP - playerDmgTaken;

    if (playerDmgTakenLog == 0)
    {
        // do nothing
    }
    else
    {
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
            printf("> Your current HP: [%i/%i]\n", playerCurrentHP, playerMaxHP);
        }
    }
}

int playerMaxHealth(int VIT, int classHPX) {
    playerMaxHP = VIT * classHPX;
    return playerMaxHP;
}

int playerDamage(int itemID, int bonusDMG) {
    int x = held[itemID].minDMG;
    int y = held[itemID].maxDMG;
    int randomDmgRoll = x + rand() % y;

    dmg = bonusDMG + randomDmgRoll;

    printf("> You Deal [%i] damage!\n", dmg);

    monsterDmgTaken = dmg;

    monsterDmgTakenLog = dmg;

    return bonusDMG + randomDmgRoll;
}

int damageConsumable(int itemID) {
    int x = items[itemID].minDMG;
    int y = items[itemID].maxDMG;

    dmg = x + rand() % y;

    printf("> You Deal [%i] damage!\n", dmg);

    monsterDmgTaken = dmg;

    monsterDmgTakenLog = dmg;

    return dmg;
}

//  Player Actions in Combat  ////////////////////////////////////////

void combatAction(int monsterID) {

    monsterDmgTaken = 0;

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
        clearBuffer();
        itemSelect();
    }
    else if (abcResult == 2)    // run!
    {
        Sleep(500);
        printf("> You retreat and run back to the Town!\n");
        Sleep(500);

        printf("> [%s] catches your skin with its attack while you run away!\n", monsters[monsterID].monsterName);
        Sleep(500);
        monsterDmgTakenLog = 0;
        combatEnd = 0;  // Variable to end the combat without using break; outside of loop
    }
}

void attackRollMain(int mainWeapon, int bonusDMG) {
    itemID = mainWeapon;

    int random = 1 + rand() % 6;

    int hit;
    int attackMODmain;
    int attackMOD = attackMODmain;
    int attackRoll = 7 + attackMOD + random;

    Sleep(1000);
    printf("\n> You attack with your [%s].\n", held[itemID].iname);
    Sleep(1000);

    if (attackRoll < 11)
    {
        hit = 1;
        monsterDmgTakenLog = 0;
        printf("> MISS!\n");
        Sleep(1000);
    }
    else
    {
        hit = 0;
        printf("> HIT!\n");
        Sleep(1000);
        playerDamage(itemID, bonusDMG);
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
    printf("\n> You attack with your [%s].\n", held[itemID].iname);
    Sleep(1000);

    if (attackRoll < 11)
    {
        hit = 1;
        monsterDmgTakenLog = 0;
        printf("> MISS!\n");
        Sleep(1000);
    }
    else
    {
        hit = 0;
        printf("> HIT!\n");
        Sleep(1000);

        int isDazed = 1 + rand() % 100;
        if (isDazed > 50)
        {
            daze = 100;
            switch (currentChar)
            {
            case 900:
                printf("> You strike deep, opening a big wound in your opponents guts rendering the creature shocked.\n");
                break;

                case 901:
                printf("> You strike with force so great that you daze your enemy.\n");
                break;

                case 902:
                printf("> You strike with such precision that your adversary is stunned.\n");
                break;
            }
        }

        playerDamage(itemID, bonusDMG);

    }
}

void attackRollSpell(int equippedSpell, int bonusDMGspell) {
    int spellID; // <- placeholder befor I will built grimoires

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
        monsterDmgTakenLog = 0;
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

void itemSelect() {
    int backpackEmpty1 = 0;
    int backpackEmpty2 = 0;

    int backpackArray[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    printf("> Your consumable items:\n");
    for (int i = 0; i < 10; i++)
    {
        Sleep(100);
        if (strcmp(backpack[i].iname, items[11].iname) != 0)
        {
            // wombo combo to check if there are any healing items in backpack
            backpackEmpty1 += 1;
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
                // wombo combo to check if there are any damaging items in backpack
                backpackEmpty2 += 1;
                continue;
            }
        }
        else
        {
            backpackArray[i] = i;

            if (backpackEmpty1 == 1)
            {
                // do nothing
            }
            else
            {
                Sleep(100);
                printf("%i. [%s]\n", i, backpack[i].iname);
            }
        }
    }

    printf("\n");
    Sleep(1000);

    if (backpackEmpty1 == 10 && backpackEmpty2 == 10)
    {
        monsterDmgTakenLog = 0;

        printf("> Backpack is either empty or these are not consumable items...\n");
        Sleep(250);
        printf("> Dont waste your turns [%s].\n", name);
        Sleep(1000);
    }
    else
    {
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

            if (chosenItem == backpackArray[0] || chosenItem == backpackArray[1]||
            chosenItem == backpackArray[2] || chosenItem == backpackArray[3] ||
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
                        if (strcmp(backpack[chosenItem].description, items[11].description) == 0)   // items[11].description IS healingPotion
                        {
                            Sleep(1000);
                            printf("You have used [%s]\n", backpack[chosenItem].iname);
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
                    printf("> You current health is: [%i/%i].\n", playerCurrentHP, playerMaxHP);
                    break;
                }
            }
        }
        break;
    }
}

void instantHealingPotion() {

playerCurrentHP = playerCurrentHP + 10;

if (playerCurrentHP > playerMaxHP)
{
    playerCurrentHP = playerMaxHP;
}

Sleep(1000);
printf("> You restore [10 Health].\n");
Sleep(1000);
printf("> You current health is: [%i/%i].\n", playerCurrentHP, playerMaxHP);
}

void regenerate() {
    int tempPotion = 0;

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(backpack[i].iname, items[11].iname) != 0)
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
            printf("\n> Your current Health is: [%i/%i]\n", playerCurrentHP, playerMaxHP);
            printf("> You have [%i]x [%s] in your backpack.\n", tempPotion, items[11].iname);

            printf("> Would you like to use one?\n");
            decision();
            if (result == 0)
            {
                healingPotion();
                removeFromBag(potion);
                whatsInTheBag();
            }
            else
            {
                printf("> Sure! Better to save it for later.\n");
            }
        }
        else
        {
            printf("\n> Wounded, you think about drinking a [Healing Potion].\n");
            printf("> but there is none in your backpack... Maybe next time.\n");
        }
    }
}

//  Decision Trees  //////////////////////////////////////////////////

void decision() {
    clearBuffer();

    char q;

    Sleep(500);

    while (1)
    {
        printf("> [Y/N]: ");
        scanf(" %c", &q);
        if (q == 'Y' || q == 'y')
        {
            result = 0;
            break;
        }
        else if (q == 'N' || q == 'n')
        {
            result = 1;
            break;
        }
        else
        {
            printf("> Y or N. Please try again.\n");

            clearBuffer();
        }
    }
}

void selectionAB() {

    clearBuffer();

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

void selectionABC() {
    clearBuffer();

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
            Sleep(2000);

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