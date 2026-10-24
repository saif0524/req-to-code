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
void setTriggerValues(const std::vector<std::string>& triggerValues);

std::vector<std::string> readInitializationFile(const std::string& filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath);
  }
  std::vector<std::string> triggerValues;
  std::string line;
  while (std::getline(file, line)) {
    triggerValues.push_back(line);
  }
  return triggerValues;
}

void setTriggerValues(const std::vector<std::string>& triggerValues) {
  // Access the system's configuration
  auto& config = getSystemConfiguration();

  // Iterate over the vector of trigger values
  for (const auto& triggerValue : triggerValues) {
    // Set the trigger value in the system
    config.setTriggerValue(triggerValue);
  }
}

