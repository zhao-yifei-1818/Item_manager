#ifndef MANAGER_H
#define MANAGER_H

#include "Item.h"
#include <vector>

class Manager {
private:
  std::vector<Item> items;

public:
  void addItem(const Item& item);
  void printAllItems() const;
  void exportToFile(const std::string& filename) const;
};

#endif // MANAGER_H
