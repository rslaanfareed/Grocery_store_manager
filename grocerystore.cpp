#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
#include <iomanip>
using namespace std;

const int MAX_ITEMS = 1000;

string itemNames[MAX_ITEMS];
float itemPrices[MAX_ITEMS];
int itemQuantities[MAX_ITEMS];
int itemCount = 0;

string toLowerStr(const string& s) {
    string res = s;
    for (char &c : res) c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    return res;
}

void loadInventory() {
    ifstream inFile("inventory.txt");
    if (inFile.is_open()) {
        inFile >> itemCount;
        for (int i = 0; i < itemCount; i++) {
            inFile >> itemNames[i] >> itemPrices[i] >> itemQuantities[i];
        }
        inFile.close();
    } else {
        cout << "No previous inventory data found." << endl;
    }
}

void saveInventory() {
    ofstream outFile("inventory.txt");
    if (outFile.is_open()) {
        outFile << itemCount << endl;
        for (int i = 0; i < itemCount; i++) {
            outFile << itemNames[i] << " " << itemPrices[i] << " " << itemQuantities[i] << endl;
        }
        outFile.close();
    } else {
        cout << "Unable to save inventory data." << endl;
    }
}

void updateItem(); // forward declaration

void addItem() {
    if (itemCount < MAX_ITEMS) {
        string name;
        cout << "Enter item name: ";
        getline(cin, name);

        for (int i = 0; i < itemCount; i++) {
            if (toLowerStr(itemNames[i]) == toLowerStr(name)) {
                cout << "You already have " << itemNames[i] << " in inventory. Updating it instead.\n";

                int newQuantity;
                float newPrice;

                cout << "Enter new quantity for " << itemNames[i] << ": ";
                cin >> newQuantity;
                cout << "Enter new price for " << itemNames[i] << ": ";
                cin >> newPrice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                itemQuantities[i] = newQuantity;
                itemPrices[i] = newPrice;

                cout << "Item updated!\n";
                saveInventory();
                return;
            }
        }

        cout << "Enter item price: ";
        cin >> itemPrices[itemCount];
        cout << "Enter item quantity: ";
        cin >> itemQuantities[itemCount];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        itemNames[itemCount] = name;
        itemCount++;
        saveInventory();
    } else {
        cout << "Inventory is full!" << endl;
    }
}


void displayInventory() {
    cout << "\nInventory:\n";
    cout << "---------------------------------------------\n";

    cout << left << setw(20) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Quantity" << endl;

    cout << "---------------------------------------------\n";

    for (int i = 0; i < itemCount; i++) {
        cout << left << setw(20) << itemNames[i]
             << setw(10) << itemPrices[i]
             << setw(10) << itemQuantities[i] << endl;
    }
}


void updateItem() {
    string itemName;
    int newQuantity;
    float newPrice;

    cout << "Enter item name to update: ";
    getline(cin, itemName);

    for (int i = 0; i < itemCount; i++) {
        if (toLowerStr(itemNames[i]) == toLowerStr(itemName)) {
            cout << "Enter new quantity for " << itemNames[i] << ": ";
            cin >> newQuantity;
            itemQuantities[i] = newQuantity;

            cout << "Enter new price for " << itemNames[i] << ": ";
            cin >> newPrice;
            itemPrices[i] = newPrice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Item updated!" << endl;
            saveInventory();
            return;
        }
    }
    cout << "Item not found!" << endl;
}

void deleteItem() {
    string itemName;
    cout << "Enter item name to delete: ";
    getline(cin, itemName);

    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (toLowerStr(itemNames[i]) == toLowerStr(itemName)) {
            found = true;
            for (int j = i; j < itemCount - 1; j++) {
                itemNames[j] = itemNames[j + 1];
                itemPrices[j] = itemPrices[j + 1];
                itemQuantities[j] = itemQuantities[j + 1];
            }
            itemCount--;
            cout << "Item deleted!" << endl;
            saveInventory();
            break;
        }
    }
    if (!found) cout << "Item not found!" << endl;
}

void calculateTotalCost() {
    string itemName;
    int quantity;
    float totalCost = 0.0;

    cout << "Enter item name and quantity to purchase (type 'done' to finish):" << endl;

    while (true) {
        cout << "Item name: ";
        getline(cin, itemName);
        if (toLowerStr(itemName) == "done") break;

        cout << "Quantity: ";
        cin >> quantity;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < itemCount; i++) {
            if (toLowerStr(itemNames[i]) == toLowerStr(itemName)) {
                if (itemQuantities[i] >= quantity) {
                    totalCost += itemPrices[i] * quantity;
                    itemQuantities[i] -= quantity;
                } else {
                    cout << "Not enough stock for " << itemNames[i] << endl;
                }
                break;
            }
        }
    }

    cout << "Total cost: " << totalCost << endl;
    saveInventory();
}

int main() {
    int choice;
    loadInventory();

    while (true) {
        cout << "\nGrocery Store Management System\n";
        cout << "1. Add Item\n2. Display Inventory\n3. Update Item\n4. Run a sale\n5. Delete Item\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayInventory(); break;
            case 3: updateItem(); break;
            case 4: calculateTotalCost(); break;
            case 5: deleteItem(); break;
            case 6:
                saveInventory();
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
