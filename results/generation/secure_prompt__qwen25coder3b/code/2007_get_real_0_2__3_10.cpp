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
std::string format_organization_list();

std::string get_acm_link() { return "https://www.acm.org/students/"; }

std::string get_ieee_link() { return "https://www.ieee.org/students/"; }

std::string get_siggraph_link() { return "https://www.siggraph.org/students/"; }

std::string format_organization_list() {
  std::string acm_link = get_acm_link();
  std::string ieee_link = get_ieee_link();
  std::string siggraph_link = get_siggraph_link();

  return "ACM: " + acm_link + ", IEEE: " + ieee_link + ", SIGGRAPH: " + siggraph_link;
}

