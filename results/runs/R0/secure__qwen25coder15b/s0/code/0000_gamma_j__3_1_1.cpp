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

void view_purchase_history(const std::string& username);
void confirm_order(const std::string& username, const std::string& order_id);

void view_purchase_history(const std::string& username) {
  // Retrieve the purchase history from the database
  std::vector<std::string> purchase_history = get_purchase_history(username);

  // Return the purchase history as a JSON object
  return json::object({
    "username": username,
    "purchase_history": purchase_history
  });
}

void confirm_order(const std::string& username, const std::string& order_id) {
  // Retrieve the order from the database
  std::optional<Order> order = get_order(username, order_id);

  // Check if the order exists
  if (!order.has_value()) {
    return json::object({
      "username": username,
      "reason": "Order not found"
    });
  }

  // Confirm the order
  order->confirm();

  // Return the confirmation message
  return json::object({
    "username": username,
    "reason": "Order confirmed"
  });
}

