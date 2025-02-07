#include <stdio.h>
#include "loanUtils.h"

// Function to check loan eligibility
int isEligible(int salary, int creditScore, float loanAmount) {
    int a = 1;
    if (salary < 30000) {
        a = 0;  // Not eligible due to low salary
    }
    if (creditScore < 650) {
        a = 0;  // Not eligible due to low credit score
    }
    if (loanAmount < 5000 || loanAmount > 100000) {
        a = 0;  // Not eligible due to incorrect loan amount
    }
    return a;  // Eligible
}

// Function to determine the applicable interest rate
float getInterestRate(int creditScore, float loanAmount) {
    float interestRate;
    if (creditScore >= 750) { // 735
        if (loanAmount <= 50000) {
            interestRate = 5.0;
        }
        else {
            interestRate = 4.5;
        }
    }
    else if (creditScore >= 700) { // 735
        if (loanAmount <= 50000) {
            interestRate = 6.5;
        }
        else {
            interestRate = 6.0;
        }
    }
    else { // Credit score is between 650 - 699
        if (loanAmount <= 50000) {
            interestRate = 8.0;
        }
        else {
            interestRate = 7.5;
        }
    }
    return interestRate;
}


// Function to display loan details
void displayLoanDetails(int salary, int creditScore, float loanAmount, int eligible, float interestRate) {
    if (!eligible) {
        if (salary < 30000) {
            printf("Loan Denied. Minimum salary requirement is $30,000.\n");
        }
        else if (creditScore < 650) {
            printf("Loan Denied. Minimum credit score requirement is 650.\n");
        }
        else {
            printf("Loan Denied. Loan amount must be between $5,000 and $100,000.\n");
        }
    }
    else {

        float totalRepayment = loanAmount + (loanAmount * (interestRate / 100));

        printf("\nLoan Approved!\n");
        printf("Interest Rate: %.2f%%\n", interestRate);
        printf("Total Payable Amount: $%.2f\n", totalRepayment);
    }
}
