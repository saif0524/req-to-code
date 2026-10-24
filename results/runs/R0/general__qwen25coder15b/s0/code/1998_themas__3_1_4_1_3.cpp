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

bool compare_temperatures(double reported_temp, double temperature_setting, double overtemperature_margin);
void output_temperature_status(bool exceeded_limit);

bool compare_temperatures(double reported_temp, double temperature_setting, double overtemperature_margin) {
  double LO = temperature_setting - overtemperature_margin;
  double UO = temperature_setting + overtemperature_margin;
  return (LO < reported_temp && reported_temp < UO);
}

void output_temperature_status(bool exceeded_limit) {
  if (exceeded_limit) {
    std::cout << "Temperature limit has been exceeded." << std::endl;
  } else {
    std::cout << "Temperature limit has not been exceeded." << std::endl;
  }
}

