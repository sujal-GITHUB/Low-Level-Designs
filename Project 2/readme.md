# Vending Machine Simulation (C++)

This project implements a simulation of a **Vending Machine system** using C++.  
It demonstrates core object-oriented programming concepts such as **classes**, **encapsulation**, **static members**, and **relationships between objects**.

---

## Features

- Add products with name, price, and quantity.  
- Sell products while checking stock and available money.  
- Return correct change to customers.  
- Remove products from the vending machine.  
- Track the vending machine’s total collected money.  
- Basic customer representation for interaction.  

---

## Classes Overview

### **Product**
- Represents an individual item.  
- Each product has:
  - Unique ID  
  - Name  
  - Price  

### **VendingMachine**
- Represents the machine holding all products.  
- Responsibilities:
  - Store and track products with quantities.  
  - Add and remove products.  
  - Sell products, check stock, and calculate change.  
  - Keep track of total money collected.  

### **Customer**
- Represents a customer interacting with the vending machine.  
- Each customer has:
  - Unique ID  
  - Name  
- Can be extended later to track purchase history or preferences.  

---

## Future Improvements

- Add a user-friendly interface for interaction.  
- Implement customer purchase history tracking.  
- Support different coin and currency denominations.  
- Replace raw pointers with smart pointers for better memory management.  
- Enhance error handling and edge-case validation.  
