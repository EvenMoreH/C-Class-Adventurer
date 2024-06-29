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
    int bonusDMG;
    int bonusDMGspell;
    int playerDmgTaken;     // NEW


    // for declaring initial MAX HP and calculating current HP (player)
    int playerMaxHP;
    int playerCurrentHP;

    // NEW: monster HP & DMG
    int monsterMaxHP;
    int monsterCurrentHP;
    int monsterDmgDone;     // NEW
    int monsterDmgTaken;    // NEW

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


////  FUNCTION DECLARATION  ////////////////////////////////////////////////////////////////////////

//  Intro & Character Selection  ///////////////////////////////////////////////////////////////////
void intro();
void loading(int s);
void chooseCharacter();
void printCharacterSheet(int currentChar);
void archerSheet();
void crusaderSheet();
void sorcererSheet();

//  Clear Buffer  //////////////////////////////////////////////////////////////////////////////////
void clearBuffer();

//  Backpack & Item Management  ////////////////////////////////////////////////////////////////////
void whatsInTheBag();
void addToBag(int itemID);
void removeFromBag(int itemID);
void foundItem(int itemID);

//  Locations  /////////////////////////////////////////////////////////////////////////////////////
void discoveredLocation(int location);      // Argument here is called location and should match one of the predefined location IDs
void enterLocation(int location);           // Argument here is called location and should match one of the predefined location IDs

//  Player HP & Damage Roll  ///////////////////////////////////////////////////////////////////////
int playerDamage(int itemID, int bonusDMG);
int playerHP(int playerDmgTaken);
int playerMaxHealth(int vitality, int classHPX);

//  Player Actions in Combat  //////////////////////////////////////////////////////////////////////
void attackRollMain(int mainWeapon, int bonusDMG);
void attackRollOff(int equippedWeaponOff, int bonusDMG);
void attackRollSpell(int equippedSpell, int bonusDMGspell);

//  Decision Trees  ////////////////////////////////////////////////////////////////////////////////
void decision();
void selectionAB();
void selectionABC();

// MONSTERS ////////////////////////////////////////////////////////////////////////////////////////
int monsterHP(int monsterDmgTaken);



int main() {
    /////////////////////////////////////////////////
        srand(time(NULL));  // declaring randomize //
    /////////////////////////////////////////////////

    intro();

    chooseCharacter();
    printCharacterSheet(currentChar);


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
            printf("> You go deeper and find a giant rat!\n");
            Sleep(1000);

            attackRollMain(mainWeapon, bonusDMG);
            Sleep(500);
            attackRollOff(offWeapon, bonusDMG);

            Sleep(1000);
            printf("> It runs away leaving an old backpack unattended in the corner.\n");

            foundItem(4);
            addToBag(4);
            whatsInTheBag();

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
    
    
    return 0;               // Ends main function
}

////  FUNCTION DEFINITION  /////////////////////////////////////////////////////////////////////////

//  Intro & Character Selection  ///////////////////////////////////////////////////////////////////

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
        
        if (characterSelect == 'a' || characterSelect == 'A' || characterSelect == 'b' || characterSelect == 'B' || characterSelect == 'c' || characterSelect == 'C')
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
            // The while loop with getchar() reads and discards characters until it encounters a newline ('\n') or end-of-file (EOF), effectively clearing the buffer.
        }
    }
    char name[50];
    char surname[50];

    while (1)
    {
        Sleep(500);
        printf("> What is your name Adventurer? ");
        scanf("%s", &name);
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
        Sleep(1000);
        printf("> Good Luck!\n\n");
}

void loading(int s) {
    // 10 element loading bar which takes the argument in seconds to display this amount of loading time
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

//  Clear Buffer  //////////////////////////////////////////////////////////////////////////////////

void clearBuffer() {
    // Clear the input buffer
    int clearBuffer;
    while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
    // I don't get the above yet but:
    // The while loop with getchar() reads and discards characters until it encounters a newline ('\n') or end-of-file (EOF), effectively clearing the buffer.
}

//  Backpack & Item Management  ////////////////////////////////////////////////////////////////////

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

void addToBag(int itemID) {
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(backpack[i].iname, items[0].iname) == 0)
        {
            backpack[i] = items[itemID];
            break;
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
    Sleep(2000);
    printf("-----------------------------------\n");
    printf("> You found [%s]\n", items[itemID].iname);
    printf("-----------------------------------\n");
    Sleep(2000);
}

//  Locations  /////////////////////////////////////////////////////////////////////////////////////

void discoveredLocation(int location) {
    currentLocation = location;
    for (int i = 0; i < 10; i++)
    {
        if (location == locations[i].locationID)
        {
            Sleep(2000);
            printf("-----------------------------------\n");
            printf("> You discovered [%s]\n", locations[i].locationName);
            printf("-----------------------------------\n");
            Sleep(2000);
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

//  Player HP & Damage Roll  ///////////////////////////////////////////////////////////////////////

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

    return bonusDMG + randomDmgRoll;
}

//  Player Actions in Combat  //////////////////////////////////////////////////////////////////////

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
        playerDamage(itemID, bonusDMG);
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

//  Decision Trees  ////////////////////////////////////////////////////////////////////////////////

void decision() {
    int q;
    Sleep(500);
    printf("> [Y/N]: ");
    scanf(" %c", &q);
    if (q == 'Y' || q == 'y')
    {
        result = 0;
    }
    else
    {
        result = 1;
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

// MONSTERS ////////////////////////////////////////////////////////////////////////////////////////

int monsterHP(int monsterDmgTaken) {
    monsterCurrentHP = monsterCurrentHP - monsterDmgTaken;

    Sleep(1000);
    printf("> Monster have taken: [%i] damage.\n", monsterDmgTaken);

    if (monsterCurrentHP <= 0)
    {
        monsterCurrentHP = 0;
        Sleep(1000);
        printf("-------------------\n");
        Sleep(200);
        printf("> [Enemy] defeated.\n");
        Sleep(200);
        printf("-------------------\n");
        Sleep(2000);
    }
    else
    {
        printf("> [Monster] current HP: [%i]\n", monsterCurrentHP);
    }
}