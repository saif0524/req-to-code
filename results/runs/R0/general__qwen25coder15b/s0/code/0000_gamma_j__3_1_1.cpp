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

void create_account(const std::string& username, const std::string& password, const std::string& email);
void update_profile(const std::string& username, const std::string& new_username, const std::string& new_password, const std::string& new_email);
void view_purchase_history(const std::string& username);

void create_account(const std::string& username, const std::string& password, const std::string& email) {
  bool result = account_management::create_account(username, password, email);
  if (!result) {
    throw std::runtime_error("Failed to create account");
  }
}

void update_profile(const std::string& username, const std::string& new_username, const std::string& new_password, const std::string& new_email) {
  bool result = account_management::update_profile(username, new_username, new_password, new_email);
  if (!result) {
    throw std::runtime_error("Failed to update profile");
  }
}

void view_purchase_history(const std::string& username) {
  bool result = account_management::get_purchase_history(username);
  if (!result) {
    throw std::runtime_error("Failed to retrieve purchase history");
  }
  // Return the purchase history as a JSON object
}

