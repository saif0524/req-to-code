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

void run_under_debug_mode();
void run_test_credit_card_transactions();
void run_test_shipping_orders();

void run_under_debug_mode() {
  // Start the system in debug mode
}

void run_test_credit_card_transactions() {
  run_under_debug_mode();
  run_under_debug_mode();
}

void run_test_shipping_orders() {
  run_under_debug_mode();
  run_under_debug_mode();
  // Add local variable to store order details
  std::string customer_name = "John Doe";
  std::string address = "123 Main St, Anytown, USA";
  std::string shipping_method = "Standard";
  // Pass order details to run_under_debug_mode() function
  run_under_debug_mode(customer_name, address, shipping_method);
}

