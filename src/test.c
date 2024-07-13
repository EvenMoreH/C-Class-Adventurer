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

    // playerCurrentHP = 27;    // testing
    // equipItem(17);           // testing
    // equipItem(23);           // testing

// Act I - Sleeping Curse
    formattedText("Lets dive in...");
    newLine(1);
    formattedText("The moon hung low over the dense, ancient woods, casting an eerie glow through the twisted branches.");
    formattedText("The air was thick with the scent of pine and damp earth, punctuated by the snarls of a ferocious wolf.");

    printf("> In a small clearing, illuminated by slivers of moonlight, [%s] is facing off against the snarling beast.\n", name);
    Sleep(1000);

    pressC();

    lastLocation = "Moonlight Den";
    encounter(4);   // 4 = Wolf intro fight
    fromCamp();     // Always in pair with encounter

    pressC();

    if (campVisit == 1)
    {
        newLine(1);
        formattedText("You hear a voice...");
        newLine(1);
        formattedText("Someone was looking for you.");
    }
    else
    {
        newLine(1);
        formattedText("You hear a voice...");
    }
    newLine(1);
    formattedText("\"Help! Please, help!\" A young girl, her face pale with fear, burst into the clearing.");
    formattedText("You see [Lila], a child from your village, her eyes wide with terror.");
    formattedText("She stumbles, breathless and desperate, as she reaches your side.");
    formattedText("\"The village... It's the [Hag]... Everyone has fallen asleep while the hunters were away!\"");
    formattedText("\"No one will wake up, the [Hag] is gone... [Dane] is looking after the folk... Please! Help...\"");
    newLine(1);

    // printf("> A. Try to calm down the girl.\n");
    // Sleep(250);
    // printf("> B. Run straight to the [Village]\n");
    // Sleep(250);

    customText("A. Try to calm down the girl.", 1, 250);
    customText("B. Run straight to the [Village]", 1, 250);

    selectionAB();
    newLine(1);
    if (abResult == 1)
    {
        formattedText("\"There, there [Lila]. Do not worry, we will figure this out, lets get back to the village.\"");
        formattedText("Girl wipes her eyes, grabs your hand and together you walk towards the [Village].");
    }
    else
    {
        formattedText("You grab crying [Lila] and run to the [Village] as fast as you can.");
    }

    pressC();

    enterLocation(200);
    lastLocation = "Village";

    formattedText("As you step into the village, a haunting stillness blankets the air,");
    formattedText("the frozen figures of its inhabitants suspended in time like statues of forgotten dreams.");
    formattedText("Each person appears caught in a moment of daily life,");
    formattedText("their expressions etched with surprise or weariness, as if sleep had claimed them where they stood.");

    pressC();

    formattedText("As you reach Dane, you can see the worry in his eyes.");
    formattedText("He quickly fills you in on what happened while you were out in the [Moonlight Den].");
    formattedText("Dane explains to you that the village has been struck by a powerful curse from the Hag.");
    formattedText("\"She had promised to help us with our crops in exchange for some of our livestock,");
    formattedText("but she double-crossed us, she took the animals and cursed the whole village afterwards.\"");

    pressC();

    formattedText("\"The only reason why me and Lila were not affected is because we were out tending to a sick cow at the time.\"");
    formattedText("\"But now... I guess we are the only ones left to take care of the entire village.\"");
    newLine(1);
    formattedText("You feel rising determination in your heart, you wont let your fiends and family suffer such fate!");
    newLine(1);
    formattedText("\"Let's head over to the Hag's hut first. Maybe we'll find some clues there, or items that could help break the curse.\"");
    formattedText("Dane instructed, looking at you.");
    printf("> \"[%s]... You have to investigate, I'll stay here with Lila and keep them safe and comfortable.\"\n", name);
    Sleep(1000);
    formattedText("Dane reassured you.");

    pressC();

    formattedText("You gather any food and supplies that you can find in [Sleeping Village] and head towards [Gloomy Forest].");
    newLine(1);

    if (playerCurrentHP < playerMaxHP)
    {
        formattedText("You manage to find some runes and potions, you drink a bit to heal your wounds, and you place the rest in your bag.");
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
        formattedText("You manage to find some runes and potions, you put them in your bag.");
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

    newLine(1);
    formattedText("As you leave, you look back and see Dane and Lila scavenge for food and blankets in the surrounding houses,");
    formattedText("ensuring that each villager is snug and taken care of during their slumber.");

    pressC();

    enterLocation(202); // Woodcarvers Road

////////////////////////////////////////////
    printf("\n> EOF\n");
    Sleep(30000);

    return 0;               // Ends main function
}