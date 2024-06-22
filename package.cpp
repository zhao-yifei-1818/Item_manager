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
  //this is the original way of calculation
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
void Package::printThisPackageOstream(std::ostream out) const
{
  out <<"Value: " << value
            << ", Date: " << date << ", Cost to Ship: " << shippingCost<<std::endl;
}
// void Person::printThisPersonOstream(std::ostream out)const

Person::Person():name("Nobody"),pay(0),payLevel(0){}
Person::Person(std::string newName):name(newName),pay(0),payLevel(0){}

//get functions
//return the whole list of that package
std::vector<Package> Person::getPackageList()const{
  return packageList;
}

double Person::getPay()const{
  return pay;
}
std::string Person::getName()const{
  return name;
}
int Person::getPackageCount()const{
  return packageCount;
}

void Person::addReward(double reward)
{
  //default pay: update 1/3 reward to his pay
  if (payLevel== 0){
    pay+= reward/3;
    std::cout<<"$"<< reward/3 << " which is one third of share, is added to "<< name << std::endl;
    std::cout<<"his updated total pay is " << pay << std::endl;
  }
  //Else pay: update further reward to his pay
}
  void Person::printThisPerson()const{
    std::cout <<"Name: " << name
            << ", Pay: " << pay << ", Pay level: " <<
             payLevel<< ", Package count: " << packageCount <<
             std::endl;
    std::cout<<"---His recorded packages:---" << std::endl;
    int index = 1;
    for (const auto& obj : packageList) {
      std::cout<< "\tIndex: " << index<<"Package count" <<std::endl;
      obj.printThisPackage();
      ++index;
    }
  }
  void Person::printThisPersonOstream(std::ostream out)const{
    out <<"Name: " << name
            << ", Pay: " << pay << ", Pay level: " <<
             payLevel<< ", Package count: " << packageCount <<
             std::endl;
    out<<"---His recorded packages:---" << std::endl;
    int index = 1;
    for (const auto& obj : packageList) {
      out<< "\tIndex: " << index<<"Package count" <<std::endl;
      obj.printThisPackage();
      ++index;
    }
  }
