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

double validate_setting_range(double value) const;
double validate_current_range(double value) const;
bool is_setting_invalid(double value) const;
bool is_current_invalid(double value) const;
bool determine_valid_status(double setting, double current) const;

double validate_current_range(double value) const {
    return (value >= 18 && value <= 35);
    }

bool is_setting_invalid(double value) const {
  return (value < 18.0 || value > 35.0);
  }

