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

std::pair<std::string, std::string, std::string> create_account_contact(std::string name, std::string email, std::string phone);
std::pair<std::pair<std::string, std::string>, std::string, std::string> create_account_purchase(std::vector<std::pair<std::string, std::string>> purchase_entry);
std::pair<std::string, std::string> create_account_order(std::string order_number, std::string confirmation_message);
std::pair<std::string, std::string> handle_purchase_data(std::string product_name, std::string price);

std::pair<std::string, std::string, std::string> create_account_contact(std::string name, std::string email, std::string phone) {
  // Validate name
  auto validate_name = [](std::string name) {
    return !name.empty() && name.length() > 0;
  };

  // Validate email
  auto validate_email = [](std::string email) {
    return (email.length() >= 12 && !email.empty() && 
           (email[0] >= 'a' && email[0] <= 'z') && 
           (email.size() >= 12 && !email.empty())
  };

  // Validate phone number
  auto validate_phone = [](std::string phone) {
    return (phone.size() >= 11 && !phone.empty() && 
           (phone[0] == '1' || phone[0] == '2' || phone[0] == '3') && 
           (phone.size() <= 12 && !phone.empty())
  };

  // Main validation
  bool valid = true;
  std::string name_val, email_val, phone_val;

  if (!validate_name(name)) {
    return std::make_pair<std::string, std::string, std::string>(

std::pair<std::pair<std::string, std::string>, std::string, std::string> create_account_purchase(std::vector<std::pair<std::string, std::string>> purchase_entry) {
  auto validate_entry = [](std::pair<std::string, std::string> entry) {
    if (entry.first.empty() || entry.second.empty() || entry.first.length() <= 0 || entry.second.length() <= 0) {
      return false;
    }
    if (!std::isalpha(entry.first)[0] || !std::isalpha(entry.second)[0]) {
      return false;
    }
    if (!std::isalnum(entry.first) || !std::isalnum(entry.second) || entry.first.size() < 12 || entry.second.size() < 12) {
      return false;
    }
    return true;
  }

  for (auto& entry : purchase_entry) {
    if (!validate_entry(entry)) {
      return std::make_pair<std::pair<std::string, std::string>, std::string, std::string>(
        

std::pair<std::string, std::string> create_account_order(std::string order_number, std::string confirmation_message) {
  // create a vector with one pair
  std::vector<std::pair<std::string, std::string>> purchase_entry({std::make_pair(order_number, confirmation_message)});
  // then call create_account_purchase with this vector
  return create_account_purchase(purchase_entry);
  }
  

std::pair<std::string, std::string> handle_purchase_data(std::string product_name, std::string price) {
  // Validate product name
  auto validate_product = [](std::string product) {
    return !product.empty() && product.length() > 0;
  };

  // Validate price
  auto validate_price = [](std::string price) {
    return std::isdigit(price) && price.length() >= 2 && price > 0;
  };

  // Main validation
  bool valid = true;
  std::string product_val, price_val;

  if (!validate_product(product_name)) {
    return std::make_pair<std::string, std::string>(std::string(

