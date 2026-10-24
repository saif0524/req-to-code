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
  // Validate input
  if (username.empty() || password.empty() || email.empty() || role.empty()) {
    throw std::invalid_argument("All fields must be filled.");
  }

  // Use smart pointers for memory safety
  std::unique_ptr<Account> account = std::make_unique<Account>(username, password, email, role);

  // Store account in the system
  // (Assuming a global or static variable to store accounts is allowed)
  accounts.push_back(std::move(account));

  // Return success
  std::cout << "Account created successfully." << std::endl;
}

void assign_privileges(std::string username, std::string role) {
  // Validate input
  if (username.empty() || role.empty()) {
    throw std::invalid_argument("Username and role must be filled.");
  }

  // Find the account by username
  auto it = std::find_if(accounts.begin(), accounts.end(), [&username](const std::unique_ptr<Account>& account) {
    return account->get_username() == username;
  });

  // Check if the account exists
  if (it == accounts.end()) {
    throw std::runtime_error("Account not found.");
  }

  // Assign the role to the account
  (*it)->set_role(role);

  // Return success
  std::cout << "Role assigned successfully for user " << username << std::endl;
}

void update_inventory(std::string product_id, std::string description, std::string picture, double price, bool is_ready) {
  // Validate input
  if (product_id.empty() || description.empty() || picture.empty() || std::to_string(price).empty() || !is_ready) {
    throw std::invalid_argument("All fields must be filled and price must be a valid number.");
  }

  // Find the account by username
  auto it = std::find_if(accounts.begin(), accounts.end(), [&product_id](const std::unique_ptr<Account>& account) {
    return account->get_product_id() == product_id;
  });

  // Check if the account exists
  if (it == accounts.end()) {
    throw std::runtime_error("Product not found.");
  }

  // Update the inventory details
  (*it)->set_description(description);
  (*it)->set_picture(picture);
  (*it)->set_price(price);
  (*it)->set_is_ready(is_ready);

  // Return success
  std::cout << "Inventory updated successfully for product 

void delete_product(std::string product_id) {
  // Validate input
  if (product_id.empty()) {
    throw std::invalid_argument("Product ID must be filled.");
  }

  // Find the product in the inventory
  auto it = std::find_if(accounts.begin(), accounts.end(), [&product_id](const std::unique_ptr<Account>& account) {
    return account->get_product_id() == product_id;
  });

  // Check if the product exists
  if (it == accounts.end()) {
    throw std::runtime_error("Product not found.");
  }

  // Remove the product from the inventory
  accounts.erase(it);

  // Return success
  std::cout << "Product deleted successfully." << std::endl;
}

void change_product_description(std::string product_id, std::string new_description) {
  // Validate input
  if (product_id.empty() || new_description.empty()) {
    throw std::invalid_argument("Product ID and new description must be filled.");
  }

  // Find the product in the inventory
  auto it = std::find_if(accounts.begin(), accounts.end(), [&product_id](const std::unique_ptr<Account>& account) {
    return account->get_product_id() == product_id;
  });

  // Check if the product exists
  if (it == accounts.end()) {
    throw std::runtime_error("Product not found.");
  }

  // Update the product's description
  (*it)->set_description(new_description);

  // Return success
  std::cout << "Product description updated successfully." << std::endl;
}

