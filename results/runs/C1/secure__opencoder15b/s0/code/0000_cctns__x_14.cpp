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

void set_user_access(const std::string& user_id, const std::vector<std::string>& groups);
void set_group_access(const std::string& group_id, const std::vector<std::string>& users);
void remove_user_from_group(const std::string& user_id, const std::string& group_id);
void remove_group_from_user(const std::string& user_id, const std::string& group_id);
void set_user_password(const std::string& user_id, const std::string& password);

void remove_user_from_group(const std::string& user_id, const std::string& group_id) {
  // Find the user and group
  User* user = find_user(user_id);
  Group* group = find_group(group_id);

  // Remove the user from the group
  group->remove_user(user);

  // Log the operation in the audit trail
  log_operation(user_id, group_id, "remove_user_from_group");
}

void remove_group_from_user(const std::string& user_id, const std::string& group_id) {
   // Find the user and group
   User* user = find_user(user_id);
   Group* group = find_group(group_id);

   // Remove the user from the group
   group->remove_user(user);

   // Log the operation in the audit trail
   log_operation(user_id, group_id, "remove_group_from_user");
}

void set_user_password(const std::string& user_id, const std::string& password) {
   // Find the user
   User* user = find_user(user_id);

   // Check if the user exists
   if (user == nullptr) {
       return_error("User does not exist.");
   }

   // Set the password for the user
   user->set_password(password);

   // Log the operation in the audit trail
   log_operation(user_id, "", "set_user_password");
}

