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

float read_temperature(int thermostat_id);
void set_temperature(int thermostat_id, float new_temperature);

float read_temperature(int thermostat_id) {
  return read_temperature(thermostat_id);
}

void set_temperature(int thermostat_id, float new_temperature) {
  float current_temperature = read_temperature(thermostat_id);
  if (current_temperature != new_temperature) {
    // Send a signal to the thermostat to set the new temperature
  }
}

