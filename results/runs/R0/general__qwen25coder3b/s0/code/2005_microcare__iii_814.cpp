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

void submitClaim(const std::string& vspName, const std::string& dateOfSubmission, int noOfMentionedForms, int noOfAvailableForms, const std::vector<std::string>& treatmentForms);
void captureDetails(const std::string& vspName, const std::string& dateOfSubmission, int& noOfMentionedForms, int& noOfAvailableForms, std::vector<std::string>& treatmentForms);
bool validateDetails(const std::string& vspName, const std::string& dateOfSubmission, int noOfMentionedForms, int noOfAvailableForms, const std::vector<std::string>& treatmentForms);
void processClaim(const std::string& vspName, const std::string& dateOfSubmission, int noOfMentionedForms, int noOfAvailableForms, const std::vector<std::string>& treatmentForms);
void submitToMISU(const std::string& vspName, const std::string& dateOfSubmission, int noOfMentionedForms, int noOfAvailableForms, const std::vector<std::string>& treatmentForms);

void submitClaim(const std::string& vspName, const std::string& dateOfSubmission, int noOfMentionedForms, int noOfAvailableForms, const std::vector<std::string>& treatmentForms) { // Submit the Claim (Treatment Form) to the MISU Field office with the specified details. }

void captureDetails(const std::string& vspName, const std::string& dateOfSubmission, int& noOfMentionedForms, int& noOfAvailableForms, std::vector<std::string>& treatmentForms) {
  std::cout << "Enter the number of mentioned forms: " << std::endl;
  std::cin >> noOfMentionedForms;
  std::cout << "Enter the number of available forms: " << std::endl;
  std::cin >> noOfAvailableForms;
  std::cout << "Enter the treatment forms (separated by spaces): " << std::endl;
  std::string input;
  std::getline(std::cin, input);
  std::istringstream iss(input);
  std::string treatmentForm;
  while (iss >> treatmentForm) {
    treatmentForms.push_back(treatmentForm);
  }
}

bool validateDetails(const std::string& vspName, const std::string& dateOfSubmission, int noOfMentionedForms, int noOfAvailableForms, const std::vector<std::string>& treatmentForms) {
  if (noOfMentionedForms > noOfAvailableForms) {
    return false;
  }
  if (treatmentForms.empty()) {
    return false;
  }
  return true;
}

void processClaim(const std::string& vspName, const std::string& dateOfSubmission, int noOfMentionedForms, int noOfAvailableForms, const std::vector<std::string>& treatmentForms) {
  if (validateDetails(vspName, dateOfSubmission, noOfMentionedForms, noOfAvailableForms, treatmentForms)) {
    submitToMISU(vspName, dateOfSubmission, noOfMentionedForms, noOfAvailableForms, treatmentForms);
  } else {
    std::cout << "Invalid details. Claim not processed." << std::endl;
  }
}

void submitToMISU(const std::string& vspName, const std::string& dateOfSubmission, int noOfMentionedForms, int noOfAvailableForms, const std::vector<std::string>& treatmentForms) {
  std::cout << "Submitting Claim (Treatment Form) to MISU Field office for VSP: " << vspName << std::endl;
  std::cout << "Date of Submission: " << dateOfSubmission << std::endl;
  std::cout << "Number of Mentioned Forms: " << noOfMentionedForms << std::endl;
  std::cout << "Number of Available Forms: " << noOfAvailableForms << std::endl;
  std::cout << "Treatment Forms: " << std::endl;
  for (const auto& form : treatmentForms) {
    std::cout << "- " << form << std::endl;
  }
  std::cout << std::endl;
}

