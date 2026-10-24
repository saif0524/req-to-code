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

void setTriggerValues(const std::vector<std::string>& triggerValues) {
  // Fetch the trigger values from the initialization file
  std::vector<std::string> triggerValuesFromFile = readInitializationFile("path/to/initialization/file.txt");

  // Assign the trigger values to the system's trigger values
  systemTriggerValues = triggerValuesFromFile;
}

void setTriggerValues(const std::vector<std::string>& triggerValues) {
  // Declare systemTriggerValues at the beginning of the function
  std::vector<std::string> systemTriggerValues;

  // Fetch the trigger values from the initialization file
  std::vector<std::string> triggerValuesFromFile = readInitializationFile("path/to/initialization/file.txt");

  // Assign the trigger values to the system's trigger values
  systemTriggerValues = triggerValuesFromFile;
}

