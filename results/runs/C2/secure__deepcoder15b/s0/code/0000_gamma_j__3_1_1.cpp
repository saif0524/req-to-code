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

{ std::pair, std::string, std::string }
{ std::pair<std::string, std::string>, std::string, std::string }

std::pair<std::string, std::string, std::string, std::string, std::string, std::string, std::string> create_account_profile(std::string name, std::string email, std::string phone, std::string address, std::string password);
std::pair<std::string, std::string, std::string> create_account_contact(std::string name, std::string email, std::string phone);
std::pair<std::pair<std::string, std::string>, std::string, std::string> create_account_purchase(std::vector<std::pair<std::string, std::string>> purchase_entry);
std::pair<std::string, std::string> create_account_order(std::string order_number, std::string confirmation_message);
std::pair<std::string, std::string> handle_purchase_data(std::string product_name, std::string price);

std::pair<std::string, std::string> create_account_profile(std::string name, std::string email, std::string phone, std::string address, std::string password) {
  using std::pair;
  using std::string;

  if (!validate_name(name)) {
    return std::make_pair<std::string, std::string>(std::string(

// Create account contact function
std::pair<std::string, std::string> create_account_contact(std::string name, std::string email, std::string phone) {
  // Validate name
  auto validate_name = [](std::string name) {
    return !name.empty() && name.length() > 0;
  };

  // Validate email
  auto validate_email = [](std::string email) {
    return (email.length() >= 12 && !email.empty() && (email[0] >= 'a' && email[0] <= 'z') && (email.size() >= 12 && !email.empty()));
  };

  // Validate phone number
  auto validate_phone = [](std::string phone) {
    return (phone.size() >= 11 && !phone.empty() && (phone[0] == '1' || phone[0] == '2' || phone[0] == '3') && (phone.size() <= 12 && !phone.empty()));
  };

  // Main validation
  bool valid = true;
  std::string name_val, email_val, phone_val;

  if (!validate_name(name)) {
    return { std::string(

std::pair<std::string, std::string> create_account_purchase(std::vector<std::pair<std::string, std::string>> purchase_entry) {
  return { purchase_entry[0][0], purchase_entry[0][1] };
}
std::pair<std::string, std::string> handle_purchase_data(std::string product_name, std::string price) {
  auto validate_product = [{}](std::string product) {
    return !product.empty() && product.length() > 0;
  };

  auto validate_price = [{}](std::string price) {
    return std::isdigit(price) && price.length() >= 2 && price > 0;
  };

  std::pair<std::string, std::string> result;
  if (!validate_product(product_name)) {
    result = { std::string(

std::pair<std::string, std::string> create_account_profile(std::string name, std::string email, std::string phone, std::string address, std::string password) {
  using std::pair;
  using std::string;

  if (!validate_name(name)) {
    return std::make_pair<std::string, std::string>(std::string{
    // Create account contact function
    std::pair<std::string, std::string> create_account_contact(std::string name, std::string email, std::string phone) {
      // Validate name
      auto validate_name = [](std::string name) {
        return !name.empty() && name.length() > 0;
      };

      // Validate email
      auto validate_email = [](std::string email) {
        return (email.length() >= 12 && !email.empty() && (email[0] >= 'a' && email[0] <= 'z') && (email.size() >= 12 && !email.empty()));
      };

      // Validate phone number
      auto validate_phone = [](std::string phone) {
        return (phone.size() >= 11 && !phone.empty() && (phone[0] == '1' || phone[0] == '2' || phone[0] == '3') && (phone.size() <= 12 && !phone.empty()));
      };

      // Main validation
      bool valid = true;
      std::string name_val, email_val, phone_val;

      if (!validate_name(name)) {
        return std::make_pair<std::string, std::string>(std::string{
          // Create account purchase function
          std::pair<std::string, std::string> create_account_purchase(std::vector<std::pair<std::string, std::string>> purchase_entry) {
            return {purchase_entry[0][0], purchase_entry[0][1]};
          }
        });
      }

      if (!validate_email(email)) {
        return std::make_pair<std::string, std::string>(std::string{
          // Create account purchase function
          std::pair<std::string, std::string> create_account_purchase(std::vector<std::pair<std::string, std::string>> purchase_entry) {
            return {purchase_entry[0][0], purchase_entry[0][1]};
          });
        });
      }

      if (!validate_phone(phone)) {
        return std::make_pair<std::string, std::string>(std::string{
          // Handle purchase data
          std::pair<std::string, std::string> handle_purchase_data(std::string product_name, std::string price) {
            return {product_name, price};
          });
        });
      }

      return {product_name, price};
    }

  }

  // ... rest of the code as per the user's requirements
}.

// ... rest of the code as per the user's requirements\n\nstd::pair<std::string, std::string> create_account_profile(std::string name, std::string email, std::string phone, std::string address, std::string password) {
  using std::pair;
  using std::string;

  if (!validate_name(name)) {
    return std::make_pair<std::string, std::string>(std::string{
      // Create account contact function
      std::pair<std::string, std::string> create_account_contact(std::string name, std::string email, std::string phone) {
        // Validate name
        auto validate_name = [](std::string name) {
          return !name.empty() && name.length() > 0;
        };

        // Validate email
        auto validate_email = [](std::string email) {
          return (email.length() >= 12 && !email.empty() && (email[0] >= 'a' && email[0] <= 'z') && (email.size() >= 12 && !email.empty()));
        };

        // Validate phone number
        auto validate_phone = [](std::string phone) {
          return (phone.size() >= 11 && !phone.empty() && (phone[0] == '1' || phone[0] == '2' || phone[0] == '3') && (phone.size() <= 12 && !phone.empty()));
        };

        // Main validation
        bool valid = true;
        std::string name_val, email_val, phone_val;

        if (!validate_name(name)) {
          return std::make_pair<std::string, std::string>(std::string{
            // Create account purchase function
            std::pair<std::string, std::string> create_account_purchase(std::vector<std::pair<std::string, std::string>> purchase_entry) {
              return {purchase_entry[0][0], purchase_entry[0][1]};
            };
          });
        }

        if (!validate_email(email)) {
          return std::make_pair<std::string, std::string>(std::string{
            // Create account purchase function
            std::pair<std::string, std::string> create_account_purchase(std::vector<std::pair<std::string, std::string>> purchase_entry) {
              return {purchase_entry[0][0], purchase_entry[0][1]};
            };
          });
        }

        if (!validate_phone(phone)) {
          return std::make_pair<std::string, std::string>(std::string{
            // Handle purchase data
            std::pair<std::string, std::string> handle_purchase_data(std::string product_name, std::string price) {
              return {product_name, price};
            };
          });
        }

        return {product_name, price};
          }
        // ... rest of the code as per the user's requirements\n\nstd::pair<std::string, std::string> handle_purchase_data(std::string product_name, std::string price) {
    auto validate_product = [{}](std::string product) {
      return !product.empty() && product.length() > 0;
    };

    auto validate_price = [{}](std::string price) {
      return std::isdigit(price) && price.length() >= 2 && price > 0;
    };

    std::pair<std::string, std::string> result;

    if (!validate_product(product_name)) {
      result = {std::string(

