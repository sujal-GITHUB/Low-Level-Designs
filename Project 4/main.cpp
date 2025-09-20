#include<bits/stdc++.h>
using namespace std;

class Coffee{
    string type;
    double price;
    unordered_map<string, double>ingredients;

    public:

    string getType(){
        return this->type;
    }

    double getPrice(){
        return this->price;
    }

    unordered_map<string, double> getIngredients(){
        return this->ingredients;
    }

    void addIngredient(string item, double quantity){
        ingredients[item] = quantity;
    }
    
    Coffee(string type, double price){
        this->price = price;
        this->type = type;
    }
};

class CoffeeVendingMachine {
    unordered_set<Coffee*> CoffeeTypes;
    unordered_map<Coffee*, int> stock;
    unordered_map<string, Coffee*> nameToCoffee;
    unordered_map<string, double> ingredientInventory;
    mutex mtx;

public:

    void showMenu(){
        for(auto it: stock){
            cout << "Coffee : " << it.first->getType()
                << "  Price : Rs." << it.first->getPrice()
                << "  Stock : " << it.second << endl;
        }
    }

    void addCoffee(string type, double price, int quantity) {
        lock_guard<mutex> lock(mtx);
        if(nameToCoffee.find(type) == nameToCoffee.end()){
            Coffee* coffee = new Coffee(type, price);
            nameToCoffee[type] = coffee;
            CoffeeTypes.insert(coffee);
        }

        stock[nameToCoffee[type]] += quantity;
    }

    void addIngredients(string type, vector<pair<string, double>> ingredients){
        lock_guard<mutex> lock(mtx);
        if(nameToCoffee.find(type) == nameToCoffee.end()){
            cout << "Coffee type not present!" << endl;
            return;
        }

        Coffee* coffee = nameToCoffee[type];
        for(auto &p: ingredients){
            coffee->addIngredient(p.first, p.second);
        }
    }

    void addInventory(string item, double quantity) {
        lock_guard<mutex> lock(mtx);
        ingredientInventory[item] += quantity;
    }

    int buyCoffee(string type, int quantity, double amount) {
        lock_guard<mutex> lock(mtx);

        if (nameToCoffee.find(type) == nameToCoffee.end()) {
            cout << "Coffee not available!" << endl;
            return -1;
        }

        Coffee* coffee = nameToCoffee[type];
        if (stock[coffee] < quantity) {
            cout << "Not enough stock!" << endl;
            return -1;
        }

        double cost = coffee->getPrice() * quantity;
        if (amount < cost) {
            cout << "Insufficient funds! Need: Rs." << cost << endl;
            return -1;
        }

        for (auto &ing : coffee->getIngredients()) {
            string item = ing.first;
            double required = ing.second * quantity;
            if (ingredientInventory[item] < required) {
                cout << "Not enough " << item << " to make " << type << endl;
                return -1;
            }
        }

        for(auto &ing : coffee->getIngredients()) {
            ingredientInventory[ing.first] -= ing.second * quantity;
            if (ingredientInventory[ing.first] < 10) {
                cout << "Low on " << ing.first << endl;
            }
        }

        stock[coffee] -= quantity;
        double change = amount - cost;
        cout << "Dispensed " << quantity << " " << type << "(s). Change: Rs." << change << endl;
        return change;
    }
};

int main() {
    CoffeeVendingMachine machine;

    // Add coffee types
    machine.addCoffee("Espresso", 50.0, 5);   // ₹50
    machine.addCoffee("Latte", 70.0, 3);      // ₹70
    machine.addCoffee("Cappuccino", 80.0, 2); // ₹80

    // Add recipes
    machine.addIngredients("Espresso", {{"CoffeePowder", 10}, {"Water", 30}});
    machine.addIngredients("Latte", {{"CoffeePowder", 8}, {"Milk", 100}, {"Sugar", 5}});
    machine.addIngredients("Cappuccino", {{"CoffeePowder", 10}, {"Milk", 80}, {"Sugar", 10}, {"Foam", 20}});

    // Add machine ingredient inventory
    machine.addInventory("CoffeePowder", 100);
    machine.addInventory("Water", 200);
    machine.addInventory("Milk", 300);
    machine.addInventory("Sugar", 100);
    machine.addInventory("Foam", 50);

    cout << "\n===== MENU =====\n";
    machine.showMenu();
    cout << "================\n\n";

    // Test cases
    cout << "\n--- Test 1: Successful purchase ---\n";
    machine.buyCoffee("Latte", 1, 100); // enough money + ingredients

    cout << "\n--- Test 2: Insufficient funds ---\n";
    machine.buyCoffee("Espresso", 1, 20); // not enough money

    cout << "\n--- Test 3: Not enough stock ---\n";
    machine.buyCoffee("Cappuccino", 5, 500); // only 2 available

    cout << "\n--- Test 4: Not enough ingredients ---\n";
    machine.buyCoffee("Latte", 5, 500); // should fail due to milk shortage

    cout << "\n===== MENU After Purchases =====\n";
    machine.showMenu();

    return 0;
}