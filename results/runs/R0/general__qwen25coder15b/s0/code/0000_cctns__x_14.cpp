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

void set_access_control(const std::string& user, const std::string& group, bool is_admin);
void add_user_to_group(const std::string& user, const std::string& group);
void remove_user_from_group(const std::string& user, const std::string& group);
void set_case_access(const std::string& user, const std::string& case_id, bool can_access);
bool check_case_access(const std::string& user, const std::string& case_id);

void set_access_control(const std::string& user, const std::string& group, bool is_admin) {
  if (is_admin) {
    // Set up user profiles and allocate users to groups
  } else {
    // Do nothing
  }
}

void add_user_to_group(const std::string& user, const std::string& group) {
  if (is_admin) {
    add_user_to_group(user, group);
  }
}

void remove_user_from_group(const std::string& user, const std::string& group) {
  if (!is_admin()) {
    return;
  }
  remove_user_from_group(user, group);
}

void set_case_access(const std::string& user, const std::string& case_id, bool can_access) {
  if (is_admin()) {
    set_access_control(user, case_id, can_access);
  }
}

bool check_case_access(const std::string& user, const std::string& case_id) {
  if (is_admin()) {
    return check_access_control(user, case_id);
  } else {
    return false;
  }
}

