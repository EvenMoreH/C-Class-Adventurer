#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

void intro();           // outputs welcome screen
void loading(int s);    // loading bar
void currentLocation(int location);
    // location as a global variable
        // location 0 - road into mountains
        // location 1 - tomb of the forsaken
        // location 2 - mountain pass
void archerSheet();
void crusaderSheet();
void sorcererSheet();

void combatStarts();


int main() {            // Main function


    return 0;               // Ends main function
}
// Code for functions:

void intro() {
    for (int intro = 0; intro < 1; intro++)
    {
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
        Sleep(300);
    }
}

void loading(int s) {
    int ms = s * 100;
    printf("\n> Loading: [");
    for (int i = 0; i < 10; i++)
    {
        printf("+");
        Sleep(ms);
    }
    printf("]\n");
}

void currentLocation(int location) {
    if (location == 1)
    {
        printf("---------------------------\n");
        printf("|                         |\n");
        printf("|        You Enter        |\n");
        printf("|                         |\n");
        printf("|  Tomb of the Forsaken   |\n");
        printf("|                         |\n");
        printf("---------------------------\n");
    }
    if (location == 2)
    {
        printf("---------------------------\n");
        printf("|                         |\n");
        printf("|        You Enter        |\n");
        printf("|                         |\n");
        printf("|      Mountain Pass      |\n");
        printf("|                         |\n");
        printf("---------------------------\n");
    }   
}

void archerSheet() {
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

void currentLocation(int location) {
    if (location == 1)
    {
        printf("---------------------------\n");
        printf("|                         |\n");
        printf("|        You Enter        |\n");
        printf("|                         |\n");
        printf("|  Tomb of the Forsaken   |\n");
        printf("|                         |\n");
        printf("---------------------------\n");
    }
    if (location == 2)
    {
        printf("---------------------------\n");
        printf("|                         |\n");
        printf("|        You Enter        |\n");
        printf("|                         |\n");
        printf("|      Mountain Pass      |\n");
        printf("|                         |\n");
        printf("---------------------------\n");
    }   
}

void combatStarts() {
    printf("---------------------------\n");
    printf("|                         |\n");
    printf("|          Fight!         |\n");
    printf("|                         |\n");
    printf("|        Round One        |\n");
    printf("|                         |\n");
    printf("---------------------------\n");
}
