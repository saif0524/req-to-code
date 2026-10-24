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
   // Check if the group already exists
   if (check_group_exists(group_name)) {
     // Return JSON with 'reasoning' and 'code' as 1
     return JSON{{"reasoning": "Group already exists", "code": 1}};
   }
   // Create the new user group
   create_user_group(group_name);
   // Return JSON with 'reasoning' and 'code' as 0
   return JSON{{"reasoning": "Group created successfully", "code": 0}};
}

void create_user(const std::string& user_name, const std::string& password, const std::string& verify_password) {
    // Check if the user already exists
    if (check_user_exists(user_name)) {
        // Return JSON with 'reasoning' and 'code' as 1
        return JSON{{"reasoning": "User already exists", "code": 1}};
    }
    // Check if the password and verify password match
    if (!check_passwords(password, verify_password)) {
        // Return JSON with 'reasoning' and 'code' as 2
        return JSON{{"reasoning": "Passwords do not match", "code": 2}};
    }
    // Create the new user
    create_user(user_name, password);
    // Return JSON with 'reasoning' and 'code' as 0
    return JSON{{"reasoning": "User created successfully", "code": 0}};
}

/**
 * Check if the provided password and verify password match.
 *
 * @param password The password to check.
 * @param verify_password The verify password to check.
 *
 * @return true if the passwords match, false otherwise.
 */
bool check_passwords(const std::string& password, const std::string& verify_password) {
    if (password != verify_password) {
        return false;
    }
    return true;
}

