//
// Files - Essentials
// o Open
// o Read
// o Write/Append
// o close
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Macro's
#define STR_MAX 30
#define RECORDS 10

// Data files...
#define DATA_SIMPLE "products.dat"

struct Product
{
    int sku;
    char description[STR_MAX + 1];
    double price;
    int quantity;
};

// Helper function for getting user answer to yes/no question
char getYesNo(const char question[]);

// Helper function to manage product data (creates 6 starter records or empties the array)
void resetProductData(struct Product prods[], int arrSize);

// Helper function to display the product data array records
void showProductData(const struct Product prods[], int arrSize);


// Basic essentials: working with files
int main(void)
{
    // 6-Products of data
    struct Product prod[RECORDS] = {
        {1010, "Horsey Toy", 14.25, 9},
        {1011, "Chicken Toy", 214.25, 8},
        {1012, "Ostrich Toy", 12.50, 7},
        {1013, "Cow Toy", 195.25, 20},
        {1014, "Turkey Toy", 6.75, 6},
        {1015, "Camel Toy", 36.25, 3}
    };

    char choice;
    int i, counter;

    // File variable needed to access a file (set to safe empty state)
    FILE* fp = NULL;

    // ----------------------------------------------------------
    // WRITE the product data to a file
    // ----------------------------------------------------------
    choice = getYesNo("Open file for WRITE (y=YES|n=NO)?: ");
    if (choice == 'y') {
        // Open connection to the file for WRITING mode
        fp = fopen(DATA_SIMPLE, "w");
        
        // Check it's a valid connection:
        if(fp != NULL)
        {
            counter = 0;

            // Loop first 3 products and write it to the file
            for (i = 0; i < 3; i++) {
                // Write the current element record (use pipe delimeter)!
                fprintf(fp, "%d|%s|%.2lf|%d\n", prod[i].sku, prod[i].description,
                       prod[i].price, prod[i].quantity);

                // Immediately writes to file! 
                // Note: Don't want to do this for each iteration... but maybe moderate 
                // it to do it every 10-50 records/loops:  if(!(counter%10))...
                fflush(fp);

                counter++;  // increment counter
            }

            // Always disconnect the file!
            fclose(fp);

            // Best practice to RESET the pointer to a safe empty state
            fp = NULL;

            printf("%d records written!\n\n", counter);
        }
        else {
            printf("Failed to open file for WRITING!\n\n");
        }
    }

    // ----------------------------------------------------------
    // APPEND product data records to the file!
    // ----------------------------------------------------------
    choice = getYesNo("Open file for APPENDING data (y=YES|n=NO)?: ");
    if (choice == 'y') {

        // Open connection to the file for APPENDING mode
        fp = fopen(DATA_SIMPLE, "a");

        // Check it's a valid connection:
        if( fp != NULL)
        {
            counter = 0;

            // Loop all the products and append to the file
            for (i = 0; i < RECORDS; i++) {

                // Only write product data that has values (sku will be positive)
                if( prod[i].sku > 0) {
                    // Write the current element record (use pipe delimeter)!
                    fprintf(fp, "%d|%s|%.2lf|%d\n", prod[i].sku, prod[i].description,
                            prod[i].price, prod[i].quantity);

                    counter++; // increment counter
                }
            }

            // always disconnect the file!
            fclose(fp);

            // Best practice to RESET the pointer to a safe empty state
            fp = NULL;

            printf("%d records appended!\n\n", counter);
        }
        else {
            printf("Failed to open file for APPENDING!\n\n");
        }
    }

        // ----------------------------------------------------------
        // READ the product data records from the file!
        // ----------------------------------------------------------
    choice = getYesNo("Open file for READING data (y=YES|n=NO)?: ");
    if (choice == 'y') {
        // Call the helper function to reset products array to safe empty state
        resetProductData(prod, RECORDS);

        // Open connection to the file for READING mode
        fp = fopen(DATA_SIMPLE, "r");

        // Check it's a valid connection:
        if( fp != NULL)
        {
            i = 0;
            counter = 0;

            // Loop the data file (protect array limits and check desired fields are being read)

            while (i < RECORDS && fscanf(fp, "%d|%30[^|]|%lf|%d\n", 
                                         &prod[i].sku, prod[i].description, 
                                         &prod[i].price, &prod[i].quantity) == 4)
            {
                i++;
                counter++; // update records read counter
            }

            // always disconnect the file!
            fclose(fp);

            // Best practice to RESET the pointer to a safe empty state
            fp = NULL;

            printf("%d records read!\n\n", counter);

            // Display the array!
            showProductData(prod, RECORDS);
        }
        else {
            printf("Failed to open file for READING!\n\n");
        }
    }

    return 0;
}

// -----------------------------------------------------------------------------

// Helper function for getting user answer to yes/no question
char getYesNo(const char question[])
{
    char answer;

    printf("----------------------------------------------------------\n"
           "Question: %s", question);
    scanf(" %c", &answer);
    printf("----------------------------------------------------------\n\n");

    return answer;
}

// Helper function to reset product data array
void resetProductData(struct Product prods[], int arrSize)
{
    int i;
    struct Product empty = { 0 }; // empty record!

    // Reset each element/record
    for (i = 0; i < arrSize; i++) {
        prods[i] = empty; // assign the empty record!
    }
}

// Helper function to display the product data array records
void showProductData(const struct Product prods[], int arrSize)
{
    int i;

    // Column Headers
    printf("SKU     Description                    Price    Quantity\n"
           "------- ------------------------------ -------- --------\n");

    // Record data
    for (i = 0; i < RECORDS; i++) {
        // Show only records with data
        if (prods[i].sku > 0) {
            printf("%7d %-30.30s %8.2lf %d\n", prods[i].sku, prods[i].description,
                   prods[i].price, prods[i].quantity);
        }
    }
}
