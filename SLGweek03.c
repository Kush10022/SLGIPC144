#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // Declare variables
    float pricePerPizza, quantity;
    float totalCostWithDelivery;
    double totalCost;
    int truncatedCost;
    char promoChar;

    // Get user input
    printf("Enter the price per pizza: ");
    scanf("%f", &pricePerPizza);

    printf("Enter the quantity of pizzas: ");
    scanf("%f", &quantity);

    // Calculate the total cost (floating-point)
    totalCost = pricePerPizza * quantity;
    printf("Original total cost (float): %.2f\n", totalCost);

    // Truncate total cost by casting to int
    truncatedCost = (int)totalCost;
    printf("Truncated total cost (int): %d\n", truncatedCost);

    // Add delivery fee and show type coercion
    totalCostWithDelivery = truncatedCost + 5.99; // Coercion: int converted to float
    printf("Total cost with delivery (float): %.2f\n", totalCostWithDelivery);

    // Convert quantity to char for promotional ASCII character
    promoChar = (char)(int)truncatedCost; // Cast to int first, then to char
    printf("Promotional ASCII character for the quantity: %c\n", promoChar);


    return 0;
}
//#include <stdio.h>
//
//int main(void) {
//	//int senior = 0; 
//	//int adult = 1;  
//
//
//	//printf("Senior : %d\n", senior++);
//	//printf("adult : %d\n", ++adult);     
//	//printf("adult : %d\n", ++adult);     
//	//printf("senior : %d\n", --senior);   
//	//printf("Result : %d , %d \n", adult++, ++senior);   
//
//	
//
//	return 0;
//}