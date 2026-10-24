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

void validate_temperature(const std::string& temperature_type, const float& temperature_value, const float& valid_lower, const float& valid_upper, bool& is_valid);

void validate_temperature(const std::string& temperature_type, const float& temperature_value, const float& valid_lower, const float& valid_upper, bool& is_valid) {
  if (temperature_type != "current" && temperature_type != "setting") {
    is_valid = false;
    return;
  }

  if (temperature_value < valid_lower || temperature_value > valid_upper) {
    is_valid = false;
    return;
  }

  is_valid = true;
}

