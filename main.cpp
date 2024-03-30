#include "Manager.h"
#include <iostream>
#include <sstream>

int main()
{
  Manager manager;
  std::string line;

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
  manager.exportToFile("items.txt");

  return 0;
}
