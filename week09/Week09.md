
---

## **📌 Scenario: Library Search System**  
You are developing a **Library Search System** that helps users:  
1. **Display all books** in the library.  
2. **Search for a book by title** (case-sensitive).  
3. **Exit the system** when finished.  

---

## **📌 Program Requirements**  

### **1. Define a Struct for Books**  
Create a `struct Book` to store:  
- `title` (C-string, max 100 characters)  
- `author` (C-string, max 100 characters)  

### **2. Use an Array of Structs**  
- The program must store **5 predefined books** in an **array of structs**.  
- Here is the list of all the book copy all and put it in the main.c file: 
- {
        {"The Great Gatsby", "F. Scott Fitzgerald"},
        {"1984", "George Orwell"},
        {"To Kill a Mockingbird", "Harper Lee"},
        {"Moby Dick", "Herman Melville"},
        {"Pride and Prejudice", "Jane Austen"}
    }
- Users will interact with this predefined list.

### **3. Implement the Following Functions**  

#### **Function 1: Display All Books**  
📌 `void displayBooks(Book books[], int count);`  
- Lists all books with their **titles** and **authors**.  

#### **Function 2: Search for a Book by Title**  
📌 `int searchBook(Book books[], int count, char title[]);`  
- Allows users to enter a book title to **search**.  
- The search should be **case-sensitive** (users must enter the exact title).  
- Uses **`strcmp()`** to compare book titles. Use it like this (strcmp("booktitle", "title");)  
- Returns the **index of the book** if found, otherwise `-1`.  

---

## **📌 Program Structure**  
The program should be divided into **three files** for modularity:  

1. **Header File (`library.h`)** → Contains `struct` definition and function declarations.  
2. **Implementation File (`library.c`)** → Implements all the functions.  
3. **Main File (`main.c`)** → Handles user input and calls functions from `library.c`.  

---

## **📌 Program Flow**  

### **Step 1: Display the Menu**  
When the program starts, display the following menu:  

```plaintext
Library Menu:
1. Display All Books
2. Search for a Book
3. Exit
Enter choice:
```

### **Step 2: Process User Input**  
- If the user selects **1**, display all books.  
- If the user selects **2**, prompt them for a book title and search for it.  
- If the user selects **3**, exit the program.  
- If the user enters an **invalid option**, display an error message and show the menu again.  

### **Step 3: Search for a Book**  
- If the book exists, display its title and author.  
- If the book is not found, show `"Book not found."`.  

---

## **📌 Sample Program Run**  

```plaintext
Library Menu:
1. Display All Books
2. Search for a Book
3. Exit
Enter choice: 1

Library Books:
1. "The Great Gatsby" by F. Scott Fitzgerald
2. "1984" by George Orwell
3. "To Kill a Mockingbird" by Harper Lee
4. "Moby Dick" by Herman Melville
5. "Pride and Prejudice" by Jane Austen

Library Menu:
1. Display All Books
2. Search for a Book
3. Exit
Enter choice: 2
Enter book title: 1984
Book Found: "1984" by George Orwell

Library Menu:
1. Display All Books
2. Search for a Book
3. Exit
Enter choice: 2
Enter book title: Harry Potter
Book not found.

Library Menu:
1. Display All Books
2. Search for a Book
3. Exit
Enter choice: 3
Exiting Library System.
```

---

## **📌 Instructions for Completing the Lab**  

### **Step 1: Create the Header File (`library.h`)**  
- Define the `Book` struct.  
- Declare the function prototypes.  

### **Step 2: Create the Implementation File (`library.c`)**  
- Implement **`displayBooks()`** to list all books.  
- Implement **`searchBook()`** to search for books using `strcmp()`.  

### **Step 3: Create the Main File (`main.c`)**  
- Store **5 predefined books** in an array.  
- Show the **menu** and process user input.  
- Use a **loop** to keep displaying the menu until the user exits.  

---
