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

void loadThermostatDefinitions(const std::string& filePath);
void parseOvertempValues(const std::string& data, std::vector<double>& overtempValues);
void setOvertempValues(const std::vector<double>& overtempValues);

void loadThermostatDefinitions(const std::string& filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file");
  }

  std::string data;
  file >> data;

  std::vector<double> overtempValues;
  parseOvertempValues(data, overtempValues);

  setOvertempValues(overtempValues);
}

void parseOvertempValues(const std::string& data, std::vector<double>& overtempValues) {
  std::istringstream stream(data);
  double value;
  while (stream >> value) {
    overtempValues.push_back(value);
  }
}

void setOvertempValues(const std::vector<double>& overtempValues) {
  for (double value : overtempValues) {
    // Assuming there is a function to set the overtemperature value in the system
    setOvertempValues(value);
  }
}

