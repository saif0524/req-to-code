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

std::function<std::pair<std::array<std::pair<std::string, 2>, 2>, std::pair<std::array<std::string, 2>>>> process_floor(int floor, std::pair<std::array<std::string, 2>, std::pair<std::string, std::string>> data);
std::function<std::pair<std::string, std::string>> process_unit(std::string unit_name);

std::function<std::pair<std::array<std::pair<std::string, 2>, 2>, std::pair<std::array<std::string, 2>>>> process_floor(int floor, std::pair<std::array<std::string, 2>, std::pair<std::string, std::string>> data) {
  std::pair<std::string, std::string> result;
  for (const auto& sub_data : data.first) {
    for (const auto& stat_data : sub_data) {
      if (stat_data == 

std::function<std::pair<std::string, std::string>> process_unit(std::string unit_name) {
  // Assuming data is stored in a map where the key is the unit name
  // For example, using a map to look up the unit's data
  std::unordered_map<std::string, std::pair<std::array<std::pair<std::string, 2>, 2>> units_map;
  // Populate units_map with data for each unit
  // Then, get the data for the given unit
  auto it = units_map.find(unit_name);
  if (it != units_map.end()) {
    std::pair<std::array<std::pair<std::string, 2>, 2>, std::array<std::string, 2>> data = it->second;
    // Process the data here
    // For example, process each stat_data
    // This is a placeholder implementation
    return {std::make_pair(data.first, data.second)};
  }
  // If the unit is not found, return an empty result
  return {std::make_pair(std::array<std::pair<std::string, 2>, 2>, std::array<std::string, 2])};
}

