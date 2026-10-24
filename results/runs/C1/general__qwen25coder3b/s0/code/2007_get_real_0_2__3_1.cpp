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

std::vector<std::string> getOregonColleges();
std::vector<std::string> filterComputerScienceCourses(const std::vector<std::string>& colleges);
std::vector<std::string> getComputerScienceCourses(const std::vector<std::string>& colleges);

std::vector<std::string> getOregonColleges() {
  std::vector<std::string> oregonColleges = {
    "Oregon State University",
    "University of Oregon",
    "Oregon Institute of Technology",
    "Oregon Health & Science University",
    "Oregon State Community College",
    "Oregon Community College"
  };
  return filterComputerScienceCourses(oregonColleges);
}

std::vector<std::string> filterComputerScienceCourses(const std::vector<std::string>& colleges) {
  std::vector<std::string> result;
  for (const auto& college : colleges) {
    if (college.find("computer science") != std::string::npos) {
      result.push_back(college);
    }
  }
  return result;
}

std::vector<std::string> getComputerScienceCourses(const std::vector<std::string>& colleges) {
  std::vector<std::string> result;
  for (const auto& college : colleges) {
    if (college.find("computer science") != std::string::npos) {
      result.push_back(college);
    }
  }
  return result;
}

