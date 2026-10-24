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

bool validateClaimForm(const std::string& claimForm);
double calculateClaimAmount(const std::string& treatmentMatrix);
bool processClaim(const std::string& claimForm, const std::string& treatmentMatrix);

bool validateClaimForm(const std::string& claimForm) {
  // Define the MSI pattern
  const std::string msiPattern = "MSI Pattern";

  // Check if the claim form contains the MSI pattern
  if (claimForm.find(msiPattern) == std::string::npos) {
    return false;
  }

  // Define mandatory fields
  const std::vector<std::string> mandatoryFields = {"Patient Name", "Treatment Date", "Treatment Description"};

  // Check if all mandatory fields are present in the claim form
  for (const auto& field : mandatoryFields) {
    if (claimForm.find(field) == std::string::npos) {
      return false;
    }
  }

  // If all checks pass, the claim form is valid
  return true;
}

double calculateClaimAmount(const std::string& treatmentMatrix) {
  double totalAmount = 0.0;
  std::istringstream stream(treatmentMatrix);
  std::string line;

  while (std::getline(stream, line)) {
    std::istringstream lineStream(line);
    std::string treatmentName;
    double cost;

    if (lineStream >> treatmentName >> cost) {
      totalAmount += cost;
    }
  }

  return totalAmount;
}

bool processClaim(const std::string& claimForm, const std::string& treatmentMatrix) {
  if (!validateClaimForm(claimForm)) {
    return false;
  }

  double claimAmount = calculateClaimAmount(treatmentMatrix);

  // Assuming the claim is processed successfully
  return true;
}

