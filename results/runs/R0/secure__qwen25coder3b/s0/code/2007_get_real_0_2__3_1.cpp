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
std::string formatCourseList(const std::vector<std::string>& courses);
void printCourseList(const std::vector<std::string>& courses);

std::vector<std::string> filterComputerScienceCourses(const std::vector<std::string>& colleges) {
  std::vector<std::string> result;
  if (colleges.empty()) {
    return result;
  }
  for (const auto& college : colleges) {
    if (college.find("Computer Science") != std::string::npos ||
        college.find("CS") != std::string::npos ||
        college.find("Computer Science") != std::string::npos) {
      result.push_back(college);
    }
  }
  return result;
}

std::vector<std::string> getComputerScienceCourses(const std::vector<std::string>& colleges) {
  std::vector<std::string> result;
  for (const auto& college : colleges) {
    if (college.find("Computer Science") != std::string::npos ||
        college.find("CS") != std::string::npos ||
        college.find("Computer Science") != std::string::npos) {
      result.push_back(college);
    }
  }
  return result;
}

std::string formatCourseList(const std::vector<std::string>& courses) {
  std::stringstream ss;
  for (size_t i = 0; i < courses.size(); ++i) {
    ss << courses[i];
    if (i < courses.size() - 1) {
      ss << "\n";
    }
  }
  return ss.str();
}

void printCourseList(const std::vector<std::string>& courses) {
  std::string formattedList = formatCourseList(courses);
  std::cout << formattedList << std::endl;
}

