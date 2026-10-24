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

std::vector<Case> searchSimple(const std::string& query);
std::vector<Case> searchAdvanced(const std::vector<SearchCriteria>& criteria);
Case retrieveRecentCase(const std::string& caseId);
Case retrieveInactiveCase(const std::string& caseId);
bool isCaseAccessedRecently(const std::string& caseId, const std::chrono::time_point<std::chrono::system_clock>& currentTime);

std::vector<Case> searchSimple(const std::string& query) {
  std::vector<Case> results;
  std::unordered_map<std::string, size_t> caseIndexMap;

  // Iterate over all cases and store their indices in the map
  for (size_t i = 0; i < cases.size(); ++i) {
    caseIndexMap[cases[i].getCaseId()] = i;
  }

  // Perform the search
  for (const auto& caseId : caseIndexMap) {
    if (caseId.first.find(query) != std::string::npos) {
      results.push_back(cases[caseIndexMap[caseId.first]]);
    }
  }

  return results;
}

std::vector<Case> searchAdvanced(const std::vector<SearchCriteria>& criteria) {
  std::vector<Case> results;

  for (const auto& case : cases) {
    if (meetsAllCriteria(case, criteria)) {
      results.push_back(case);
    }
  }

  return results;
}

bool meetsAllCriteria(const Case& case, const std::vector<SearchCriteria>& criteria) {
  for (const auto& criterion : criteria) {
    if (!case.meetsCriterion(criterion)) {
      return false;
    }
  }

  return true;
}

struct Case {
  std::string getCaseId() const;
  std::chrono::time_point<std::chrono::system_clock> getAccessTime() const;
};

Case retrieveRecentCase(const std::string& caseId) {
  std::map<std::chrono::time_point<std::chrono::system_clock>, Case> accessTimeMap;

  // Iterate over all cases and update the map with the most recent access time
  for (const auto& case : cases) {
    if (case.getAccessTime() > std::chrono::system_clock::now() - std::chrono::days(60)) {
      accessTimeMap[case.getAccessTime()] = case;
    }
  }

  // Retrieve the case with the most recent access time
  if (!accessTimeMap.empty()) {
    return accessTimeMap.rbegin()->second;
  }

  // Return an empty case if no recent access found
  return Case();
}

struct Case { std::string getCaseId() const; std::chrono::time_point<std::chrono::system_clock> getAccessTime() const; }; Case retrieveInactiveCase(const std::string& caseId) { std::map<std::chrono::time_point<std::chrono::system_clock>, Case> accessTimeMap; for (const auto& case : cases) { if (case.getAccessTime() > std::chrono::system_clock::now() - std::chrono::days(60)) { accessTimeMap[case.getAccessTime()] = case; } } if (!accessTimeMap.empty()) { return accessTimeMap.rbegin()->second; } return Case(); }

bool isCaseAccessedRecently(const std::string& caseId, const std::chrono::time_point<std::chrono::system_clock>& currentTime) {
  std::map<std::string, std::chrono::time_point<std::chrono::system_clock>> accessTimeMap;

  // Iterate over all cases and update the map with the most recent access time
  for (const auto& case : cases) {
    if (case.getAccessTime() > currentTime - std::chrono::days(60)) {
      accessTimeMap[case.getCaseId()] = case.getAccessTime();
    }
  }

  // Check if the case with the given ID exists in the map
  auto it = accessTimeMap.find(caseId);
  if (it != accessTimeMap.end()) {
    // Compare the access time of the case with the current time
    return it->second > currentTime - std::chrono::days(60);
  }

  // Return false if the case does not exist or has not been accessed recently
  return false;
}

