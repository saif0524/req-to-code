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

void captureSalesmanDetails(const std::string& salesmanCode, const std::string& salesmanName, const std::string& dob, const std::string& age, const std::string& gender, const std::string& communicationAddress, const std::string& contactNo, const std::string& emailId, const std::string& salesTeamCode);
std::string getSalesmanDetails(const std::string& salesmanCode);
void updateSalesmanDetails(const std::string& salesmanCode, const std::string& salesmanName, const std::string& dob, const std::string& age, const std::string& gender, const std::string& communicationAddress, const std::string& contactNo, const std::string& emailId, const std::string& salesTeamCode);
void deleteSalesmanDetails(const std::string& salesmanCode);
std::vector<std::string> getSalesTeams();

void captureSalesmanDetails(const std::string& salesmanCode, const std::string& salesmanName, const std::string& dob, const std::string& age, const std::string& gender, const std::string& communicationAddress, const std::string& contactNo, const std::string& emailId, const std::string& salesTeamCode) {
   // Validate the salesman code
   if (salesmanCode.empty()) {
     throw std::invalid_argument("Salesman code cannot be empty.");
   }

   // Retrieve the salesman details
   Salesman salesman = salesmanMaster.find(salesmanCode);

   // Update the salesman details
   salesman.salesmanName = salesmanName;
   salesman.dob = dob;
   salesman.age = age;
   salesman.gender = gender;
   salesman.communicationAddress = communicationAddress;
   salesman.contactNo = contactNo;
   salesman.emailId = emailId;
   salesman.salesTeamCode = salesTeamCode;

   // Convert the updated salesman details to JSON format
   nlohmann::json jsonSalesman;
   jsonSalesman["salesmanCode"] = salesman.salesmanCode;
   jsonSalesman["salesmanName"] = salesman.salesmanName;
   jsonSalesman["dob"] = salesman.dob;
   jsonSalesman["age"] = salesman.age;
   jsonSalesman["gender"] = salesman.gender;
   jsonSalesman["communicationAddress"] = salesman.communicationAddress;
   jsonSalesman["contactNo"] = salesman.contactNo;
   jsonSalesman["emailId"] = salesman.emailId;
   jsonSalesman["salesTeamCode"] = salesman.salesTeamCode;

   return jsonSalesman.dump();
}

std::string getSalesmanDetails(const std::string& salesmanCode) {
   // Validate the salesman code
   if (salesmanCode.empty()) {
     throw std::invalid_argument("Salesman code cannot be empty.");
   }

   // Retrieve the salesman details
   Salesman salesman = salesmanMaster.find(salesmanCode);

   // Convert the salesman details to JSON format
   nlohmann::json jsonSalesman;
   jsonSalesman["salesmanCode"] = salesman.salesmanCode;
   jsonSalesman["salesmanName"] = salesman.salesmanName;
   jsonSalesman["dob"] = salesman.dob;
   jsonSalesman["age"] = salesman.age;
   jsonSalesman["gender"] = salesman.gender;
   jsonSalesman["communicationAddress"] = salesman.communicationAddress;
   jsonSalesman["contactNo"] = salesman.contactNo;
   jsonSalesman["emailId"] = salesman.emailId;
   jsonSalesman["salesTeamCode"] = salesman.salesTeamCode;

   return jsonSalesman.dump();
}

void updateSalesmanDetails(const std::string& salesmanCode, const std::string& salesmanName, const std::string& dob, const std::string& age, const std::string& gender, const std::string& communicationAddress, const std::string& contactNo, const std::string& emailId, const std::string& salesTeamCode) {
   // Validate the salesman code
   if (salesmanCode.empty()) {
     throw std::invalid_argument("Salesman code cannot be empty.");
   }

   // Retrieve the salesman details
   Salesman salesman = salesmanMaster.find(salesmanCode);

   // Update the salesman details
   salesman.salesmanName = salesmanName;
   salesman.dob = dob;
   salesman.age = age;
   salesman.gender = gender;
   salesman.communicationAddress = communicationAddress;
   salesman.contactNo = contactNo;
   salesman.emailId = emailId;
   salesman.salesTeamCode = salesTeamCode;

   // Convert the updated salesman details to JSON format
   nlohmann::json jsonSalesman;
   jsonSalesman["salesmanCode"] = salesman.salesmanCode;
   jsonSalesman["salesmanName"] = salesman.salesmanName;
   jsonSalesman["dob"] = salesman.dob;
   jsonSalesman["age"] = salesman.age;
   jsonSalesman["gender"] = salesman.gender;
   jsonSalesman["communicationAddress"] = salesman.communicationAddress;
   jsonSalesman["contactNo"] = salesman.contactNo;
   jsonSalesman["emailId"] = salesman.emailId;
   jsonSalesman["salesTeamCode"] = salesman.salesTeamCode;

   return jsonSalesman.dump();
}

void deleteSalesmanDetails(const std::string& salesmanCode) {
    // Validate the salesman code
    if (salesmanCode.empty()) {
     throw std::invalid_argument("Salesman code cannot be empty.");
    }

    // Retrieve the salesman details
    auto salesman = salesmanMaster.find(salesmanCode);

    // Delete the salesman details
    salesmanMaster.erase(salesman);

    // Convert the updated salesman details to JSON format
    nlohmann::json jsonSalesman;
    jsonSalesman["salesmanCode"] = salesman.salesmanCode;
    jsonSalesman["salesmanName"] = salesman.salesmanName;
    jsonSalesman["dob"] = salesman.dob;
    jsonSalesman["age"] = salesman.age;
    jsonSalesman["gender"] = salesman.gender;
    jsonSalesman["communicationAddress"] = salesman.communicationAddress;
    jsonSalesman["contactNo"] = salesman.contactNo;
    jsonSalesman["emailId"] = salesman.emailId;
    jsonSalesman["salesTeamCode"] = salesman.salesTeamCode;

    return jsonSalesman.dump();
}

std::vector<std::string> getSalesTeams() {
     std::vector<std::string> salesTeams;
     for (const auto& [salesmanCode, salesman] : salesmanMaster) {
         salesTeams.push_back(salesman.salesTeamCode);
     }
     return salesTeams;
}

std::vector<std::string> getSalesTeams() {
     std::vector<std::string> salesTeams;
     for (const auto& [salesmanCode, salesman] : salesmanMaster) {
         salesTeams.push_back(salesman.salesTeamCode);
     }
     return salesTeams;
}

