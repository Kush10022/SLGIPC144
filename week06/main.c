#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bankUtils.h"

int main() {
    float balance = 1000.0;         // Initial balance
    int running = 1;                // Flag to control the main loop
    int option;                     // User's menu option

    printf("Welcome to Simple Bank!\nYour initial balance is $%.2f.\n", balance);

    // Main menu loop controlled by 'running' flag
    while (running) {
        displayMenu();  // Display menu options
        scanf("%d", &option);

        // Handle user options
        if (option == 1) {
            balance = depositMoney(balance);  // Update balance and track deposits
        }
        else if (option == 2) {
            balance = withdrawMoney(balance);  // Update balance and track withdrawals
        }
        else if (option == 3) {
            checkBalance(balance);  // Display current balance
        }
        else if (option == 4) {
            printf("\nThank you for banking with us!\n");
            checkBalance(balance);
            running = 0;  // Exit loop
        }
        else {
            printf("Invalid option. Please select between 1 and 4.\n");
        }
    }

    return 0;
}
