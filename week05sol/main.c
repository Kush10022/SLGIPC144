#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "loanUtils.h"

int main() {
    int salary, creditScore, eligible;
    float loanAmount, interestRate;

    // Get user input
    printf("Enter your annual salary: ");
    scanf("%d", &salary);

    printf("Enter your credit score: ");
    scanf("%d", &creditScore);

    printf("Enter the loan amount requested: ");
    scanf("%f", &loanAmount);

    // Check eligibility
    eligible = isEligible(salary, creditScore, loanAmount);

    // If eligible, determine the interest rate
    if (eligible) {
        interestRate = getInterestRate(creditScore, loanAmount);
    }
    else {
        interestRate = 0.0;  // No interest rate since loan is denied
    }

    // Display loan approval/rejection details
    displayLoanDetails(salary, creditScore, loanAmount, eligible, interestRate);

    return 0;
}
