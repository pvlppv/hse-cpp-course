///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///////////////////////////////////////////////////////////////////////////////

/*
Car
Define a Car struct with private attributes
for year of manufacture (year), color (color),
number of doors (count_doors), fuel level
(fuel_level) and mileage (mileage).
Implement a constructor to initialize these
attributes. Fuel level and mileage must be
the default values are 50.0 and 0.0 respectively.
Implement the drive(double distance) method.
which reduces the fuel level depending on
distance traveled and increases mileage.
  Assume that the car consumes 1 liter
  fuel for 10 km.
Implement the refuel(double amount) method to
  add fuel to the tank.
Add a stop() method that prints a message
that the car has been stopped.
Implement an info() method that prints information
about the car: year of manufacture, color, number of doors,
fuel level and mileage.
Implement methods to change colors
car and obtaining current color values,
fuel level and mileage.
In the main function, create several Car objects with different characteristics.
Test all class methods to make sure they work correctly. Try walking some distance, refueling the car, changing its color and then displaying information about it.
*/

#include <iostream>
#include <string>

struct Car {
    int year;
    std::string color;
    int count_doors;
    double fuel_level;
    double mileage;

    Car(int y, std::string c, int d, double f = 50.0, double dis = 0.0)
        : year(y), color(c), count_doors(d), fuel_level(f), mileage(dis) {}

    void drive(double distance) {
        double fuel_consumed = distance / 10.0;
        if (fuel_consumed <= fuel_level) {
            fuel_level -= fuel_consumed;
            mileage += distance;
            std::cout << "Drove " << distance << " km. Remaining fuel: " << fuel_level << " liters\n";
        } else {
            std::cout << "Not enough fuel to complete the journey\n";
        }
    }

    void refuel(double amount) {
        fuel_level += amount;
        std::cout << "Refueled " << amount << " liters. Current fuel level: " << fuel_level << " liters\n";
    }

    void stop() {
        std::cout << "The car has been stopped.\n";
    }

    void info() {
        std::cout << "Year: " << year << ", Color: " << color << ", Number of doors: " << count_doors
                  << ", Fuel level: " << fuel_level << " liters, Mileage: " << mileage << " km\n";
    }

    void changeColor(std::string new_color) {
        color = new_color;
        std::cout << "Color changed to " << color << '\n';
    }

    std::string getColor() const {
        return color;
    }

    double getFuelLevel() const {
        return fuel_level;
    }

    double getMileage() const {
        return mileage;
    }
};

int main() {
    Car car1(2010, "black", 5);
    car1.info();
    car1.drive(100);
    car1.info();
    car1.refuel(20);
    car1.info();
    car1.changeColor("red");
    car1.info();

    Car car2(2022, "white", 3);
    car2.info();
    car2.drive(200);
    car2.info();
    car2.stop();

    return 0;
}
