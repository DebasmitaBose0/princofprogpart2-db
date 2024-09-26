//C + + class to manage a shopping list allowing addition removal and display of items with total cost collection 
#include <iostream>

class ShoppingItem
{
public:
    char name[20]; // Array to store item name
    float price;
    int quantity;

    ShoppingItem(const char *itemName = "", float itemPrice = 0.0, int itemQuantity = 0)
    {
        int i = 0;
        while (itemName[i] != '\0' && i < 19)
        {
            name[i] = itemName[i];
            i++;
        }
        name[i] = '\0'; // Null terminate the string
        price = itemPrice;
        quantity = itemQuantity;
    }

    float totalCost()
    {
        return price * quantity;
    }
};

class ShoppingList
{
private:
    ShoppingItem items[100]; // Array to store up to 100 items
    int itemCount;           // Number of items in the shopping list

public:
    ShoppingList() : itemCount(0) {}

    void addItem(const char *itemName, float price, int quantity)
    {
        if (itemCount < 100)
        {
            items[itemCount++] = ShoppingItem(itemName, price, quantity);
        }
        else
        {
            std::cout << "Shopping list is full!\n";
        }
    }

    void removeItem(int index)
    {
        if (index >= 0 && index < itemCount)
        {
            for (int i = index; i < itemCount - 1; i++)
            {
                items[i] = items[i + 1]; // Shift items left to remove the item
            }
            itemCount--;
        }
        else
        {
            std::cout << "Invalid index!\n";
        }
    }

    void displayList()
    {
        if (itemCount == 0)
        {
            std::cout << "Shopping list is empty!\n";
            return;
        }

        std::cout << "Shopping List:\n";
        for (int i = 0; i < itemCount; i++)
        {
            std::cout << i + 1 << ". " << items[i].name << " - $" << items[i].price << " x " << items[i].quantity
                      << " = $" << items[i].totalCost() << "\n";
        }
    }

    float getTotalCost()
    {
        float totalCost = 0.0;
        for (int i = 0; i < itemCount; i++)
        {
            totalCost += items[i].totalCost();
        }
        return totalCost;
    }
};

int main()
{
    ShoppingList list;

    list.addItem("Apples", 1.99, 4);
    list.addItem("Bread", 2.49, 2);
    list.addItem("Milk", 3.19, 1);

    list.displayList();
    std::cout << "Total Cost: $" << list.getTotalCost() << "\n";

    list.removeItem(1); // Remove "Bread"
    list.displayList();
    std::cout << "Total Cost: $" << list.getTotalCost() << "\n";

    return 0;
}
