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
std::string generate_report();

double read_temperature() {
  // Read the current temperature from the system
  double temperature = get_current_temperature();
  return temperature;
}

bool check_temperature(double temperature) {  // Check if the temperature is within acceptable limits.  double acceptable_limit = get_acceptable_limit();  return temperature >= acceptable_limit && temperature <= acceptable_limit; }

std::string generate_report() {  double temperature = read_temperature();  bool is_within_limit = check_temperature(temperature);  std::string report = "Current temperature: " + std::to_string(temperature) + "\n";  if (!is_within_limit) {    report += "Warning: Temperature is out of acceptable limits.\n";  }  report += "System status: " + get_system_status() + "\n";  return report; }

