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
// Used in decision trees to move between locations
int currentLocation;

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
       {0, "", "", "", "", 0, 0},     // <- something to mimic empty slots
       {1, "Bow", "Weapon", "Piercing", "A finely crafted weapon for striking enemies from afar.", 1, 8},
       {2, "Shortsword", "Weapon", "Slashing", "A quick and versatile blade perfect for close combat.", 1, 6},
       {3, "Longsword", "Weapon", "Slashing", "A balanced weapon offering reach and power in every swing.", 1, 8},
       {4, "Shield",  "Weapon", "Bludgeoning", "A sturdy wooden barrier to block incoming attacks and protect its bearer.", 1, 6},
       {5, "Staff", "Weapon", "Bludgeoning", "A magical conduit for channeling spells and ancient powers.", 1, 6},
       {6, "Leather Armor", "Armor", "", "Lightweight armor offering decent protection and mobility.", 0, 0},
       {7, "Chain Mail", "Armor", "", "Interlocked metal rings providing strong defense against slashes.", 0, 0},
       {8, "Robes", "Armor", "", "Enchanted garments that enhance magical abilities and offer comfort.", 0, 0},

        // for Grimoirs value1/value2 damage represent equipped spell
       {9, "Grimoire", "Weapon", "Main", "A tome of arcane knowledge filled with powerful spells and secrets", 1, 2},

       // consumables
       {10, "Healing Potion", "Consumable", "Heals for 10 Health", "", 0, 0},
       {11, "Avalanche Rune", "Consumable", "Deals Damage", "", 6, 13},
       {42, "Fireball Rune", "Consumable", "Deals Damage", "", 12, 25},
       {43, "Magic Missile Rune", "Consumable", "Deals Damage", "", 4, 9},

        // special grimoires
       {14, "Scholar's Grimoire", "Weapon", "Main", "", 5, 6},
       {15, "Grimoire of Druidcraft", "Weapon", "Main", "", 3, 4},
       {16, "Grimoire of Wildfire", "Weapon", "Main", "", 7, 8},

       // Weapons
       {17, "Longbow", "Weapon", "Main", "", 3, 11},
       {18, "Warhammer", "Weapon", "Main", "", 3, 11},
       {19, "Uller's Bow", "Weapon", "Main", "", 6, 15},
       {20, "Sword of Light", "Weapon", "Main", "", 6, 15},
       {21, "placeholder", "Weapon", "Main", "", 1, 8},
       {22, "placeholder", "Weapon", "Main", "", 1, 8},

       // Armors
        // value1 = damage reduction
        // value2 = bonus to HP MAX
       {23, "Studded Leather Armor", "Armor", "Armor", "", 2, 5},
       {24, "Steel Breastplate", "Armor", "Armor", "", 3, 3},
       {25, "Scholar's Robes", "Armor", "Armor", "", 0, 10},
       {26, "placeholder", "Armor", "Armor", "", 6, 15},
       {27, "placeholder", "Armor", "Armor", "", 6, 15},
       {28, "placeholder", "Armor", "Armor", "", 6, 15},

       // story items:
       {99, "Stoneskull Key", "Story", "", "Required to open Stone Gates located at [Mountain Road]", 0, 0},
    };

    // Global backpack management
    // backpack IDs = 100-110
    struct item backpack[] = {
        {100, "", "", "", "", 0, 0},
        {101, "", "", "", "", 0, 0},
        {102, "", "", "", "", 0, 0},
        {103, "", "", "", "", 0, 0},
        {104, "", "", "", "", 0, 0},
        {105, "", "", "", "", 0, 0},
        {106, "", "", "", "", 0, 0},
        {107, "", "", "", "", 0, 0},
        {108, "", "", "", "", 0, 0},
        {109, "", "", "", "", 0, 0},
        {110, "", "", "", "", 0, 0},
    };

// Global Spells
    // spells IDs = 600-610
    struct spell spells[] = {
        {600, "", "", "", 0, 0},    // base empty spell slot
        {601, "Ice Lance", "", "Cold", 2, 11},              // base
        {602, "Lightning Strike", "", "Lightning", 4, 5},   // weaker but less RNG
        {603, "Acid Bomb", "", "Acid", 12, 13},
        {604, "Starburst", "", "Fire", 20, 21},
        {605, "Fireball", "", "", 12, 25},
        {606, "Burning Hands", "", "", 18, 7},
        {607, "Eldritch Blast", "", "", 4, 13},             // base
        {608, "Fire Bolt", "", "", 5, 7},                   // weaker but less RNG
        {609, "", "", "", 0, 0},
        {610, "", "", "", 0, 0},
    };

// Global held items management
    // held IDs = 130-133
    struct item held[] = {
        {130, "", "", "", "", 0, 0},    // Main Weapon
        {131, "", "", "", "", 0, 0},    // Off hand weapon
        {132, "", "", "", "", 0, 0},    // Armor
        {133, "", "", "", "", 0, 0},    // ??
    };

// Struct for future item replacement
    struct item temp[] = {
        {0, "", "", "", "", 0, 0},
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