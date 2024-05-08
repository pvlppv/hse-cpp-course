#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

// Implement a class system to represent various
// geometric shapes and calculation of their area.

// Base class Shape:
// Contains the x and y coordinates of the shape's center.
// Declares the area() function to calculate area.
// Derived class Circle:
// Inherits Shape.
// Adds the radius property.
// Implements the area() function to calculate the area of a circle.
// Rectangle derived class:
// Inherits Shape.
// Adds width and height properties.
// Implements the area() function to calculate the area of a rectangle.

class Shape {
 protected:
  double x, y;
 public:
  Shape(double x, double y) : x(x), y(y) {}
  virtual double area() const = 0;
  virtual void print() const = 0;
};

class Circle : public Shape {
 public:
  Circle(double r, double x, double y) : Shape(x, y), radius(r) {}
  double area() const override { return M_PI * radius * radius; }
  void print() const override {
    std::cout << "Circle: r = " << radius << " area = " << area() << '\n';
  }
 private:
  double radius;
};

class Rectangle : public Shape {
 public:
  Rectangle(double width, double height, double x, double y)
      : Shape(x, y), a(width), b(height) {}
  double area() const override { return a * b; }
  void print() const override {
    std::cout << "Rectangle: a = " << a << " b = " << b
              << " area = " << area() << '\n';
  }
 private:
  double a, b;
};

int main() {
  std::srand(std::time(nullptr));
  std::vector<std::unique_ptr<Shape>> v;
  for (int i = 0; i < 10; ++i) {
    if (std::rand() % 2 == 0) {
      v.push_back(std::make_unique<Circle>(
          std::rand() % 10, std::rand() % 10, std::rand() % 10));
    } else {
      v.push_back(std::make_unique<Rectangle>(
          std::rand() % 10, std::rand() % 10, std::rand() % 10, std::rand() % 10));
    }
    v[i]->print();
  }
  return 0;
}

