#include "Item.h"
#include "Manager.h"
#include <iostream>
#include <limits>
#include <sstream>

int main()
{
  Manager manager;
  std::string line;
  int selection = 5;

  while (selection != 0) {
    std::cout << "Input an Action number:\n"
              << "1: Add Item\n"
              << "2: Load from items.txt\n"
              << "3: Print All Items\n"
              << "4: Export to items.txt\n"
              << "0: Exit\n"
              << "Input: ";
    std::cin >> selection;

    // Clear the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (selection == 1) {
      std::cout << "Enter item details (recipient, value, date, cost to ship) "
                   "separated by spaces: ";
      std::getline(std::cin, line);

      std::stringstream ss(line);
      std::string recipient;
      int value, date, costToShip;

      ss >> recipient >> value >> date >> costToShip;

      Item newItem(recipient, value, date, costToShip);
      manager.addItem(newItem);

      std::cout << "Item added successfully.\n";
    } else if (selection == 2) {
      manager.readFromFile("items.txt");
      std::cout << "Items loaded from items.txt.\n";
    } else if (selection == 3) {
      manager.printAllItems();
    } else if (selection == 4) {
      manager.exportToFile("items.txt");
      std::cout << "Items exported to items.txt.\n";
    } else if (selection != 0) {
      std::cout << "Invalid selection. Please try again.\n";
    }
  }

  std::cout << "Program exited.\n";
  return 0;
}
