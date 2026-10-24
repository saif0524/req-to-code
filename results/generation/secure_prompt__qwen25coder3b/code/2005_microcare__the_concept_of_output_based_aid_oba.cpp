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

std::string generateVoucher(const std::string& patientId, const std::string& serviceType, const std::string& providerId, double amount);
bool refundVoucher(const std::string& voucherId, double amount);
bool validateVoucher(const std::string& voucherId);
void processVoucher(const std::string& voucherId, double amount, const std::string& providerId);
std::string generateReport(const std::string& providerId);

std::string generateVoucher(const std::string& patientId, const std::string& serviceType, const std::string& providerId, double amount) {
  std::string voucherId = patientId + '_' + serviceType + '_' + providerId + '_' + std::to_string(time(nullptr));
  std::string patientDetails = "PatientId: " + patientId + ", ServiceType: " + serviceType + ", ProviderId: " + providerId;
  std::string voucherJson = "{\"voucherId\": \"" + voucherId + "\", \"patientDetails\": \"" + patientDetails + "\", \"serviceType\": \"" + serviceType + "\", \"providerId\": \"" + providerId + "\", \"amount\": " + std::to_string(amount) + "}";
  return voucherJson;
}

bool refundVoucher(const std::string& voucherId, double amount) {
  // Validate voucher ID
  if (!validateVoucher(voucherId)) {
    return false;
  }

  // Check if amount to be refunded is valid
  if (amount <= 0 || amount > getVoucherBalance(voucherId)) {
    return false;
  }

  // Update voucher balance
  double newBalance = getVoucherBalance(voucherId) - amount;
  setVoucherBalance(voucherId, newBalance);

  // Return success response
  std::string response = "{\"reasoning\": \"Voucher refunded successfully.\", \"status\": \"success\", \"voucherId\": \"" + voucherId + "\", \"amount\": " + std::to_string(amount) + "}";
  return true;
}

bool validateVoucher(const std::string& voucherId) {
  // Check if voucherId is valid
  if (voucherId.empty()) {
    return false;
  }

  // Retrieve voucher details from storage
  std::string voucherJson = getVoucherDetails(voucherId);

  // Validate voucher status
  if (voucherJson.empty()) {
    return false;
  }

  // Check if voucher is not expired
  std::string expirationDate = getVoucherExpirationDate(voucherId);
  if (expirationDate.empty() || expirationDate < getCurrentDate()) {
    return false;
  }

  // Return JSON response
  std::string response = "{\"reasoning\": \"Voucher is valid and not expired.\", \"status\": \"success\", \"voucherId\": \"" + voucherId + "\", \"amount\": 

void processVoucher(const std::string& voucherId, double amount, const std::string& providerId) {
  // Validate voucher ID
  if (!validateVoucher(voucherId)) {
    return;
  }

  // Check if amount to be processed is valid
  if (amount <= 0 || amount > getVoucherBalance(voucherId)) {
    return;
  }

  // Update provider's balance
  double providerBalance = getProviderBalance(providerId);
  providerBalance += amount;
  setProviderBalance(providerId, providerBalance);

  // Update voucher status
  setVoucherStatus(voucherId, "processed");

  // Return success response
  std::string response = "{\"reasoning\": \"Voucher processed successfully.\", \"status\": \"success\", \"voucherId\": \"" + voucherId + "\", \"amount\": " + std::to_string(amount) + "}";
  std::cout << response << std::endl;
}

std::string generateReport(const std::string& providerId) {
  std::string report = "{\"reasoning\": \"3 to 6 steps explaining how and why you implement it this way, and \"code\": \"\"}";
  std::vector<std::string> voucherIds = getVoucherIdsByProvider(providerId);
  double totalAmount = 0.0;
  for (const auto& voucherId : voucherIds) {
    if (validateVoucher(voucherId)) {
      totalAmount += getVoucherBalance(voucherId);
    }
  }
  report += "\"code\": \"{\"totalAmount\": 

