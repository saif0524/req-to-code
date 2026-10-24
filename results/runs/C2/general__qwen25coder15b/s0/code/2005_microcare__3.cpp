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

bool validate_voucher_number(const std::string& voucher_number);
bool validate_clinical_info(const std::string& clinical_info);
bool validate_diagnosis_details(const std::string& diagnosis_details);
bool validate_drug_and_investigation_details(const std::string& drug_and_investigation_details);
bool validate_costs(const std::string& costs);

bool validate_voucher_number(const std::string& voucher_number) {
  if (voucher_number.length() < 10) {
    return false;
  }
  if (!std::all_of(voucher_number.begin(), voucher_number.end(), ::isalnum)) {
    return false;
  }
  return true;
}

bool validate_clinical_info(const std::string& clinical_info) {
  if (clinical_info.length() < 10) {
    return false;
  }
  if (!std::all_of(clinical_info.begin(), clinical_info.end(), ::isalnum)) {
    return false;
  }
  return true;
}

bool validate_diagnosis_details(const std::string& diagnosis_details) {
  if (diagnosis_details.length() < 10) {
    return false;
  }
  if (!std::all_of(diagnosis_details.begin(), diagnosis_details.end(), ::isalnum)) {
    return false;
  }
  return true;
}

bool validate_drug_and_investigation_details(const std::string& drug_and_investigation_details) {
  if (drug_and_investigation_details.length() < 10) {
    return false;
  }
  if (!std::regex_match(drug_and_investigation_details, std::regex("[A-Za-z0-9]+"))) {
    return false;
  }
  return true;
}

bool validate_costs(const std::string& costs) {
  if (costs.empty()) {
    return false;
  }
  if (costs.length() < 1) {
    return false;
  }
  if (!std::regex_match(costs, std::regex("^[0-9]+$"))) {
    return false;
  }
  return true;
}

