// C Strings vs. Char arrays
// - Initializing
// - Output
// - Input
//
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//int main(void)
//{
//    // 1. How could we store a product description?
//    //char prodDescription[40 + 1] = { 0 };  // null term. byte
//    //char prodDescription[40 + 1] = { '\0' }; // null term. byte
//    char prodDescription[40 + 1] = "camels and horses"; // 6 chars 5 for camel, +1 Null term. byte
//
//    int i;
//
//    // 2. How do you display a C String?
//    // NO!!
//    //for (i = 0; prodDescription[i] != '\0'; i++) {
//    //    printf("%c", prodDescription[i]);
//    //    putchar(prodDescription[i]); // light weight function to show a single char!
//    //}
//
//    // YES!
//    printf("%s\n", prodDescription);
//
//    // 3. how do we get user input c string data??
//    printf("Enter a new c string value: ");
//    // no address-of operator (&) why? ... wait until next week!
//    //scanf("%s", prodDescription ); // limited to no spaces!!
//    scanf("%40[^\n]", prodDescription); // Accept anything but the newline
//
//    // Show the value:
//    printf("%s\n", prodDescription);
//
//
//    // 4. How do you assign a c string to a variable (after it's declared)?
//    // prodDescription = "horse"; //NO! can't do this... need to wait a couple of weeks....
//
//      
//    return 0;
//}



//____________________________________________________________________________________
//
////
//// Parallel Arrays
//// - Organization of related data
//// - Must use the same index across all arrays
////
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//#define CAPACITY 3
//
//// Gets user input for arrSize elements for all products.
//void userInputProducts(int upcArray[], float priceArray[], char taxArray[], int arrSize)
//{
//    int i;
//
//    for (i = 0; i < arrSize; i++) {
//        printf("Enter product-%d data\n", i + 1);
//        // UPC
//        printf("\tUPC number   : ");
//        scanf("%d", &upcArray[i]);
//        // PRICE
//        printf("\tPRICE        : ");
//        scanf("%f", &priceArray[i]);
//        // TAXABLE (Y|N)
//        printf("\tTAXABLE (Y|N): ");
//        scanf(" %c", &taxArray[i]);
//    }
//}
//
//// Display all the related attributes for all products based on arrSize
//void showProductData(int upcArray[], float priceArray[], char taxArray[], int arrSize)
//{
//    int i;
//
//    printf("Here's the product data...\n\n");
//    printf("#  UPC      PRICE    TAXABLE\n"
//        "-- -------- -------- -------\n");
//
//    for (i = 0; i < arrSize; i++) {
//        printf("%2d %8d %8.2f %3c\n", i + 1, upcArray[i], priceArray[i], taxArray[i]);
//    }
//}
//
//int main(void)
//{
//    // Product: UPC
//    //          price
//    //          taxable
//    // Use same index to relate each attribute
//
//    // product UPC's
//    int upcs[CAPACITY] = { 0 };
//    // product Price's
//    float prices[CAPACITY] = { 0.0f };
//    // product taxable flag (Y,N)
//    char taxable[CAPACITY] = { '\0' }; // NULL terminator
//
//    // input user values:
//    printf("Enter %d product upc's...\n", CAPACITY);
//
//    // call helper function to get user input values:
//    userInputProducts(upcs, prices, taxable, CAPACITY);
//
//    // call helper function to display the UPC data!
//    showProductData(upcs, prices, taxable, CAPACITY);
//
//    return 0;
//}

//
//
////____________________________________________________________________________________________
////
//////
////// Structures:
////// - Construction
////// - Declaration
////// - Initializing
////// - Output
////// - Input
////// - Member arrays
//////
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define CAPACITY 3
#define MAX_STR 30

// Create a new data type representing a PRODUCT
struct Product
{
    int upc;
    float price;
    int quantity;
    char isTaxable;
    char description[MAX_STR + 1]; // C string
};

// Create functions....

// Gets user input for a single product (and return it)
struct Product getUserInputProduct(int seq)
{
    // safe empty state
    struct Product prod = { 0 }; 
    printf("Enter data for product #%d\n", seq);
    // prompt for UPC:
    printf("Enter UPC value: ");
    scanf("%d", &prod.upc);
    printf("Enter Price: $");
    scanf("%f", &prod.price);
    printf("Enter Quantity: ");
    scanf("%d", &prod.quantity);
    printf("Is product taxable (Y|N): ");
    scanf(" %c", &prod.isTaxable);
    printf("Product Description: ");
    scanf(" %30[^\n]", prod.description);

    putchar('\n');

    return prod;
}

// Display all the related attributes for a product
// printf("%2d %8d %8.2f %8d %7c %s\n",...)
// TODO:
void displayProductData(struct Product product, int seq)
{
    printf("%2d %8d %8.2f %8d %7c %s\n",
        seq,
        product.upc,
        product.price,
        product.quantity,
        product.isTaxable,
        product.description);
}

// Entry point to the application and the core logic
int main(void)
{
    int i;

    // Product Data
    // safe empty state (always!!)
    //struct Product product = { 0 };
    //struct Product product = { 111, 111.11f, 'Y'};
    struct Product products[CAPACITY] =
    {
        {111, 111.11f, 10, 'Y', "Back Massager"},
        {222, 222.22f, 16, 'N', "String Cheese"}
    };

    // 4. Display the values
    //// Display 2nd product in array:
    //printf("UPC        : %d\n", products[0].upc);
    //printf("PRICE      : %.2f\n", products[0].price);
    //printf("TAXABLE    : %c\n", products[0].isTaxable);
    //printf("DESCRIPTION: %s\n\n", products[0].description);

    // get input for each product in array:
    for (i = 0; i < CAPACITY; i++) {
        // get user input for a product:
        // replace element with new user input values
        products[i] = getUserInputProduct(i + 1);
    }

    // Display each product in array:
    printf("Here's the product data...\n\n");
    printf("#  UPC      PRICE    QUANTITY TAXABLE DESCRIPTION\n"
        "-- -------- -------- -------- ------- --------------------\n");
    for (i = 0; i < CAPACITY; i++) {
        if (products[i].upc > 0) {
            displayProductData(products[i], i + 1);
        }
    }

    return 0;
}