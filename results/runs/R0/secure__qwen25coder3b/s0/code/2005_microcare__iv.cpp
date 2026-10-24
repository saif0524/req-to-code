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

bool validateClaimForm(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, std::string& claimStatus);
void captureClaimDetails(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, std::string& claimStatus);
void processClaim(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, std::string& claimStatus);
void sendClaimBackToVSP(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, std::string& claimStatus);
void logClaimDetails(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, const std::string& claimStatus);

bool validateClaimForm(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, std::string& claimStatus) {
  claimStatus = 'Valid';

  if (treatmentFormNo.empty() || claimNo.empty() || submittedDate.empty() || vspName.empty() || voucherNo.empty() || patientType.empty() || patientName.empty() || gender.empty() || address.empty() || contactNo.empty() || doctorName.empty() || doctorsNote.empty() || hivDetails.empty() || patientStatus.empty() || claimAmount <= 0) {
    claimStatus = 'Rejected';
    return false;
  }

  return true;
}

void captureClaimDetails(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, std::string& claimStatus) {
  claimStatus = 'Valid';

  if (!validateClaimForm(treatmentFormNo, claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount, claimStatus)) {
    claimStatus = 'Rejected';
    return;
  }

  // Capture claim details
  // Example: Store in a map or struct
  // claimDetailsMap[treatmentFormNo] = {claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount};

  // Log claim details
  logClaimDetails(treatmentFormNo, claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount, claimStatus);
}

void processClaim(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, std::string& claimStatus) {
  claimStatus = 'Valid';

  if (!validateClaimForm(treatmentFormNo, claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount, claimStatus)) {
    claimStatus = 'Rejected';
    return;
  }

  // Capture claim details
  // Example: Store in a map or struct
  // claimDetailsMap[treatmentFormNo] = {claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount};

  // Log claim details
  logClaimDetails(treatmentFormNo, claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount, claimStatus);
}

void sendClaimBackToVSP(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, std::string& claimStatus) {
  claimStatus = 'Valid';

  if (!validateClaimForm(treatmentFormNo, claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount, claimStatus)) {
    claimStatus = 'Rejected';
    // Send claim back to VSP
    // Example: Use a messaging system or API to send the claim back
    // SendClaimBackToVSP(treatmentFormNo, claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount);
    return;
  }

  // Capture claim details
  // Example: Store in a map or struct
  // claimDetailsMap[treatmentFormNo] = {claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount};

  // Log claim details
  logClaimDetails(treatmentFormNo, claimNo, submittedDate, vspName, voucherNo, visitCount, patientType, patientName, age, gender, address, contactNo, doctorName, doctorsNote, hivDetails, patientStatus, claimAmount, claimStatus);
}

void logClaimDetails(const std::string& treatmentFormNo, const std::string& claimNo, const std::string& submittedDate, const std::string& vspName, const std::string& voucherNo, int visitCount, const std::string& patientType, const std::string& patientName, int age, const std::string& gender, const std::string& address, const std::string& contactNo, const std::string& doctorName, const std::string& doctorsNote, const std::string& hivDetails, const std::string& patientStatus, double claimAmount, const std::string& claimStatus) {
  // Example: Use a simple file-based logging mechanism
  std::ofstream logFile("claim_log.txt", std::ios::app);
  if (logFile.is_open()) {
    logFile << "Treatment Form No: " << treatmentFormNo << ", Claim No: " << claimNo << ", Submitted Date: " << submittedDate << ", VSP Name: " << vspName << ", Voucher No: " << voucherNo << ", Visit Count: " << visitCount << ", Patient Type: " << patientType << ", Patient Name: " << patientName << ", Age: " << age << ", Gender: " << gender << ", Address: " << address << ", Contact No: " << contactNo << ", Doctor Name: " << doctorName << ", Doctors Note: " << doctorsNote << ", HIV Details: " << hivDetails << ", Patient Status: " << patientStatus << ", Claim Amount: " << claimAmount << ", Claim Status: " << claimStatus << "\n";
    logFile.close();
  } else {
    // Handle error if log file cannot be opened
    std::cerr << "Error: Unable to open log file" << std::endl;
  }
}

