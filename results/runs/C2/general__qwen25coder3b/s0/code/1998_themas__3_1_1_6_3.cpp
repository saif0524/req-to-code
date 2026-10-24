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

std::vector<std::string> readInitializationFile(const std::string& filePath);
std::pair<double, double> extractTemperatureRange(const std::vector<std::string>& data);
bool validateTemperatureRange(double minTemp, double maxTemp);
void setValidTemperatureRange(double minTemp, double maxTemp);
void initializeOperationalParameters(const std::string& filePath);

std::vector<std::string> readInitializationFile(const std::string& filePath) {
  std::ifstream file(filePath);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      data.push_back(line);
    }
    file.close();
  }
  return data;
}

std::pair<double, double> extractTemperatureRange(const std::vector<std::string>& data) {
  std::pair<double, double> range;
  for (const auto& line : data) {
    size_t pos = line.find(',');
    if (pos != std::string::npos) {
      range.first = std::stod(line.substr(0, pos));
      range.second = std::stod(line.substr(pos + 1));
      break;
    }
  }
  return range;
}

bool validateTemperatureRange(double minTemp, double maxTemp) {
  if (minTemp < maxTemp) {
    return true;
  } else {
    return false;
  }
}

void initializeOperationalParameters(const std::string& filePath) {
  std::vector<std::string> data = readInitializationFile(filePath);
  std::pair<double, double> range = extractTemperatureRange(data);
  if (validateTemperatureRange(range.first, range.second)) {
    setValidTemperatureRange(range.first, range.second);
  } else {
    // Handle invalid range
  }
}

