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

bool validateDistributorName(const std::string& distributorName);
bool validateSalesmanName(const std::string& salesmanName);
bool validateDate(const std::string& date);
bool validateQty(const std::string& qty);
std::string generateDistributionInvoiceNo();

bool validateDistributorName(const std::string& distributorName) {
  if (distributorName.empty() || distributorName.find_first_not_of(' ') == std::string::npos) {
    return false;
  }
  // Additional logic to check if the distributor name exists in the Distributor Master can be added here
  return true;
}

bool validateSalesmanName(const std::string& salesmanName) {
  if (salesmanName.empty() || salesmanName.find_first_not_of(' ') == std::string::npos) {
    return false;
  }
  // Additional logic to check if the salesman name exists in the Sales Man Master can be added here
  return true;
}

bool validateDate(const std::string& date) {
  std::istringstream iss(date);
  std::tm tm;
  iss >> std::get_time(&tm, "%Y-%m-%d");
  return !iss.fail() && std::mktime(&tm) != -1;
}

bool validateQty(const std::string& qty) {
  std::stringstream ss(qty);
  double value;
  ss >> value;
  return ss.fail() ? false : true;
}

std::string generateDistributionInvoiceNo() {
  static int count = 0;
  std::string prefix = "DINV-";
  std::stringstream ss;
  ss << prefix << count++ << "-";
  char buffer[11];
  std::time_t now = std::time(nullptr);
  std::tm* tm = std::localtime(&now);
  std::strftime(buffer, sizeof(buffer), "%Y%m%d", tm);
  ss << buffer;
  return ss.str();
}

