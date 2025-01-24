
---

### **Scenario:**  
You are developing a program for a grocery store to calculate the total price of a fruit order and print a detailed receipt. To follow **modular programming principles**, the program will be split into three files:  
1. A header file (`fruit_utils.h`) for declaring functions.  
2. An implementation file (`fruit_utils.c`) for defining the functions.  
3. A main file (`main.c`) for executing the program and calling the functions.  

---

### **Programming Task:**  
In this lab, you will create a modular program that:  

1. **Header File (`fruit_utils.h`):**  
   - Declare the following functions:  
     a. `float calculateTotal(float pricePerKg, float quantity);`  
     b. `void printReceipt(char fruitName, float pricePerKg, float quantity, float totalPrice);`  

2. **Implementation File (`fruit_utils.c`):**  
   - Define the functions declared in `fruit_utils.h`:  
     a. **`calculateTotal`:** Multiplies `pricePerKg` and `quantity` to calculate the total price.  
     b. **`printReceipt`:** Prints a receipt with the fruit name's first charector, price per kilogram, quantity, and total price formatted as shown below.  

3. **Main File (`main.c`):**  
   - Prompt the user for:  
     a. The name of the fruit's first charector (e.g., "A").  
     b. The price per kilogram (e.g., `3.25`).  
     c. The quantity in kilograms (e.g., `5.5`).  
   - Call `calculateTotal` to compute the total price.  
   - Call `printReceipt` to display the final receipt.  

4. **Modular Design:**  
   - Ensure the program is split into three files: `fruit_utils.h`, `fruit_utils.c`, and `main.c`.  
   - Use `#include "fruit_utils.h"` in `fruit_utils.c` and `main.c` to connect them.  

---

### **Prompt Example:**  
```plaintext
Enter the name of the fruit: M
Enter the price per kilogram: 4.25  
Enter the quantity in kilograms: 3.5  
```
---

### **Expected Output:**  

```plaintext
--- Grocery Store Receipt ---
Fruit: Mangoes  
Price per kilogram: $4.25  
Quantity: 3.50 kg  
Total price: $14.88  
Thank you for shopping with us!  
```
---
