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

std::string get_user_status(const std::string& username);
bool validate_user_status(const std::string& status);
void create_user(const std::string& username, const std::string& status);
void update_user_status(const std::string& username, const std::string& new_status);

std::string get_user_status(const std::string& username) {
  std::string status = get_user_status(username);
  if (!validate_user_status(status)) {
    return "Invalid status";
  }
  create_user(username, status);
  return status;
}

bool validate_user_status(const std::string& status) {
  std::string current_status = get_user_status(status);
  if (current_status != "Active" && current_status != "Inactive") {
    return false;
  }
  return true;
}

void create_user(const std::string& username, const std::string& status) {
  if (!validate_user_status(status)) {
    return;
  }
  if (get_user_status(username) != 

void update_user_status(const std::string& username, const std::string& new_status) {
  if (!validate_user_status(new_status)) {
    return;
  }
  if (get_user_status(username) != "Active" && get_user_status(username) != "Inactive") {
    return;
  }
  create_user(username, new_status);
}

