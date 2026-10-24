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

std::vector<College> get_oregon_college_list();
std::vector<College> filter_colleges_by_type(const std::vector<College>& colleges, CollegeType type);
std::vector<College> get_community_college_list();
std::vector<College> get_private_college_list();
College get_college_details(const std::string& college_name);

std::vector<College> get_oregon_college_list() {
  return get_college_list("Oregon");
}

std::vector<College> filter_colleges_by_type(const std::vector<College>& colleges, CollegeType type) {
  std::vector<College> filtered_colleges;
  for (const auto& college : colleges) {
    if (college.type == type) {
      filtered_colleges.push_back(college);
    }
  }
  return filtered_colleges;
}

std::vector<College> get_community_college_list() {
  std::vector<College> filtered_colleges = filter_colleges_by_type(get_oregon_college_list(), CollegeType::COMMUNITY);
  return filtered_colleges;
}

std::vector<College> get_private_college_list() {
  return filter_colleges_by_type(get_oregon_college_list(), CollegeType::PRIVATE);
}

std::vector<College> get_college_details(const std::string& college_name) {
  std::vector<College> filtered_colleges = filter_colleges_by_type(get_oregon_college_list(), CollegeType::COMMUNITY);
  for (const auto& college : filtered_colleges) {
    if (college.name == college_name) {
      return college;
    }
  }
  return College();
}

