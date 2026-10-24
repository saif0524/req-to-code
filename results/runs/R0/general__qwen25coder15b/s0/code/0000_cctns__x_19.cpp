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
Case retrieve_case(const std::string& case_id);
void display_case(const Case& case_data);
void update_case(const Case& updated_case);
void delete_case(const std::string& case_id);

std::vector<Case> search_cases(const std::vector<Case>& cases, const SearchCriteria& criteria) {
  std::vector<Case> result;
  for (const auto& case_ : cases) {
    if (case_.matches(criteria)) {
      result.push_back(case_);
    }
  }
  return result;
}

Case retrieve_case(const std::string& case_id) {
  for (const auto& case_ : cases) {
    if (case_.matches(case_id)) {
      return case_;
    }
  }
  return Case();
}

void display_case(const Case& case_data) {
  std::cout << "Case ID: " << case_data.id << std::endl;
  std::cout << "Case Name: " << case_data.name << std::endl;
  std::cout << "Case Description: " << case_data.description << std::endl;
  std::cout << "Case Status: " << case_data.status << std::endl;
  std::cout << "Case Date: " << case_data.date << std::endl;
  std::cout << "Case Location: " << case_data.location << std::endl;
  std::cout << "Case Contact: " << case_data.contact << std::endl;
  std::cout << "Case Notes: " << case_data.notes << std::endl;
}

void update_case(const Case& updated_case) {
  for (auto& case_ : cases) {
    if (case_.matches(updated_case.id)) {
      case_ = updated_case;
      return;
    }
  }
}

void delete_case(const std::string& case_id) {
  for (auto it = cases.begin(); it != cases.end(); ++it) {
    if (it->id == case_id) {
      cases.erase(it);
      return true;
    }
  }
  return false;
}

