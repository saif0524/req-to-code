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

std::function<double*(double)> buildPlugins(const std::function<double*>> &p) { return std::function<void>(); }

double calculateArea(double radius) { return std::M_PI * radius * radius; }

