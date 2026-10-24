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

void run_debug_mode();
void run_test_credit_card_transaction(const std::string& card_number, const std::string& expiration_date, const std::string& cvv);
void run_test_shipping_order(const std::string& order_id, const std::string& recipient_name, const std::string& recipient_address);
void create_test_environment();

bool debug_mode = false; void run_debug_mode() { debug_mode = true; }

void run_test_credit_card_transaction(const std::string& card_number, const std::string& expiration_date, const std::string& cvv) {
  // Validate input
  if (card_number.empty() || expiration_date.empty() || cvv.empty()) {
    throw std::invalid_argument("All fields must be provided");
  }

  // Simulate transaction
  std::cout << "Simulating test credit card transaction with card number: " << card_number << std::endl;
  std::cout << "Expiration date: " << expiration_date << std::endl;
  std::cout << "CVV: " << cvv << std::endl;
}

void run_test_shipping_order(const std::string& order_id, const std::string& recipient_name, const std::string& recipient_address) {
  // Validate input
  if (order_id.empty() || recipient_name.empty() || recipient_address.empty()) {
    throw std::invalid_argument("All fields must be provided");
  }

  // Simulate shipping order
  std::cout << "Simulating test shipping order with order ID: " << order_id << std::endl;
  std::cout << "Recipient Name: " << recipient_name << std::endl;
  std::cout << "Recipient Address: " << recipient_address << std::endl;
}

bool test_environment_active = false; void create_test_environment() { test_environment_active = true; std::cout << "Test environment created" << std::endl; }

