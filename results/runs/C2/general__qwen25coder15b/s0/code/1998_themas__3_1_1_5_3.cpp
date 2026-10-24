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
  // Read the initialization file and store the overtemperature values in a vector of strings
  std::vector<std::string> overtempValues;
  // Add your code to read the initialization file and store the overtemperature values in the vector of strings
  return overtempValues;
}

void setOvertempValues(const std::vector<std::string>& overtempValues) {
  // Read the initialization file and store the overtemperature values in a vector of strings
  std::vector<std::string> initializationFileValues = readInitializationFile("path/to/initialization/file.txt");

  // Set the overtemperature values from the data in the initialization file
  for (const auto& value : initializationFileValues) {
    overtempValues.push_back(value);
  }
}

