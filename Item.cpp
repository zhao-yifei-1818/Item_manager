#include "Item.h"
#include <iostream>

Item::Item():
    recipient("Unknown"), value(0), date(0), costToShip(0), reward(0.0)
{
}

Item::Item(const std::string& rec, int v, int d, int c):
    recipient(rec), value(v), date(d), costToShip(c)
{
  calculateReward();
}
std::string Item::getRecipient() const
{
  return recipient;
}

int Item::getValue() const
{
  return value;
}

int Item::getDate() const
{
  return date;
}

int Item::getCostToShip() const
{
  return costToShip;
}
int Item::getReward() const
{
  return reward;
}
void Item::calculateReward()
{
  if (value <= 10000) {
    reward = 0.02 * value;
  } else if (value >= 50000) {
    reward = 0.015 * value;
  } else {
    reward = 0.0175 * value;
  }
}

void Item::printItem() const
{
  std::cout << "Recipient: " << recipient << ", Value: " << value
            << ", Date: " << date << ", Cost to Ship: " << costToShip
            << ", Reward: " << reward << std::endl;
}