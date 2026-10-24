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

Distributor createDistributor(const std::string& distributorCode, const std::string& name, const std::string& typeOfBusiness, const std::string& proprietorName, const std::string& designation, const std::string& address, const std::string& contactNo, const std::string& emailId, const std::string& status);
void updateDistributor(Distributor& distributor, const std::string& distributorCode, const std::string& name, const std::string& typeOfBusiness, const std::string& proprietorName, const std::string& designation, const std::string& address, const std::string& contactNo, const std::string& emailId, const std::string& status);
Distributor getDistributor(const std::string& distributorCode);
std::vector<Distributor> listDistributors();
void deleteDistributor(const std::string& distributorCode);

struct Distributor {
  std::string distributorCode;
  std::string name;
  std::string typeOfBusiness;
  std::string proprietorName;
  std::string designation;
  std::string address;
  std::string contactNo;
  std::string emailId;
  std::string status;
};

Distributor createDistributor(const std::string& distributorCode, const std::string& name, const std::string& typeOfBusiness, const std::string& proprietorName, const std::string& designation, const std::string& address, const std::string& contactNo, const std::string& emailId, const std::string& status) {
  Distributor distributor;
  distributor.distributorCode = distributorCode;
  distributor.name = name;
  distributor.typeOfBusiness = typeOfBusiness;
  distributor.proprietorName = proprietorName;
  distributor.designation = designation;
  distributor.address = address;
  distributor.contactNo = contactNo;
  distributor.emailId = emailId;
  distributor.status = status;
  return distributor;
}

Distributor updateDistributor(Distributor& distributor, const std::string& distributorCode, const std::string& name, const std::string& typeOfBusiness, const std::string& proprietorName, const std::string& designation, const std::string& address, const std::string& contactNo, const std::string& emailId, const std::string& status) {
  if (!name.empty()) distributor.name = name;
  if (!typeOfBusiness.empty()) distributor.typeOfBusiness = typeOfBusiness;
  if (!proprietorName.empty()) distributor.proprietorName = proprietorName;
  if (!designation.empty()) distributor.designation = designation;
  if (!address.empty()) distributor.address = address;
  if (!contactNo.empty()) distributor.contactNo = contactNo;
  if (!emailId.empty()) distributor.emailId = emailId;
  if (!status.empty()) distributor.status = status;
  return distributor;
}

Distributor getDistributor(const std::string& distributorCode) { struct Distributor; for (const auto& distributor : distributors) { if (distributor.distributorCode == distributorCode) { return distributor; } } return Distributor(); }

std::vector<Distributor> listDistributors() { std::vector<Distributor> result; for (const auto& distributor : distributors) { if (distributor.distributorCode == distributorCode) { result.push_back(distributor); } } return result; }

void deleteDistributor(const std::string& distributorCode) { std::vector<Distributor> distributors; for (auto it = distributors.begin(); it != distributors.end(); ++it) { if (it->distributorCode == distributorCode) { distributors.erase(it); return; } } // Return a success message or status }

