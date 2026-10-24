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
bool validateDiagnosisDetails(const std::string& diagnosisDetails);
bool validateDrugAndInvestigationDetails(const std::string& drugAndInvestigationDetails);
bool validateCosts(const std::string& costs);

bool validateVoucherNumber(const std::string& voucherNumber) {
  if (voucherNumber.empty()) {
    return false;
  }

  // Define a regular expression for voucher number format
  std::regex voucherNumberPattern("^[A-Za-z0-9]{10}$");

  // Check if the voucher number matches the pattern
  if (!std::regex_match(voucherNumber, voucherNumberPattern)) {
    return false;
  }

  // Check for uniqueness in the database
  // This would typically involve querying the database for the voucher number
  // For demonstration, we assume a function `isVoucherNumberUnique` is available
  if (!isVoucherNumberUnique(voucherNumber)) {
    return false;
  }

  return true;
}

bool validateClinicalInformation(const std::string& clinicalInfo) {
  // Define a simple format for clinical information
  std::string expectedFormat = "Patient Name, Date of Birth, Medical Condition";

  // Check if the clinical information matches the expected format
  if (clinicalInfo == expectedFormat) {
    return true;
  }

  return false;
}

bool validateDiagnosisDetails(const std::string& diagnosisDetails) {
  if (diagnosisDetails.empty()) {
    return false;
  }

  std::istringstream iss(diagnosisDetails);
  std::string diagnosis;

  while (iss >> diagnosis) {
    if (diagnosis.empty()) {
      return false;
    }
  }

  return true;
}

bool validateDrugAndInvestigationDetails(const std::string& drugAndInvestigationDetails) {
  if (drugAndInvestigationDetails.empty()) {
    return false;
  }

  std::istringstream iss(drugAndInvestigationDetails);
  std::string part;

  // Check if there is at least one comma in the input
  if (std::getline(iss, part, ',')) {
    if (part.empty()) {
      return false;
    }

    // Check if there is another part after the first comma
    if (std::getline(iss, part, ',')) {
      if (part.empty()) {
        return false;
      }
    }

    return true;
  }

  return false;
}

bool validateCosts(const std::string& costs) {
  if (costs.empty()) {
    return false;
  }

  std::regex costsPattern("^[0-9]+(\.[0-9]+)?$");

  if (!std::regex_match(costs, costsPattern)) {
    return false;
  }

  return true;
}

