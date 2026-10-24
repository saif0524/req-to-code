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

bool validateDistributorAddress(const std::string& address);
bool checkDuplicateName(const std::string& name);
std::string generateDuplicateIndicator(const std::string& name);
void printDistributorDetails(const Distributor& distributor);
void viewSalesHistory(const Distributor& distributor);

bool validateDistributorAddress(const std::string& address) {

  std::regex pattern(R"(District, Sub-District, County, Sub-County or Village / Town, road or street)");

  if (!std::regex_match(address, pattern)) {
    return false;
  }

  static std::vector<std::string> existingAddresses = {
    "District, Sub-District, County, Sub-County or Village / Town, road or street",
    "Another District, Another Sub-District, Another County, Another Sub-County or Village / Town, Another road or street"
  };

  for (const auto& existing : existingAddresses) {
    if (existing == address) {
      return false;
    }
  }

  return true;
}

bool checkDuplicateName(const std::string& name) {
  static std::vector<std::string> existingNames = {
    "Distributor1",
    "Distributor2",
    "Distributor3"
  }; // Example names, replace with actual data

  for (const auto& existing : existingNames) {
    if (existing == name) {
      return true;
    }
  }

  return false;
}

std::string generateDuplicateIndicator(const std::string& name) {
  static int duplicateCounter = 0;
  return name + '_' + std::to_string(duplicateCounter++);
}

struct Sale { std::string batchNo; std::string dateOfPurchase; int qtyPurchase; int qtySold; int qtyReturned; int balanceQty; }; void printDistributorDetails(const Distributor& distributor) { std::cout << "Distributor Name: " << distributor.name << std::endl; std::cout << "Address: " << distributor.address << std::endl; // Add other details as required by the requirement text }

void viewSalesHistory(const Distributor& distributor) { std::cout << "Distributor Name: " << distributor.name << std::endl; std::cout << "Address: " << distributor.address << std::endl; // Add other details as required by the requirement text std::cout << "Batch No" << "\t" << "Date of purchase" << "\t" << "Qty Purchase" << "\t" << "Qty Sold" << "\t" << "Qty Returned" << "\t" << "Balance Qty" << std::endl; for (const auto& sale : distributor.salesHistory) { std::cout << sale.batchNo << "\t" << sale.dateOfPurchase << "\t" << sale.qtyPurchase << "\t" << sale.qtySold << "\t" << sale.qtyReturned << "\t" << sale.balanceQty << std::endl; } }

