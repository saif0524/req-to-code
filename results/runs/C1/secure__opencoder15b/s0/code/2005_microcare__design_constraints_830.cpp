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

void create_user_group(const std::string& group_name);
void create_user(const std::string& user_name, const std::string& password, const std::string& verify_password);
bool check_passwords(const std::string& password, const std::string& verify_password);
bool check_user_exists(const std::string& user_name);
bool check_group_exists(const std::string& group_name);

void create_user_group(const std::string& group_name) {
   // Check if the user is the system admin
   if (is_system_admin()) {
     // Check if the user group already exists
     if (!check_group_exists(group_name)) {
       // Create the user group
       create_user_group_db(group_name);
     } else {
       // Return an error message
       return_json(409, "User group already exists.");
     }
   } else {
     // Return an error message
     return_json(403, "Only the system admin can create user groups.");
   }
}

void create_user(const std::string& user_name, const std::string& password, const std::string& verify_password) {
   // Check if the user is the system admin
   if (!is_system_admin()) {
     // Return an error message
     return_json(403, "Only the system admin can create user groups.");
   }

   // Check if the user group already exists
   if (!check_group_exists(user_name)) {
     // Create the user group and the user in the database
     create_user_group_db(user_name);
     create_user_db(user_name, password, verify_password);
   } else {
     // Return an error message
     return_json(409, "User group already exists.");
   }
}

bool check_passwords(const std::string& password, const std::string& verify_password) {
  if (password == verify_password) {
    return true;
  } else {
    return false;
  }
}

bool check_user_exists(const std::string& user_name) {
   // Check if the user already exists in the database
   if (user_exists_in_db(user_name)) {
     // Return an error message
     return_json(409, "User already exists.");
   }
   return true;
}

bool check_group_exists(const std::string& group_name) {
    // Check if the user group already exists in the database
    if (user_group_exists_in_db(group_name)) {
      // Return an error message
      return_json(409, "User group already exists.");
    }
    return true;
}

