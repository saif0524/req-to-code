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

bool validate_temperature_setting(int setting, int lower, int upper);
bool validate_current_temperature(int temperature, int lower, int upper);

bool validate_temperature_setting(int setting, int lower, int upper) {
  if (setting < lower || setting > upper) {
    return false;
  } else {
    return true;
  }
}

bool validate_current_temperature(int temperature, int lower, int upper) {
  if (temperature < lower || temperature > upper) {
    return false;
  } else {
    return true;
  }
}

