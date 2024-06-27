#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

int q;
int result;
int abResult;
int ab;
int abcResult;
int abc;
int dmg;
int dmgTaken;
int playerMaxHP;
int playerCurrentHP;


void selectionAB();
void selectionABC();

void decision();

int hp(int dmgTaken);
int playerMaxHealth(int VIT, int classHPX);

// Commented out all things related to damage done as backpack management is not initialized in this file and i can't use min/max dmg 
// int damage(int itemID);


int main() {            // Main function

    srand(time(NULL));

    playerMaxHealth(7, 12);
    printf("MAX HP: [%i].\n", playerMaxHP);

    printf("> Goblin ambushes you!\n");
    Sleep(1000);

    printf("> Will you run? [A] or fight? [B]\n");
    Sleep(1000);

    selectionAB();

    if (abResult == 0)
    {
        Sleep(1000);
        printf("> You run for your life, goblin grazes yours skin with rusty knife but you manage to escape.\n");

        dmgTaken = 51;
        hp(dmgTaken);

    }
    else
    {
        Sleep(1000);
        printf("> Combat starts!\n");
        Sleep(1000);
        printf("> What will you do?\n");
        Sleep(1000);
        printf("> A. Attack\n> B. Use spell\n> C. Retreat\n");

        selectionABC();

        if (abcResult == 0)
        {
            Sleep(1000);
            printf("> You shoot with your [Bow].\n");
            Sleep(1000);
            
            // dmg = damage(2);
            // printf("> You deal %d damage!\n", dmg);

        }
        if (abcResult == 1)
        {
            Sleep(1000);
            printf("> You cast: [Fire Bolt].\n");
        }
        if (abcResult == 2)
        {
            Sleep(1000);
            printf("> You retreat to safety.\n");
        }        
    }


    return 0;               // Ends main function
}

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

        // Clear the input buffer
        int clearBuffer;
        while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
        // I don't get the above yet but:
        // The while loop with getchar() reads and discards characters until it encounters a newline ('\n') or end-of-file (EOF), effectively clearing the buffer.
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

        // Clear the input buffer
        int clearBuffer;
        while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) { }
        // I don't get the above yet but:
        // The while loop with getchar() reads and discards characters until it encounters a newline ('\n') or end-of-file (EOF), effectively clearing the buffer.
        }
    }
}

// int damage(int itemID) {
//     int x = items[itemID].minDMG;
//     int y = items[itemID].maxDMG;

//     return x + rand() % y;
// }

int hp(int dmgTaken) {
    playerCurrentHP = playerMaxHP - dmgTaken;

    Sleep(1000);
    printf("> You have taken: [%i] damage.\n", dmgTaken);

    if (playerCurrentHP < 0)
    {
        playerCurrentHP = 0;
        Sleep(1000);
        printf("----------------------------------------\n");
        Sleep(500);
        printf("> You have died. You journey ends here.\n");
        Sleep(500);
        printf("----------------------------------------\n");
        Sleep(2000);
    }
    else
    {
        printf("> Your current HP: [%i]", playerCurrentHP);
    }
}

// character sheet when printed sets stats like VIT and sets classHPX
int playerMaxHealth(int VIT, int classHPX) {
    playerMaxHP = VIT * classHPX;
    return playerMaxHP;
}