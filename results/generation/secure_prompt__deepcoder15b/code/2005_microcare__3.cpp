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

std::pair<std::string, std::string> extract_and_validate_claims(std::string voucher_number) {
  bool valid_voucher = validate_voucher_number(voucher_number);
  bool valid_name = validate_description(name);
  bool valid_amount = validate_amount(amount);
  bool valid_additional = validate_additional_info(additional_info);

  if (valid_voucher && valid_name && valid_amount && valid_additional) {
    return std::make_pair(voucher_number, name);
  } else {
    return std::string(

bool validate_voucher_number(std::string voucher_number) {
  if (!std::isdigit(voucher_number[0]) || voucher_number.size() != 10) {
    return false;
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
  

std::pair<std::string, std::string> extract_and_validate_claims(std::string voucher_number) {
  bool valid_voucher = validate_voucher_number(voucher_number);
  return std::make_pair(voucher_number, valid_voucher ? std::string(voucher_number) : std::string(0));
}

bool validate_voucher_number(std::string voucher_number) {
  if (!std::isdigit(voucher_number[0]) || voucher_number.size() != 10) {
    return false;
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
  if (amount[6] != '0' && amount.size() > 7) {
    return false;
  }
  if (amount[7] != '0' && amount.size() > 8) {
    return false;
  }
  if (amount[8] != '0' && amount.size() > 9) {
    return false;
  }
  return true;
}

bool validate_additional_info(std::string additional_info) {
  if (additional_info.empty()) {
    return false;
  }
  for (char c : additional_info) {
    if (!isalpha(c) && !isdigit(c)) {
      return false;
    }
  }
  return true;
}

bool save_claim_to_database(std::pair<std::string, std::string> claim_data) {
  std::string validated_voucher = extract_voucher(claim_data);
  bool valid_voucher = validate_voucher_number(validated_voucher);
  std::string validated_name;
  bool valid_name = validate_description(claim_data);
  std::string validated_description;
  bool valid_description = validate_amount(claim_data);
  std::string validated_amount;
  bool valid_amount = validate_additional_info(claim_data);
  std::string validated_additional;

  if (valid_voucher && valid_name && valid_description && valid_amount && valid_additional) {
    return true;
  }
  return false;
}

std::pair<std::string, std::string> extract_voucher(std::string claim_data) {
  return validate_voucher_number(claim_data);
}
```, 

