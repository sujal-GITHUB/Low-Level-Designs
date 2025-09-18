#include <bits/stdc++.h>
using namespace std;

static int vending_machine_number = 1;
static int product_number = 1;
static int customer_number = 1;

class Product {
    int productId;
    double price;
    string name;

public:
    Product(string name, double price) {
        this->name = name;
        this->productId = product_number++;
        this->price = price;
    }

    double getPrice(){ 
        return price; 
    }

    string getName(){ 
        return name; 
    }

    int getId(){ 
        return productId; 
    }
};

class VendingMachine {
    int id;
    unordered_map<Product*, int> ProductQuantity;
    int totalMoney;

public:
    set<Product*> products;

    VendingMachine() {
        id = vending_machine_number++;
        totalMoney = 0;
    }

    void addProduct(string name, double price) {
        Product* product = new Product(name, price);
        products.insert(product);
        ProductQuantity[product] = 1;
    }

    void addProduct(string name, double price, int quantity) {
        for (auto it : products) {
            if (it->getName() == name) {
                ProductQuantity[it] += quantity;
                return;
            }
        }
        addProduct(name, price);
        ProductQuantity[*products.rbegin()] += (quantity - 1);
    }

    bool inStock(Product* product, int quantity) {
        auto pr = products.find(product);

        if (pr == products.end()) 
        return false;

        if (ProductQuantity[product] < quantity) 
        return false;

        return true;
    }

    int giveChange(int cost, int amountGiven) {
        return amountGiven - cost;
    }

    int sellProduct(Product* product, int quantity, int cash) {
        if (!inStock(product, quantity)) {
            cout << "Product not in Stock!" << endl;
            return -1;
        }

        int cost = product->getPrice() * quantity;

        if (cash < cost) {
            cout << "Insufficient funds!" << endl;
            return -1;
        }

        ProductQuantity[product] -= quantity;
        totalMoney += cost;
        return giveChange(cost, cash);
    }

    int getStock(Product* product) {
        auto p = ProductQuantity.find(product);

        if (p == ProductQuantity.end()) 
        return 0;

        return p->second;
    }

    void removeProduct(Product* product) {
        products.erase(product);
        ProductQuantity.erase(product);
        delete product;
    }
};

class Customer {
    int customerId;
    string customerName;

public:
    Customer(string name) {
        this->customerName = name;
        this->customerId = customer_number++;
    }
};

int main() {
    VendingMachine vm;

    // --- Add Products ---
    cout << "=== Adding Products ===" << endl;
    vm.addProduct("Coke", 25.0, 5);
    vm.addProduct("Pepsi", 20.0, 3);
    vm.addProduct("Water", 10.0);

    // --- Get Product pointers ---
    Product* coke = nullptr;
    Product* pepsi = nullptr;
    Product* water = nullptr;

    // loop through vending machine's internal set
    for (auto p : vm.products) {
        if (p->getName() == "Coke") coke = p;
        if (p->getName() == "Pepsi") pepsi = p;
        if (p->getName() == "Water") water = p;
    }

    cout << "\n=== Initial Stock ===" << endl;
    cout << "Coke: " << vm.getStock(coke) << endl;   // expect 5
    cout << "Pepsi: " << vm.getStock(pepsi) << endl; // expect 3
    cout << "Water: " << vm.getStock(water) << endl; // expect 1

    // --- Sell Product (Valid Sale) ---
    cout << "\n=== Selling Coke (Valid) ===" << endl;
    cout << "Change returned: " << vm.sellProduct(coke, 2, 60) << endl; // expect 10
    cout << "Remaining Coke stock: " << vm.getStock(coke) << endl;      // expect 3

    // --- Sell Product (Insufficient Money) ---
    cout << "\n=== Selling Pepsi (Insufficient Money) ===" << endl;
    cout << "Change returned: " << vm.sellProduct(pepsi, 2, 30) << endl; // expect -1
    cout << "Remaining Pepsi stock: " << vm.getStock(pepsi) << endl;     // expect 3

    // --- Sell Product (Insufficient Stock) ---
    cout << "\n=== Selling Water (Not Enough Stock) ===" << endl;
    cout << "Change returned: " << vm.sellProduct(water, 5, 100) << endl; // expect -1
    cout << "Remaining Water stock: " << vm.getStock(water) << endl;      // expect 1

    // --- Remove Product ---
    cout << "\n=== Removing Coke ===" << endl;
    vm.removeProduct(coke);
    cout << "Stock after removal (Coke): " << vm.getStock(coke) << endl; // expect 0

    // --- Try selling removed product ---
    cout << "\n=== Selling Removed Product (Coke) ===" << endl;
    cout << "Change returned: " << vm.sellProduct(coke, 1, 50) << endl; // expect -1

    cout << "\n=== Test Completed ===" << endl;
    return 0;
}