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
void setOvertempValues(const std::vector<std::string>& overtempValues);

std::vector<std::string> readInitializationFile(const std::string& filePath) {
  std::ifstream file(filePath);
  std::vector<std::string> overtempValues;
  std::string line;
  while (std::getline(file, line)) {
    overtempValues.push_back(line);
  }
  return overtempValues;
}

void setOvertempValues(const std::vector<std::string>& overtempValues) {
  // Access the appropriate member variables or properties of the system
  for (const auto& overtempValue : overtempValues) {
    // Set the overtemperature value in the system
  }
}

