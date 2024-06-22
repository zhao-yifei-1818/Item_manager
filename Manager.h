#ifndef MANAGER_H
#define MANAGER_H

#include "package.h"
#include <vector>

class Manager {
private:
  std::vector<Person> personList;
  //assume this is total need to be paid.
  double totalToPay;
  //assume this is total shipping cost that needs to be reported.
  double totalShippingCost;
public:
  void addPerson(const Person& person);// take existing Person, add to Person array
  void printAllpackages() const;
  void printAllpersons() const;
  void exportToFile(const std::string& filename) const;
  void readFromFile(const std::string& filename);

};

#endif // MANAGER_H
