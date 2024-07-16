#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


#include "../include/globalStruct.h"
#include "../include/globalVar.h"


//// STRUCTS /////////////////////////////////////////////////////////

int location;
int currentLocation;    // Used in decision trees to move between locations

// Locations - global
    // Location IDs = 200-210

    struct location locations[] = {
       {200, "Village", ""},
       {201, "Moonlight Den", ""},
       {202, "Woodcarvers Road", ""},
       {203, "Mountain Pass", ""},
       {204, "Mines", ""},
       {205, "Graveyard", ""},
       {206, "Vontel's Rest", ""},
       {207, "The Oasis", ""},
    };

    // item IDs = 0-99
    //damage explained: 1k8 is rand % 7 + 1 thus {1, 7} in a struct
    struct item items[] = {
       {0, "", "", 0, 0},     // <- something to mimic empty slots
       {1, "Bow", "Piercing", 1, 8},            // base item do not alter (Archer)
       {2, "Shortsword", "Slashing", 1, 6},     // base item do not alter (Archer)
       {3, "Longsword", "Slashing", 1, 8},      // base item do not alter (Crusader)
       {4, "Shield", "Bludgeoning", 1, 6},      // base item do not alter (Crusader)
       {5, "Staff", "Bludgeoning", 1, 6},       // base item do not alter (Sorcerer)
       {6, "Leather Armor", "", 0, 0},          // base item do not alter (Archer)
       {7, "Chain Mail", "", 0, 0},             // base item do not alter (Crusader)
       {8, "Robes", "", 0, 0},                  // base item do not alter (Sorcerer)

        // for grimoirs min/max damage represent equipped spell
            // 1 = Ice Lance
            // 2 = Lightning Strike
            // 3 = Acid Bomb
            // 4 = Starburst
            // 5 - Eldritch Blast
            // 6 - Fire Bolt
       {9, "Grimoire", "", 1, 2},                // base item do not alter (Sorcerer)

       // consumables
       {10, "Healing Potion", "Heals for 10 Health", 0, 0},
       {11, "Avalanche Rune", "Deals Damage", 6, 13},
       {12, "Fireball Rune", "Deals Damage", 12, 25},
       {13, "Magic Missile Rune", "Deals Damage", 4, 9},

        // special grimoires
       {14, "Scholar's Grimoire", "Main", 5, 6},
       {15, "Grimoire of Druidcraft", "Main", 3, 4},
       {16, "Grimoire of Wildfire", "Main", 7, 8},

       // Weapons
       {17, "Longbow", "Main", 3, 11},
       {18, "Warhammer", "Main", 3, 11},
       {19, "Uller's Bow", "Main", 6, 15},
       {20, "Sword of Light", "Main", 6, 15},
       {21, "placeholder", "Main", 1, 8},
       {22, "placeholder", "Main", 1, 8},

       // Armors
        // minDMG = damage reduction
        // maxDMG = bonus to HP MAX
       {23, "Studded Leather Armor", "Armor", 2, 5},
       {24, "Steel Breastplate", "Armor", 3, 3},
       {25, "Scholar's Robes", "Armor", 0, 10},
       {26, "placeholder", "Armor", 6, 15},
       {27, "placeholder", "Armor", 6, 15},
       {28, "placeholder", "Armor", 6, 15},

       // story items:
       {29, "Stoneskull Key", "Required to open Stone Gates located at [Mountain Road]", 0, 0},
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

// Global Spells
    // backpack IDs = 400-410
    struct item spells[] = {
        {400, "", "", 0, 0},    // base empty spell slot
        {401, "Ice Lance", "Cold", 2, 11},              // base
        {402, "Lightning Strike", "Lightning", 4, 5},   // weaker but less RNG
        {403, "Acid Bomb", "Acid", 12, 13},
        {404, "Starburst", "Fire", 20, 21},
        {405, "Fireball", "", 12, 25},
        {406, "Burning Hands", "", 18, 7},
        {407, "Eldritch Blast", "", 4, 13},             // base
        {408, "Fire Bolt", "", 5, 7},                   // weaker but less RNG
        {409, "", "", 0, 0},
        {410, "", "", 0, 0},
    };

// Global held items management
    // held IDs = 130-133
    struct item held[] = {
        {130, "", "", 0, 0},    // Main Weapon
        {131, "", "", 0, 0},    // Off hand weapon
        {132, "", "", 0, 0},    // Armor
        {133, "", "", 0, 0},    // ??
    };

    // monsterIDs = 400 - 499
    struct monster monsters[] = {
        {400, "", "", 0, "", 0, 0, "", 0, 0, "", 0, 0, 0}, // empty monster to initialize the list
        {401, "Giant Rat", "", 18, "Bite", 2, 6, "Scratch", 2, 4, "Run", 0, 0, 5},
        {402, "Goblin", "", 28, "Knife", 2, 4, "Kick", 1, 3, "", 0, 0, 0},
        {403, "Hobgoblin", "", 48, "Greatclub", 6, 8, "Headbutt", 4, 6, "Skullcrsher", 12, 12, 10},
        {404, "Wolf", "", 15, "Claw", 1, 5, "Bite", 2, 7, "Run", 0, 0, 5},
        {405, "", "", 0, "", 0, 0, "", 0, 0, "", 0, 0, 0},
    };