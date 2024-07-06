#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <windows.h>    // Unlocks windows functionalities


int main() {            // Main function
    // Locations rework needed
    // Running away rework
        // when running away, player should run back to town
        // when leaving town player should choose from which point the journey should continue
        // Locations have to be mapped out to see what connects to what
        // Flags "LocationXYZ complete = 1/0" must be created to keep tabs to which locations it is not worth to go back
            // If location complete, message: "Nothing new in this location awaits you adventurer, you move along"
        // Flags tied to "locationDiscovered" will be needed, so it can only show list of available locations
            // Set of flags "LocationXYZ discovered = 1/0"

    // Progress tracking
        // Location IDs = 200-210
        // locationID/name and 3 levels of completeness
        // queries on progress[].progress3
            // if progress[].progress3 == 1 location complete
    struct prog {
        int locationID;
        char* locationName;
        int progress;   // 0, 1, 2, 3
    };

    struct prog progress[] = {
        {200, "Town", 0}, // 0
        {200, "Town", 1}, // 1
        {200, "Town", 2}, // 2
        {200, "Town", 3}, // 3
        {201, "Forest", 0}, // 4 - Forest 0%
        {201, "Forest", 1}, // 5 - Forest 33%
        {201, "Forest", 2}, // 6 - Forest 66%
        {201, "Forest", 3}, // 7 - Forest complete
    };

    struct prog currentProgress[] = {
        {200, "", 0},
    };

    currentProgress[0] = progress[7];

    switch (currentProgress[0].progress)
    {
    case  0:
        printf("> You enter the Forest.\n");
        goto town;
        break;
    case  1:
        printf("> Pack of wolfs ambush you.\n");
        break;
    case  2:
        printf("> You enter the bear cave.\n");
        break;
    case  3:
        printf("> You leave the Forest.\n");
        goto forest;
        break;
    }

forest:
    for (int i = 0; i < 2; i++)
    {
        printf("I'm in a forest\n");
    }

town:
    for (int i = 0; i < 2; i++)
    {
        printf("I'm in a town\n");
    }

    return 0;               // Ends main function
}