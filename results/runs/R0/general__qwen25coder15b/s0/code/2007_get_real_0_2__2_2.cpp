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

std::vector<std::string> get_real_pages();
std::vector<std::string> get_real_features();
std::string get_real_page_details(std::string page_name);
void get_real_page_prototype(std::string page_name);
int get_real_page_priority(std::string page_name);

std::vector<std::string> get_real_pages() {
  return get_real_features();
}

std::vector<std::string> get_real_features() {
  std::vector<std::string> features = {
    "Exploring College Jobs & Money",
    "High School Courses",
    "I’m Looking For…",
    "Articles",
    "Professional Organizations",
    "RSS feeds of current CS information",
    "Ask an Engineer, Ask a Prof – FAQ",
    "Consider a CS minor in other professions",
    "Other ideas/page proposals"
  };
  return features;
}

std::string get_real_page_details(std::string page_name) {
  std::vector<std::string> features = get_real_features();
  auto it = std::find_if(features.begin(), features.end(), [&page_name](const std::string& feature) {
    return feature == page_name;
  });
  if (it != features.end()) {
    return *it;
  } else {
    return "";
  }
}

void get_real_page_prototype(std::string page_name) {
  std::vector<std::string> features = get_real_features();
  auto it = std::find_if(features.begin(), features.end(), [&page_name](const std::string& feature) {
    return feature == page_name;
  });
  if (it != features.end()) {
    return *it;
  } else {
    return "";
  }
}

int get_real_page_priority(std::string page_name) {
  std::map<std::string, int> page_priorities = {
    {"Exploring College Jobs & Money", 1},
    {"High School Courses", 2},
    {"I’m Looking For…", 3},
    {"Articles", 4},
    {"Professional Organizations", 5},
    {"RSS feeds of current CS information", 6},
    {"Ask an Engineer, Ask a Prof – FAQ", 7},
    {"Consider a CS minor in other professions", 8},
    {"Other ideas/page proposals", 9}
  };

  auto it = page_priorities.find(page_name);
  if (it != page_priorities.end()) {
    return it->second;
  } else {
    return 0;
  }
}

