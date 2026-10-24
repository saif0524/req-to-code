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

void navigate_to_section(const std::string& system_name, const std::string& section_name);

void display_overview_page(const std::string& system_name);
void load_default_help_topic(const std::string& system_name);

void display_overview_page(const std::string& system_name) {
  navigate_to_section(system_name, "Getting Started");
}

void load_default_help_topic(const std::string& system_name) {
  navigate_to_section(system_name, "Getting Started");
}

