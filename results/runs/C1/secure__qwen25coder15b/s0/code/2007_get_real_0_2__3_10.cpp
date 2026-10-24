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

std::string get_acm_link();
std::string get_ieee_link();
std::string get_siggraph_link();
std::string get_student_section_link(const std::string& organization);

std::string get_student_section_link(const std::string& organization) {
  if (organization == "ACM") {
    return get_acm_link();
  } else if (organization == "IEEE") {
    return get_ieee_link();
  } else if (organization == "SIGGRAPH") {
    return get_siggraph_link();
  } else {
    return "Invalid organization";
  }
}

