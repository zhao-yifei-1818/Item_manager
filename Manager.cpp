#include "Manager.h"
#include <fstream>
#include <iostream>
void Manager::addItem(const Item& item)
{
  items.push_back(item);
}

void Manager::printAllItems() const
{
  for (const auto& item : items) {
    item.printItem();
  }
}
void Manager::exportToFile(const std::string& filename) const
{
  std::ofstream outFile(filename);
  if (!outFile) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }

  for (const auto& item : items) {
    outFile << item.getRecipient() << " " << item.getValue() << " "
            << item.getDate() << " " << item.getCostToShip() << " "
            << item.getReward() << std::endl;
  }

  outFile.close();
  std::cout << "Item details exported to " << filename << std::endl;
}

void Manager::readFromFile(const std::string& filename)
{
  std::ifstream inFile(filename);
  if (!inFile) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }

  std::string recipient;
  int value, date, costToShip;
  while (inFile >> recipient >> value >> date >> costToShip) {
    addItem(Item(recipient, value, date, costToShip));
  }

  inFile.close();
  std::cout << "Item details read from " << filename << std::endl;
}
