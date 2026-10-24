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

bool validateDistributorAndSalesMan(const std::string& distributorName, const std::string& salesManName, const std::string& voucherId);
bool checkReturnDate(const std::string& returnDate);
bool processSalesReturn(const std::string& distributorName, const std::string& salesManName, const std::string& voucherId, const std::string& returnDate);

bool validateDistributorAndSalesMan(const std::string& distributorName, const std::string& salesManName, const std::string& voucherId) {
  // Retrieve the distributor and sales man master records
  DistributorMaster distributorMaster;
  SalesManMaster salesManMaster;

  // Check if the distributor and sales man names match the voucher details
  if (distributorMaster.getName(voucherId) == distributorName && salesManMaster.getName(voucherId) == salesManName) {
    return true; // Voucher was sold to the specified distributor and sales man
  }

  return false; // Voucher is not sold to the specified distributor and sales man
}

bool checkReturnDate(const std::string& returnDate) {
  std::tm returnDateStruct;
  std::istringstream iss(returnDate);
  iss >> std::get_time(&returnDateStruct, "%Y-%m-%d");

  std::time_t now = std::time(nullptr);
  std::tm nowStruct = *std::localtime(&now);

  return std::mktime(&returnDateStruct) <= std::mktime(&nowStruct);
}

bool processSalesReturn(const std::string& distributorName, const std::string& salesManName, const std::string& voucherId, const std::string& returnDate) {
  if (!validateDistributorAndSalesMan(distributorName, salesManName, voucherId)) {
    return false; // Voucher is not sold to the specified distributor and sales man
  }

  if (!checkReturnDate(returnDate)) {
    return false; // Return date is greater than the current system date
  }

  // Accept the voucher as it passes all checks
  return true;
}

