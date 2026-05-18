#include <iostream>
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart() {
   customerName = "none";
   currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string customerName, string currentDate) {
   this->customerName = customerName;
   this->currentDate = currentDate;
}

string ShoppingCart::GetCustomerName() const {
   return customerName;
}

string ShoppingCart::GetDate() const {
   return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
   cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName) {
   for (unsigned int i = 0; i < cartItems.size(); ++i) {
      if (cartItems.at(i).GetName() == itemName) {
         cartItems.erase(cartItems.begin() + i);
         return;
      }
   }
   cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
   for (unsigned int i = 0; i < cartItems.size(); ++i) {
      if (cartItems.at(i).GetName() == item.GetName()) {

         // Only update fields that are not default values
         if (item.GetDescription() != "none") {
            cartItems.at(i).SetDescription(item.GetDescription());
         }
         if (item.GetPrice() != 0) {
            cartItems.at(i).SetPrice(item.GetPrice());
         }
         if (item.GetQuantity() != 0) {
            cartItems.at(i).SetQuantity(item.GetQuantity());
         }
         return;
      }
   }
   cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::GetNumItemsInCart() const {
   int totalQty = 0;
   for (unsigned int i = 0; i < cartItems.size(); ++i) {
      totalQty += cartItems.at(i).GetQuantity();
   }
   return totalQty;
}

int ShoppingCart::GetCostOfCart() const {
   int totalCost = 0;
   for (unsigned int i = 0; i < cartItems.size(); ++i) {
      totalCost += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
   }
   return totalCost;
}

void ShoppingCart::PrintTotal() const {
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << "Number of Items: " << GetNumItemsInCart() << endl;
   cout << endl;

   if (cartItems.empty()) {
      cout << "SHOPPING CART IS EMPTY" << endl;
      cout << endl;
      cout << "Total: $0" << endl;
      return;
   }

   for (unsigned int i = 0; i < cartItems.size(); ++i) {
      cartItems.at(i).PrintItemCost();
   }

   cout << endl;
   cout << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() const {
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << endl;
   cout << "Item Descriptions" << endl;

   for (unsigned int i = 0; i < cartItems.size(); ++i) {
      cartItems.at(i).PrintItemDescription();
   }
}