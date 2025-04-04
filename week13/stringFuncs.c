//
// String Functions
// - Char Analysis functions (islower, isupper, isalpha, isdigit, isspace, isblank)
// - Char Manipulation functions (toupper, tolower)
// - length
// - copying
// - appending
// - searching (by char, string)
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h> // analysis and manipulation functions
#include <string.h> // c string library functions

#define STR_MAX 100

int upperCaseCount(const char str[])
{
    int rc = 0, i;
    for (i = 0; str[i] != '\0'; i++) {
        //// OLD LONG METHOD:
        //if (str[i] >= 'A' && str[i] <= 'Z') {
        //    rc++;
        //}

        // NEW EASY Method:
        if (isupper(str[i])) { // Uses ctype.h library function
            rc++;
        }
    }
    return rc;
}

void makeLower(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        //// OLD LONG METHOD:
        //if (str[i] >= 'A' && str[i] <= 'Z') {
        //    str[i] = str[i] + ('a' - 'A');
        //}

        // NEW EASY Method:
        //str[i] = tolower(str[i]); // convert char to lower
        if (isupper(str[i])) {
            // Use ctype.h library function to convert to lower case!
            str[i] = tolower(str[i]);
        }
    }
}

void stringStuff(void)
{
    char strA[STR_MAX + 1] = "Turkey";
    char strB[STR_MAX + 1] = "Horse ";
    char strC[STR_MAX + 1] = "Chicken";

    char strD[STR_MAX + 1] = "2020 Summer Olympics";
    char strE[STR_MAX + 1] = "2020 Winter Olympics";
    char strF[STR_MAX + 1] = "2020 Olympics";

    char* result = NULL; // used in string search 
    char ch;
    int len = 0;
    
    // Set len to the character length of the strB string
    len = strlen(strB);

    // Copy strB to strA
    strcpy(strA, strB); // strA is replaced with strB

    // APPEND strC to strA
    strcat(strA, strC); // append/add to strA value of strC

    printf("Len: %d\n", len);
    printf("A: %s\n", strA);
    printf("B: %s\n", strB);
    printf("C: %s\n\n", strC);

    // --------------------------------------------------------
    //// String comparing....
    
    // (Will discuss this more in Lab class on Friday)


    // --------------------------------------------------------
    // String Searching
    do {
        printf("Let's do some STRING searching... (enter 'quit' to stop)\n");
        printf("Enter a string to search: ");
        scanf("%30[^\n]", strA);
        while (getchar() != '\n'); // clear buffer

        // See if strA is in somewhere in the string strD:
        result = strstr(strD, strA);  // will return NULL if not found
        if (result != NULL) {
            // How do you determine the beginning matching index (subtract addresses)?
            printf("\tFound a match in strD:'%s'(index:%d)\n", strD, result-strD);
        }
        else {
            printf("\tNo match found in strD:'%s'!\n", strD);
        }

        // See if strA is in somewhere in the string strE:
        result = strstr(strE, strA);  // will return NULL if not found
        if (result != NULL) {
            printf("\tFound a match in strE:'%s'!\n", strE);
        }
        else {
            printf("\tNo match found in strE:'%s'!\n", strE);
        }

        // See if strA is in somewhere in the string strF:
        result = strstr(strF, strA);  // will return NULL if not found
        if (result != NULL) {
            printf("\tFound a match in strF:'%s'!\n\n", strF);
        }
        else {
            printf("\tNo match found in strF:'%s'!\n\n", strF);
        }

    } while (strcmp(strA, "quit"));
    putchar('\n');

    // --------------------------------------------------------
    // Character Searching
    strcpy(strA, "the quick brown foxes jumped over the lazy dog!");
    do {
        printf("Let's do some CHARACTER searching... (enter 'q' to stop)\n");
        printf("                       1         2         3         4         5\n");
        printf("             012345678901234567890123456789012345678901234567890\n");
        printf("Given strA: '%s'\n"
               "Enter a letter to search:", strA);
        scanf("%c", &ch); // <-- the letter to search for in the strA string
        while (getchar() != '\n');

        printf("Searching strA:'%s' for letter '%c'\n\n", strA, ch);
        // Search for the ch in the string strA!
        result = strchr(strA, ch); // will return NULL if not found
        
        if (result != NULL) {
            printf("\tFound '%c' at index:%d!\n\n", ch, result - strA);
        }
        else {
            printf("\tNot found!\n\n");
        }
    } while (ch != 'q');
}

int main(void)
{
    char str[STR_MAX + 1] = "iPC 144 Horse";
    printf("Character Analysis and Manipulation functions (ctype.h)...\n");
    printf("Uppercase chars: %d\n", upperCaseCount(str));
    makeLower(str);
    printf("%s\n\n", str);

    printf("String functions (string.h)...\n");
    stringStuff();

    return 0;
}