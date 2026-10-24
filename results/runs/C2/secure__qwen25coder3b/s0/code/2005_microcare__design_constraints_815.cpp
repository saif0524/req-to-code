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

bool validateClaimInput(const std::string& vspName, const std::string& dateOfSubmission, const std::vector<int>& mentionedForms, const std::vector<int>& availableForms, const std::vector<int>& noOfClaims);
void generateReceipt(const std::string& vspName, const std::string& dateOfSubmission, const std::vector<int>& mentionedForms, const std::vector<int>& availableForms, const std::vector<int>& noOfClaims);
std::string getVspName();
std::string getCurrentDate();
bool validateNoOfClaims(const std::vector<int>& mentionedForms, const std::vector<int>& availableForms, const std::vector<int>& noOfClaims);

bool validateClaimInput(const std::string& vspName, const std::string& dateOfSubmission, const std::vector<int>& mentionedForms, const std::vector<int>& availableForms, const std::vector<int>& noOfClaims) {
  if (vspName.empty()) {
    return false;
  }

  if (dateOfSubmission != getCurrentDate()) {
    return false;
  }

  for (int form : mentionedForms) {
    if (form < 0 || form >= availableForms.size()) {
      return false;
    }
  }

  if (!validateNoOfClaims(mentionedForms, availableForms, noOfClaims)) {
    return false;
  }

  return true;
}

void generateReceipt(const std::string& vspName, const std::string& dateOfSubmission, const std::vector<int>& mentionedForms, const std::vector<int>& availableForms, const std::vector<int>& noOfClaims) {
  if (!validateClaimInput(vspName, dateOfSubmission, mentionedForms, availableForms, noOfClaims)) {
    return;
  }

  std::string receipt = "Receipt\n\nVSP Name: " + vspName + "\nDate of Submission: " + dateOfSubmission + "\nNo of claims mentioned: " + std::to_string(mentionedForms.size()) + "\nNo of claims Available: " + std::to_string(availableForms.size()) + "\n\nTreatment Form No: " + std::to_string(mentionedForms[0]);

  // Additional treatment forms can be added here if needed.

  std::cout << receipt << std::endl;
}

std::string getVspName() { return "VSP Name from VSP Master"; }

std::string getCurrentDate() { return std::format("%Y-%m-%d %H:%M:%S", std::chrono::system_clock::now()); }

bool validateNoOfClaims(const std::vector<int>& mentionedForms, const std::vector<int>& availableForms, const std::vector<int>& noOfClaims) {
  if (mentionedForms.size() != noOfClaims.size()) {
    return false;
  }

  for (size_t i = 0; i < mentionedForms.size(); ++i) {
    if (mentionedForms[i] != availableForms[i]) {
      return false;
    }
  }

  return true;
}

