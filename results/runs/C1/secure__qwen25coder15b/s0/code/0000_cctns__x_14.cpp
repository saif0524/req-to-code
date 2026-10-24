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

struct User;
struct Group;
bool is_admin(const User& user);
bool add_user_to_group(const User& user, const Group& group);
bool remove_user_from_group(const User& user, const Group& group);
bool is_user_in_group(const User& user, const Group& group);
void audit_trail(const std::string& message, const std::string& user, const std::string& group);

void set_access_control(const std::string& user, const std::string& group, bool is_admin);
void add_user_to_group(const std::string& user, const std::string& group);
void remove_user_from_group(const std::string& user, const std::string& group);
void set_security_attributes(const std::string& user, const std::string& group, const std::string& access_rights, const std::string& security_level, const std::string& privileges, const std::string& password);
void quick_search(const std::string& query);

void set_access_control(const std::string& user, const std::string& group, bool is_admin) {
  if (!is_admin(user)) {
    return "Error: User does not have the required permissions to set access control.";
  }
  set_access_control(user, group, true);
  add_user_to_group(user, group);
  remove_user_from_group(user, group);
  if (!is_user_in_group(user, group)) {
    return "Error: User does not belong to the group.";
  }
  set_security_attributes(user, group, access_rights, security_level, privileges, password);
  audit_trail("Set security attributes for user {} and group {}", user, group);
}

void add_user_to_group(const std::string& user, const std::string& group) {
  if (!is_admin(user)) {
    return "Error: User does not have the required permissions to add user to group.";
  }
  set_access_control(user, group, true);
  add_user_to_group(user, group);
}

void remove_user_from_group(const std::string& user, const std::string& group) {
  if (!is_admin(user)) {
    return "Error: User does not have the required permissions to remove user from group.";
  }
  if (user == group) {
    return "Error: User cannot remove themselves from the group.";
  }
  if (!is_user_in_group(user, group)) {
    return "Error: User does not belong to the group.";
  }
  // Loop to remove the user from the group
  for (auto it = group_users.begin(); it != group_users.end(); ++it) {
    if (*it == user) {
      group_users.erase(it);
      break;
    }
  }
}

void set_security_attributes(const std::string& user, const std::string& group, const std::string& access_rights, const std::string& security_level, const std::string& privileges, const std::string& password) {
  if (!is_admin(user)) {
    return "Error: User does not have the required permissions to set security attributes.";
  }
  set_access_control(user, group, true);
  add_user_to_group(user, group);
  remove_user_from_group(user, group);
  if (!is_user_in_group(user, group)) {
    return "Error: User does not belong to the group.";
  }
  set_security_attributes(user, group, access_rights, security_level, privileges, password);
  audit_trail("Set security attributes for user {} and group {}", user, group);
}

void quick_search(const std::string& query) {
  std::vector<std::string> search_results;
  for (const auto& case_info : cases) {
    if (is_user_in_group(case_info.user, case_info.group)) {
      search_results.push_back(case_info.title);
      audit_trail("Accessed case {}", case_info.user, case_info.group);
    }
  }
  return search_results;
}

