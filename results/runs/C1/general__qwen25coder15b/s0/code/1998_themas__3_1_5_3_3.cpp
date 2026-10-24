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

void generate_request(const std::string& unit_name, bool is_on);
void process_request(const std::string& unit_name, bool is_on);

void generate_request(const std::string& unit_name, bool is_on) {
  process_request(unit_name, is_on);
}

void process_request(const std::string& unit_name, bool is_on) {
  generate_request(unit_name, is_on);
}

