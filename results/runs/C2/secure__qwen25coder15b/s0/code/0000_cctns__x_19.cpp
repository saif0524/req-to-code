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

struct Case {
  std::string id;
  std::vector<std::string> access_history;
  bool matches(const SearchCriteria& criteria) const;
};

enum SearchCriteria {
  RECENT,
  // Define search criteria here
};
using Case = std::vector<Case>; enum SearchCriteria {  // Define search criteria here };

std::vector<Case> search_cases(const std::vector<Case>& cases, const SearchCriteria& criteria);
Case retrieve_case(const std::vector<Case>& cases, const std::string& case_id);
std::vector<Case> get_recent_cases(const std::vector<Case>& cases, const std::string& user_id);
std::vector<Case> get_old_cases(const std::vector<Case>& cases, const std::string& user_id);

using Case = std::vector<Case>; Case retrieve_case(const std::vector<Case>& cases, const std::string& case_id) {  std::vector<Case> result;  for (const auto& case_ : cases) {    if (case_.id == case_id) {      result.push_back(case_);    }  }  return result; }

using Case = std::vector<Case>; Case retrieve_case(const std::vector<Case>& cases, const std::string& case_id) {  for (const auto& case_ : cases) {    if (case_.id == case_id) {      return case_;    }  }  return Case(); }

std::vector<Case> get_recent_cases(const std::vector<Case>& cases, const std::string& user_id) {
  std::vector<Case> result;
  for (const auto& case_ : cases) {
    if (std::find(case_.access_history.begin(), case_.access_history.end(), user_id) != case_.access_history.end()) {
      result.push_back(case_);
    }
  }
  return result;
}

struct Case {
  std::string id;
  std::vector<std::string> access_history;
  bool matches(const SearchCriteria& criteria) const;
};

enum SearchCriteria {
  RECENT,
  // Define search criteria here
};

std::vector<Case> search_cases(const std::vector<Case>& cases, const SearchCriteria& criteria) {
  std::vector<Case> result;
  for (const auto& case_ : cases) {
    if (case_.matches(criteria)) {
      result.push_back(case_);
    }
  }
  return result;
}

using Case = std::vector<Case>; Case retrieve_case(const std::vector<Case>& cases, const std::string& case_id) {  std::vector<Case> result;  for (const auto& case_ : cases) {    if (case_.id == case_id) {      result.push_back(case_);    }  }  return result; }

std::vector<Case> get_recent_cases(const std::vector<Case>& cases, const std::string& user_id) {
  std::vector<Case> result = search_cases(cases, SearchCriteria::RECENT);
  for (auto& case_ : result) {
    if (case_.access_history.find(user_id) != case_.access_history.end()) {
      result.erase(std::remove(result.begin(), result.end(), case_), result.end());
    }
  }
  return result;
}

