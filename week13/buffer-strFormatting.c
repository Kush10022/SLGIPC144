//
// Input Buffer and String formatting
// - Managing the input buffer
// - String formatting
// - Dynamic string input
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define STR_MAX 30

void clearBuffer(void)
{
    while (getchar() != '\n');
}

void inputBuffer(void)
{
    int year = 0, month = 0, day = 0;
    char initial = 0;
    double weight = 0.0;
    char fullname[STR_MAX + 1] = { 0 };

    printf("Enter year/month/day: ");
    scanf("%d/%d/%d", &year, &month, &day);
    // clear the input buffer?
    //while (getchar() != '\n'); // do nothing
    clearBuffer();

    printf("Enter Middle Intitial: ");
    scanf(" %c", &initial);
    // clear the input buffer?
    clearBuffer();

    printf("Enter Weight: ");
    scanf("%lf", &weight);
    // clear the input buffer?
    clearBuffer();

    printf("Enter fullname: ");
    scanf("%30[^\n]", fullname);
    // clear the input buffer?
    clearBuffer();

    printf("Date    : %04d-%02d-%02d\n", year, month, day);
    printf("Weight  : %.2lf\n", weight);
    printf("Fullname: %s\n", fullname);
    printf("Initial : %c\n", initial);
}

// More about string output formatting!
void stringFormatting(void)
{
               //           1
               // 012345678901234567
    char str[] = "CPP1IPC14420240325";
    // 2024-03-25
    printf("String  : %s\n", str);
    printf("Program : %.3s\n", str);
    printf("Semester: %.1s\n", &str[3]);
    printf("Course  : %.6s\n", &str[4]);
    printf("Date    : %.4s-%.2s-%.2s\n", &str[10], &str[14], &str[16]);
}

void dynamicStringInput(void)
{
    char fmt[20 + 1] = { 0 }; // Need this to store input format string
    char str[STR_MAX + 1] = { 0 };

    printf("Enter a string no longer than %d chars: ", STR_MAX);
    scanf("%30[^\n]", str);
    printf("You entered: %s\n\n", str);
    clearBuffer();

    // -------------------------------------------------------------
    // Do it again.. only this time don't hard code string max ("%30")!
    
    //"%30[^\n]"
    // stores "output" to the string!
    sprintf(fmt, "%%%d[\n]", STR_MAX);

    printf("Enter a string no longer than %d chars: ", STR_MAX);
    scanf(fmt, str);
    clearBuffer();

    printf("You entered: %s\n\n", str);
}

int main(void)
{
    inputBuffer();
    stringFormatting();
    dynamicStringInput();


    return 0;
}