#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bankUtils.h"

// Function to display the menu
void displayMenu() {
    printf("\n1. Deposit Money\n");
    printf("2. Withdraw Money\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
    printf("\nSelect an option: ");
}

// Function to handle deposits using a for loop
float depositMoney(float balance) {
    int numDeposits;
    printf("How many deposits would you like to make? ");
    scanf("%d", &numDeposits);

    for (int i = 1; i <= numDeposits; i++) {
        float depositAmount;

        // Do-while loop to ensure positive deposit
        do {
            printf("Enter deposit amount %d: ", i);
            scanf("%f", &depositAmount);

            if (depositAmount <= 0) {
                printf("Error: Deposit amount must be positive.\n");
            }
        } while (depositAmount <= 0);

        balance += depositAmount;
        printf("Deposit successful! New balance: $%.2f\n", balance);
    }

    return balance;
}

// Function to handle withdrawals using a while loop
float withdrawMoney(float balance) {
    float withdrawAmount;
    int validWithdrawal = 0;

    // While loop to ensure valid withdrawal
    while (!validWithdrawal) {
        printf("Enter withdrawal amount: ");
        scanf("%f", &withdrawAmount);

        if (withdrawAmount <= 0) {
            printf("Error: Withdrawal amount must be positive.\n");
        }
        else if (withdrawAmount > balance) {
            printf("Error: Insufficient funds. Your balance is $%.2f.\n", balance);
        }
        else {
            balance -= withdrawAmount;
            printf("Withdrawal successful! New balance: $%.2f\n", balance);
            validWithdrawal = 1;  // Exit the loop after successful withdrawal
        }
    }

    return balance;
}

// Function to display current balance
void checkBalance(float balance) {
    printf("Your current balance is: $%.2f\n", balance);
}
