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

std::pair<std::vector<std::pair<std::string, std::string>>, std::vector<std::string>> function_to_initialization_data(std::vector<std::string> initialization_data, std::vector<std::string> parameters);
std::vector<std::pair<std::string, std::string>> function_to_load_h_c_unit_definitions(std::vector<std::string> initialization_data);
std::vector<std::pair<std::string, std::string>> function_to_process_units(std::vector<std::string> units, std::vector<std::string> parameters);
std::vector<std::string> function_to_manage_database(std::vector<std::string> units, std::vector<std::string> quadrants, std::vector<std::string> floors);
void function_to_handle_changes(std::vector<std::string> units, std::vector<std::string> quadrants, std::vector<std::string> floors);

pair<std::vector<std::pair<std::string, std::string>>, std::vector<std::string>> function_to_initialization_data(std::vector<std::string> initialization_data, std::vector<std::string> parameters) {
  std::vector<std::pair<std::string, std::string>> unit_data;
  for (size_t i = 0; i < initialization_data.size(); i++) {
    std::string line = initialization_data[i];
    std::string type;
    std::string power, temp;
    std::istringstream iss(line);
    iss >> type >> power >> temp;
    std::vector<std::pair<std::string, std::string>> unit_info = {
      {type, power},
      {temp}
    };
    unit_data.push_back(unit_info);
  }
  return {unit_data, parameters};
  }
  

vector<pair<string,string>> function_to_load_h_c_unit_definitions(vector<string> initialization_data) {
  vector<pair<string,string>> unit_definitions;
  for (const string& line : initialization_data) {
    string type, power, temp;
    stringstream iss(line);
    iss >> type >> power >> temp;
    if (type == 

vector<pair<string,string>> function_to_process_units(vector<string> units, vector<string> parameters) {
  vector<pair<string,string>> processed_units;
  for (const auto& unit : units) {
    string type;
    string power;
    string temp;
    string required_type;
    string new_type;
    string new_power;
    string new_temp;
    string new_unit;
    string new_unit_def;

    // Extract parameters from the current unit
    string line = unit;
    string line_from_iss;
    iss >> type >> power >> temp;
    type = type;
    power = power;
    temp = temp;

    // Determine required type based on parameters
    if (parameters.find(

vector<string> function_to_manage_database(vector<string> units, vector<string> quadrants, vector<string> floors) {
  vector<string> result;
  // Process each unit
  for (size_t i = 0; i < units.size(); i++) {
    string line = units[i];
    string type, power, temp;
    stringstream iss(line);
    iss >> type >> power >> temp;
    vector<pair<string, string>> unit_info = {{type, power}, {temp}};
    unit_data.push_back(unit_info);
  }

  // Process each quadrant
  for (const string& quad_line : quadrants) {
    string quad_line_str = quad_line;
    for (size_t j = 0; j < units.size(); j++) {
      string unit_line = units[j];
      string type, power, temp;
      stringstream iss(unit_line);
      iss >> type >> power >> temp;
      vector<pair<string, string>> unit_info = {{type, power}, {temp}};
      unit_data.push_back(unit_info);
    }
    for (size_t j = 0; j < units.size(); j++) {
      string unit_line = units[j];
      string type, power, temp;
      stringstream iss(unit_line);
      iss >> type >> power >> temp;
      if (type == "H/C") {
        result.push_back("H/C Unit Definition for " + unit_line);
      }
    }
  }

  // Process each floor
  for (const string& floor_line : floors) {
    string floor_line_str = floor_line;
    for (size_t j = 0; j < units.size(); j++) {
      string unit_line = units[j];
      string type, power, temp;
      stringstream iss(unit_line);
      iss >> type >> power >> temp;
      vector<pair<string, string>> unit_info = {{type, power}, {temp}};
      unit_data.push_back(unit_info);
    }
    for (size_t j = 0; j < units.size(); j++) {
      string unit_line = units[j];
      string type, power, temp;
      stringstream iss(unit_line);
      iss >> type >> power >> temp;
      if (type == "H/C") {
        result.push_back("H/C Unit on Floor " + floor_line_str + " for " + unit_line);
      }
    }
  }

  return result;
  }

vector<string> function_to_handle_changes(vector<string> units, vector<string> quadrants, vector<string> floors) {
    vector<string> new_params;
    for (const string& line : units) {
      string line;
      string line_from_iss;
      iss >> line;
      iss >> line_from_iss;
      string type, power, temp;
      iss >> type >> power >> temp;
      if (type == "H/C") {
        new_params.push_back(get_params_from_unit(line));
      }
    }
    return new_params;
  }

vector<string> get_params_from_unit(string line) {
  string line_from_iss;
  iss >> line;
  iss >> line_from_iss;
  string type, power, temp;
  iss >> type >> power >> temp;
  return {type, power, temp};
}

vector<string> function_to_handle_changes(vector<string> units, vector<string> quadrants, vector<string> floors) {
  vector<string> new_params;
  for (const string& line : units) {
    string line_from_iss;
    iss >> line;
    iss >> line_from_iss;
    string type, power, temp;
    iss >> type >> power >> temp;
    if (type == "H/C") {
      new_params.push_back(get_params_from_unit(line));
    }
  }
  return new_params;
  }
};

