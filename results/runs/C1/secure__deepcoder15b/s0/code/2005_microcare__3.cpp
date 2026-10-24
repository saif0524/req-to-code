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

std::pair<std::string, std::string> extract_and_validate_claims(std::string voucher_number, std::string name, std::string description, std::string amount, std::string additional_info);
bool validate_voucher_number(std::string voucher_number);
bool validate_description(std::string description);
bool validate_amount(std::string amount);
void save_claim_to_database(std::pair<std::string, std::string> claim_data);

std::pair<std::string, std::string> extract_and_validate_claims(std::string voucher_number, std::string name, std::string description, std::string amount, std::string additional_info) {
  // Validate each parameter
  bool valid_voucher = validate_voucher_number(voucher_number);
  bool valid_name = validate_description(name);
  bool valid_description = validate_amount(description);
  bool valid_amount = validate_amount(amount);
  bool valid_additional = validate_additional_info(additional_info);

  // Check if all validations are successful
  if (valid_voucher && valid_name && valid_description && valid_amount && valid_additional) {
    // Extract validated values
    std::string validated_voucher = extract_voucher(claim_data);
    std::string validated_name = validate_description(name);
    std::string validated_description = validate_amount(description);
    std::string validated_amount = validate_amount(amount);
    std::string validated_additional = validate_additional_info(additional_info);

    // Combine validated values into a pair
    return {validated_voucher, validated_name};
  }

  // Handle invalid cases
  if (!valid_voucher && valid_name && valid_description && valid_amount && valid_additional) {
    return {std::string(0), std::string(0)};
  }

  // Handle other invalid cases
  if (valid_voucher && !valid_name && valid_description && valid_amount && valid_additional) {
    return {std::string(0), std::string(0)};
  }

  // Similarly handle other invalid combinations
  // ... (continue for other parameters as needed)
  // ...
  // ...
  // ...
  return {std::string(0), std::string(0)};
  }
  // ... (rest of the code)
}

bool validate_voucher_number(std::string voucher_number) {
  if (voucher_number.size() != 10) return false;
  for (char c : voucher_number) {
    if (!std::isdigit(c)) return false;
  }
  return true;
  }

bool validate_description(std::string description) {
  if (description.empty()) {
    return false; 
  }
  for (char c : description) {
    if (!isalpha(c) && !isdigit(c)) {
      return false; 
    }
  }
  return true; 
  }
  

bool validate_amount(std::string amount) {
  if (amount.empty() || amount.size() != 10) {
    return false; 
  }
  if (!std::isdigit(amount[0]) || !std::isdigit(amount[1]) || !std::isdigit(amount[2]) || !std::isdigit(amount[3])) {
    return false; 
  }
  if (amount[4] != '0') {
    return false; 
  }
  if (amount[5] != '.') {
    return false; 
  }
  if (amount[6] != '0') {
    return false; 
  }
  if (amount[7] != '0') {
    return false; 
  }
  if (amount[8] != '0') {
    return false; 
  }
  return true; 
  }
  

std::pair<std::string, std::string> extract_and_validate_claims(std::string voucher_number, std::string name, std::string description, std::string amount, std::string additional_info) {
  // Validate each parameter
  bool valid_voucher = validate_voucher_number(voucher_number);
  bool valid_name = validate_description(name);
  bool valid_description = validate_amount(description);
  bool valid_amount = validate_amount(amount);
  bool valid_additional = validate_additional_info(additional_info);

  // Collect all valid results
  std::vector<bool> valid_results = {
    valid_voucher,
    valid_name,
    valid_description,
    valid_amount,
    valid_additional
  };

  // Check if all validations are successful
  if (valid_results.all())) {
    // Extract validated values
    std::string validated_voucher;
    std::string validated_name;
    std::string validated_description;
    std::string validated_amount;
    std::string validated_additional;

    if (valid_voucher && valid_name && valid_description && valid_amount && valid_additional) {
      // Extract validated values
      validated_voucher = extract_voucher(claim_data);
      validated_name = name;
      validated_description = description;
      validated_amount = amount;
      validated_additional = additional_info;
    }

    return {validated_voucher, validated_name};
  }

  // Handle invalid cases
  if (!valid_voucher && valid_name && valid_description && valid_amount && valid_additional) {
    return {0, 0};
  }

  // Handle other invalid cases
  if (valid_voucher && !valid_name && valid_description && valid_amount && valid_additional) {
    return {0, 0};
  }

  // Similarly handle other parameters as needed
  // ... (continue for other parameters as needed)
  // ...
  return {0, 0};
  }
}

