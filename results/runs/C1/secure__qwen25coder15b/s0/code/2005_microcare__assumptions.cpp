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

bool validateClaimForm(const std::string& patientName, const std::string& treatmentMatrix, const std::string& voucherSlip);
std::string getThumpImpression(const std::string& patientName);
void stickVoucherSlip(const std::string& voucherSlip, const std::string& claimForm);
double calculateClaimAmount(const std::string& treatmentMatrix, const std::string& voucherSlip);

bool validateClaimForm(const std::string& patientName, const std::string& treatmentMatrix, const std::string& voucherSlip) {
  // Check if all mandatory information is present
  if (patientName.empty() || treatmentMatrix.empty() || voucherSlip.empty()) {
    return false;
  }
  // Additional checks can be added here
  return true;
}

std::string getThumpImpression(const std::string& patientName) {
  // Get the thump impression from the patient
  return patientName + ' signed the claim';
}

void stickVoucherSlip(const std::string& voucherSlip, const std::string& claimForm) {
  std::string mutableClaimForm = claimForm;
  mutableClaimForm += voucherSlip;
}

double calculateClaimAmount(const std::string& treatmentMatrix, const std::string& voucherSlip) {
  // Split the treatment matrix into rows and columns
  std::istringstream iss(treatmentMatrix);
  std::vector<std::vector<std::string>> matrix;
  std::string row;
  while (std::getline(iss, row)) {
    std::vector<std::string> rowVec;
    std::istringstream issRow(row);
    std::string cell;
    while (std::getline(issRow, cell, ',')) {
      rowVec.push_back(cell);
    }
    matrix.push_back(rowVec);
  }

  // Split the voucher slip into treatment and amount
  std::istringstream issVoucher(voucherSlip);
  std::string treatment, amount;
  std::getline(issVoucher, treatment, ':');
  std::getline(issVoucher, amount);

  // Find the cost associated with the treatment
  double cost = 0.0;
  for (const auto& row : matrix) {
    if (row[0] == treatment) {
      cost = std::stod(row[1]);
      break;
    }
  }

  // Return the total claim amount
  return cost;
}

