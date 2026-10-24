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

void confirmOrder(Order order, string email);

void confirmOrder(Order order, string email) {
  // Step 1: Confirm the order
  order.status = 'confirmed';

  // Step 2: Prepare the email body
  string emailBody = "Order details: " + order.details;

  // Step 3: Send the email
  sendEmail(email, "Confirmation", emailBody);
}

