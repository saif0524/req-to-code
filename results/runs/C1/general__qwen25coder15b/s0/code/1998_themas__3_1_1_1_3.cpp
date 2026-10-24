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

void load_hc_unit_definitions(const std::string& initialization_data_file);
std::string determine_quadrant(int floor, int room);
std::string determine_thermostat(int floor, int room);
void assign_hc_unit_to_thermostat(const std::string& hc_unit, const std::string& thermostat);

void load_hc_unit_definitions(const std::string& initialization_data_file) {
  std::ifstream file(initialization_data_file);
  std::string line;
  std::map<std::string, std::pair<int, int>> hc_unit_definitions;

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open initialization data file");
  }

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string unit_name;
    int floor;
    int room;

    iss >> unit_name >> floor >> room;

    hc_unit_definitions[unit_name] = {floor, room};
  }

  file.close();
}

std::string determine_quadrant(int floor, int room) {
  std::map<std::string, std::pair<int, int>> hc_unit_definitions = {
    {"HC1", {1, 1}},
    {"HC2", {1, 2}},
    {"HC3", {1, 3}},
    {"HC4", {1, 4}},
    {"HC5", {2, 1}},
    {"HC6", {2, 2}},
    {"HC7", {2, 3}},
    {"HC8", {2, 4}},
    {"HC9", {3, 1}},
    {"HC10", {3, 2}},
    {"HC11", {3, 3}},
    {"HC12", {3, 4}}
  };

  for (const auto& [unit_name, quadrant] : hc_unit_definitions) {
    if (unit_name == "HC" + std::to_string(floor) + std::to_string(room)) {
      return quadrant.first + "" + quadrant.second;
    }
  }

  throw std::runtime_error("Unit not found");
}

std::string determine_thermostat(int floor, int room) {
  std::map<std::string, std::pair<int, int>> hc_unit_definitions = load_hc_unit_definitions("initialization_data.txt");

  std::string quadrant = determine_quadrant(hc_unit_definitions[hc_unit].first, hc_unit_definitions[hc_unit].second);
  std::string thermostat_name = determine_thermostat(quadrant, hc_unit_definitions[hc_unit].first, hc_unit_definitions[hc_unit].second);

  return thermostat_name;
}

void assign_hc_unit_to_thermostat(const std::string& hc_unit, const std::string& thermostat) {
  std::map<std::string, std::pair<int, int>> hc_unit_definitions = load_hc_unit_definitions("initialization_data.txt");

  std::string quadrant = determine_quadrant(hc_unit_definitions[hc_unit].first, hc_unit_definitions[hc_unit].second);
  std::string thermostat_name = determine_thermostat(quadrant, hc_unit_definitions[hc_unit].first, hc_unit_definitions[hc_unit].second);

  hc_unit_definitions[hc_unit].second = thermostat_name;
}

