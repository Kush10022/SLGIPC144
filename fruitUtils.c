#include <stdio.h>
#include "fruitUtils.h"

// Function to calculate the total price
float calculateTotal(float pricePerKg, float quantity) {
    return pricePerKg * quantity;
}

// Function to print the receipt
void printReceipt(char fruitName, float pricePerKg, float quantity, float totalPrice) {
    printf("\n--- Grocery Store Receipt ---\n");
    printf("Fruit: %c\n", fruitName);
    printf("Price per kilogram: $%.2f\n", pricePerKg);
    printf("Quantity: %.2f kg\n", quantity);
    printf("Total price: $%.2f\n", totalPrice);
    printf("Thank you for shopping with us!\n");
}
