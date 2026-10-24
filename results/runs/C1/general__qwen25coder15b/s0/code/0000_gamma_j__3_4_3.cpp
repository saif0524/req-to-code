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

struct Order; using validateOrder = bool(const Order& order); using updateOrderStatus = void(const Order& order); using sendConfirmationEmail = void(const Order& order);

void confirmOrder(const Order& order);
void updateOrder(const Order& order);
void sendConfirmationEmail(const Order& order);

void confirmOrder(const Order& order) {
  // Validate the order
  if (!validateOrder(order)) {
    return;
  }

  // Update the order status
  updateOrderStatus(order);

  // Send a confirmation email
  sendConfirmationEmail(order);

  // Return a success message
  return;
}

void updateOrder(const Order& order) {
  // Validate the order
  if (!validateOrder(order)) {
    return;
  }

  // Update the order status
  updateOrderStatus(order);

  // Send a confirmation email
  sendConfirmationEmail(order);

  // Return a success message
  return;
}

void sendConfirmationEmail(const Order& order) {
  // Validate the order
  if (!validateOrder(order)) {
    return;
  }

  // Update the order status
  updateOrderStatus(order);

  // Send a confirmation email
  sendConfirmationEmail(order);

  // Return a success message
  return;
}

