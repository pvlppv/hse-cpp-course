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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class Shape {
 protected:
  double x, y;

 public:
  Shape(double x, double y) : x(x), y(y) {}
  virtual double area() const = 0;
};

class Circle : public Shape {
 private:
  double radius;

 public:
  Circle(double x, double y, double radius) : Shape(x, y), radius(radius) {}
  double area() const override { return M_PI * radius * radius; }
};

class Rectangle : public Shape {
 private:
  double width, height;

 public:
  Rectangle(double x, double y, double width, double height)
      : Shape(x, y), width(width), height(height) {}
  double area() const override { return width * height; }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  std::vector<std::unique_ptr<Shape>> shapes;

  for (int i = 0; i < 10; ++i) {
    if (rand() % 2 == 0) {
      double radius = rand() % 10 + 1;
      shapes.push_back(std::make_unique<Circle>(0, 0, radius));
    } else {
      double width = rand() % 10 + 1;
      double height = rand() % 10 + 1;
      shapes.push_back(std::make_unique<Rectangle>(0, 0, width, height));
    }
  }

  for (const auto &shape : shapes) {
    std::cout << "Area: " << shape->area() << std::endl;
  }

  return 0;
}

