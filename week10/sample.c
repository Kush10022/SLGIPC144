//
// Introduction to Pointers!
// - Declaring a pointer
// - Accessing the value a pointer points to ("Contents of", indirection/dereference)
// - Changing the value a pointer points to
// - Use case: use pointers to shorten long structure expressions
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// -------------------------
// // Macro's
// -------------------------
#define STR_SIZE 20
#define ASSESS_COUNT 5

// -------------------------
// Structures
// -------------------------
struct Grade
{
    float possible;
    float earned;
    char description[STR_SIZE + 1];
};

struct Student
{
    int id;
    struct Grade grades[ASSESS_COUNT];
};

// Pointer introduction
void introPointer(void);

// Pointer use case!
void pointerUseCase(void);

int main(void)
{
    //printf("Intro to pointers...\n");
    //introPointer();

    putchar('\n');
    //printf("Pointers use case ...\n");
    pointerUseCase();

    return 0;
}

// Pointer introduction
void introPointer(void)
{
    // 1. Pointer introduction
    // Declare a pointer (safe empty state)
    int horse = 32;
    int* ptrHorse = NULL; // set to safe empty state!
    ptrHorse = &horse; // set to point to "horse" variable address
    int* ptrCow = ptrHorse;
    int* ptrChicken = &horse;

    printf("Horse   : %d\n", horse);
    printf("Horse   : %p\n", &horse);
    printf("ptrHorse: %d\n", ptrHorse);
    printf("ptrHorse: %p\n", &ptrHorse);
    printf("ptrHorse: %d\n", *ptrHorse);
    putchar('\n');

    *ptrHorse = 64; // change value it points to
    *ptrChicken = 128;
    *ptrCow = 77;
    horse = 999;
    printf("Changed value to 64...\n");
    printf("Horse     : %d\n", horse);
    printf("ptrHorse  : %d\n", *ptrHorse);
    printf("ptrCow    : %d\n", *ptrCow);
    printf("ptrChicken: %d\n", *ptrChicken);
}

// Pointer use case!
void pointerUseCase(void)
{
    int i;

    // 2. Example case to use pointers...
    
    // - Declare complex structure variable initialized to some values
    struct Student horse = { 1111, {
                            { 50, 49, "Midterm"},
                            { 10, 5, "Lab01"},
                            { 10, 7, "Lab02"},
                            { 10, 6, "Lab03"},
                            { 10, 1, "Lab04"}  } };

    // - Declare two helper pointers
    float* ptrPossible = NULL;
    float* ptrEarned = NULL;
    
    // - Do a loop to show all grades
    for (i = 0; i < ASSESS_COUNT; i++) {
        // - Apply pointers (show benefit)
        ptrPossible = &horse.grades[i].possible;
        ptrEarned = &horse.grades[i].earned;

        //printf("%s: %.2f / %.2f\n",
        //       horse.grades[i].description,
        //       horse.grades[i].earned,
        //       horse.grades[i].possible);

        printf("%s: %.2f / %.2f\n",
               horse.grades[i].description, *ptrEarned, *ptrPossible );
    }

    // - Show MANUAL method using pointers to update values
    // set lab04 to 10 earned marks!
    horse.grades[4].earned = 10.0f;

    // - Do a loop to show all grades
    for (i = 0; i < ASSESS_COUNT; i++) {
        // - Apply pointers (show benefit)
        ptrPossible = &horse.grades[i].possible;
        ptrEarned = &horse.grades[i].earned;
        printf("%s: %.2f / %.2f\n",
               horse.grades[i].description, *ptrEarned, *ptrPossible);
    }

    // - Show user input (scanf) method using pointers to update values
    ptrEarned = &horse.grades[4].earned;
    printf("Enter the grade for lab04 you WANT to have: ");
    scanf("%f", ptrEarned);

    // - Do a loop to show all grades
    for (i = 0; i < ASSESS_COUNT; i++) {
        // - Apply pointers (show benefit)
        ptrPossible = &horse.grades[i].possible;
        ptrEarned = &horse.grades[i].earned;
        printf("%s: %.2f / %.2f\n",
               horse.grades[i].description, *ptrEarned, *ptrPossible);
    }
}
