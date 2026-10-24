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

void captureSalesmanDetails(Salesman& salesman);
void displaySalesmanMaster(const std::vector<Salesman>& salesmen);
Salesman selectSalesmanFromMaster(const std::vector<Salesman>& salesmen, const std::string& salesmanName);
void updateSalesmanMaster(Salesman& salesman);
void initializeSalesmanMaster(std::vector<Salesman>& salesmen);

void captureSalesmanDetails(Salesman& salesman) {
  std::cout << "Enter Salesman Code: " << std::endl;
  std::cin >> salesman.salesmanCode;
  std::cout << "Enter Salesman Name: " << std::endl;
  std::cin >> salesman.name;
  std::cout << "Enter Salesman DOB: " << std::endl;
  std::cin >> salesman.dob;
  std::cout << "Enter Salesman Age: " << std::endl;
  std::cin >> salesman.age;
  std::cout << "Enter Salesman Gender: " << std::endl;
  std::cin >> salesman.gender;
  std::cout << "Enter Salesman Communication Address: " << std::endl;
  std::cin >> salesman.communicationAddress;
  std::cout << "Enter Salesman Contact No: " << std::endl;
  std::cin >> salesman.contactNo;
  std::cout << "Enter Salesman E-Mail Id: " << std::endl;
  std::cin >> salesman.emailId;
  std::cout << "Enter Salesman Team: " << std::endl;
  std::cin >> salesman.salesTeam;
}

void displaySalesmanMaster(const std::vector<Salesman>& salesmen) {
  for (const auto& salesman : salesmen) {
    std::cout << "Salesman Code: " << salesman.salesmanCode << std::endl;
    std::cout << "Salesman Name: " << salesman.name << std::endl;
    std::cout << "Salesman DOB: " << salesman.dob << std::endl;
    std::cout << "Salesman Age: " << salesman.age << std::endl;
    std::cout << "Salesman Gender: " << salesman.gender << std::endl;
    std::cout << "Salesman Communication Address: " << salesman.communicationAddress << std::endl;
    std::cout << "Salesman Contact No: " << salesman.contactNo << std::endl;
    std::cout << "Salesman E-Mail Id: " << salesman.emailId << std::endl;
    std::cout << "Salesman Team: " << salesman.salesTeam << std::endl;
    std::cout << "-----------------------------" << std::endl;
  }
}

Salesman selectSalesmanFromMaster(const std::vector<Salesman>& salesmen, const std::string& salesmanName) {
  for (const auto& salesman : salesmen) {
    if (salesman.name == salesmanName) {
      return salesman;
    }
  }
  Salesman defaultSalesman;
  return defaultSalesman;
}

void updateSalesmanMaster(Salesman& salesman) {
  for (auto& s : salesmen) {
    if (s.name == salesman.name) {
      s.salesmanCode = salesman.salesmanCode;
      s.name = salesman.name;
      s.dob = salesman.dob;
      s.age = salesman.age;
      s.gender = salesman.gender;
      s.communicationAddress = salesman.communicationAddress;
      s.contactNo = salesman.contactNo;
      s.emailId = salesman.emailId;
      s.salesTeam = salesman.salesTeam;
      break;
    }
  }
}

void initializeSalesmanMaster(std::vector<Salesman>& salesmen) {
  for (auto& s : salesmen) {
    s.salesmanCode = "";
    s.name = "";
    s.dob = "";
    s.age = 0;
    s.gender = "";
    s.communicationAddress = "";
    s.contactNo = "";
    s.emailId = "";
    s.salesTeam = "";
  }
}

