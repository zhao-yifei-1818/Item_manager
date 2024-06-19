#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
/*
class Person{
  public:
  //constructor
  Person();
  Person(std::string name);

  //c ctor

  //get functions
  int getPackage();
  double getPay();
  std::string getName();
  
  private:
  Package* package;
  std::string name;
  double pay;
  int package_count;
};
*/
class Package {
public:
  //Constructors
  Package();
  Package(double newValue, std::string newDate, double newShippingCost);

  //get functions
  double getValue() const;
  std::string getDate() const;
  double getShippingCost() const;

  // Additional member functions
  void printThisPackage() const;
  double calculateReward() const;

private:
  double value;
  std::string date;
  double shippingCost;
};

#endif // Package_H