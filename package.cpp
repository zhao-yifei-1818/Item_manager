#include "Package.h"
#include <iostream>

Package::Package():
    value(0), date("blankDate"), shippingCost(0)
{
}

Package::Package(double newValue, std::string newDate, double newShippingCost):
     value(newValue), date(newDate), shippingCost(newShippingCost)
{
}


double Package::getValue() const
{
  return value;
}

std::string Package::getDate() const
{
  return date;
}

double Package::getShippingCost() const
{
  return shippingCost;
}


double Package::calculateReward() const
{
  double reward;
  if (value <= 10000) {
    reward = 0.02 * value;
  } else if (value >= 50000) {
    reward = 0.015 * value;
  } else {
    reward = 0.0175 * value;
  }
  return reward;
}

void Package::printThisPackage() const
{
  std::cout <<"Value: " << value
            << ", Date: " << date << ", Cost to Ship: " << shippingCost<<std::endl;
}