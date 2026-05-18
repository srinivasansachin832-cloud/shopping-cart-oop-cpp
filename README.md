# Shopping Cart OOP Project in C++

A command-line shopping cart application written in C++ using object-oriented design principles.

## Overview
This project models a basic shopping cart system using multiple classes and separate header/source files. It supports adding items, removing items, modifying item quantities, printing item descriptions, and calculating the total cart cost.

## Features
- Object-oriented class design
- Separate `.h` and `.cpp` files
- Item representation with name, description, price, and quantity
- Shopping cart management using a vector of items
- Menu-driven console interface
- Cost calculation and item description output

## Files
- `ItemToPurchase.h` - class declaration for individual cart items
- `ItemToPurchase.cpp` - class definition for item behavior
- `ShoppingCart.h` - class declaration for the shopping cart
- `ShoppingCart.cpp` - class definition for cart operations
- `main.cpp` - user interface and menu logic

## Concepts Used
- Classes and objects
- Constructors
- Encapsulation
- Accessors and mutators
- Vectors
- Input/output
- Multi-file C++ project structure

## How to Compile
Using g++:

```bash
g++ main.cpp ItemToPurchase.cpp ShoppingCart.cpp -o shoppingcart
./shoppingcart 
