#ifndef globalStruct_H_
#define globalStruct_H_

//put your function headers here
//// STRUCTS /////////////////////////////////////////////////////////

// Locations - global
    // Location IDs = 200-210
extern int location;
extern int currentLocation;    // Used in decision trees to move between locations

struct location {
    int locationID;
    char *locationName;
    char *locationDescription;
};
    extern struct location locations[]; // #1

// Monster structs
struct monster {
    int monsterID;
    char* monsterName;
    char* monsterDescription;
    // required to initialize struct,
        // will have a random value added to it to calculate MonsterMaxHP
    int monsterBaseHP;
    char* monsterAttack1;
    int monsterAttack1minDMG;
    int monsterAttack1maxDMG;
    char* monsterAttack2;
    int monsterAttack2minDMG;
    int monsterAttack2maxDMG;
    // if threshold is triggered
    char* monsterAttack3;
    int monsterAttack3minDMG;
    int monsterAttack3maxDMG;
    // (if monsterCurrentHP <= monsterThreshold use special attack once and break;)
    int monsterThreshold;
};

extern struct monster monsters[]; // #2

// Spells
struct spell {
    int id;
    char* spellName;
    char* damageType;
    char* spellDescription;
    int spellMinDMG;
    int spellMaxDMG;
};
    extern struct spell spells[]; // #3

// Global item management

// id, itemName, type, additionalProperty, description, value1, value2
struct item {
    int id;
    char* itemName;
    // Specifies if weapon, armor, story, consumable
    char* type;
    // Stores properties like:
        // main hand weapon
        // off hand weapon
        // deals damage (for consumables)
        // heals for XYZ
        // damage type
    char* additionalProperty;
    // For weapons it will be used to specify damage type
    char* description;
    // for weapons: minimum damage && for armor: damage reduction
    int value1;
    // for weapons: maximum damage && for armor: bonus health
    int value2;
};
    extern struct item items[];
    extern struct item backpack[];
    extern struct item held[];

#endif