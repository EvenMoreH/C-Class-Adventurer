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

#include "../include/decisions.h"
#include "../include/encounter.h"
#include "../include/equipment.h"
#include "../include/intro.h"
#include "../include/location.h"
#include "../include/monsters.h"
#include "../include/playerActions.h"


int main() {
    randomize();

    intro();
    skip();
    chooseCharacter();
    printCharacterSheet(currentChar);

// Act I - Sleeping Curse
    printf("> Lets dive in...\n\n");
    Sleep(1000);

    printf("> The moon hung low over the dense, ancient woods, casting an eerie glow through the twisted branches.\n");
    Sleep(1000);
    printf("> The air was thick with the scent of pine and damp earth, punctuated by the snarls of a ferocious wolf.\n");
    Sleep(1000);
    printf("> In a small clearing, illuminated by slivers of moonlight, [%s] is facing off against the snarling beast.\n", name);
    Sleep(1000);

    skip();

    lastLocation = "Moonlight Den";
    encounter(4);   // Wolf intro fight
    fromCamp();     // Always in pair with encounter

    skip();

    if (campVisit == 1)
    {
        printf("\n> You hear a voice...\n");
        Sleep(1000);
        printf("\n> Someone was looking for you.\n");
    }
    else
    {
        printf("\n> You hear a voice...\n");
    }
    Sleep(1000);
    printf("\n> \"Help! Please, help!\" A young girl, her face pale with fear, burst into the clearing.\n");
    Sleep(1000);
    printf("> You see [Lila], a child from your village, her eyes wide with terror.\n");
    Sleep(1000);
    printf("> She stumbles, breathless and desperate, as she reaches your side.\n");
    Sleep(1000);
    printf("> \"The village... It's the [Hag]... Everyone has fallen asleep while the hunters were away!\"\n");
    Sleep(1000);
    printf("> \"No one will wake up, the [Hag] is gone... [Dane] is looking after the folk...\"\n\n");
    Sleep(1000);

    printf("> A. Try to calm down the girl.\n");
    Sleep(250);
    printf("> B. Run straight to the [Village]\n");
    Sleep(250);

    selectionAB();
    printf("\n");
    if (abResult == 1)
    {
        printf("> There, there [Lila]. Do not worry, we will figure this out, lets get back to the village.\n");
        Sleep(1000);
        printf("> Girl wipes her eyes, grabs your hand and together you walk towards the [Village]\n");
        Sleep(1000);
    }
    else
    {
        printf("> You grab crying [Lila] and run to the [Village] as fast as you can.\n");
        Sleep(1000);
    }

    skip();

    enterLocation(200);
    lastLocation = "Village";

////////////////////////////////////////////
    printf("\n> EOF\n");
    Sleep(30000);

    return 0;               // Ends main function
}