#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "library.h"

int main() {
    // Predefined list of books
    struct Book books[MAX_BOOKS] = {
        {"The Great Gatsby", "F. Scott Fitzgerald"},
        {"1984", "George Orwell"},
        {"To Kill a Mockingbird", "Harper Lee"},
        {"Moby Dick", "Herman Melville"},
        {"Pride and Prejudice", "Jane Austen"}
    };

    char title[MAX_TITLE];
    int choice;

    while (1) {
        printf("\nLibrary Menu:\n");
        printf("1. Display All Books\n2. Search for a Book\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayBooks(books, MAX_BOOKS);
        }
        else if (choice == 2) {
            printf("Enter book title: ");
            scanf(" %[^\n]", title);

            int index = searchBook(books, MAX_BOOKS, title);
            if (index != -1) {
                printf("Book Found: \"%s\" by %s\n", books[index].title, books[index].author);
            }
            else {
                printf("Book not found.\n");
            }
        }
        else if (choice == 3) {
            printf("Exiting Library System.\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
