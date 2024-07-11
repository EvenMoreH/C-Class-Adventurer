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
    pressC();
    chooseCharacter();
    printCharacterSheet(currentChar);
    pressC();

    playerCurrentHP = 27;    // testing
    equipItem(17);           // testing
    equipItem(23);           // testing

// Act I - Sleeping Curse
    printf("> Lets dive in...\n\n");
    Sleep(1000);

    printf("> The moon hung low over the dense, ancient woods, casting an eerie glow through the twisted branches.\n");
    Sleep(1000);
    printf("> The air was thick with the scent of pine and damp earth, punctuated by the snarls of a ferocious wolf.\n");
    Sleep(1000);
    printf("> In a small clearing, illuminated by slivers of moonlight, [%s] is facing off against the snarling beast.\n", name);
    Sleep(1000);

    pressC();

    lastLocation = "Moonlight Den";
    encounter(1);   // 4 = Wolf intro fight
    fromCamp();     // Always in pair with encounter

    pressC();

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
    printf("> \"No one will wake up, the [Hag] is gone... [Dane] is looking after the folk... Please! Help...\"\n\n");
    Sleep(1000);

    printf("> A. Try to calm down the girl.\n");
    Sleep(250);
    printf("> B. Run straight to the [Village]\n");
    Sleep(250);

    selectionAB();
    printf("\n");
    if (abResult == 1)
    {
        printf("> \"There, there [Lila]. Do not worry, we will figure this out, lets get back to the village.\"\n");
        Sleep(1000);
        printf("> Girl wipes her eyes, grabs your hand and together you walk towards the [Village]\n");
        Sleep(1000);
    }
    else
    {
        printf("> You grab crying [Lila] and run to the [Village] as fast as you can.\n");
        Sleep(1000);
    }

    pressC();

    enterLocation(200);
    lastLocation = "Village";

    printf("> As you step into the village, a haunting stillness blankets the air,\n");
    Sleep(1000);
    printf("  the frozen figures of its inhabitants suspended in time like statues of forgotten dreams.\n");
    Sleep(1000);
    printf("> Each person appears caught in a moment of daily life,\n");
    Sleep(1000);
    printf("  their expressions etched with surprise or weariness,\n");
    Sleep(1000);
    printf("  as if sleep had claimed them where they stood.\n");
    Sleep(1000);

    pressC();

    printf("> As you reach Dane, you can see the worry in his eyes.\n");
    Sleep(1000);
    printf("> He quickly fills you in on what happened while you were out in the [Moonlight Den].\n");
    Sleep(1000);
    printf("> Dane explains to you that the village has been struck by a powerful curse from the Hag.\n\n");
    Sleep(1000);
    printf("> \"She had promised to help us with our crops in exchange for some of our livestock,\n");
    Sleep(1000);
    printf("  but she double-crossed us, she took the animals and cursed the whole village afterwards.\"\n");
    Sleep(1000);

    pressC();

    printf("> \"The only reason why me and Lila were not affected is because we were out tending to a sick cow at the time.\"\n");
    Sleep(1000);
    printf("> \"But now... I guess we are the only ones left to take care of the entire village.\"\n");
    Sleep(1000);
    printf("\n> You feel rising determination in your heart, you wont let your fiends and family suffer such fate!\n");
    Sleep(1000);
    printf("\n> \"Let's head over to the Hag's hut first. Maybe we'll find some clues there, or items that could help break the curse.\"\n");
    Sleep(1000);
    printf("  Dane instructed, looking at you.\n\n");
    Sleep(1000);
    printf("> \"[%s]... You have to investigate, I'll stay here with Lila and keep them safe and comfortable.\"\n", name);
    Sleep(1000);
    printf("  Dane reassured you.\n");
    Sleep(1000);

    pressC();

    printf("> You gather any food and supplies that you can find in [Sleeping Village] and head towards [Gloomy Forest].\n\n");
    Sleep(500);

    if (playerCurrentHP < playerMaxHP)
    {
        Sleep(500);
        printf("> You manage to find some runes and potions, you drink a bit to heal your wounds, and you place the rest in your bag\n");
        Sleep(250);
        addToBag(potion);
        Sleep(250);
        addToBag(potion);
        Sleep(250);
        addToBag(13);
        Sleep(250);
        addToBag(13);
        Sleep(250);
        whatsInTheBag();
        Sleep(250);
        playerCurrentHP = playerMaxHP;
    }
    else
    {
        Sleep(500);
        printf("> You manage to find some runes and potions, you put them in your bag\n");
        Sleep(250);
        addToBag(potion);
        Sleep(250);
        addToBag(potion);
        Sleep(250);
        addToBag(potion);
        Sleep(250);
        addToBag(14);
        Sleep(250);
        addToBag(14);
        Sleep(250);
        whatsInTheBag();
        Sleep(250);
    }

    lastLocation = "Woodcarvers Road";

    printf("\n> As you leave you look back and see Dane and Lila scavenge for food and blankets in the surrounding houses,\n");
    Sleep(1000);
    printf("  ensuring that each villager is snug and taken care of during their slumber.\n");
    Sleep(1000);

    pressC();

    enterLocation(202);

////////////////////////////////////////////
    printf("\n> EOF\n");
    Sleep(30000);

    return 0;               // Ends main function
}