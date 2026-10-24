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

using namespace std;
std::unordered_map<std::string, std::shared_ptr<CustomerAccount>> accounts;

void create_account(const std::string& username, const std::string& password, const std::string& email, const std::string& contact_info, const std::string& address_info);
void register(const std::string& username, const std::string& password, const std::string& email, const std::string& contact_info, const std::string& address_info);
bool login(const std::string& username, const std::string& password);
void logout();
void view_purchase_history();

using namespace std;

void create_account(const std::string& username, const std::string& password, const std::string& email, const std::string& contact_info, const std::string& address_info) {
  if (accounts.find(username) != accounts.end()) {
    return std::nullopt;
  }
  auto account = std::make_shared<CustomerAccount>(username, password, email, contact_info, address_info);
  accounts[username] = account;
}

void register(const std::string& username, const std::string& password, const std::string& email, const std::string& contact_info, const std::string& address_info) {
  if (accounts.find(username) != accounts.end()) {
    return std::nullopt;
  }
  auto account = std::make_shared<CustomerAccount>(username, password, email, contact_info, address_info);
  accounts[username] = account;
}

using namespace std;

std::unordered_map<std::string, std::shared_ptr<CustomerAccount>> accounts;

bool login(const std::string& username, const std::string& password) {
  auto it = accounts.find(username);
  if (it != accounts.end()) {
    if (it->second->password == password) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

void logout(const std::string& username) {
  if (accounts.find(username) != accounts.end()) {
    accounts.erase(accounts.find(username));
    // Clear any session-specific data associated with the account
    // For example, clear the session ID or any other data that is specific to the user's session
  } else {
    return false;
  }
}

void view_purchase_history(const std::string& username) {
  auto it = accounts.find(username);
  if (it != accounts.end()) {
    if (it->second->purchase_history.empty()) {
      return std::nullopt;
    } else {
      json purchase_history_json = json::parse(it->second->purchase_history);
      return purchase_history_json;
    }
  } else {
    return std::nullopt;
  }
}

