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

void generate_unit_unavailable_event(const std::string& thermostat_name, const std::string& heating_cooling_unit_name);
std::string get_thermostat_name(const std::string& request);
std::string get_heating_cooling_unit_name(const std::string& request);
void log_event(const std::string& event_type, const std::string& thermostat_name, const std::string& heating_cooling_unit_name);

void generate_unit_unavailable_event(const std::string& thermostat_name, const std::string& heating_cooling_unit_name) {
  log_event("Unit Unavailable", thermostat_name, heating_cooling_unit_name);
}

std::regex request_regex(".* thermostat: (.*?) heating or cooling unit: (.*?)\"\); std::smatch match; if (std::regex_search(request, match, request_regex)) { return match[1]; } else { return "Unknown"; }

std::string get_heating_cooling_unit_name(const std::string& request) { return std::regex_search(request, request_regex)[1]; }

void log_event(const std::string& event_type, const std::string& thermostat_name, const std::string& heating_cooling_unit_name) {
  std::string log_entry = event_type + ' ' + thermostat_name + ' ' + heating_cooling_unit_name;
  // Write log_entry to system log using logging library or function
}

