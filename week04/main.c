#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "fruitUtils.h"

int main() {
    // Declare variables
    char fruitName;
    float pricePerKg, quantity, totalPrice;

    // Get user input
    printf("Enter the name of the fruit: ");
    scanf("%c", &fruitName);
    printf("Enter the price per kilogram: ");
    scanf("%f", &pricePerKg);
    printf("Enter the quantity in kilograms: ");
    scanf("%f", &quantity);

    // Call the function to calculate the total price
    totalPrice = calculateTotal(pricePerKg, quantity);

    // Call the function to print the receipt
    printReceipt(fruitName, pricePerKg, quantity, totalPrice);

    return 0;
}
