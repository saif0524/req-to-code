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

void create_account(const std::string& username, const std::string& password, const std::string& email, const std::string& phone, const std::string& address, const std::string& credit_card_number, const std::string& expiration_date, const std::string& cvv);
bool login(const std::string& username, const std::string& password);
void logout();
void view_purchase_history();
void confirm_order();

void create_account(const std::string& username, const std::string& password, const std::string& email, const std::string& phone, const std::string& address, const std::string& credit_card_number, const std::string& expiration_date, const std::string& cvv) {
  static std::map<std::string, std::string> user_credentials;

  if (user_credentials.find(username) != user_credentials.end()) {
    std::cout << "Error: Username already exists." << std::endl;
    return;
  }

  user_credentials[username] = password;

  std::cout << "Account created successfully." << std::endl;
}

bool login(const std::string& username, const std::string& password) {
  static std::map<std::string, std::string> user_credentials;
  if (user_credentials.find(username) != user_credentials.end() && user_credentials[username] == password) {
    return true;
  }
  return false;
}

void logout() {
  static std::string logged_in_username;
  if (logged_in_username != "") {
    logged_in_username = "";
  }
}

void view_purchase_history() {
  static std::map<std::string, std::vector<std::string>> purchase_history;
  static std::string logged_in_username;

  if (logged_in_username != "") {
    auto it = purchase_history.find(logged_in_username);
    if (it != purchase_history.end()) {
      for (const auto& entry : it->second) {
        std::cout << entry << std::endl;
      }
    } else {
      std::cout << "No purchase history found for this customer." << std::endl;
    }
  } else {
    std::cout << "Customer is not logged in." << std::endl;
  }
}

void confirm_order() {
  static std::map<std::string, std::vector<std::string>> order_details;
  static std::string logged_in_username;

  if (logged_in_username != "") {
    auto it = order_details.find(logged_in_username);
    if (it != order_details.end()) {
      std::cout << "Order confirmed for customer: " << logged_in_username << std::endl;
      // Additional logic to confirm the order can be added here
    } else {
      std::cout << "No order found for this customer." << std::endl;
    }
  } else {
    std::cout << "Customer is not logged in." << std::endl;
  }
}

