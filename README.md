# Grocery Store Manager

A console-based grocery store management system built in C++. Handles inventory, billing, and persistent data storage - all from the terminal.

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

---

## Overview

This project simulates a real grocery store backend. It tracks items, prices, and stock quantities. All inventory data is saved to a file so nothing is lost between sessions - load, operate, save.

---

## Features

- Add new items or auto-update if item already exists
- Display full inventory in a formatted table
- Update item price and quantity
- Delete items from inventory
- Run a sale — calculates total bill and reduces stock automatically
- Data persists via file handling (`inventory.txt`)

---

## Functions

| Function | Purpose |
|---|---|
| `loadInventory()` | Loads saved items from file on startup |
| `saveInventory()` | Writes current inventory back to file |
| `addItem()` | Adds a new item or updates existing |
| `displayInventory()` | Renders all items in a table |
| `updateItem()` | Modifies price or quantity |
| `deleteItem()` | Removes an item from inventory |
| `calculateTotalCost()` | Processes a sale and adjusts stock |

---

## Concepts Used

- File I/O (`ifstream` / `ofstream`)
- Arrays and functions
- String manipulation and case-insensitive search
- Menu-driven program structure
- Input validation

---

## How to Run

**Compile**
```bash
g++ grocerystore.cpp -o store
```

**Run**
```bash
./store
```

> On Windows use `store.exe` or just `store` in the terminal.

---

## Project Structure
## Project Structure

```
Grocery_store_manager/
├── grocerystore.cpp
├── inventory.txt
└── README.md
```


---




**Muhammad Arslan Fareed** · [LinkedIn](https://www.linkedin.com/in/muhammadarslanfareed) · [GitHub](https://github.com/rslaanfareed)
