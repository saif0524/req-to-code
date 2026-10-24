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

bool validateDistributorName(const std::string& name);
std::string generateDistributorID();
void printDistributorDetails(const Distributor& distributor);
void viewSalesHistory(const Distributor& distributor);
void updateDistributor(Distributor& distributor);

bool validateDistributorName(const std::string& name) {
  static std::vector<std::string> distributorNames;
  for (const auto& existingName : distributorNames) {
    if (existingName == name) {
      return false;
    }
  }
  distributorNames.push_back(name);
  return true;
}

std::string generateDistributorID() {
  static std::vector<std::string> distributorIDs;
  static int counter = 0;
  std::string baseID = "Distributor_";
  std::string id = baseID + std::to_string(counter);
  distributorIDs.push_back(id);
  counter++;
  return id;
}

struct Distributor {
  std::string name;
  std::string address;
  std::string id;
  bool active;
};

void printDistributorDetails(const Distributor& distributor) {
  std::cout << "Distributor Name: " << distributor.name << std::endl;
  std::cout << "Address: " << distributor.address << std::endl;
  std::cout << "ID: " << distributor.id << std::endl;
  std::cout << "Active: " << (distributor.active ? "Yes" : "No") << std::endl;
}

void viewSalesHistory(const Distributor& distributor) {
  std::cout << "Distributor Name: " << distributor.name << std::endl;
  std::cout << "Sales History: " << std::endl;
  for (const auto& sale : distributor.salesHistory) {
    std::cout << "Batch No: " << sale.batchNo << std::endl;
    std::cout << "Date: " << sale.date << std::endl;
    std::cout << "Qty: " << sale.qty << std::endl;
    std::cout << "Purchase Qty: " << sale.purchaseQty << std::endl;
    std::cout << "Sold Qty: " << sale.soldQty << std::endl;
    std::cout << "Returned Qty: " << sale.returnedQty << std::endl;
    std::cout << "Balance Qty: " << sale.balanceQty << std::endl;
    std::cout << "-------------------------" << std::endl;
  }
}

bool updateDistributor(Distributor& distributor) {
  if (!validateDistributorName(distributor.name)) {
    std::cout << "Error: Duplicate distributor name" << std::endl;
    return false;
  }

  if (distributor.address.empty()) {
    std::cout << "Error: Address field cannot be empty" << std::endl;
    return false;
  }

  distributor.active = true; // Assuming active status is always true for update

  std::cout << "Distributor updated successfully" << std::endl;
  return true;
}

