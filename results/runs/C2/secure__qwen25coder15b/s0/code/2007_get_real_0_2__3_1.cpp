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

struct College { std::string type; };

std::vector<College> get_oregon_colleges();
std::vector<College> filter_colleges_by_type(const std::vector<College>& colleges, const std::string& type);
std::vector<College> get_community_colleges(const std::vector<College>& colleges);
std::vector<College> get_private_colleges(const std::vector<College>& colleges);
std::vector<College> get_comprehensive_colleges(const std::vector<College>& colleges);

std::vector<College> get_oregon_colleges() { return colleges; }

struct College { std::string type; }; std::vector<College> filter_colleges_by_type(const std::vector<College>& colleges, const std::string& type) { std::vector<College> filtered_colleges; for (const auto& college : colleges) { if (college.type == type) { filtered_colleges.push_back(college); } } return filtered_colleges; }

std::vector<College> get_community_colleges(const std::vector<College>& colleges) {  std::vector<College> filtered_colleges;  for (const auto& college : colleges) {    if (college.type == 'Community College') {      filtered_colleges.push_back(college);    }  }  return filtered_colleges; }

struct College { int type; }; std::vector<College> get_private_colleges(const std::vector<College>& colleges) { std::vector<College> filtered_colleges; for (const auto& college : colleges) { if (college.type == 0) { filtered_colleges.push_back(college); } } return filtered_colleges; }

struct College { std::string type; College(const std::string& t) : type(t) {} }; std::vector<College> get_comprehensive_colleges(const std::vector<College>& colleges) { return filter_colleges_by_type(colleges, College('University')); }

