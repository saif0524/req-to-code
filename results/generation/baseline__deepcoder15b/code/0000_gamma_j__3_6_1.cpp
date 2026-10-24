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

std::function<void> buildPlugins();
double calculateArea(double radius);

std::function<void(double)> buildPlugins(double*> ptr) {
  return std::function<double>([]{} { return *ptr; });
}

double calculateArea(double radius) {
    return M_PI * radius * radius;
    }

