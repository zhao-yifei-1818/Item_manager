#ifndef MANAGER_H
#define MANAGER_H

#include "package.h"
#include <vector>

class Manager {
private:
  std::vector<Package> packages;

public:
  void addPackage(const Package& package);
  void printAllpackages() const;
  void exportToFile(const std::string& filename) const;
  void readFromFile(const std::string& filename);

};

#endif // MANAGER_H
