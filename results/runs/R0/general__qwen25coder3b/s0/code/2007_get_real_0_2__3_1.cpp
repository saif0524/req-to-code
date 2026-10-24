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

std::vector<std::string> filterComputerScienceCourses(const std::vector<std::string>& colleges);
std::vector<std::string> getComputerScienceCourses(const std::vector<std::string>& colleges);

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

