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

bool validate_temperature(const double& current_temp, const double& lower_temp, const double& upper_temp);
bool validate_temperature_setting(const double& setting_temp, const double& lower_temp, const double& upper_temp);

bool validate_temperature(const double& current_temp, const double& lower_temp, const double& upper_temp) {
  if (current_temp < lower_temp) {
    return false;
  }
  if (current_temp > upper_temp) {
    return false;
  }
  return true;
}

bool validate_temperature_setting(const double& setting_temp, const double& lower_temp, const double& upper_temp) {
  if (setting_temp < lower_temp) {
    return false;
  }
  if (setting_temp > upper_temp) {
    return false;
  }
  return true;
}

