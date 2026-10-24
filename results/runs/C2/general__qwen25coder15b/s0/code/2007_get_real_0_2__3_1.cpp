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

struct College { std::string name; std::string type; }; enum CollegeType { COMMUNITY, PRIVATE };
struct College; enum CollegeType;

std::vector<College> get_oregon_college_list();
std::vector<College> filter_colleges_by_type(const std::vector<College>& colleges, CollegeType type);
std::vector<College> get_community_college_list();
std::vector<College> get_private_college_list();
College get_college_details(const std::string& college_name);

#ifndef COLLEGE_H
#define COLLEGE_H

struct College {
  std::string name;
  std::string type;
};

#endif // COLLEGE_H

struct College { std::string name; std::string type; }; enum CollegeType { COMMUNITY, PRIVATE }; std::vector<College> filter_colleges_by_type(const std::vector<College>& colleges, CollegeType type) { std::vector<College> filtered_colleges; for (const auto& college : colleges) { if (college.type.compare(std::to_string(type)) == 0) { filtered_colleges.push_back(college); } } return filtered_colleges; }

using College = College; using CollegeType = CollegeType; using std::vector = std::vector<College>; std::vector<College> get_community_college_list() { std::vector<College> filtered_colleges = filter_colleges_by_type(get_oregon_college_list(), CollegeType::COMMUNITY); return filtered_colleges; }

struct College { std::string name; std::string type; }; enum CollegeType { COMMUNITY, PRIVATE }; std::vector<College> get_private_college_list() { return filter_colleges_by_type(get_oregon_college_list(), CollegeType::PRIVATE); }

std::vector<College> get_college_details(const std::string& college_name) {  std::vector<College> filtered_colleges = filter_colleges_by_type(get_oregon_college_list(), CollegeType::COMMUNITY);  for (const auto& college : filtered_colleges) {    if (college.name == college_name) {      return college;    }  }  return College(); }

