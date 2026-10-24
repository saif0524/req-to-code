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
std::vector<std::pair<std::string, std::string>> parseInitializationFile(const std::vector<std::string>& lines);
std::pair<std::string, std::string> extractValidTemperatureRange(const std::vector<std::pair<std::string, std::string>>& parsedData);
bool validateTemperatureRange(const std::pair<std::string, std::string>& validTemperatureRange);

std::vector<std::string> readInitializationFile(const std::string& filePath) {
  std::ifstream file(filePath, std::ios::binary);
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    lines.push_back(line);
  }
  return lines;
}

std::vector<std::pair<std::string, std::string>> parseInitializationFile(const std::vector<std::string>& lines) {
  std::vector<std::pair<std::string, std::string>> parsedData;
  for (const auto& line : lines) {
    std::istringstream iss(line);
    std::string key, value;
    iss >> key >> value;
    parsedData.push_back({key, value});
  }
  return parsedData;
}

std::pair<std::string, std::string> extractValidTemperatureRange(const std::vector<std::pair<std::string, std::string>>& parsedData) {
  for (const auto& pair : parsedData) {
    if (pair.first == "valid_temperature_range") {
      return pair;
    }
  }
  return {}; // Return an empty pair if the key is not found
}

bool validateTemperatureRange(const std::pair<std::string, std::string>& validTemperatureRange) {
  return validTemperatureRange.first == "valid_temperature_range";
}

