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

std::string getSalesmanDetails(const std::string& salesmanCode) {
   // Retrieve the salesman details from the database or any other data source.
   // For the purpose of this example, let's assume we have a vector of salesman objects.
   std::vector<Salesman> salesmen;
   // ...
   // Loop through the salesmen vector and find the salesman with the matching salesman code.
   for (const auto& salesman : salesmen) {
     if (salesman.salesmanCode == salesmanCode) {
       // Return the salesman details as a JSON string.
       return salesman.toJson();
     }
   }
   // Return an error message if the salesman code is not found.
   return "Salesman not found.";
}

void updateSalesmanDetails(const std::string& salesmanCode, const std::string& salesmanName, const std::string& dob, const std::string& age, const std::string& gender, const std::string& communicationAddress, const std::string& contactNo, const std::string& emailId, const std::string& salesTeamCode) {
   // Retrieve the salesman details from the database or any other data source.
   // For the purpose of this example, let's assume we have a vector of salesman objects.
   std::vector<Salesman> salesmen;
   // ...
   // Loop through the salesmen vector and find the salesman with the matching salesman code.
   for (const auto& salesman : salesmen) {
     if (salesman.salesmanCode == salesmanCode) {
       // Update the salesman details.
       salesman.salesmanName = salesmanName;
       salesman.dob = dob;
       salesman.age = age;
       salesman.gender = gender;
       salesman.communicationAddress = communicationAddress;
       salesman.contactNo = contactNo;
       salesman.emailId = emailId;
       salesman.salesTeamCode = salesTeamCode;
       // Return the updated salesman details as a JSON string.
       return salesman.toJson();
     }
   }
   // Return an error message if the salesman code is not found.
   return "Salesman not found.";
}

void deleteSalesmanDetails(const std::string& salesmanCode) {
    // Retrieve the salesman details from the database or any other data source.
    // For the purpose of this example, let's assume we have a vector of salesman objects.
    std::vector<Salesman> salesmen;
    // ...
    // Loop through the salesmen vector and find the salesman with the matching salesman code.
    for (const auto& salesman : salesmen) {
      if (salesman.salesmanCode == salesmanCode) {
        // Delete the salesman details.
        salesman.salesmanName = "";
        salesman.dob = "";
        salesman.age = "";
        salesman.gender = "";
        salesman.communicationAddress = "";
        salesman.contactNo = "";
        salesman.emailId = "";
        salesman.salesTeamCode = "";
        // Return the updated salesman details as a JSON string.
        return salesman.toJson();
     }
    }
    // Return an error message if the salesman code is not found.
    return "Salesman not found.";
}

Here is the corrected code:


struct SalesTeam {
    std::string salesTeamCode;
    // other fields...
};

struct Salesman {
    std::string salesmanCode;
    std::string salesmanName;
    std::string dob;
    std::string age;
    std::string gender;
    std::string communicationAddress;
    std::string contactNo;
    std::string emailId;
    SalesTeam salesTeamCode;
    // other fields...
};

std::vector<std::string> getSalesTeams() {
    // Retrieve the list of all sales teams from the database or any other data source.
    // For the purpose of this example, let's assume we have a vector of sales teams.
    std::vector<SalesTeam> salesTeams;
    // ...
    // Loop through the salesTeams vector and return the list of all sales team codes as a JSON string.
    std::string json = "[";
    for (const auto& salesTeam : salesTeams) {
      json += "" + salesTeam.salesTeamCode + ",";
    }
    json += "]";
    return json;
}

std::vector<Salesman> getAllSalesmen() {
    // Retrieve the list of all salesmen from the database or any other data source.
    // For the purpose of this example, let's assume we have a vector of salesmen.
    std::vector<Salesman> salesmen;
    // ...
    // Loop through the salesmen vector and return the list of all salesman codes as a JSON string.
    std::string json = "[";
    for (const auto& salesman : salesmen) {
      json += "" + salesman.salesmanCode + ",";
    }
    json += "]";
    return json;
}

