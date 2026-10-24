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

bool validateSalesmanData(const std::string& salesmanCode, const std::string& name, const std::string& dob, const std::string& age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& email, const std::string& salesTeam);
void captureSalesmanDetails(Salesman& salesman);
void displaySalesmanDetails(const Salesman& salesman);
void updateSalesmanDetails(Salesman& salesman);
void deleteSalesmanDetails(const std::string& salesmanCode);

bool validateSalesmanData(const std::string& salesmanCode, const std::string& name, const std::string& dob, const std::string& age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& email, const std::string& salesTeam) {
  if (salesmanCode.empty() || name.empty() || dob.empty() || age.empty() || gender.empty() || address.empty() || contactNo.empty() || email.empty() || salesTeam.empty()) {
    return false;
  }

  // Check if age is a valid number
  if (!std::isdigit(age[0])) {
    return false;
  }

  // Check if contactNo is a valid number
  if (!std::isdigit(contactNo[0])) {
    return false;
  }

  // Check if email is a valid format
  if (email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
    return false;
  }

  return true;
}

void captureSalesmanDetails(Salesman& salesman) { Salesman tempSalesman; std::string salesmanCode, name, dob, age, gender, address, contactNo, email, salesTeam; std::cout << "Salesman Code: " << std::endl; std::cin >> salesmanCode; std::cout << "Name: " << std::endl; std::cin >> name; std::cout << "DOB: " << std::endl; std::cin >> dob; std::cout << "Age: " << std::endl; std::cin >> age; std::cout << "Gender: " << std::endl; std::cin >> gender; std::cout << "Address: " << std::endl; std::cin >> address; std::cout << "Contact No: " << std::endl; std::cin >> contactNo; std::cout << "Email: " << std::endl; std::cin >> email; std::cout << "Sales Team: " << std::endl; std::cin >> salesTeam; if (!validateSalesmanData(salesmanCode, name, dob, age, gender, address, contactNo, email, salesTeam)) { std::cout << "Invalid input. Please try again." << std::endl; return; } tempSalesman.salesmanCode = salesmanCode; tempSalesman.name = name; tempSalesman.dob = dob; tempSalesman.age = age; tempSalesman.gender = gender; tempSalesman.address = address; tempSalesman.contactNo = contactNo; tempSalesman.email = email; tempSalesman.salesTeam = salesTeam; salesman = tempSalesman; displaySalesmanDetails(salesman); }

struct Salesman { std::string salesmanCode; std::string name; std::string dob; std::string age; std::string gender; std::string address; std::string contactNo; std::string email; std::string salesTeam; }; void displaySalesmanDetails(const Salesman& salesman) { std::cout << "Salesman Code: " << salesman.salesmanCode << std::endl; std::cout << "Name: " << salesman.name << std::endl; std::cout << "DOB: " << salesman.dob << std::endl; std::cout << "Age: " << salesman.age << std::endl; std::cout << "Gender: " << salesman.gender << std::endl; std::cout << "Address: " << salesman.address << std::endl; std::cout << "Contact No: " << salesman.contactNo << std::endl; std::cout << "Email: " << salesman.email << std::endl; std::cout << "Sales Team: " << salesman.salesTeam << std::endl; }

void updateSalesmanDetails(Salesman& salesman) { std::string salesmanCode, name, dob, age, gender, address, contactNo, email, salesTeam; std::cout << "Salesman Code: " << std::endl; std::cin >> salesmanCode; std::cout << "Name: " << std::endl; std::cin >> name; std::cout << "DOB: " << std::endl; std::cin >> dob; std::cout << "Age: " << std::endl; std::cin >> age; std::cout << "Gender: " << std::endl; std::cin >> gender; std::cout << "Address: " << std::endl; std::cin >> address; std::cout << "Contact No: " << std::endl; std::cin >> contactNo; std::cout << "Email: " << std::endl; std::cin >> email; std::cout << "Sales Team: " << std::endl; std::cin >> salesTeam; if (!validateSalesmanData(salesmanCode, name, dob, age, gender, address, contactNo, email, salesTeam)) { std::cout << "Invalid input. Please try again." << std::endl; return; } salesman.salesmanCode = salesmanCode; salesman.name = name; salesman.dob = dob; salesman.age = age; salesman.gender = gender; salesman.address = address; salesman.contactNo = contactNo; salesman.email = email; salesman.salesTeam = salesTeam; displaySalesmanDetails(salesman); }

void deleteSalesmanDetails(const std::string& salesmanCode) {
  std::vector<Salesman> salesmen;
  // Assume salesmen is a global vector containing all salesman details

  for (auto it = salesmen.begin(); it != salesmen.end(); ++it) {
    if (it->salesmanCode == salesmanCode) {
      salesmen.erase(it);
      std::cout << "Salesman deleted successfully." << std::endl;
      return;
    }
  }

  std::cout << "Salesman not found." << std::endl;
}

