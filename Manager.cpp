#include "Manager.h"
#include <fstream>
#include <iostream>
//one package is pushed to manager vector.
void Manager::addPackage(const Package& package)
{
  packages.push_back(package);
}

//This list of packages is all printed
void Manager::printAllpackages() const
{
  for (const auto& package : packages) {
    package.printThisPackage();
  }
}

void Manager::exportToFile(const std::string& filename) const
{
  std::ofstream outFile(filename);
  if (!outFile) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }

  for (const auto& package : packages) {
    outFile << package.getValue() << " "
            << package.getDate() << " " 
            << package.getShippingCost() << std::endl;
  }

  outFile.close();
  std::cout << "package details exported to " << filename << std::endl;
}

void Manager::readFromFile(const std::string& filename)
{
  std::ifstream inFile(filename);
  if (!inFile) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }

  std::string recipient;
  double value, shippingCost;
  std::string date;
  while (inFile >> value >> date >> shippingCost) {
    Package newPackage (value, date, shippingCost);
    addPackage(newPackage);
  }

  inFile.close();
  std::cout << "package details read from " << filename << std::endl;
}
