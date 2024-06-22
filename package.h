#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <vector>
#include <iostream>
class Person{
  public:
  //constructor
  Person();
  Person(std::string newName);

  //get functions
  std::vector<Package> getPackageList()const;
  double getPay()const;
  std::string getName()const;
  int getPackageCount()const;
  //utility functions
    //reward is added to the person depending on his payLevel.
  void addReward(double reward);
  //administration functions
    //print single person's everything
  void printThisPerson()const;
    //output single person's everything
  void printThisPersonOstream(std::ostream& out)const;
  private:
  //person has a list of packages
  std::vector<Package> packageList;
  //person's name
  std::string name;
  //person's accumulated pay so far.
  double pay;
  //person's pay level, represented as number;
  int payLevel;
  //person's package count
  int packageCount;
};

class Package {
public:
  //Constructors
  Package();
  Package(double newValue, std::string newDate, double newShippingCost);

  //get functions
  double getValue() const;
  std::string getDate() const;
  double getShippingCost() const;

  //return its total reward as a number.
  double calculateReward() const;
  // Additional member functions
//administration functions
  //print this single package
  void printThisPackage() const;
  void printThisPackageOstream(std::ostream& out)const;
private:
  double value;
  std::string date;
  double shippingCost;
};

#endif // Package_H