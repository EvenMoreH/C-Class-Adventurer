#include <time.h>       // Copilot links it as required for randomizers
#include <stdlib.h>     // StackOverflow says it is required to avoid "implicit declaration of function 'srand'" error while randomizing
#include <stdio.h>      // Standard library
#include <stdbool.h>    // Library required to use booleans
#include <string.h>     // Unlocks string functions
#include <limits.h>     // Allows to see max values for integers etc
#include <math.h>       // Enables using math functions
#include <windows.h>    // Unlocks windows functionalities


int main() {            // Main function

    char *myString1 = "";
    char *myString3 = "point test";

    printf("%s\n", *myString1);
    printf("%s\n", myString3);

    printf("%i\n", strlen(myString3));


    myString3 = "abcdefghijkl";

    printf("%s\n", myString3);

    printf("%i\n", strlen(myString3));



    myString3 = "lololololololololololol";

    printf("%s\n", myString3);

    printf("%i\n", strlen(myString3));



    return 0;               // Ends main function
}