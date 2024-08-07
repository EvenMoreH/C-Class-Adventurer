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


// Struct for item replacement
    struct item temp[] = {
        {0, "", "", "", "", 0, 0},
        {1, "", "", "", "", 0, 0},  // for equipment tiers
    };

// item IDs = 0-99
    //damage explained: 1k8 is: [1 + rand % 7] thus {1, 7} in a struct.
        // damage range 17-32 is: [17 + rand % 15] as it generates random number from 0-15 and adds 17 on top of it.
    struct item items[] = {
        // Base Items 1-9
       {0, "", "", "", "", 0, 0},     // <- something to mimic empty slots
       {1, "Bow", "Weapon", "Main", "A finely crafted weapon for striking enemies from afar", 1, 8},
       {2, "Shortsword", "Weapon", "Off", "A quick and versatile blade perfect for close combat", 1, 6},
       {3, "Longsword", "Weapon", "Main", "A balanced weapon offering reach and power in every swing", 1, 8},
       {4, "Shield",  "Weapon", "Off", "A sturdy wooden barrier to block incoming attacks and protect its bearer", 1, 6},
       {5, "Staff", "Weapon", "Off", "A magical conduit for channeling spells and ancient powers", 1, 6},
       {6, "Leather Armor", "Armor", "", "Lightweight armor offering decent protection and mobility", 0, 0},
       {7, "Chain Mail", "Armor", "", "Interlocked metal rings providing strong defense against slashes", 0, 0},
       {8, "Robes", "Armor", "", "Enchanted garments that enhance magical abilities and offer comfort", 0, 0},
        // for Grimoirs value1/value2 damage represent equipped spell
       {9, "Grimoire", "Weapon", "Main", "A tome of arcane knowledge filled with powerful spells and secrets", 1, 2},

       // Consumables 10-29
       {10, "Healing Potion", "Consumable", "Heals",
            "A small vial of crimson liquid that restores a portion of the drinker's health when consumed",0, 0},
       {11, "Avalanche Rune", "Consumable", "Deals Damage",
            "An inscribed stone that, when activated, causes a cascade of ice and rock to crash down on foes", 6, 13},
       {12, "Fireball Rune", "Consumable", "Deals Damage",
            "A rune that ignites a devastating explosion of flames upon activation, engulfing enemies in a fiery blast", 12, 25},
       {13, "Magic Missile Rune", "Consumable", "Deals Damage",
            "A minor glyph that releases a barrage of homing energy projectiles targeting foes upon activation", 4, 9},

        // Grimoires 30-39
       {30, "Scholar's Grimoire", "Weapon", "Main",
        "More advanced tome filled with spells, aiding the wielder in mastering basics of arcane arts", 8, 9},
       {31, "Grimoire of Druidcraft", "Weapon", "Main",
            "A book brimming with ancient spells and enchantments, allowing the user to harness the power of nature", 3, 4},
       {32, "Grimoire of Wildfire", "Weapon", "Main",
            "A fiery tome containing powerful incantations that summon and control destructive flames", 5, 6},

       // Weapons 40-59
       {40, "Longbow", "Weapon", "Main",
            "A tall, powerful bow designed for precise, long-range combat", 3, 11},
       {41, "Warhammer", "Weapon", "Main",
            "A heavy, versatile hammer with a massive head, ideal for crushing armor and bones in battle", 3, 11},
       {42, "Uller's Bow", "Weapon", "Main", "", 6, 15},    // WIP
       {43, "Sword of Light", "Weapon", "Main", "", 6, 15}, // WIP
       {44, "placeholder", "Weapon", "Off", "", 1, 8}, // WIP
       {45, "placeholder", "Weapon", "Main", "", 1, 8}, // WIP

       // Armors 60-79
        // value1 = damage reduction
        // value2 = bonus to HP MAX
       {60, "Studded Leather Armor", "Armor", "Armor",
            "Flexible leather armor reinforced with metal studs, offering a balance of mobility and protection", 2, 5},
       {61, "Steel Breastplate", "Armor", "Armor",
            "A solid steel chest piece that provides excellent defense against physical attacks", 3, 3},
       {62, "Scholar's Robes", "Armor", "Armor",
            "Elegant and flowing robes imbued with minor enchantments, favored by mages and intellectuals", 0, 10},
       {63, "placeholder", "Armor", "Armor", "", 6, 15},    // WIP
       {64, "placeholder", "Armor", "Armor", "", 6, 15},    // WIP
       {65, "placeholder", "Armor", "Armor", "", 6, 15},    // WIP

       // Story Items 80-99
       {80, "Stoneskull Key", "Story", "Key", "Required to open Stone Gates located at [Mountain Road]", 0, 0}, // Key Example
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

// for calling functions
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

// monsterIDs = 400 - 499
    struct monster monsters[] = {
        {400, "", "", 0, "", 0, 0, "", 0, 0, "", 0, 0, 0}, // empty monster to initialize the list
        {401, "Giant Rat", "", 18, "Bite", 2, 6, "Scratch", 2, 4, "Run", 0, 0, 5},
        {402, "Goblin", "", 28, "Knife", 2, 4, "Kick", 1, 3, "", 0, 0, 0},
        {403, "Hobgoblin", "", 48, "Greatclub", 6, 8, "Headbutt", 4, 6, "Skullcrsher", 12, 12, 10},
        {404, "Wolf", "", 15, "Claw", 1, 5, "Bite", 2, 7, "Run", 0, 0, 5},
        {405, "", "", 0, "", 0, 0, "", 0, 0, "", 0, 0, 0},
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
    // held IDs = 900-910
    struct item held[] = {
        {900, "", "", "", "", 0, 0},    // Main Weapon
        {901, "", "", "", "", 0, 0},    // Off hand weapon
        {902, "", "", "", "", 0, 0},    // Armor
        {903, "", "", "", "", 0, 0},    // TODO: Bigger Backpack
        // Space for rings and amulets etc.
    };