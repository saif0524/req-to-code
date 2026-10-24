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
void extractHCUDefinitions(const std::vector<std::string>& hcuDefinitions, std::vector<std::string>& hcuList);
bool validateHCUDefinitions(const std::vector<std::string>& hcuList);
void initializeHCUList(const std::vector<std::string>& hcuList, std::vector<std::string>& hcuDefinitions);

void loadHCUDefinitions(const std::string& initializationDataFile, std::vector<std::string>& hcuDefinitions) {
  std::ifstream file(initializationDataFile);
  if (!file.is_open()) {
    hcuDefinitions.clear();
    hcuDefinitions.push_back("Error: Unable to open file");
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    // Assuming each line contains a unit definition
    hcuDefinitions.push_back(line);
  }

  file.close();
}

void parseInitializationData(const std::string& initializationData, std::vector<std::string>& hcuDefinitions) {
  std::istringstream stream(initializationData);
  std::string line;

  while (std::getline(stream, line)) {
    hcuDefinitions.push_back(line);
  }
}

void extractHCUDefinitions(const std::vector<std::string>& hcuDefinitions, std::vector<std::string>& hcuList) {
  std::set<std::string> uniqueHCU;

  for (const auto& definition : hcuDefinitions) {
    uniqueHCU.insert(definition);
  }

  hcuList.assign(uniqueHCU.begin(), uniqueHCU.end());
}

bool validateHCUDefinitions(const std::vector<std::string>& hcuList) {
  const int expectedUnits = 12; // 4 quadrants * 3 floors * 1 unit per quadrant
  return hcuList.size() == expectedUnits;
}

void initializeHCUList(const std::vector<std::string>& hcuList, std::vector<std::string>& hcuDefinitions) {
  hcuDefinitions.assign(hcuList.begin(), hcuList.end());
}

