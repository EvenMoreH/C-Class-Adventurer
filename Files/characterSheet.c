#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

// level 1 - 5
// stats 1 - 9
// stat sum = 18

void archerSheet();
void crusaderSheet();
void sorcererSheet();


int main() {            // Main function

    printf("> This is you: \n");
    archerSheet();

    Sleep(60000);
    return 0;               // Ends main function
}

void archerSheet() {
    int lvl = 1;
    int STR = 5;
    int DEX = 7;
    int VIT = 5;
    int MGC = 1;
    int classHPX = 10;

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
    printf("|     - Dagger            |\n");
    printf("|     - Leather Armor     |\n");
    printf("|     - Backpack          |\n");
    printf("---------------------------\n");
}
void crusaderSheet() {
    int lvl = 1;
    int STR = 5;
    int DEX = 7;
    int VIT = 5;
    int MGC = 1;
    int classHPX = 12;

    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Level: [1]        |\n");
    printf("|  Your Class: [Crusader] |\n");
    printf("|  Your Statistics:       |\n");
    printf("|     - Strength: [7]     |\n");
    printf("|     - Dexterity: [3]    |\n");
    printf("|     - Vitality: [7]     |\n");
    printf("|     - Magic: [1]        |\n");
    printf("---------------------------\n");
    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Equipment:        |\n");
    printf("|     - Flail             |\n");
    printf("|     - Shield            |\n");
    printf("|     - Plate   Armor     |\n");
    printf("|     - Backpack          |\n");
    printf("---------------------------\n");
}
void sorcererSheet() {
    int lvl = 1;
    int STR = 5;
    int DEX = 7;
    int VIT = 5;
    int MGC = 1;
    int classHPX = 8;

    Sleep(500);
    printf("---------------------------\n");
    printf("|  Your Level: [1]        |\n");
    printf("|  Your Class: [Sorcerer] |\n");
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
}
