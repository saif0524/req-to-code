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

std::string get_siggraph_link() {
  std::string acm_link = get_acm_link();
  std::string ieee_link = get_ieee_link();
  std::string siggraph_link = "https://www.siggraph.org/education/sections/";\n\nreturn "ACM: " + acm_link + ", IEEE: " + ieee_link + ", SIGGRAPH: " + siggraph_link;\n}

std::string format_organization_list() {
  std::string acm_link = get_acm_link();
  std::string ieee_link = get_ieee_link();
  std::string siggraph_link = get_siggraph_link();

  return "ACM: " + acm_link + ", IEEE: " + ieee_link + ", SIGGRAPH: " + siggraph_link;
}

