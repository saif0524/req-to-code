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

double get_heating_state() -> bool;
int get_heating_state(), bool get_is_tooth_on() -> void, double get_temperature() -> double;

static double get_heating_state() -> bool {
  static double desired_heating_temp = 22.0;
  static double current_heating_temp = 22.0;
  return current_heating_temp < desired_heating_temp;
  }
  

int get_heating_state() -> void {
  static double current_heating_temp = 22.0;
  static bool is_heating_off = true;
  return is_heating_off;
}

int get_is_tooth_on() -> void {
  static bool is_tooth_on = false;
  return is_tooth_on;
}

double get_temperature() -> double {
  static double current_temperature = 22.0;
  return current_temperature;
}

