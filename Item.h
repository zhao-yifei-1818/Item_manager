#ifndef ITEM_H
#define ITEM_H

#include <string>
class Person{
  private:
  Item* item;
  std::string name;
  double pay;
  public:
  Person();
  Person(std::string name);
  int getItem();
  double getPay();
  
};
class Item {
private:
  int value;
  std::string date;
  int costToShip;

public:
  Item();
  Item(const std::string& rec, int v, int d, int c);

  std::string getRecipient() const;
  int getValue() const;
  int getDate() const;
  int getCostToShip() const;
  double getReward() const;

  // Additional member functions
  void calculateReward();
  void printItem() const;
};

#endif // ITEM_H