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

void create_voucher(const std::string& user_id, const std::string& voucher_number, const std::string& validity_date, int quantity);
void withhold_voucher(const std::string& voucher_number);
void edit_voucher(const std::string& voucher_number, const std::string& new_voucher_number, const std::string& new_validity_date, int new_quantity);
void delete_voucher(const std::string& voucher_number);

void create_voucher(const std::string& user_id, const std::string& voucher_number, const std::string& validity_date, int quantity) {
  // Validate input parameters
  if (user_id.empty() || voucher_number.empty() || validity_date.empty() || quantity <= 0) {
    return;
  }

  // Check if the user is authorized to create a voucher
  if (!is_user_authorized(user_id)) {
    return;
  }

  // Create the new voucher
  voucher_t voucher;
  voucher.user_id = user_id;
  voucher.voucher_number = voucher_number;
  voucher.validity_date = validity_date;
  voucher.quantity = quantity;

  // Add the new voucher to the system
  add_voucher(voucher);
}

void withhold_voucher(const std::string& voucher_number) {
  // Check if the voucher number exists in the system
  if (!is_voucher_exists(voucher_number)) {
    return;
  }

  // Check if the user has the necessary permissions to perform this action
  if (!is_user_authorized(voucher_number)) {
    return;
  }

  // Mark the voucher as with-held
  update_voucher(voucher_number, voucher_status::withheld);
}

void edit_voucher(const std::string& voucher_number, const std::string& new_voucher_number, const std::string& new_validity_date, int new_quantity) {
  // Check if the voucher number exists in the system
  if (!is_voucher_exists(voucher_number)) {
    return;
  }

  // Check if the user has the necessary permissions to perform this action
  if (!is_user_authorized(voucher_number)) {
    return;
  }

  // Update the details of the voucher
  update_voucher(voucher_number, {new_voucher_number, new_validity_date, new_quantity});

  // Return a JSON object with the message 'Voucher edited successfully'
  return json::object({"message", "Voucher edited successfully"});
}

void delete_voucher(const std::string& voucher_number) {
  // Check if the voucher number exists in the system
  if (!is_voucher_exists(voucher_number)) {
    return json::object({

