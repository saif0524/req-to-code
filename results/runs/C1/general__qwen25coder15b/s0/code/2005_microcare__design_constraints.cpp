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

struct voucher_t {
  std::string user_id;
  std::string voucher_number;
  std::string validity_date;
};

void create_voucher(const std::string& user_id, const std::string& voucher_number, const std::string& validity_date);
void withhold_voucher(const std::string& voucher_number);
void edit_voucher(const std::string& voucher_number, const std::string& new_voucher_number, const std::string& new_validity_date);
void delete_voucher(const std::string& voucher_number);

void create_voucher(const std::string& user_id, const std::string& voucher_number, const std::string& validity_date) {
  // Validate input parameters
  if (user_id.empty() || voucher_number.empty() || validity_date.empty()) {
    return "Error: Invalid input parameters";
  }

  // Check if user has necessary permissions
  if (!user_has_permission(user_id, "create_voucher")) {
    return "Error: Unauthorized access";
  }

  // Create new voucher
  voucher_t new_voucher;
  new_voucher.user_id = user_id;
  new_voucher.voucher_number = voucher_number;
  new_voucher.validity_date = validity_date;

  // Save new voucher to database
  if (!save_voucher_to_database(new_voucher)) {
    return "Error: Failed to create voucher";
  }

  // Return success message
  return "Voucher created successfully";
}

void withhold_voucher(const std::string& voucher_number) {
  // Validate input parameters
  if (voucher_number.empty()) {
    return "Error: Invalid voucher number";
  }

  // Check if voucher exists in the database
  voucher_t voucher;
  if (!get_voucher_from_database(voucher_number, voucher)) {
    return "Error: Voucher not found";
  }

  // Check if user has necessary permissions
  if (!user_has_permission(voucher.user_id, "withhold_voucher")) {
    return "Error: Unauthorized access";
  }

  // Mark voucher as with-held in the database
  voucher.is_withheld = true;
  if (!save_voucher_to_database(voucher)) {
    return "Error: Failed to withhold voucher";
  }

  // Return success message
  return "Voucher withheld successfully";
}

void edit_voucher(const std::string& voucher_number, const std::string& new_voucher_number, const std::string& new_validity_date) {
  // Validate input parameters
  if (voucher_number.empty() || new_voucher_number.empty() || new_validity_date.empty()) {
    return "Error: Invalid input parameters";
  }

  // Check if voucher exists in the database
  voucher_t voucher;
  if (!get_voucher_from_database(voucher_number, voucher)) {
    return "Error: Voucher not found";
  }

  // Check if user has the necessary permissions
  if (!user_has_permission(voucher.user_id, "edit_voucher")) {
    return "Error: Unauthorized access";
  }

  // Update the details of the voucher
  voucher.voucher_number = new_voucher_number;
  voucher.validity_date = new_validity_date;
  voucher.is_withheld = false;

  // Save the updated voucher to the database
  if (!save_voucher_to_database(voucher)) {
    return "Error: Failed to edit voucher";
  }

  // Return success message
  return "Voucher edited successfully";
}

void delete_voucher(const std::string& voucher_number) {
  // Validate input parameters
  if (voucher_number.empty()) {
    return "Error: Invalid voucher number";
  }

  // Check if voucher exists in the database
  voucher_t voucher;
  if (!get_voucher_from_database(voucher_number, voucher)) {
    return "Error: Voucher not found";
  }

  // Check if user has necessary permissions
  if (!user_has_permission(voucher.user_id, "delete_voucher")) {
    return "Error: Unauthorized access";
  }

  // Mark voucher as deleted in the database
  voucher.is_deleted = true;
  if (!save_voucher_to_database(voucher)) {
    return "Error: Failed to delete voucher";
  }

  // Return success message
  return "Voucher deleted successfully";
}

