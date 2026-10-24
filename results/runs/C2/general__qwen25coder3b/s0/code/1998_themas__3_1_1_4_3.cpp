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

struct System { void setTrigger(double value) { /* implementation */ } };

std::vector<std::string> readInitializationFile(const std::string& filePath);
std::vector<double> parseTriggerValues(const std::vector<std::string>& triggerValues);
void setTriggerValues(const std::vector<double>& triggerValues);

std::vector<std::string> readInitializationFile(const std::string& filePath) {
  std::vector<std::string> triggerValues;
  std::ifstream file(filePath);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      triggerValues.push_back(line);
    }
    file.close();
  }
  return triggerValues;
}

std::vector<double> parseTriggerValues(const std::vector<std::string>& triggerValues) {
  std::vector<double> parsedValues;
  for (const auto& value : triggerValues) {
    parsedValues.push_back(std::stod(value));
  }
  return parsedValues;
}

void setTriggerValues(const std::vector<double>& triggerValues) { System system; for (const auto& value : triggerValues) { system.setTrigger(value); } }

