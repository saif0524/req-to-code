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

void loadHCUDefinitions(const std::string& initializationDataFile, std::vector<std::string>& hcuDefinitions);
void parseInitializationData(const std::string& initializationData, std::vector<std::string>& hcuDefinitions);
bool validateHCUDefinitions(const std::vector<std::string>& hcuDefinitions);
void extractHCUDefinitions(const std::vector<std::string>& hcuDefinitions, std::vector<std::string>& hcuList);
void initializeHCUList(const std::vector<std::string>& hcuList, std::vector<std::string>& hcuDefinitions);

void loadHCUDefinitions(const std::string& initializationDataFile, std::vector<std::string>& hcuDefinitions) {
  std::ifstream file(initializationDataFile);
  if (!file.is_open()) {
    hcuDefinitions.clear();
    hcuDefinitions.push_back("Error opening file");
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line.find("HEATING COOLING UNIT DEFINITION") != std::string::npos) {
      std::istringstream iss(line);
      std::string definition;
      while (iss >> definition) {
        if (std::find(hcuDefinitions.begin(), hcuDefinitions.end(), definition) == hcuDefinitions.end()) {
          hcuDefinitions.push_back(definition);
        }
      }
    }
  }

  file.close();
}

void parseInitializationData(const std::string& initializationData, std::vector<std::string>& hcuDefinitions) {
  std::istringstream iss(initializationData);
  std::string line;

  while (std::getline(iss, line)) {
    if (line.find("HEATING COOLING UNIT DEFINITION") != std::string::npos) {
      std::istringstream subIss(line);
      std::string definition;

      while (subIss >> definition) {
        if (std::find(hcuDefinitions.begin(), hcuDefinitions.end(), definition) == hcuDefinitions.end()) {
          hcuDefinitions.push_back(definition);
        }
      }
    }
  }
}

bool validateHCUDefinitions(const std::vector<std::string>& hcuDefinitions) {
  if (hcuDefinitions.empty()) {
    return false;
  }

  for (const auto& definition : hcuDefinitions) {
    if (!isValidHCUDefinition(definition)) {
      return false;
    }
  }

  return true;
}

void extractHCUDefinitions(const std::vector<std::string>& hcuDefinitions, std::vector<std::string>& hcuList) {
  std::set<std::string> uniqueDefinitions;

  for (const auto& definition : hcuDefinitions) {
    uniqueDefinitions.insert(definition);
  }

  hcuList.assign(uniqueDefinitions.begin(), uniqueDefinitions.end());
}

void initializeHCUList(const std::vector<std::string>& hcuList, std::vector<std::string>& hcuDefinitions) {
  std::vector<std::string> hcuDefinitionsCopy = hcuDefinitions;

  for (const auto& definition : hcuList) {
    if (std::find(hcuDefinitionsCopy.begin(), hcuDefinitionsCopy.end(), definition) != hcuDefinitionsCopy.end()) {
      hcuDefinitionsCopy.push_back(definition);
    }
  }

  hcuDefinitions = hcuDefinitionsCopy;
}

