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

void assign_administrator_privileges(const std::vector<std::string>& usernames);
void update_inventory(const std::vector<std::string>& usernames);
void add_product_description(const std::string& username, const std::string& product_id, const std::string& description);
void delete_product_description(const std::string& username, const std::string& product_id);
void change_product_price(const std::string& username, const std::string& product_id, double new_price);

void assign_administrator_privileges(const std::vector<std::string>& usernames) {
  if (usernames.empty()) {
    return;
  }
  if (usernames.size() == 1) {
    assign_administrator_privileges(usernames[0]);
  }
  for (const auto& username : usernames) {
    assign_administrator_privileges(username);
  }
}

void User::update_inventory(const std::vector<std::string>& usernames) {
  for (const auto& username : usernames) {
    update_inventory(username);
  }
}

void add_product_description(const std::string& username, const std::string& product_id, const std::string& description) {
  add_product_description(username, product_id, description);
}

void change_product_price(const std::string& username, const std::string& product_id, double new_price) {
  // Iterate over the list of usernames and call the change_product_price function for each user
  for (const auto& user : usernames) {
    change_product_price(user, product_id, new_price);
  }
}

