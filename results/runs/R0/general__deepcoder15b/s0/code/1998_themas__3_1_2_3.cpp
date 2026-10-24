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

vector<Unit>& units;
double get_current_temp Unit index;
double get_temp_setting Unit index;
Unit* unit;
vector<Unit>& units;

vector<Unit>& units,
    

double get_current_temp(int unit_index) {
    return units[unit_index].temperature;
    }

double get_temp_setting(int unit_index) {
  return units[unit_index].temperature_setting;
}

Unit* unit(int unit_index) {
  double current_temp = get_current_temp(unit_index);
  double setting_temp = get_temp_setting(unit_index);
  if (current_temp < setting_temp) {
    return new Unit(unit_index);
  }
  return nullptr;
}

bool check_units_needs_on(const vector<Unit>& units) {
    bool needs_on = false;
    for (const auto& unit : units) {
        double current_temp = unit.get_current_temp();
        double setting_temp = unit.get_temp_setting();
        if (current_temp < setting_temp) {
            needs_on = true;
            break;
        }
    }
    return needs_on;
}

