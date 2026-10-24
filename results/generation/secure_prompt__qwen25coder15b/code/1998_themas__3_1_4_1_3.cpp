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

double read_temperature();
double read_temperature_setting();
std::pair<double, double> read_overtemperature_limits();
bool compare_temperatures(double current_temp, double setting, std::pair<double, double> limits);
void handle_temperature_limit_exceeded(double current_temp, double setting, std::pair<double, double> limits);

double read_temperature() { return read_temperature(); }

double read_temperature_setting() { return 25.0; }

std::pair<double, double> read_overtemperature_limits() { return {20.0, 30.0}; }

bool compare_temperatures(double current_temp, double setting, std::pair<double, double> limits) {
  if (current_temp <= setting && current_temp >= limits.first) {
    return true;
  } else if (current_temp >= setting && current_temp <= limits.second) {
    return true;
  } else {
    return false;
  }
}

void handle_temperature_limit_exceeded(double current_temp, double setting, std::pair<double, double> limits) {
  if (current_temp <= setting && current_temp >= limits.first) {
    return;
  } else if (current_temp >= setting && current_temp <= limits.second) {
    return;
  } else {
    std::cout << "Temperature limit exceeded" << std::endl;
  }
}

