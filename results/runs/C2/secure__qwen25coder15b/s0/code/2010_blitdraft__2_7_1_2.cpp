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

void display_overview_page(const std::string& system_name);
void load_default_help_topic(const std::string& system_name);

void display_overview_page(const std::string& system_name) {
  load_default_help_topic(system_name);
}

void load_default_help_topic(const std::string& system_name) {
  display_overview_page(system_name);
}

