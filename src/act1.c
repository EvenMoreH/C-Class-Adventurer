#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities

#include "../include/act1.h"

#include "../include/globalStruct.h"
#include "../include/globalVar.h"

#include "../include/decisions.h"
#include "../include/encounter.h"
#include "../include/equipment.h"
#include "../include/intro.h"
#include "../include/location.h"
#include "../include/monsters.h"
#include "../include/playerActions.h"


void actOne() {
    actOneVillage();
    actOneWoodcarversRoad();
    if (abResult == 1) // left
    {
        actOneVontelsRest();
    }
    else // right
    {
        actOneOasis();
    }
}
void actOneVillage() {
    // Act I - Moonlight Den and Village
    storyText("Lets dive in...");
    newLine(1);
    storyText("The moon hung low over the dense, ancient woods, casting an eerie glow through the twisted branches.");
    storyText("The air was thick with the scent of pine and damp earth, punctuated by the snarls of a ferocious wolf.");
    storyTextUnformatted("> In a small clearing, illuminated by slivers of moonlight,");
    storyTextToString(playerName);
    storyTextUnformatted("is facing off against the hungry beast.");
    newLine(1);

    pressC();

    lastLocation = "Moonlight Den";
    fullEncounter(4, false);   // 4 = Wolf intro fight

    pressC();

    if (campVisit == 1)
    {
        newLine(1);
        storyText("You hear a voice...");
        newLine(1);
        storyText("Someone was looking for you.");
    }
    else
    {
        newLine(1);
        storyText("You hear a voice...");
    }
    newLine(1);
    storyText("\"Help! Please, help!\" A young girl, her face pale with fear, burst into the clearing.");
    storyText("You see [Lila], a child from your village, her eyes wide with terror.");
    storyText("She stumbles, breathless and desperate, as she reaches your side.");
    storyText("\"The village... It's the [Hag]... Everyone has fallen asleep while the hunters were away!\"");
    storyText("\"No one will wake up, the [Hag] is gone... [Dane] is looking after the folk... Please! Help...\"");
    newLine(1);
    customText("A. Try to calm down the girl.", 1, 250);
    customText("B. Run straight to the [Village]", 1, 250);

    selectionAB();
    newLine(1);
    if (abResult == 1)
    {
        storyText("\"There, there [Lila]. Do not worry, we will figure this out, lets get back to the village.\"");
        storyText("Girl wipes her eyes, grabs your hand and together you walk towards the [Village].");
    }
    else
    {
        storyText("You grab crying [Lila] and run to the [Village] as fast as you can.");
    }

    pressC();

    enterLocation(200);
    lastLocation = "Village";

    storyText("As you step into the village, a haunting stillness blankets the air,");
    storyText("the frozen figures of its inhabitants suspended in time like statues of forgotten dreams.");
    storyText("Each person appears caught in a moment of daily life,");
    storyText("their expressions etched with surprise or weariness, as if sleep had claimed them where they stood.");

    pressC();

    storyText("As you reach [Dane], you can see the worry in his eyes.");
    storyText("He quickly fills you in on what happened while you were out in the [Moonlight Den].");
    storyText("[Dane] explains to you that the village has been struck by a powerful curse from the [Hag].");
    storyText("\"She had promised to help us with our crops in exchange for some of our livestock,");
    storyText("but she double-crossed us, she took the animals and cursed the whole village afterwards.\"");

    pressC();

    storyText("\"The only reason why me and [Lila] were not affected is because we were out tending to a sick cow at the time.\"");
    storyText("\"But now... I guess we are the only ones left to take care of the entire village.\"");
    newLine(1);
    storyText("You feel rising determination in your heart... You wont let your fiends and family suffer such fate!");
    newLine(1);
    storyText("\"Let's head over to the Hag's hut first. Maybe we'll find some clues there, or items that could help break the curse.\"");
    storyText("[Dane] instructed, looking at you.");
    storyTextUnformatted(">");
    storyTextToString(playerName);
    storyTextUnformatted("... You have to investigate, I'll stay here with [Lila] and keep them safe and comfortable.\"");
    newLine(1);
    storyText("[Dane] reassured you.");

    pressC();

    storyText("You gather any food and supplies that you can find in [Sleeping Village] and head towards [Gloomy Forest].");
    newLine(1);

    if (playerCurrentHP < playerMaxHP)
    {
        storyText("You manage to find some runes and potions, you drink a bit to heal your wounds, and you place the rest in your bag.");
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
        storyText("You manage to find some runes and potions, you put them in your bag.");
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
    storyText("As you leave, you look back and see [Dane] and [Lila] scavenge for food and blankets in the surrounding houses,");
    storyText("ensuring that each villager is snug and taken care of during their slumber.");

    pressC();
}

void actOneWoodcarversRoad() {
    // Act1 - Woodcarvers Road
    enterLocation(202); // Woodcarvers Road

    storyText("You took your time walking down the narrow dirt road that led from the village.");
    storyText("Traveling alone along the winding [Woodcarvers Road], you felt like a solitary figure in a vast painting of nature.");
    storyText("The road, flanked by imposing hills cloaked in thick forest, cast long shadows that seemed to stretch out towards you.");
    storyText("Towering trees stood sentinel on either side, their branches swaying gently in the breeze.");
    storyText("Sunlight filtered through the dense canopy above, creating a mesmerizing play of light and shadow on the path before you.");
    storyText("The earthy fragrance of damp soil mingled with the sharp scent of pine needles,");
    storyText("enveloping you in a comforting embrace as you ventured forth with cautious steps.");
    storyText("The only company you had were the rustling leaves underfoot and the occasional bird's call echoing through the woods.");
    storyText("These natural sounds added to the eerie ambiance, reminding you of your smallness");
    storyText("amidst the grandeur of the untamed wilderness that surrounded you.");

    pressC();

    storyText("After several long hours of trekking, your boots scuff against the worn roots at the base of [Starstruck Oak].");
    storyText("The branches above sway in a gentle breeze as you rack your brain,");
    storyText("trying to recall the safest route to [King's Thicket] - the last stop before [Gloomy Forest].");
    customText("Should you go: ", 10, 800);
    customText("A. Left, towards [Vontel's Rest]", 10, 300);
    customText("B. Right, towards [The Oasis]", 10, 300);

    selectionAB();
    newLine(1);
}
void actOneVontelsRest() {
    storyText("You follow path to the left, before dusk you should arrive at [Vontel's Rest]");

    loading(2.5);

    storyText("After a few hours of journey, you finally reach your destination,");
    enterLocation(206);

}
void actOneOasis() {
    storyText("You follow path to the right, before dusk you should arrive at [The Oasis]");

    loading(2.5);

    storyText("After a few hours of journey, you finally reach your destination,");

    enterLocation(207);

    storyText("A hidden spot deep in the woods with a crystal clear spring that is said to have magical healing powers.");
    storyText("It's surrounded by lush greenery and colorful flowers, creating a peaceful and tranquil atmosphere.");
    storyText("You take a deep breath and look for a spot to set up your camp for the night.");
    storyText("However something feels off...");

    pressC();

    storyText("The once crystal-clear water now appears murky and foreboding,");
    storyText("hinting at the presence of something sinister lurking within its depths.");
    storyText("Shadows dance beneath the surface, and a sense of unease settled over the area.");
    storyText("Whatever is living in the water had tainted its purity and cast an eerie aura over the surroundings.");
    storyText("The surface remains still and undisturbed, but there is a palpable tension in the air,");
    storyText("as if something is waiting just below the surface, ready to strike.");
    newLine(1);
    storyText("It is a stark contrast to the tranquil scene you have been observing while approaching from the distance.");

    pressC();

    customText("A. Do you approach the waters to investigate?", 10, 500);
    customText("B. You steer clear from the shore and continue setting up the camp.", 10, 500);

    selectionAB();
    newLine(1);

    if (abResult == 1) // Investigate the waters
    {
        // water investigation leading to easier encounter
    }
    else // camp setup and ambush from water monster
    {
        // you set up camp and ambush will happen
    }
}