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

bool validateFormSubmission(const std::string& formNo, const std::string& noOfAvailableForms, const std::string& noOfClaimsMentioned);
std::string generateReceipt(const std::string& vspName, const std::string& dateOfSubmission, const std::string& noOfClaimsMentioned, const std::string& noOfClaimsAvailable);
void printReport(const std::string& vspName, const std::string& dateOfSubmission, const std::string& noOfClaimsMentioned, const std::string& noOfClaimsAvailable);

bool validateFormSubmission(const std::string& formNo, const std::string& noOfAvailableForms, const std::string& noOfClaimsMentioned) {
  try {
    int forms = std::stoi(formNo);
    int availableForms = std::stoi(noOfAvailableForms);
    int mentionedClaims = std::stoi(noOfClaimsMentioned);

    if (availableForms >= mentionedClaims) {
      return true;
    } else {
      return false;
    }
  } catch (const std::invalid_argument& e) {
    // Handle invalid argument exception
    return false;
  }
}

bool validateFormSubmission(const std::string& formNo, const std::string& noOfAvailableForms, const std::string& noOfClaimsMentioned) {
   try {
     int forms = std::stoi(formNo);
     int availableForms = std::stoi(noOfAvailableForms);
     int mentionedClaims = std::stoi(noOfClaimsMentioned);

     if (availableForms >= mentionedClaims) {
       return true;
     } else {
       return false;
     }
   } catch (const std::invalid_argument& e) {
     // Handle invalid argument exception
     return false;
   }
}

bool validateFormSubmission(const std::string& formNo, const std::string& noOfAvailableForms, const std::string& noOfClaimsMentioned) {
   try {
     int forms = std::stoi(formNo);
     int availableForms = std::stoi(noOfAvailableForms);
     int mentionedClaims = std::stoi(noOfClaimsMentioned);

     if (availableForms >= mentionedClaims) {
       return true;
     } else {
       return false;
     }
   } catch (const std::invalid_argument& e) {
     // Handle invalid argument exception
     return false;
   }
}

void printReport(const std::string& vspName, const std::string& dateOfSubmission, const std::string& noOfClaimsMentioned, const std::string& noOfClaimsAvailable) {
   // Print the report with the receipt details.
}

