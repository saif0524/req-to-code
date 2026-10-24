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

void confirmOrder(Order& order);
void updateOrder(Order& order);
void sendConfirmationEmail(const Order& order);
bool validateOrder(const Order& order);
Order createOrder(Customer& customer, const Product& product);

void confirmOrder(Order& order) {
  if (validateOrder(order)) {
    sendConfirmationEmail(order);
    return true;
  }
  return false;
}

void updateOrder(Order& order) {
  if (validateOrder(order)) {
    sendConfirmationEmail(order);
    return true;
  }
  updateOrder(order);
  sendConfirmationEmail(order);
  return false;
}

void sendConfirmationEmail(const Order& order) {
  if (sendEmail(order)) {
    return true;
  }
  return false;
}

bool validateOrder(const Order& order) {
  if (order.customerId.empty() || order.productId.empty() || order.quantity <= 0) {
    return false;
  }
  if (!productExists(order.productId)) {
    return false;
  }
  if (order.quantity > stockAvailable(order.productId)) {
    return false;
  }
  return true;
}

Order createOrder(Customer& customer, const Product& product) {
  Order order;
  order.customerId = customer.id;
  order.productId = product.id;
  order.quantity = 1;
  if (!validateOrder(order)) {
    return order;
  }
  sendConfirmationEmail(order);
  return order;
}

