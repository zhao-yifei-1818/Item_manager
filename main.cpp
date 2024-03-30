#include "Manager.h"
#include "Item.h"
#include <iostream>
#include <sstream>

int main()
{
  Manager manager;
  std::string line;
  int selection = 0;
  while(selection != 0){
    std::cout << "Input an Action number:\n1: Add Item\n2: Load from Item.txt3: printAll()4: Export to Item.txt\nInput: "<< std::endl;
    if (selection == 1){
  std::cout << "Enter item details (recipient, value, date, cost to ship) "
               "separated by spaces: ";
  std::getline(std::cin, line);

  std::stringstream ss(line);
  std::string recipient;
  int value, date, costToShip;

  ss >> recipient >> value >> date >> costToShip;

  Item newItem(recipient, value, date, costToShip);
  manager.addItem(newItem);

  std::cout << "Added item details:\n";
  manager.printAllItems();
  // Export item details to a text file
    }
    else if (selection == 2){
      manager.readFromFile("items.txt");
    }
    else if (selection == 3){
    manager.printAllItems();

    }
    else if (selection == 4){
    manager.exportToFile("items.txt");

    }
  }

  return 0;
}