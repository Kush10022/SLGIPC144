//
// Arrays and Functions
// - 2 Notations for single dimension arrays ([] | *)
// - Introduction to pointer arithmetic
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define CAPACITY 5
#define STR_CAPACITY 40

// Get user input for prices (no more than up to arrSize)
//void getPrices(double prices[], int arrSize);
void getPrices(double* prices, int arrSize);

// Display the valid prices in the arrays
//void showPrices(double prices[], int arrSize);
void showPrices(const double* prices, int arrSize);

// Display the C string names
//void showNames(char names[]);
void showNames(const char* names);

// Example's
void exampleArray(void);
void exampleStringArray(void);

// ----------------------------------------------------
// Entry point to the application
int main(void)
{
    printf("Arrays example...\n\n");
    exampleArray();
    putchar('\n');

    printf("C string array example...\n\n");
    exampleStringArray();

    return 0;
}

void exampleArray(void)
{
    double prices[CAPACITY] = { 0 };

    // Get some prices...
    //getPrices(&prices[0], CAPACITY);
    getPrices(prices, CAPACITY);

    // Display the prices...
    showPrices(prices, CAPACITY);
}

void exampleStringArray(void)
{
    // Create C string to store: Horse DONKEY chicken
    char names[STR_CAPACITY + 1] = "Horse DONKEY chicken";

    // Display the names...
    showNames(names);      // show all names
    showNames(&names[6]);  // show from DONKEY onward
    showNames(names + 13); // show from chicken only (POINTER ARITHMETIC)
}

// Get user input for prices (no more than up to arrSize)
//void getPrices(double prices[], int arrSize)
void getPrices(double* prices, int arrSize)
{
    int i = 0;
    int another = 1; // Flag to control exit from loop

    for (i = 0; another && i < arrSize; i++) {
        printf("Enter price-%d: $", i + 1);
        scanf("%lf", &prices[i]);

        printf("\tDo another (0=NO): ");
        scanf("%d", &another); // set's the flag
    }
}

void showPrices(double* prices, int arrSize)
//void showPrices(double prices[], int arrSize)
{
    int i;
    for (i = 0; i < arrSize; i++) {
        // Only show "valid" elements when there is a positive price 
        if (prices[i] > 0.0) {
            printf("Price-%d: %.2lf\n", i + 1, prices[i]);
        }
    }
}


// Display the C string names
//void showNames(char name[])
void showNames(char* name)
{
    printf("%s\n\n", name);
}
