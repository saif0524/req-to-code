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

bool validateClaimForm(const std::string& claimFormNo, const std::string& vspName, const std::string& voucherNo, const std::string& patientName, const std::string& contactNo, const std::string& doctorName, const std::string& hivDetails, const std::string& claimAmount);
void captureClaimDetails(const std::string& claimFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, const std::string& visitCount, const std::string& patientType, const std::string& patientName, const std::string& age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& claimAmount, const std::string& claimStatus);
void markClaimRejected(const std::string& claimFormNo);

bool validateClaimForm(const std::string& claimFormNo, const std::string& vspName, const std::string& voucherNo, const std::string& patientName, const std::string& contactNo, const std::string& doctorName, const std::string& hivDetails, const std::string& claimAmount) {
  if (claimFormNo.empty() || vspName.empty() || voucherNo.empty() || patientName.empty() || contactNo.empty() || doctorName.empty() || claimAmount.empty()) {
    return false;
  }
  return true;
}

void captureClaimDetails(const std::string& claimFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, const std::string& visitCount, const std::string& patientType, const std::string& patientName, const std::string& age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& claimAmount, const std::string& claimStatus) {
  // Create a JSON object to store the claim details
  json claimDetails;
  claimDetails[

void markClaimRejected(const std::string& claimFormNo) {
  json claimDetails;
  claimDetails["status"] = "Rejected";
  claimDetails["reason"] = "Mandatory information missing";
  // Send claimDetails back to VSP
}

