#include <fstream>
#include <iostream>
#include <vector>

class Vehicle {
 private:
  int a = 10;
 protected:
  int b = 100;
 public:
  std::string brand = "Ford";
  void beep() {
    std::cout << "Tuut, tuut! \\n";
  }
};
class Car : public Vehicle {
  void m() {
    //a = 100;
    b = 1000;
    brand = "";
  }
 public:
  std::string model = "Mustang";
};
int main() {
  Car myCar;
  //myCar.b = 100;
  myCar.beep();
  std::cout << myCar.brand + " " + myCar.model;
  return 0;
}