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
void determine_heating_mode(bool is_temperature_satisfied);
void determine_cooling_mode(bool is_temperature_satisfied);
void process_temperature_condition(double current_temperature, double lower_trigger, double upper_trigger);

bool is_temperature_satisfied(double current_temperature, double lower_trigger, double upper_trigger) {
  return current_temperature >= lower_trigger && current_temperature <= upper_trigger;
}

void determine_heating_mode(bool is_temperature_satisfied) {
  if (is_temperature_satisfied) {
    determine_heating_mode(true);
  } else {
    determine_cooling_mode(true);
  }
}

void determine_cooling_mode(bool is_temperature_satisfied) {
  if (!is_temperature_satisfied) {
    if (current_temperature < lower_trigger) {
      is_cooling_mode = true;
      // Output request to turn on cooling unit
    } else {
      is_cooling_mode = true;
      // Output request to turn on heating unit
    }
  }
}

void process_temperature_condition(double current_temperature, double lower_trigger, double upper_trigger) {
  if (is_temperature_satisfied(current_temperature, lower_trigger, upper_trigger)) {
    determine_heating_mode(true);
  } else {
    determine_cooling_mode(true);
  }
}

