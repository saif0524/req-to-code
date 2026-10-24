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

struct Available Thermostats {{ int num_thermos; }} int get_available_thermos(int index) int max_current;
{"struct" Available Thermostats {{ 
  int num_thermos; 
  } 
  "int" get_available_thermos(const std::vector<Available Thermostats>& &available) {
    int max_current = -1;
    for (const std::vector<Available Thermostats>& t : available) {
      int current = get_current_temp(t.thermostat);
      if (current > max_current) {
        max_current = current;
      }
    }
    return max_current;
  }
  "int" get_current_temp(const int thermostat) {
    if (thermostat < 0 || thermostat >= num_thermos) {
      return -1;
    }
    // Assuming available_thermos is a map from thermostat index to current temperature
    // Here, for simplicity, we assume that the thermostat is selected correctly
    return get_available_thermos(std::vector<Available Thermostats>(1, Available Thermostats(thermostat)))[0].current;
  }
}}
struct Available Thermostats {{ int num_thermos; } int get_available_thermos(int index) ...

int get_current_temp(const int thermostat);
bool validate_temp(const struct Available Thermostats &available, int desired);
void handle_selection(const int index);
void display_interface(const int selected, int current_temp);

int get_current_temp(const int thermostat) {
  if (thermostat < 0 || thermostat >= num_thermos) {
    return -1;
  }
  // Assuming get_available_thermos returns a vector of Available Thermostats
  const std::vector<Available Thermostats> available = get_available_thermos(std::vector<Available Thermostats>(1, Available Thermostats(thermostat)));
  return available[0].current;
}

bool validate_temp(const struct Available Thermostats &available, int desired) { int max_current = -1; for (const struct Available Thermostats& t : available) { int current = get_current_temp(t.thermostat); if (current > max_current) { max_current = current; } } return desired <= max_current; }

int get_current_temp(const int thermostat) 
  if (thermostat < 0 || thermostat >= num_thermos) 
    return -1; 
  // Assuming available_thermoses is a map from thermostat index to current temperature 
  return get_available_thermoses(1, Available Thermostats(thermostat))[0].current; 
  
  bool validate_temp(const struct Available Thermostats &available, int desired) 
    { int max_current = -1; 
    for (const struct Available Thermostats &t : available) 
    { int current = get_current_temp(t.thermostat); 
      if (current > max_current) 
        max_current = current; 
    }
    return desired <= max_current; 
  
  void handle_selection(const int index) 
  { 
    if (available_thermoses.empty()) 
    { 
      available_thermoses.clear(); 
      return; 
    } 
    
    available_thermoses.clear(); 
    int selected = index; 
    // If needed, handle the selected index here 
  } 
  

void display_interface(int selected, int current_temp) {
  int current = get_current_temp(selected);
  std::cout << 

