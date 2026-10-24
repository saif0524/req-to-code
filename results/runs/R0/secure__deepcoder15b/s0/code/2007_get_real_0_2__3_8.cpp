#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

double radius -> double;
double base, double height -> double;
double length, double width -> double;
double radius -> double;
int sides, double side -> double;

double area(double radius) {
    return M_PI * radius * radius;
    }

double area(double base, double height) {
  return (base * height) / 2.0; 
}

double perimeter(double length, double width) {
    double sum = length + width;
    return 2 * sum;
    }

double radius(double radius) {
  return (4.0 / 3.0) * M_PI * radius * radius * radius;
}

double polygon_area(int sides, double side) { double area = 0.0; double central_angle = 2 * M_PI / sides; double sin_central = sin(central_angle); area = (sides * pow(side, 2) * sin_central) / (4.0); return area; }

