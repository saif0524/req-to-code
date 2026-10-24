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

void create_account(const std::string& username, const std::string& password);
bool login(const std::string& username, const std::string& password);
void logout(const std::string& username);
void update_profile(const std::string& username, const std::string& new_password, const std::string& new_email);
std::tuple<std::string, std::string> get_account_info(const std::string& username);

void create_account(const std::string& username, const std::string& password) {
  // Check if the account already exists
  if (account_exists(username)) {
    // Return an error message
    return std::make_tuple("Account already exists.", "" );
  }

  // Create a new account
  CustomerAccount new_account;
  new_account.username = username;
  new_account.password = password;
  new_account.email = "";
  new_account.profile = "";

  // Add the new account to the system
  accounts.push_back(new_account);

  // Return success message
  return std::make_tuple("Account created successfully.", "" );
}

bool login(const std::string& username, const std::string& password) {
  // Check if the account exists
  if (!account_exists(username)) {
    // Return an error message
    return std::make_tuple("Account does not exist.", "" );
  }

  // Verify the provided password
  if (password != get_account_password(username)) {
    // Return an error message
    return std::make_tuple("Incorrect password.", "" );
  }

  // Return success message
  return std::make_tuple("Logged in successfully.", "" );
}

void logout(const std::string& username) {
  // Find the customer's account
  auto it = std::find_if(accounts.begin(), accounts.end(), [&username](const CustomerAccount& account) { return account.username == username; });

  // If the account exists, remove it from the system
  if (it != accounts.end()) {
    accounts.erase(it);
  }
}

void update_profile(const std::string& username, const std::string& new_password, const std::string& new_email) {
  // Check if the account exists
  if (!account_exists(username)) {
    // Return an error message
    return std::make_tuple("Account does not exist.", "" );
  }

  // Verify the provided password
  if (login(username, new_password) != std::make_tuple("Logged in successfully.", "" )) {
    // Return an error message
    return std::make_tuple("Incorrect password.", "" );
  }

  // Update the customer's profile
  for (auto& account : accounts) {
    if (account.username == username) {
      account.email = new_email;
      account.password = new_password;
    }
  }

  // Return success message
  return std::make_tuple("Profile updated successfully.", "" );
}

std::tuple<std::string, std::string> get_account_info(const std::string& username) {
  // Find the customer's account
  auto it = std::find_if(accounts.begin(), accounts.end(), [&username] (const CustomerAccount& account) { return account.username == username; });

  // If the account exists, return its information
  if (it != accounts.end()) {
    return std::make_tuple("Account information retrieved successfully.", "Account information: username: " + it->username + ", email: " + it->email + ", password: " + it->password);
  }

  // If the account does not exist, return an error message
  return std::make_tuple("Account does not exist.", "");
}

