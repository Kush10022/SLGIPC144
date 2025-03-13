#define MAX_BOOKS 5
#define MAX_TITLE 100

// Struct for a book
struct Book{
    char title[MAX_TITLE];
    char author[MAX_TITLE];
};

// Function Declarations
void displayBooks(struct Book books[], int count);
int searchBook(struct Book books[], int count, char title[]);

