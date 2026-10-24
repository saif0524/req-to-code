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

bool is_temperature_satisfied(double current_temperature, double lower_trigger, double upper_trigger);
void determine_hc_mode(double current_temperature, double lower_trigger, double upper_trigger);

bool is_temperature_satisfied(double current_temperature, double lower_trigger, double upper_trigger) {
  return current_temperature >= lower_trigger && current_temperature <= upper_trigger;
}

