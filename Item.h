#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
  std::string recipient;
  int value;
  int date; // Format: mmddyy
  int costToShip;
  double reward;

public:
  Item();
  Item(const std::string& rec, int v, int d, int c);

  std::string getRecipient() const;
  int getValue() const;
  int getDate() const;
  int getCostToShip() const;
  int getReward() const;

  // Additional member functions
  void calculateReward();
  void printItem() const;
};

#endif // ITEM_H