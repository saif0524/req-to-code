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

struct Distributor {
   int id;
   std::string details;
   enum Status {
       ACTIVE,
       DEACTIVE
   }
};

Distributor parseDistributorDetails(std::string distributorDetails) {
   // TODO: Implement this function to parse the distributor details from the input string.
}

std::string getDistributorDetails(int distributorId);
bool updateDistributorDetails(int distributorId, std::string updatedDetails);
bool deleteDistributor(int distributorId);
bool addNewDistributor(std::string distributorDetails);
std::vector<std::string> getDistributorList();

std::string getDistributorDetails(int distributorId) {
   for (int i = 0; i < distributors.size(); i++) {
     if (distributors[i].id == distributorId) {
       return distributors[i].details;
     }
   }
   return "Distributor not found.";
}

bool updateDistributorDetails(int distributorId, std::string updatedDetails) {
    std::vector<Distributor> updatedDistributors = distributors;
    for (int i = 0; i < updatedDistributors.size(); i++) {
      if (updatedDistributors[i].id == distributorId) {
        updatedDistributors[i].details = updatedDetails;
        break;
     }
    }
    distributors = updatedDistributors;
    return true;
}

bool deleteDistributor(int distributorId) {
   std::vector<Distributor> updatedDistributors = distributors;
   for (int i = 0; i < updatedDistributors.size(); i++) {
     if (updatedDistributors[i].id == distributorId) {
       updatedDistributors.erase(updatedDistributors.begin() + i);
       break;
     }
   }
   distributors = updatedDistributors;
   return true;
}

bool addNewDistributor(std::string distributorDetails) {
   Distributor newDistributor = parseDistributorDetails(distributorDetails);
   distributors.push_back(newDistributor);
   return true;
}

std::vector<std::string> getDistributorList() {
   std::vector<std::string> distributorList;
   for (int i = 0; i < distributors.size(); i++) {
     distributorList.push_back(distributors[i].details);
   }
   return distributorList;
}

