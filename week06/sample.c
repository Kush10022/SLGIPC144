#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// Problem:  
// ask the user to enter number of product 
// based on the number of prod loop through each product and prompt the user to enter the price for each product
// after that calculate the total price for all the product.
// check for the price range from 10 - 250 before adding it into total var.


void task1(void); // use while loop to complete the problem
void task2(void);// use do - while loop to complete the problem
void task3(void); // use for loop to complete the problem
void task4(void); // use the for and nested do-while to check the prod price between the range 10 - 250.


void task1(void)
{
	int prod, counter = 0;
	double price, total = 0;
	printf("How many do you want to buy? ");
	scanf("%d", &prod);

	while (counter < prod) {
		printf("Please enter price for prod - %d : ", counter + 1);
		scanf("%lf", &price);

		total += price;
		counter++;
	}
	printf("the total price is : %.2lf", total);
}

void task2(void)
{

	int prod, counter = 0;
	double price, total = 0;
	printf("How many do you want to buy? ");
	scanf("%d", &prod);

	do{
		printf("Please enter price for prod - %d : ", counter + 1);
		scanf("%lf", &price);

		total += price;
		counter++;
	} while (counter < prod);
	printf("the total price is : %.2lf", total);
}

void task3(void)
{

	int prod;
	double price, total = 0;
	printf("How many do you want to buy? ");
	scanf("%d", &prod);

	for (int  counter = 0; counter < prod; counter++) {
		printf("Please enter price for prod - %d : ", counter + 1);
		scanf("%lf", &price);

		total += price;
		
	}
	printf("the total price is : %.2lf", total);
}

void task4(void)
{
	int prod, valid;
	double price, total = 0;
	printf("How many do you want to buy? ");
	scanf("%d", &prod);
	const double MIN_PRICE = 10.00, MAX_PRICE = 250.00;

	for (int counter = 0; counter < prod; counter++) {
		
		do {
			valid = 1;
			printf("Please enter price for prod - %d : ", counter + 1);
			scanf("%lf", &price);

			if (price < MIN_PRICE || price > MAX_PRICE) {
				printf("Please enter again! \n");
				valid = 0;
			}
		} while (!valid); // while(1)
		total += price;
	}
	printf("the total price is : %.2lf", total);
}

int main(void) {
	task4();
	return 0;
}



