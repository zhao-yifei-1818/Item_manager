#include "Manager.h"
#include <fstream>
#include <iostream>


//one person is pushed to manager vector.
void Manager::addPerson(const Person& person)
{
  personList.push_back(person);
}

//This list of packages is all printed
void Manager::printAllpackages() const
{
  for (const auto& person : personList) {
    int index = 1;
    for (const auto& package : person.getPackageList()) {
      std::cout<< "\tIndex: " << index<<"Package details:" <<std::endl;
      package.printThisPackage();
      ++index;
    }
  }
}
//This list of persons is all printed
void Manager::printAllpersons() const
{
  for (const auto& person : personList) {
    person.printThisPerson();
  }
}

void Manager::exportToFile(const std::string& filename) const
{
  std::ofstream outFile(filename);
  if (!outFile) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }

  for (const auto& person : personList) {
    person.printThisPersonOstream(outFile);
  }

  outFile.close();
  std::cout << "package details exported to " << filename << std::endl;
}

//need further attention
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
  }

  inFile.close();
  std::cout << "package details read from " << filename << std::endl;
}
