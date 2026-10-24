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

string const checkDistributorExistence(const string &distributor);
string const checkSalesmanExistence(const string &salesman);
void displayVoucherGrid(int batchNo, int voucherNo, string validityDate, vector<Voucher> &vouchers);

string checkDistributorExistence(const string &distributor) {
    bool existsDistributor = false;
    for (const auto &entry : systemDistributors) {
        if (entry.distributor == distributor) {
            existsDistributor = true;
            break;
        }
    }
    return existsDistributor ? "Distributor exists." : "Distributor does not exist.";
    "reasoning": "The function checks if a given distributor exists in the system by iterating through all entries and comparing the distributor name. It returns a message indicating whether the distributor exists or not.\n"}
    

string const checkSalesmanExistence(const string &salesman) {
    bool existsSalesman = false;
    for (const auto &entry : systemSalesmen) {
      if (entry.salesMAN == salesman) {
        existsSalesman = true;
        break;
      }
    }
    return existsSalesman ? 

void displayVoucherGrid(int batchNo, int voucherNo, string validityDate, vector<Voucher> &vouchers) {
  if (vouchers.empty()) {
    return;
  }
  vector<string> displayStrings;
  for (const auto &voucher : vouchers) {
    string info = batchNo + " | " + voucher.batchNo + " | " + voucher.voucherNo + " | " + validityDate;
    displayStrings.push_back(info);
  }
  for (size_t i = 0; i < displayStrings.size(); i++) {
    displayStrings[i] += " | ";
  }
  for (size_t i = 0; i < displayStrings.size(); i++) {
    displayStrings[i] += " | ";
  }
  for (size_t i = 0; i < displayStrings.size(); i++) {
    displayStrings[i] += " | ";
  }
  for (size_t i = 0; i < displayStrings.size(); i++) {
    displayStrings[i] += " | ";
  }
  string result = displayStrings[0];
  for (size_t i = 1; i < displayStrings.size(); i++) {
    result += " | " + displayStrings[i];
  }
  result += "\n";
  return result;
  "reasoning": "\n"code": "
  "}"
```json{

