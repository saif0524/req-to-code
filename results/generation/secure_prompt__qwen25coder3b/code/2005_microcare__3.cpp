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

bool validateVoucherNumber(const std::string& voucherNumber);
bool validateClinicalInformation(const std::string& clinicalInfo);
bool validateDrugAndInvestigationDetails(const std::string& drugDetails, const std::string& investigationDetails);
bool validateCosts(const std::vector<double>& costs);

bool validateVoucherNumber(const std::string& voucherNumber) {
  // Define a regular expression pattern for voucher numbers
  std::regex voucherPattern("^[A-Za-z0-9]{10}$");

  // Check if the voucher number matches the pattern
  if (!std::regex_match(voucherNumber, voucherPattern)) {
    return false;
  }

  // Check if the voucher number is unique in the database
  // This would involve querying the database and checking for duplicates
  // For demonstration, assume a function `isVoucherNumberUnique` is available
  if (!isVoucherNumberUnique(voucherNumber)) {
    return false;
  }

  // If all checks pass, return true
  return true;
}

bool validateClinicalInformation(const std::string& clinicalInfo) {
  // Define a regular expression pattern for clinical information
  std::regex clinicalPattern("^[A-Za-z0-9\s\.,!?-]*$");

  // Check if the clinical information matches the pattern
  if (!std::regex_match(clinicalInfo, clinicalPattern)) {
    return false;
  }

  // Check if the clinical information is not empty
  if (clinicalInfo.empty()) {
    return false;
  }

  // If all checks pass, return true
  return true;
}

bool validateDrugAndInvestigationDetails(const std::string& drugDetails, const std::string& investigationDetails) {
  // Check if drugDetails is empty
  if (drugDetails.empty()) {
    return false;
  }

  // Check if investigationDetails is empty
  if (investigationDetails.empty()) {
    return false;
  }

  // If both strings are non-empty, return true
  return true;
}

bool validateCosts(const std::vector<double>& costs) {
  for (double cost : costs) {
    if (cost < 0) {
      return false;
    }
  }
  return true;
}

