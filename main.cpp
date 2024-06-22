#include "package.h"
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
              << "1: Print All Current File\n"
              << "X2: Add package\n"
              << "X3: Load from packages.txt\n"
              << "X4: Export to packages.txt\n"
              << "0: Exit\n"
              << "Input: ";
    std::cin >> selection;

    // Clear the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (selection == 1) {
      manager.printAllpersons();
    } else if (selection == 2) {
      std::cout << "Enter package details (value, date, cost to ship) "
                   "separated by spaces: ";
      std::getline(std::cin, line);
      std::stringstream ss(line);
      double value, shippingCost;
      std::string date;
      ss >> value >> date >> shippingCost;

      Package newpackage(value, date, shippingCost);
      manager.addPackage(newpackage);
            std::cout << "package added successfully.\n";

      
      std::cout << "packages loaded from packages.txt.\n";
    } else if (selection == 3) {
      manager.readFromFile("packages.txt");
      
    } else if (selection == 4) {
      manager.exportToFile("packages.txt");
      std::cout << "packages exported to packages.txt.\n";
    } else if (selection != 0) {
      std::cout << "Invalid selection. Please try again.\n";
    }
  }

  std::cout << "Program exited.\n";
  return 0;
}
