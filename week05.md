
---

## **Scenario:**  
You are developing a **loan approval system** for a bank. The system must:  

✔ **Check if a customer qualifies for a loan** based on **salary** and **credit score**.  
✔ **Determine the interest rate** based on the loan amount and customer’s credit score.  
✔ **Display a loan summary** including the **total repayment amount**.  

---

## **Loan Eligibility Criteria:**  
To qualify for a loan, the customer must meet all the following conditions:  
- **Annual salary must be at least $30,000.**  
- **Credit score must be 650 or higher.**  
- **Requested loan amount must be between $5,000 and $100,000.**  

If any of these conditions are **not met**, the loan is **denied**, and an appropriate message is displayed.  

---

## **Interest Rate Calculation:**  
If the loan is **approved**, the interest rate is assigned based on the **credit score** and **loan amount** as per the table below:  

| **Credit Score** | **Loan Amount ≤ $50,000** | **Loan Amount > $50,000** |
|-----------------|----------------------|----------------------|
| **750+**        | **5% interest**       | **4.5% interest**   |
| **700 - 749**   | **6.5% interest**     | **6% interest**     |
| **650 - 699**   | **8% interest**       | **7.5% interest**   |

**Formula to calculate total repayment amount:**  
\[
Total Payable = Loan Amount + (Loan Amount * Interest Rate)
\]

---

## **Programming Task:**  

You will create a **modular C program (`lab4e.c`)** that follows these steps:  

### **1. Header File (`loan_utils.h`)**  
- Declare the following functions:
  - `int isEligible(int salary, int creditScore, float loanAmount);`  
  - `float getInterestRate(int creditScore, float loanAmount);`  
  - `void displayLoanDetails(int salary, int creditScore, float loanAmount, int eligible, float interestRate);`  

### **2. Implementation File (`loan_utils.c`)**  
- Define the functions declared in `loan_utils.h`:  
  - **`isEligible`** → Checks if the applicant meets the **eligibility criteria** and returns `1` (eligible) or `0` (not eligible).  
  - **`getInterestRate`** → Determines the **interest rate** based on **loan amount** and **credit score**.  
  - **`displayLoanDetails`** → Prints the loan **approval/rejection** message, **interest rate**, and **total repayment amount**.  

### **3. Main File (`main.c`)**  
- **Gets user input** for salary, credit score, and loan amount.  
- Calls **`isEligible()`** to check loan approval.  
- If eligible, calls **`getInterestRate()`** to determine the **applicable interest rate**.  
- Calls **`displayLoanDetails()`** to **print loan details**.  

---

## **Prompt Example:**  
```plaintext
Enter your annual salary: 
Enter your credit score: 
Enter the loan amount requested: 
```

---

## **Expected Output Examples:**  

### **Example 1: Approved Loan (High Credit Score, Small Loan)**  
**Input:**  
```plaintext
Enter your annual salary: 60000  
Enter your credit score: 730  
Enter the loan amount requested: 45000  
```
**Output:**  
```plaintext
Loan Approved!
Interest Rate: 6.50%
Total Payable Amount: $48,925.00
```

---

### **Example 2: Approved Loan (Very High Credit Score, Large Loan)**  
**Input:**  
```plaintext
Enter your annual salary: 80000  
Enter your credit score: 770  
Enter the loan amount requested: 70000  
```
**Output:**  
```plaintext
Loan Approved!
Interest Rate: 4.50%
Total Payable Amount: $73,150.00
```

---

### **Example 3: Rejected Loan (Low Salary)**  
**Input:**  
```plaintext
Enter your annual salary: 25000  
Enter your credit score: 780  
Enter the loan amount requested: 30000  
```
**Output:**  
```plaintext
Loan Denied. Minimum salary requirement is $30,000.
```

---

### **Example 4: Rejected Loan (Bad Credit Score)**  
**Input:**  
```plaintext
Enter your annual salary: 55000  
Enter your credit score: 620  
Enter the loan amount requested: 50000  
```
**Output:**  
```plaintext
Loan Denied. Minimum credit score requirement is 650.
```

---

### **Example 5: Rejected Loan (Loan Amount Too High)**  
**Input:**  
```plaintext
Enter your annual salary: 75000  
Enter your credit score: 800  
Enter the loan amount requested: 150000  
```
**Output:**  
```plaintext
Loan Denied. Loan amount must be between $5,000 and $100,000.
```

---
