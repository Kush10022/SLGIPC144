#include <stdio.h>
#include <string.h>
#include "library.h"

// Function to display all books in the library
void displayBooks(struct Book books[], int count) {
    printf("\nLibrary Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. \"%s\" by %s\n", i + 1, books[i].title, books[i].author);
    }
}

// Function to search for a book using strcmp()
int searchBook(struct Book books[], int count, char title[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return i; // Return the index of the book
        }
    }
    return -1; // Book not found
}
