Grocery Store Management System (C++)

A console-based grocery store inventory and billing system built in C++.
This program allows managing store items, updating stock, and calculating customer bills with data saved between runs.

Overview
This project simulates a small grocery store management system. It keeps track of items, their prices, and quantities. The inventory is stored in a file so data is not lost when the program closes.

⚙️ Features
Add new grocery items
Automatically update item if it already exists
Display formatted inventory table
Update item price and quantity
Delete items from inventory
Run a sale and calculate total bill
Reduces stock after purchase
Data persistence using file handling

💾 Data Storage

Inventory is saved in:
inventory.txt
This file stores:
Item name
Item price
Item quantity
The file is loaded automatically when the program starts.

🧠 Concepts Used
Arrays
Functions
File handling (ifstream / ofstream)
String manipulation
Case-insensitive search
Menu-driven programs
Input validation handling

🛠 Technologies
C++
Standard Library (iostream, fstream, iomanip, etc.)
Runs in terminal/console
▶ How to Run
Compile
g++ grocerystore.cpp -o store
Execute
store

📂 Program Structure
Function	            Purpose
loadInventory() 	    Loads saved items from file
saveInventory()	      Saves inventory to file
addItem()	            Adds or updates an item
displayInventory()	  Shows all items in table format
updateItem()	        Changes price/quantity
deleteItem()	        Removes an item
calculateTotalCost()	Processes a sale and updates stock

🚀 Program Flow
Inventory loads from file
User chooses option from menu
Operations modify in-memory data
Inventory saved after changes

📚 Learning Outcomes
Through this project, I practiced:
Managing structured data
Persistent storage using files
Designing interactive console applications
Handling user input safely
Implementing real-world logic in C++
