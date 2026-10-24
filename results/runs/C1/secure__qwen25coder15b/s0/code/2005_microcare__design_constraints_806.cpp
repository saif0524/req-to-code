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
void handle_duplicate_name(const std::string& salesman_name);

bool check_duplicate_id(const std::string& salesman_id, const std::string& team_id) {
  // Check if the salesman ID and team ID are duplicated
  if (check_duplicate_id(salesman_id, team_id)) {
    // Handle the case of a duplicate salesman name by providing a warning message or changing the name
    handle_duplicate_name(salesman_id);
    return true;
  } else {
    return false;
  }
}

void handle_duplicate_name(const std::string& salesman_name, const std::string& team_id) {
  if (check_duplicate_id(salesman_id, team_id)) {
    // Provide a warning message
    std::cout << "Warning: Duplicate salesman name detected. Please change the name.\n";
  } else {
    // Change the name
    std::cout << "Name changed to: " << salesman_name << std::endl;
  }
}

