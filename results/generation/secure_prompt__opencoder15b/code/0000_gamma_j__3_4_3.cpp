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

void confirmOrder(Order order);

void confirmOrder(Order order) {
  // Check if the order is valid
  if (order.isValid()) {
    // Send confirmation email
    sendConfirmationEmail(order);
  } else {
    // Provide a way for the customer to revise and update their order
    provideOrderUpdate(order);
  }
}

