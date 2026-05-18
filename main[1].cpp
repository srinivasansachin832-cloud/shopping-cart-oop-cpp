#include <iostream>
#include <string>
#include "ShoppingCart.h"
using namespace std;

void PrintMenu() {
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
   cout << "Choose an option:" << endl;
}

void ExecuteMenu(char option, ShoppingCart& cart) {
   string name, description;
   int price, quantity;

   if (option == 'a') {
      cout << "ADD ITEM TO CART" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, name);

      cout << "Enter the item description:" << endl;
      getline(cin, description);

      cout << "Enter the item price:" << endl;
      cin >> price;

      cout << "Enter the item quantity:" << endl;
      cin >> quantity;
      cin.ignore();

      ItemToPurchase item(name, description, price, quantity);
      cart.AddItem(item);
      cout << endl;
   }
   else if (option == 'd') {
      cout << "REMOVE ITEM FROM CART" << endl;
      cout << "Enter name of item to remove:" << endl;
      getline(cin, name);

      cart.RemoveItem(name);
      cout << endl;
   }
   else if (option == 'c') {
      cout << "CHANGE ITEM QUANTITY" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, name);

      cout << "Enter the new quantity:" << endl;
      cin >> quantity;
      cin.ignore();

      ItemToPurchase item;
      item.SetName(name);
      item.SetQuantity(quantity);

      cart.ModifyItem(item);
      cout << endl;
   }
   else if (option == 'i') {
      cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
      cart.PrintDescriptions();
      cout << endl;
   }
   else if (option == 'o') {
      cout << "OUTPUT SHOPPING CART" << endl;
      cart.PrintTotal();
      cout << endl;
   }
   // invalid option: do nothing
}

int main() {
   string customerName;
   string currentDate;

   cout << "Enter customer's name:" << endl;
   getline(cin, customerName);

   cout << "Enter today's date:" << endl;
   getline(cin, currentDate);

   cout << endl;

   ShoppingCart cart(customerName, currentDate);

   char option = ' ';

   while (option != 'q') {
      PrintMenu();
      cin >> option;
      cin.ignore();

      if (option == 'q') {
         cout << endl;
         break;
      }

      if (option == 'a' || option == 'd' || option == 'c' ||
          option == 'i' || option == 'o') {
         cout << endl;
         ExecuteMenu(option, cart);
      }
   }

   return 0;
}