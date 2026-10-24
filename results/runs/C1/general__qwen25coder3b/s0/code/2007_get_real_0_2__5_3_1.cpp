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

bool check_consistency(const std::string& web_design, const std::string& ouss_site);
void clarify_preferences(std::map<std::string, int>& preferences);
std::vector<std::string> get_quality_attributes();
bool verify_attributes(const std::vector<std::string>& attributes);
bool adaptability_check(const std::string& web_design);

bool check_consistency(const std::string& web_design, const std::string& ouss_site) {
  return web_design == ouss_site;
}

void clarify_preferences(std::map<std::string, int>& preferences) {
  preferences["adaptability"] = 3;
  preferences["availability"] = 2;
  preferences["correctness"] = 4;
  preferences["flexibility"] = 3;
  preferences["interoperability"] = 2;
  preferences["maintainability"] = 4;
  preferences["portability"] = 3;
  preferences["reliability"] = 4;
  preferences["reusability"] = 3;
  preferences["robustness"] = 4;
  preferences["testability"] = 3;
  preferences["usability"] = 4;
}

std::vector<std::string> get_quality_attributes() { return clarify_preferences({}); }

bool verify_attributes(const std::vector<std::string>& attributes) {
  std::vector<std::string> predefined_attributes = get_quality_attributes();
  for (const auto& attr : attributes) {
    if (std::find(predefined_attributes.begin(), predefined_attributes.end(), attr) == predefined_attributes.end()) {
      return false;
    }
  }
  return true;
}

bool adaptability_check(const std::string& web_design) {
  std::vector<std::string> adaptable_qualities = {"responsive", "mobile-friendly", "scalable", "user-friendly", "accessible"};
  for (const auto& quality : adaptable_qualities) {
    if (web_design.find(quality) != std::string::npos) {
      return true;
    }
  }
  return false;
}

