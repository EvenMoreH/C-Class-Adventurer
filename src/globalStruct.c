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
        // Base Items 1-9
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

       // Consumables 10-29
       {10, "Healing Potion", "Consumable", "Heals for 10 Health",
            "A small vial of crimson liquid that restores a portion of the drinker's health when consumed.",0, 0},
       {11, "Avalanche Rune", "Consumable", "Deals Damage",
            "An inscribed stone that, when activated, causes a cascade of ice and rock to crash down on foes.", 6, 13},
       {12, "Fireball Rune", "Consumable", "Deals Damage",
            "A rune that ignites a devastating explosion of flames upon activation, engulfing enemies in a fiery blast.", 12, 25},
       {13, "Magic Missile Rune", "Consumable", "Deals Damage",
            "A minor glyph that releases a barrage of homing energy projectiles targeting foes upon activation.", 4, 9},

        // Grimoires 30-39
       {30, "Scholar's Grimoire", "Weapon", "Main",
        "More advanced tome filled with spells, aiding the wielder in mastering basics of arcane arts.", 8, 9},
       {31, "Grimoire of Druidcraft", "Weapon", "Main",
            "A book brimming with natural spells and enchantments, allowing the user to harness the power of nature.", 3, 4},
       {32, "Grimoire of Wildfire", "Weapon", "Main",
            "A fiery tome containing powerful incantations that summon and control destructive flames.", 5, 6},

       // Weapons 40-59
       {40, "Longbow", "Weapon", "Main", "", 3, 11},
       {41, "Warhammer", "Weapon", "Main", "", 3, 11},
       {42, "Uller's Bow", "Weapon", "Main", "", 6, 15},
       {43, "Sword of Light", "Weapon", "Main", "", 6, 15},
       {44, "placeholder", "Weapon", "Main", "", 1, 8},
       {45, "placeholder", "Weapon", "Main", "", 1, 8},

       // Armors 60-79
        // value1 = damage reduction
        // value2 = bonus to HP MAX
       {60, "Studded Leather Armor", "Armor", "Armor", "", 2, 5},
       {61, "Steel Breastplate", "Armor", "Armor", "", 3, 3},
       {62, "Scholar's Robes", "Armor", "Armor", "", 0, 10},
       {63, "placeholder", "Armor", "Armor", "", 6, 15},
       {64, "placeholder", "Armor", "Armor", "", 6, 15},
       {65, "placeholder", "Armor", "Armor", "", 6, 15},

       // Story Items 80-99
       {80, "Stoneskull Key", "Story", "", "Required to open Stone Gates located at [Mountain Road]", 0, 0},
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
    // Main Spell - high RNG + high DMG
    // Off Spell - low RNG + low DMG
    struct spell spells[] = {
        {600, "", "", "", 0, 0},    // base empty spell slot
        // Base Grimoire
        {601, "Ice Lance", "Cold", "", 2, 11},
        {602, "Lightning Strike", "Lightning", "", 4, 5},
        // Grimoire of Druidcraft
        {603, "Acid Bomb", "Acid", "", 12, 25},
        {604, "Moonfire", "Radiant", "", 18, 7},
        // Grimoire of Wildlife
        {605, "Fireball", "Fire", "", 12, 25},
        {606, "Burning Hands", "Fire", "", 18, 7},
        // TBD
        {607, "Fire Bolt", "Fire", "", 5, 7},
        // Scholar's Grimoire
        {608, "Eldritch Blast", "Force", "", 4, 13},
        {609, "Magic Missiles", "Force", "", 4, 9},
        {610, "", "", "", 0, 0},
    };

// Global held items management
    // held IDs = 130-133
    struct item held[] = {
        {900, "", "", "", "", 0, 0},    // Main Weapon
        {901, "", "", "", "", 0, 0},    // Off hand weapon
        {902, "", "", "", "", 0, 0},    // Armor
        {903, "", "", "", "", 0, 0},    // TODO: Bigger Backpack
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