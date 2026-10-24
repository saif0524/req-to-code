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
bool validateTemperatureRange(const std::pair<std::string, std::string>& temperatureRangePair);
void setValidTemperatureRange(const std::pair<std::string, std::string>& temperatureRangePair);

std::vector<std::string> readInitializationFile(const std::string& filePath) {
  std::ifstream file(filePath);
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  return lines;
}

std::vector<std::pair<std::string, std::string>> parseInitializationFile(const std::vector<std::string>& lines) {
  std::vector<std::pair<std::string, std::string>> pairs;
  for (const auto& line : lines) {
    std::istringstream iss(line);
    std::string key, value;
    iss >> key >> value;
    pairs.push_back(std::make_pair(key, value));
  }
  return pairs;
}

bool validateTemperatureRange(const std::pair<std::string, std::string>& temperatureRangePair) {
  if (temperatureRangePair.first != "temperatureRange") {
    return false;
  }
  std::istringstream iss(temperatureRangePair.second);
  double temperatureRange;
  iss >> temperatureRange;
  if (!iss) {
    return false;
  }
  if (temperatureRange < -100 || temperatureRange > 100) {
    return false;
  }
  return true;
}

void setValidTemperatureRange(const std::pair<std::string, std::string>& temperatureRangePair) {
  if (temperatureRangePair.first != "temperatureRange") {
    return false;
  }
  std::istringstream iss(temperatureRangePair.second);
  double temperatureRange;
  iss >> temperatureRange;
  if (!iss) {
    return false;
  }
  if (temperatureRange < -100 || temperatureRange > 100) {
    return false;
  }
  // Set the valid temperature range value
  setValidTemperatureRange(temperatureRange);
  return true;
}

