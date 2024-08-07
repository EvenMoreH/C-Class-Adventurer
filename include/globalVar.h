#ifndef globalVar_H_
#define globalVar_H_

//put your function headers here

// Global variables
    extern int itemID;
    extern int spellID;
    extern int combatEnd;          // sets combat flag on/off
    extern char playerName[51];
    extern int daze;               // responsible for applying daze penalty to monsters
    extern int MGC;                // global for Magic stat for characters
    extern int lvl;
    extern int camping;        // sets flag if player would run to camp
    extern int campVisit;          // sets flag if player was at a camp
    extern char* lastLocation;     // pinter to string for manual control where combat had been placed
    extern int regenerated;    // sets flag if player regenerated in camp to not regenerate again after combat ends
    extern int s;

    extern char parsed[51];


    // selected character
        // 900 - Archer
        // 901 - Crusader
        // 902 - Sorcerer
    extern int currentChar;

    // for managing items that are held(equipped)
    extern int mainWeapon;
    extern int offWeapon;
    extern int equippedArmor;

    // for yes or no questions
    extern char q;
    extern int result;

    // for A or B decisions
    extern char ab;
    extern int abResult;

    // for A or B or C decisions
    extern char abc;
    extern int abcResult;

    // for dealing and receiving damage (player)
    extern int dmg;
    extern int bonusDMG;
    extern int bonusDMGspell;
    extern int playerDmgTaken;     // NEW
    extern int playerDmgTakenLog;  // log testing to skip dmg logs if dmg = 0
    extern int SelectedSpellMinDMG;
    extern int SelectedSpellMaxDMG;

    // for declaring initial MAX HP and calculating current HP (player)
    extern int playerMaxHP;
    extern int playerCurrentHP;
    extern int globalResistance;

    // NEW: monster HP & DMG
    extern int monsterID;
    extern int monsterCurrentHP;
    extern int monsterAmbushHP;
    extern int monsterDmgDone;     // NEW
    extern int monsterDmgTaken;    // NEW
    // NEW  // required for monster to only use special attack once
    extern int specialMonsterAttack;
    // NEW  // required for monster Run check
    extern char* monsterRun;
    extern int monsterDmgTakenLog;   // log testing to skip dmg logs if dmg = 0

    // ITEM Shortcuts
    extern int potion;

void randomize();

//  Clear Buffer  ////////////////////////////////////////////////////

void clearBuffer();

void pressC();

void formattedText(char* printout);

void customText(char* printout, int sleepBefore, int sleepAfter);

void newLine (int lines);

void storyText(char textToWrite[]);

void storyTextUnformatted(char textToWrite[]);

void parser(char string[]);

void storyTextToString(char variableToParse[]);

void idFinder(int itemID);

int potionScaling(int lvl);
#endif