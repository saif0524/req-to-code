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

std::vector<Case> search_cases(const std::vector<Case>& cases, const SearchCriteria& criteria);
Case retrieve_case(const std::vector<Case>& cases, const std::string& case_id);
std::vector<Case> get_recent_cases(const std::vector<Case>& cases, const std::string& user_id);
std::vector<Case> get_old_cases(const std::vector<Case>& cases, const std::string& user_id);

std::vector<Case> search_cases(const std::vector<Case>& cases, const SearchCriteria& criteria) {
  std::vector<Case> result;
  for (const auto& case_ : cases) {
    if (case_.matches(criteria)) {
      result.push_back(case_);
    }
  }
  return result;
}

Case retrieve_case(const std::vector<Case>& cases, const std::string& case_id) {
  std::vector<Case> result;
  for (const auto& case_ : cases) {
    if (case_.id == case_id) {
      result.push_back(case_);
    }
  }
  return result;
}

std::vector<Case> get_recent_cases(const std::vector<Case>& cases, const std::string& user_id) {
  std::vector<Case> result;
  for (const auto& case_ : cases) {
    if (case_.access_history.find(user_id) != case_.access_history.end()) {
      result.push_back(case_);
    }
  }
  return result;
}

std::vector<Case> get_old_cases(const std::vector<Case>& cases, const std::string& user_id) {
  std::vector<Case> result = get_recent_cases(cases, user_id);
  for (auto& case_ : result) {
    if (case_.access_history.find(user_id) != case_.access_history.end()) {
      result.erase(std::remove(result.begin(), result.end(), case_), result.end());
    }
  }
  return result;
}

