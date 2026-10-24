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
void create_test_environment();

void run_under_debug_mode() {
  // Ensure the system is properly initialized
  initialize_system();

  // Enable debug mode
  set_debug_mode(true);

  // Run the system in debug mode
  run_system();
}

void run_test_credit_card_transactions() {
  // Ensure the system is properly initialized
  initialize_system();

  // Set up the test credit card transactions
  setup_test_credit_card_transactions();

  // Execute the test credit card transactions
  execute_test_credit_card_transactions();
}

void run_test_shipping_orders() {
  // Ensure the system is properly initialized
  initialize_system();

  // Set up the test shipping order
  setup_test_shipping_order();

  // Execute the test shipping order
  execute_test_shipping_order();

  // Verify the results
  verify_test_shipping_order();
}

void create_test_environment() {
  // Initialize the system
  initialize_system();

  // Set up the test data
  setup_test_data();

  // Ensure that all necessary resources are available
  ensure_resources_available();
}

