#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string> 
using namespace std;

class ItemToPurchase {
    public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price = 0, int quantity = 0); 
    
    //Mutators 
    void SetName(string name);
    void SetDescription(string description);
    void SetPrice(int price);
    void SetQuantity(int quantity);

    // Accessors
      string GetName() const;
      string GetDescription() const;
      int GetPrice() const;
      int GetQuantity() const;

      // Output helpers
      void PrintItemCost() const;
      void PrintItemDescription() const;

   private:
      string itemName;
      string itemDescription;
      int itemPrice;
      int itemQuantity;
};
#endif