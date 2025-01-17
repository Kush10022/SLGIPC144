# SLGIPC144
---
### **Scenario:**  
Imagine you’re helping a pizza restaurant calculate the total cost for an order. However, the system needs to handle some adjustments: the user enters the price per pizza and quantity as floating-point values, but the final bill uses integers for simplicity. Also, the restaurant sends promotional ASCII characters based on the number of pizzas ordered.  

---
In the file `SLGsession3.c`, write a program that:  

1. **Gets User Input**:  
   - Prompt the user to enter the **price per pizza** (a floating-point number).  
   - Prompt the user to enter the **quantity of pizzas** (also a floating-point number).  

2. **Calculates the Total Cost**:  
   - Multiply the price per pizza by the quantity to calculate the total cost.  

3. **Truncation and Explicit Casting**:  
   - Cast the total cost (a floating-point number) to an integer for billing purposes (truncate the fractional part).  
   - Display the truncated total cost.  

4. **Arithmetic Expression and Type Coercion**:  
   - Add a delivery fee of 5.99 (a floating-point constant) to the total cost. Store this value in a `float` variable, showing how coercion works.  
   - Print the final total (with delivery fee) formatted to two decimal places.  

5. **Narrowing Conversion**:  
   - Cast the truncated total cost of pizzas ordered (as an integer) to a `char`. Display the corresponding ASCII character for fun (e.g., if quantity is 65, it corresponds to 'A').  

6. **Final Output**:  
   - Clearly display the original inputs, the truncated total cost, the total with delivery fee, and the promotional ASCII character.
   - 
---

### **Prompt Example:**  
```plaintext
Enter the price per pizza:  
Enter the quantity of pizzas:  
```
---

### **Sample Output:**  

```plaintext
Enter the price per pizza: 9.99  
Enter the quantity of pizzas: 3.6  
Original total cost (float): 35.96  
Truncated total cost (int): 35  
Total cost with delivery (float): 40.99  
Promotional ASCII character for the quantity: D  
```

---
