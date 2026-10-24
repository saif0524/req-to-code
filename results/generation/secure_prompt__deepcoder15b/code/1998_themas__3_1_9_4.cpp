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

struct Available Thermostats={{ int num_thermos; }}
struct Available Thermostats get_available_thermos(const int index)

int get_current_temp(const int thermostat);
bool validate_temp(const struct Available Thermostats &available, int desired);
void display_interface(const int selected, int current_temp);

int get_current_temp(const int thermostat) {
  if (thermostat < 0 || thermostat >= num_thermos) {
    return -1;
  }
  // Assuming available_thermos is a function that returns the current temperature
  return available_thermos[ thermostat ].current;
}

bool validate_temp(const struct Available Thermostats &available, int desired) {
  int max_current = -1; 
  for (const struct Available Thermostats& t : available) { 
    int current = get_current_temp(t.thermostat); 
    if (current > max_current) { 
      max_current = current; 
    } 
  } 
  return (desired >= max_current);
}

void display_interface(int selected, int current_temp) {
  int current = get_current_temp(selected);
  return std::to_string(selected) + 

