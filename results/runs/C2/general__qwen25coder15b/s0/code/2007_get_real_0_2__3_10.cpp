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

using namespace std;

std::vector<std::string> get_acm_links();
std::vector<std::string> get_ieee_links();
std::vector<std::string> get_siggraph_links();
std::vector<std::string> get_student_sections(const std::string& organization);

std::vector<std::string> get_acm_links() {
  std::vector<std::string> links = get_acm_links();
  links.push_back("https://www.acm.org/");\nreturn links;\n}

using namespace std;
std::vector<std::string> get_ieee_links() {
  std::vector<std::string> links = get_acm_links();
  links.push_back("https://www.ieee.org/student/");\nreturn links;\n}

std::vector<std::string> get_siggraph_links() {
  return get_student_sections("SIGGRAPH");
}

std::vector<std::string> get_student_sections(const std::string& organization) {
  if (organization == "ACM") {
    return get_acm_links();
  } else if (organization == "IEEE") {
    return get_ieee_links();
  } else if (organization == "SIGGRAPH") {
    return get_siggraph_links();
  } else {
    return {}; // Return an empty vector if the organization is not recognized
  }
}

