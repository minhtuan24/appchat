// g++ -std=c++17 src/oop1.cpp -o oop1

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() override { return width * height; }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() override { return M_PI * radius * radius; }
};

int main()
{
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Rectangle>(3, 4));
    shapes.push_back(make_unique<Circle>(2));

    for (auto &s : shapes)
    {
        cout << "Dien tich: " << s->area() << endl;
    }
}
