#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>
using namespace std;

// PointType Class
class PointType {
private:
    double x, y;

public:
    // Constructors
    PointType() : x(0), y(0) {}
    PointType(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }

    // Setters
    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }
};

// CircleType Class
class CircleType {
private:
    PointType center;
    PointType pointOnCircumference;

public:
    // Constructors
    CircleType() : center(0, 0), pointOnCircumference(1, 0) {}
    CircleType(PointType c, PointType p) : center(c), pointOnCircumference(p) {}

    // Function to calculate radius
    double getRadius() const {
        double dx = pointOnCircumference.getX() - center.getX();
        double dy = pointOnCircumference.getY() - center.getY();
        return sqrt(dx * dx + dy * dy);
    }

    // Function to calculate circumference
    double getCircumference() const {
        return 2 * M_PI * getRadius();
    }

    // Function to calculate area
    double getArea() const {
        return M_PI * pow(getRadius(), 2);
    }

    // Print function
    void print() const {
        cout << "Radius: " << getRadius() << endl;
        cout << "Circumference: " << getCircumference() << endl;
        cout << "Area: " << getArea() << endl;
    }
};

// Main Program to Test the Class
int main() {
    // Create points
    PointType center(0, 0);
    PointType onCircumference(0, 5);

    // Create circle
    CircleType circle(center, onCircumference);

    // Display properties of the circle
    circle.print();

    return 0;
}