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
std::vector<std::string> get_student_sections_links();
void display_links(const std::vector<std::string>& links);

std::string get_acm_link() { return get_student_sections_links()[0]; }

std::string get_ieee_link() { return get_student_sections_links()[1]; }

std::string get_siggraph_link() { return get_student_sections_links()[2]; }

std::vector<std::string> get_student_sections_links() {
  std::vector<std::string> links;
  links.push_back(get_acm_link());
  links.push_back(get_ieee_link());
  links.push_back(get_siggraph_link());
  return links;
}

void display_links(const std::vector<std::string>& links) {
  for (const auto& link : links) {
    std::cout << link << '\n';
  }
}

