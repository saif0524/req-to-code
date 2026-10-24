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
std::pair<int, int> parseTemperatureRange(const std::vector<std::string>& data);
bool validateTemperatureRange(int minTemp, int maxTemp);
void setValidTemperatureRange(int minTemp, int maxTemp);
void initializeOperationalParameters(const std::string& filePath);

std::vector<std::string> readInitializationFile(const std::string& filePath) {
  std::vector<std::string> data;
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

std::pair<int, int> parseTemperatureRange(const std::vector<std::string>& data) {
  std::pair<int, int> range;
  for (const auto& line : data) {
    if (line.find("temperature_range") != std::string::npos) {
      size_t start = line.find("=") + 1;
      size_t end = line.find(",");
      range.first = std::stoi(line.substr(start, end - start));
      start = end + 2;
      end = line.find("\n");
      range.second = std::stoi(line.substr(start, end - start));
      break;
    }
  }
  return range;
}

bool validateTemperatureRange(int minTemp, int maxTemp) {
  if (minTemp >= maxTemp) {
    return false;
  }
  if (minTemp < 0 || maxTemp > 100) {
    return false;
  }
  return true;
}

void initializeOperationalParameters(const std::string& filePath) {
  std::vector<std::string> data = readInitializationFile(filePath);
  std::pair<int, int> range = parseTemperatureRange(data);
  if (validateTemperatureRange(range.first, range.second)) {
    setValidTemperatureRange(range.first, range.second);
  }
}

