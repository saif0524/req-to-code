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
  // This step is already handled by the function 'confirmOrder'.

  // Step 2: Send a confirmation email
  // The 'sendEmail' function is assumed to be a function that sends an email to the customer.
  sendEmail(email, "Confirmation Email", "Your order has been confirmed.\n\nOrder details: 

