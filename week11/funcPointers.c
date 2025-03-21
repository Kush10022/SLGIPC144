//
// Pointers and Functions
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Get user input for an animal ID and return it
//int getAnimalID(void);
void getAnimalID(int* id);

// Get user input for an animal weight and return it
//double getAnimalWeight(void);
void getAnimalWeight(double* weight);

// Get user input for an animal running speed and return it
//float getRunningSpeed(void);
void getRunningSpeed(float* speed);

// single function to get all the data (use multiple pointers)
void getAnimalData(int* id, double* weight, float* speed);

// Display the animal details
//void showAnimalDetails(int id, double weight, float speed);
void showAnimalDetailsPtr(int* id, double* weight, float* speed);

int main(void)
{
    int animalID = 0;
    double animalWeight = 0.0;
    float runningSpeed = 0.0f;

    printf("Let's enter some animal data...\n\n");
    // Old method:
    //animalID = getAnimalID();
    //animalWeight = getAnimalWeight();
    //runningSpeed = getRunningSpeed();
    
    //// Use pointers for each function:
    //getAnimalID(&animalID);
    //getAnimalWeight(&animalWeight);
    //getRunningSpeed(&runningSpeed);

    // Get all the data!! (in a single function: return 3 values via the pointers)
    getAnimalData(&animalID, &animalWeight, &runningSpeed);

    putchar('\n');

    //showAnimalDetails(animalID, animalWeight, runningSpeed);
    showAnimalDetailsPtr(&animalID, &animalWeight, &runningSpeed);

    return 0;
}

// Get user input for an animal ID and return it
void getAnimalID(int* id)
{
    printf("Enter animal ID: ");
    scanf("%d", id); // do not provide & of pointer... just the variable
}

// Get user input for an animal weight and return it
//void getAnimalWeight(double* weight)
void getAnimalWeight(double* weight) 
{
    printf("Enter animal weight: ");
    scanf("%lf", weight);
}

// Get user input for an animal running speed and return it
//float getRunningSpeed(void)
void getRunningSpeed(float* speed) 
{
    printf("Enter animal running speed: ");
    scanf("%f", speed);
}

// single function to get all the data (use multiple pointers)
void getAnimalData(int* id, double* weight, float* speed)
{
    getAnimalID(id);
    getAnimalWeight(weight);
    getRunningSpeed(speed);
}


// Display the animal details
//void showAnimalDetails(int id, double weight, float speed)
//{
//    printf("Animal Details\n"
//           "--------------\n"
//           "ID           : %d\n"
//           "Weight       : %.1lf\n"
//           "Running Speed: %.1f\n\n", id, weight, speed);
//}

// Display the animal details
void showAnimalDetailsPtr(int* id, double* weight, float* speed)
{
    printf("Animal Details\n"
           "--------------\n"
           "ID           : %d\n"
           "Weight       : %.1lf\n"
           "Running Speed: %.1f\n\n", *id, *weight, *speed);
}
