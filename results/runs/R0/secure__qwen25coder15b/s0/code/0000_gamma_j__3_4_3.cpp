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

void confirmOrder(const Order& order);
void updateOrder(const Order& order);
void sendConfirmationEmail(const Order& order);

void confirmOrder(const Order& order) {
  if (!isValidOrder(order)) {
    return "Invalid order";
  }
  order.setStatus("confirmed");
  sendConfirmationEmail(order);
}

void updateOrder(const Order& order) {
  if (!isValidOrder(order)) {
    return "Invalid order";
  }
  order.setStatus("updated");
  sendConfirmationEmail(order);
}

void sendConfirmationEmail(const Order& order) {
  if (!isValidOrder(order)) {
    return "Invalid order";
  }
  order.setStatus("confirmed");
  sendEmail(order);
}

