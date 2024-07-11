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
    char locationName[40];
    char locationDescription[200];
};
    extern struct location locations[];

// Global item management
struct item {
    int id;
    char* iname;
    // char iname[25];
    char* description;  // For weapons it will be used to specify damage type
    // char description[100];  // For weapons it will be used to specify damage type
    int minDMG;
    int maxDMG;
};
    extern struct item items[];
    extern struct item backpack[];
    extern struct item spells[];
    extern struct item held[];

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

    extern struct monster monsters[];

#endif