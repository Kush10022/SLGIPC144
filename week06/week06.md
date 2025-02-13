### **Modular Banking Application Using For, While, Do-While Loops with Flags in C**  

---

### **Objectives:**  
By the end of this activity, you will:  
1. Implement **for**, **while**, and **do-while** loops in a modular C program.  
2. Use **flags** to control program flow instead of using `break` or `continue`.  
3. Structure your code using **multiple files** (header file, implementation file, and main file).  
4. Use **functions** to handle deposits, withdrawals, and balance checking.  

---

### **Scenario:**  
You are tasked with developing a **menu-driven banking application** for a simple bank account system. The program will allow users to:  

✔ **Deposit money** (using a **for loop** to handle multiple deposits in one session).  
✔ **Withdraw money** (using a **while loop** to ensure valid withdrawals that don't exceed the balance).  
✔ **Check their balance** (display the current account balance).  
✔ **Exit the program** (using **flags** to control when the program ends).

The program will be structured into **three files** to practice **modular programming** and **function management**.

---

### **Program Structure:**  
Your program should be split into the following files:  

1. **Header File (`bankUtils.h`)**  
   - This file will contain **function declarations** and **constants** if needed.

2. **Implementation File (`bankUtils.c`)**  
   - This file will contain the **definitions** of all the functions declared in the header file.

3. **Main File (`main.c`)**  
   - This file will handle **user interaction** and call functions defined in `bankUtils.c`.

---

### **Program Requirements:**  

1. **Display a Menu Using a Loop:**  
   The program should repeatedly display the following menu options until the user chooses to exit:  
   - **Option 1:** Deposit Money  
   - **Option 2:** Withdraw Money  
   - **Option 3:** Check Balance  
   - **Option 4:** Exit  

2. **Deposit Money (Using For Loop):**  
   - When the user selects **Deposit Money**, prompt them to enter the **number of deposits** they would like to make.  
   - Use a **for loop** to handle multiple deposits in one session.  
   - For each deposit, use a **do-while loop** to ensure the deposit amount is **positive**.  
   - After each successful deposit, update and display the **new balance**.

3. **Withdraw Money (Using While Loop):**  
   - When the user selects **Withdraw Money**, prompt them to enter the **withdrawal amount**.  
   - Use a **while loop** to validate that the withdrawal amount is **positive** and **does not exceed the current balance**.  
   - If the withdrawal is valid, update the balance and display the new amount.  
   - If the withdrawal exceeds the balance, display an error message and prompt the user again.

4. **Check Balance:**  
   - Display the **current balance** when the user selects this option.

5. **Exit the Program Using Flags:**  
   - Do **not** use `break` or `continue` to exit the loops.  
   - Use a **flag variable** to control when the program should exit the loop.  
   - The program should exit when the user selects **Option 4 (Exit)**, and a summary of total balance

---

### **Detailed Function Requirements:**

1. **Function Declarations (in `bankUtils.h`):**  
   - `void displayMenu();`  
   - `float depositMoney(float balance);`  
   - `float withdrawMoney(float balance);`  
   - `void checkBalance(float balance);`

2. **Function Descriptions:**  
   - **`displayMenu()`**: Displays the banking options.  
   - **`depositMoney(float balance)`**:  
     - Handles multiple deposits using a **for loop**.  
     - Validates each deposit using a **do-while loop** to ensure the amount is positive.  
     - Updates the balance.
   - **`withdrawMoney(float balance)`**:  
     - Ensures withdrawals are **positive** and do not **exceed the balance** using a **while loop**.  
     - Updates the balance.
   - **`checkBalance(float balance)`**: Displays the current balance.

---

### **Step-by-Step Instructions:**

1. **Create the Header File (`bankUtils.h`):**  
   - Declare the four functions you will define in the implementation file.  
   - Use **include guards** to prevent multiple inclusions.

2. **Create the Implementation File (`bankUtils.c`):**  
   - Define all four functions.  
   - For **depositMoney()**, implement a **for loop** for multiple deposits and use a **do-while loop** to ensure positive deposits.  
   - For **withdrawMoney()**, use a **while loop** to validate the withdrawal amount.

3. **Create the Main File (`main.c`):**  
   - Initialize the account balance to `$1000`.  
   - Use a **while loop** controlled by a **flag variable** to display the menu until the user chooses to exit.  
   - Based on user input, call the appropriate function.  
   - When the user exits, display a summary of total balance.

---

### **Sample Program Flow:**

```plaintext
Welcome to Simple Bank!
Your initial balance is $1000.00.

1. Deposit Money  
2. Withdraw Money  
3. Check Balance  
4. Exit  

Select an option: 
```

---

### **Expected Output Examples:**

#### **Example 1: Multiple Deposits Using For Loop**
```plaintext
Welcome to Simple Bank!
Your initial balance is $1000.00.

1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit

Select an option: 1
How many deposits would you like to make? -1

1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit

Select an option: 1
How many deposits would you like to make? 0

1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit

Select an option: 1
How many deposits would you like to make? 2
Enter deposit amount 1: -20
Error: Deposit amount must be positive.
Enter deposit amount 1: 100
Deposit successful! New balance: $1100.00
Enter deposit amount 2: 222
Deposit successful! New balance: $1322.00

1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit

Select an option: 2
Enter withdrawal amount: 2000
Error: Insufficient funds. Your balance is $1322.00.
Enter withdrawal amount: 122
Withdrawal successful! New balance: $1200.00

1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit

Select an option: 3
Your current balance is: $1200.00

1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit

Select an option: 0
Invalid option. Please select between 1 and 4.

1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit

Select an option: 4

Thank you for banking with us!
Your current balance is: $1200.00
```

---