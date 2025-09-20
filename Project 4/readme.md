# Coffee Vending Machine Simulation (C++)

This project implements a simulation of a **Coffee Vending Machine system** using C++.  
It demonstrates object-oriented programming concepts such as **classes**, **encapsulation**, **composition**, and **thread safety** with `mutex`.

---

## Features

- Support for multiple coffee types: **Espresso, Latte, Cappuccino**, etc.  
- Each coffee has a **specific price** and a **recipe (ingredients + quantities)**.  
- Machine maintains an **ingredient inventory** and checks availability before dispensing.  
- Display a **menu** with available coffee types, prices, and stock.  
- Customers can purchase coffee with money; machine dispenses the coffee and returns **change**.  
- Low ingredient warnings when inventory runs short.  
- Thread-safe operations to handle **concurrent user requests**.  

---

## Classes Overview

### **Coffee**
- Represents an individual coffee type.  
- Each coffee has:
  - Name (e.g., Espresso, Latte)  
  - Price  
  - Recipe (ingredients with required quantities)  

### **CoffeeVendingMachine**
- Represents the machine that manages coffees and ingredients.  
- Responsibilities:
  - Add new coffee types with price and stock.  
  - Maintain and update ingredient inventory.  
  - Add recipes for each coffee type.  
  - Show the menu with prices and available stock.  
  - Handle customer purchases:
    - Check stock and ingredient availability.  
    - Deduct used ingredients.  
    - Dispense coffee and return change.  
    - Warn when ingredient levels are low.  
  - Ensure thread safety using `mutex`.  

---

## Example Workflow

1. Add coffee types (**Espresso, Latte, Cappuccino**) with price and stock.  
2. Define recipes for each coffee type (e.g., Espresso = CoffeePowder + Water).  
3. Load machine with ingredient inventory (CoffeePowder, Water, Milk, Sugar, Foam, etc.).  
4. Customers buy coffee by providing coffee type, quantity, and amount.  
5. Machine validates stock, ingredients, and funds before dispensing.  
6. Machine warns when an ingredient is running low.  

---

## Future Improvements

- Add a **graphical interface** for better user interaction.  
- Support for **multiple currencies/denominations**.  
- Implement **smart pointers** instead of raw pointers for memory safety.  
- Track **total money collected** by the machine.  
- Extend customer handling (purchase history, preferences, loyalty points).  
