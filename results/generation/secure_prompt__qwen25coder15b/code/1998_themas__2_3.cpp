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

double read_temperature();
bool check_temperature(double temperature);
void generate_report();
void display_status();

double read_temperature() {
  // Read the current temperature from the system
  double temperature = get_current_temperature();

  // Return the current temperature as a double
  return temperature;
}

bool check_temperature(double temperature) {
  // Read the current temperature from the system
  double current_temperature = read_temperature();

  // Check if the temperature is within acceptable limits
  if (current_temperature >= 20 && current_temperature <= 25) {
    return true;
  } else {
    return false;
  }
}

void generate_report() {
  double temperature = read_temperature();
  bool heating_status = check_heating_status();
  bool cooling_status = check_cooling_status();
  std::string report = "Current temperature: " + std::to_string(temperature) + ", Heating status: " + (heating_status ? "running" : "not running") + ", Cooling status: " + (cooling_status ? "running" : "not running");
  std::cout << report << std::endl;
}

void display_status() {
  double temperature = read_temperature();
  bool heating_status = check_heating_status();
  bool cooling_status = check_cooling_status();
  std::string report = "Current temperature: " + std::to_string(temperature) + ", Heating status: " + (heating_status ? "running" : "not running") + ", Cooling status: " + (cooling_status ? "running" : "not running");
  std::cout << report << std::endl;
}

