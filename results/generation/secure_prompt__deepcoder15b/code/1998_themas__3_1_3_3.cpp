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

bool is_setting_invalid(double value) const;
bool is_current_invalid(double value) const;
bool determine_valid_status(double setting, double current) const;

using namespace std;

bool is_setting_invalid(double value) const {
  return (value < 18.0 || value > 35.0);
}

bool is_current_invalid(double value) const \r\r  return (value < 18.0) || (value > 35.0);

bool determine_valid_status(double setting, double current) const \r\r  return !is_setting_invalid(setting) && !is_current_invalid(current);

