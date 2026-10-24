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

void create_account(std::string username, std::string password, std::string email, std::string role);
void assign_privileges(std::string username, std::string role);
void update_inventory(std::string product_id, std::string description, std::string picture, double price, bool is_ready);
void delete_product(std::string product_id);
void change_product_description(std::string product_id, std::string new_description);

void create_account(std::string username, std::string password, std::string email, std::string role) {
  User user(username, password, email, role);
  users.push_back(user);
  return json{{"username", username}, {"email", email}, {"role", role}};
}

void assign_privileges(std::string username, std::string role) {
  for (auto& user : users) {
    if (user.username == username) {
      user.role = role;
      return json{{"username", username}, {"role", role}};
    }
  }
  return json{{"reason", "User not found"}};
}

void update_inventory(std::string product_id, std::string description, std::string picture, double price, bool is_ready) {
  for (auto& product : inventory) {
    if (product.id == product_id) {
      product.description = description;
      product.picture = picture;
      product.price = price;
      product.is_ready = is_ready;
      return json{{"product_id", product_id}, {"description", description}, {"picture", picture}, {"price", price}, {"is_ready", is_ready}, {"reason", "Updated successfully"}};
    }
  }
  return json{{"reason", "Product not found"}};
}

void delete_product(std::string product_id) {
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    if (it->id == product_id) {
      inventory.erase(it);
      return json{{"product_id", product_id}, {"reason", "Deleted successfully"}};
    }
  }
  return json{{"reason", "Product not found"}};
}

void change_product_description(std::string product_id, std::string new_description) {
  for (auto& product : inventory) {
    if (product.id == product_id) {
      product.description = new_description;
      return json{{"product_id", product_id}, {"description", new_description}, {"reason", "Updated successfully"}};
    }
  }
  return json{{"reason", "Product not found"}};
}

