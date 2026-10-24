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

bool validateSalesReturnData(const std::string& distributorName, const std::string& salesManName, const std::string& salesReturnDate, double salesReturnAmount, int numberOfVouchersReturned, const std::string& batchNo, const std::string& voucherNo);
void captureSalesReturnTransaction(const std::string& distributorName, const std::string& salesManName, const std::string& salesReturnDate, double salesReturnAmount, int numberOfVouchersReturned, const std::string& batchNo, const std::string& voucherNo);
void logSalesReturnTransaction(const std::string& distributorName, const std::string& salesManName, const std::string& salesReturnDate, double salesReturnAmount, int numberOfVouchersReturned, const std::string& batchNo, const std::string& voucherNo);
void updateVoucherInventory(int numberOfVouchersReturned);
void sendSalesReturnNotification(const std::string& distributorName, const std::string& salesManName, const std::string& salesReturnDate, double salesReturnAmount, int numberOfVouchersReturned, const std::string& batchNo, const std::string& voucherNo);

bool validateSalesReturnData(const std::string& distributorName, const std::string& salesManName, const std::string& salesReturnDate, double salesReturnAmount, int numberOfVouchersReturned, const std::string& batchNo, const std::string& voucherNo) {
  if (distributorName.empty() || salesManName.empty() || salesReturnDate.empty() || batchNo.empty() || voucherNo.empty()) {
    return false;
  }
  if (numberOfVouchersReturned < 0) {
    return false;
  }
  if (salesReturnAmount < 0) {
    return false;
  }
  return true;
}

void captureSalesReturnTransaction(const std::string& distributorName, const std::string& salesManName, const std::string& salesReturnDate, double salesReturnAmount, int numberOfVouchersReturned, const std::string& batchNo, const std::string& voucherNo) {
  logSalesReturnTransaction(distributorName, salesManName, salesReturnDate, salesReturnAmount, numberOfVouchersReturned, batchNo, voucherNo);
}

void logSalesReturnTransaction(const std::string& distributorName, const std::string& salesManName, const std::string& salesReturnDate, double salesReturnAmount, int numberOfVouchersReturned, const std::string& batchNo, const std::string& voucherNo) {
  std::string logMessage = "Distributor: " + distributorName + ", Sales Man: " + salesManName + ", Sales Return Date: " + salesReturnDate + ", Sales Return Amount: " + std::to_string(salesReturnAmount) + ", Number of Vouchers Returned: " + std::to_string(numberOfVouchersReturned) + ", Batch No: " + batchNo + ", Voucher No: " + voucherNo;
  std::cout << logMessage << std::endl;
}

void updateVoucherInventory(int numberOfVouchersReturned) {
  static int currentInventory = 1000; // Assume this is the current inventory value
  if (numberOfVouchersReturned < 0) {
    std::cerr << "Error: Negative number of vouchers returned" << std::endl;
    return;
  }
  currentInventory -= numberOfVouchersReturned;
  std::cout << "Updated inventory: " << currentInventory << std::endl;
}

void sendSalesReturnNotification(const std::string& distributorName, const std::string& salesManName, const std::string& salesReturnDate, double salesReturnAmount, int numberOfVouchersReturned, const std::string& batchNo, const std::string& voucherNo) {
  std::string logMessage = "Distributor: " + distributorName + ", Sales Man: " + salesManName + ", Sales Return Date: " + salesReturnDate + ", Sales Return Amount: " + std::to_string(salesReturnAmount) + ", Number of Vouchers Returned: " + std::to_string(numberOfVouchersReturned) + ", Batch No: " + batchNo + ", Voucher No: " + voucherNo;
  std::cout << logMessage << std::endl;
}

