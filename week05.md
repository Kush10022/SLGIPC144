### **Scenario:**  
A local amusement park offers ticket prices based on the visitor’s age. You need to create a **modular program** that:  
1. **Gets the user's age** as input.  
2. **Determines the ticket price** using a function with conditional statements.  
3. **Displays the final ticket price** in a structured format.  

The ticket prices are based on the following rules:  
- **Children (0 - 5 years old):** Free admission.  
- **Youth (6 - 12 years old):** $10 per ticket.  
- **Teen (13 - 17 years old):** $15 per ticket.  
- **Adult (18 - 59 years old):** $20 per ticket.  
- **Senior (60+ years old):** $12 per ticket.  

Your program should also handle invalid input:  
- If the user enters a **negative age**, display an error message and exit.  

---

### **Programming Task:**  

In the file `lab4.c`, write a program that:  

1. **Defines a function** `int getTicketPrice(int age)` that:  
   - Takes the visitor’s **age** as a parameter.  
   - Uses **conditional statements** to determine the ticket price.  
   - Returns the appropriate ticket price as an `int`.  

2. **Defines a function** `void displayTicketPrice(int age, int price)` that:  
   - Takes the **age** and the **ticket price** as parameters.  
   - Prints a formatted message displaying the ticket cost.  

3. **Implements the `main()` function** that:  
   - Prompts the user to **enter their age**.  
   - Calls `getTicketPrice()` to determine the price.  
   - Calls `displayTicketPrice()` to print the ticket details.  
   - Displays an error message if the age is invalid.  

---

### **Prompt Example:**  
```plaintext
Enter your age: 
```

---

### **Expected Output Examples:**  

#### **Example 1: Child (0-5 years)**
```plaintext
Enter your age: 4
You are 4 years old. Your ticket is free!
```

#### **Example 2: Teen (13-17 years)**
```plaintext
Enter your age: 15
You are 15 years old. Your ticket price is $15.
```

#### **Example 3: Senior (60+ years)**
```plaintext
Enter your age: 65
You are 65 years old. Your ticket price is $12.
```

#### **Example 4: Invalid Input**
```plaintext
Enter your age: -3
Invalid age entered. Please enter a valid age.
```
---

