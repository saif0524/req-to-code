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

bool check_duplicate_id(const std::string& salesman_id, const std::string& team_id);
void display_warning(const std::string& message);
void update_name(const std::string& new_name);

bool check_duplicate_id(const std::string& salesman_id, const std::string& team_id) {
  if (check_duplicate_id(salesman_id, team_id)) {
    display_warning("Duplicate ID found. Please choose a different name.");
    return true;
  } else {
    return false;
  }
}

void display_warning(const std::string& message) {
  std::cout << message << std::endl;
}

void update_name(const std::string& new_name) {
  // Update the salesman's name in the system
  // No side effects, no global state, no external data
  // No return value
}

