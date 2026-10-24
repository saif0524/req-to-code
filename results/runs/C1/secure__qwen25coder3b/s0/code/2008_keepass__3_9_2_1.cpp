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
bool validateInput(const std::string& input);
void handleUserSelection(const std::string& groupName, const std::string& subgroupName, const std::vector<std::string>& fieldsToSearch);

std::vector<std::string> findGroupOrSubgroup(const std::string& groupName, const std::string& subgroupName) {
  if (!validateInput(groupName) || !validateInput(subgroupName)) {
    return {};
  }

  // Placeholder for database search logic
  std::vector<std::string> results;

  // Example search logic
  if (groupName == "ExampleGroup" && subgroupName == "ExampleSubgroup") {
    results.push_back("ExampleResult1");
    results.push_back("ExampleResult2");
  }

  return results;
}

std::vector<std::string> searchFields(const std::vector<std::string>& results, const std::vector<std::string>& fieldsToSearch) {
  std::vector<std::string> searchResults;

  for (const auto& result : results) {
    for (const auto& field : fieldsToSearch) {
      if (result.find(field) != std::string::npos) {
        searchResults.push_back(result);
        break;
      }
    }
  }

  return searchResults;
}

void displayResults(const std::vector<std::string>& results) {
  for (const auto& result : results) {
    std::cout << result << std::endl;
  }
}

bool validateInput(const std::string& input) {
  if (input.empty()) {
    return false;
  }
  for (char c : input) {
    if (!std::isalnum(c)) {
      return false;
    }
  }
  return true;
}

void handleUserSelection(const std::string& groupName, const std::string& subgroupName, const std::vector<std::string>& fieldsToSearch) {
  if (!validateInput(groupName) || !validateInput(subgroupName)) {
    return;
  }

  std::vector<std::string> results = findGroupOrSubgroup(groupName, subgroupName);

  if (results.empty()) {
    std::cout << "No results found." << std::endl;
    return;
  }

  std::vector<std::string> searchResults = searchFields(results, fieldsToSearch);

  displayResults(searchResults);
}

