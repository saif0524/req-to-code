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

std::vector<std::string> findGroupOrSubgroup(const std::string& groupName, const std::string& subgroupName);
std::vector<std::string> searchFields(const std::vector<std::string>& results, const std::vector<std::string>& fieldsToSearch);
void displayResults(const std::vector<std::string>& results);
void handleUserInput(const std::string& searchWord, const std::vector<std::string>& fieldsToSearch);
void processSearch(const std::string& searchWord, const std::vector<std::string>& fieldsToSearch);

std::vector<std::string> findGroupOrSubgroup(const std::string& groupName, const std::string& subgroupName) {
  std::vector<std::string> foundGroups;
  // Iterate through the database and check for matching groups or subgroups
  for (const auto& group : database) {
    if (group.name == groupName || (group.name == subgroupName && group.parentName == groupName)) {
      foundGroups.push_back(group.name);
    }
  }
  return foundGroups;
}

std::vector<std::string> searchFields(const std::vector<std::string>& results, const std::vector<std::string>& fieldsToSearch) {
  std::vector<std::string> foundResults;
  for (const auto& result : results) {
    for (const auto& field : fieldsToSearch) {
      if (result.find(field) != std::string::npos) {
        foundResults.push_back(result);
        break;
      }
    }
  }
  return foundResults;
}

void displayResults(const std::vector<std::string>& results) {
  for (const auto& result : results) {
    customDisplayFunction(result);
  }
}

void handleUserInput(const std::string& searchWord, const std::vector<std::string>& fieldsToSearch) {
  std::vector<std::string> foundGroups = findGroupOrSubgroup(searchWord, "");
  std::vector<std::string> results = searchFields(foundGroups, fieldsToSearch);
  displayResults(results);
}

void processSearch(const std::string& searchWord, const std::vector<std::string>& fieldsToSearch) {
  std::vector<std::string> foundGroups = findGroupOrSubgroup(searchWord, "");
  std::vector<std::string> results = searchFields(foundGroups, fieldsToSearch);
  displayResults(results);
}

