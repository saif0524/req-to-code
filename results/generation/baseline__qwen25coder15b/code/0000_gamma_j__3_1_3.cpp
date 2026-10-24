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

void create_account(const std::string& username, const std::string& password, const std::string& email, const std::string& contact_info);
bool login(const std::string& username, const std::string& password);
void logout();
void view_purchase_history();
void confirm_order(const std::string& order_id);

void create_account(const std::string& username, const std::string& password, const std::string& email, const std::string& contact_info) {
  CustomerAccountManager::create_account(username, password, email, contact_info);
}

bool login(const std::string& username, const std::string& password) {
  return CustomerAccountManager::login(username, password);
}

void logout() { CustomerAccountManager::logout(); }

void view_purchase_history() {
  CustomerAccountManager::view_purchase_history();
}

void confirm_order(const std::string& order_id) {
  // Retrieve the purchase history of the current customer
  auto purchase_history = CustomerAccountManager::view_purchase_history();

  // Find the order with the provided order ID
  auto order = std::find_if(purchase_history.begin(), purchase_history.end(), [&order_id](const auto& order) {
    return order.id == order_id;
  });

  // If the order is found, update its status to 'confirmed'
  if (order != purchase_history.end()) {
    order->status = 'confirmed';
    CustomerAccountManager::update_order_status(order);
  } else {
    // Log an error if the order is not found
    std::cerr << "Order not found: " << order_id << std::endl;
  }
}

