//
// Structures and Functions
// - structure pointer
// - array of structures
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define STR_CAPACITY 40

#define STRING_MAX 30

// How many bytes of memory? 
// (min: 51, but padding is applied and likely 56 : nearest multiple of 8)
struct Animal
{
    int ID;
    char name[STRING_MAX + 1];
    int birthYear;
    double weight;
    float speed;
};

// Get user input for animal data and return it
//struct Animal getAnimalData(void) // <--- OLD METHOD
// Use a pointer (pass by address)!
void getAnimalData(struct Animal* animal);

// Display animal details
//void showAnimalData(const struct Animal animal ) // OLD method (pass by value/copy)
void showAnimalData(const struct Animal* animal);  // Use POINTER (pass by address)

int main(void)
{
    // Declare an Animal and set to safe empty state
    struct Animal horse = { 0 };

    // Get animal data...
    //horse = getAnimalData(); // <--- OLD method 
    getAnimalData(&horse);    // Use a pointer (Pass by address)

    // Display animal details
    //showAnimalData(horse); // <--- OLD method (Pass by value/copy)
    showAnimalData(&horse); // Use a pointer (Pass by address)

    return 0;
}

// Get user input for animal data and return it
//struct Animal getAnimalData(void) // <--- OLD METHOD returning a struct Animal

// Use a pointer (pass by address)!
void getAnimalData(struct Animal* animal)
{
    // Don't need this! use the pointer argument!
    //struct Animal animal = { 0 };

    printf("Enter Animal ID: ");
    scanf("%d", &animal->ID); // Use "arrow-notation" to access members
    printf("Enter Animal Name: ");
    scanf(" %40[^\n]", animal->name);
    printf("Enter birth year: ");
    scanf("%d", &animal->birthYear);
    printf("Enter Animal weight: ");
    scanf("%lf", &animal->weight);
    printf("Enter running speed: ");
    scanf("%f", &animal->speed);

    //return animal; // Don't need to return now!
}

// Display animal details
//void showAnimalData(const struct Animal animal ) // OLD method (pass by value/copy)
void showAnimalData(const struct Animal* animal)  // Use POINTER (pass by address)
{
    printf("Horse Details\n"
           "-------------\n");
    printf("ID: %d\n", (*animal).ID);   // DON'T do this!
    printf("Name: %s\n", animal->name); // GOOD method! (arrow-notation)
    printf("Birth Year: %d\n", animal->birthYear);
    printf("Weight: %.1lf\n", animal->weight);
    printf("Speed: %.1f\n\n", animal->speed);
}
