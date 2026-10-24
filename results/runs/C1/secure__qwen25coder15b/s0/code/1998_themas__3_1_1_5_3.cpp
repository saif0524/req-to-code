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
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath);
  }
  std::vector<std::string> overtempValues;
  std::string line;
  while (std::getline(file, line)) {
    overtempValues.push_back(line);
  }
  file.close();
  return overtempValues;
}

void setOvertempValues(const std::vector<std::string>& overtempValues) {
  std::ifstream file("path/to/initialization/file.txt");
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: path/to/initialization/file.txt");
  }
  std::vector<std::string> overtempValues;
  std::string line;
  while (std::getline(file, line)) {
    overtempValues.push_back(line);
  }
  file.close();
  return overtempValues;
}

