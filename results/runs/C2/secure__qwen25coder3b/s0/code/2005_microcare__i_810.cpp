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

bool validateVSPMasterInfo(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrict, const std::string& localityLevel, const std::string& facilityType, const std::string& registrationBody, const std::string& contactPerson, const std::string& designation, const std::string& contactNo, const std::string& emailId, const std::string& status);
bool createVSPMaster(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrict, const std::string& localityLevel, const std::string& facilityType, const std::string& registrationBody, const std::string& contactPerson, const std::string& designation, const std::string& contactNo, const std::string& emailId, const std::string& status);
bool updateVSPMaster(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrict, const std::string& localityLevel, const std::string& facilityType, const std::string& registrationBody, const std::string& contactPerson, const std::string& designation, const std::string& contactNo, const std::string& emailId, const std::string& status);
bool deleteVSPMaster(const std::string& vspCode);
std::optional<VSPMaster> getVSPMaster(const std::string& vspCode);

bool validateVSPMasterInfo(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrict, const std::string& localityLevel, const std::string& facilityType, const std::string& registrationBody, const std::string& contactPerson, const std::string& designation, const std::string& contactNo, const std::string& emailId, const std::string& status) {
  std::optional<std::string> reason;

  // Check VSP Code
  if (vspCode.empty() || vspCode.length() > 10) {
    reason = "VSP Code must be between 1 and 10 characters long."
  }

  // Check Providers Name
  if (providersName.empty() || providersName.length() > 50) {
    reason = "Providers Name must be between 1 and 50 characters long."
  }

  // Check Physical Address
  if (physicalAddress.empty() || physicalAddress.length() > 100) {
    reason = "Physical Address must be between 1 and 100 characters long."
  }

  // Check Communication Address
  if (communicationAddress.empty() || communicationAddress.length() > 100) {
    reason = "Communication Address must be between 1 and 100 characters long."
  }

  // Check Health Sub-District
  if (healthSubDistrict.empty() || healthSubDistrict.length() > 50) {
    reason = "Health Sub-District must be between 1 and 50 characters long."
  }

  // Check Locality Level
  if (localityLevel.empty() || localityLevel.length() > 50) {
    reason = "Locality Level must be between 1 and 50 characters long."
  }

  // Check Facility Type
  if (facilityType.empty() || facilityType.length() > 50) {
    reason = "Facility Type must be between 1 and 50 characters long."
  }

  // Check Registration Body
  if (registrationBody.empty() || registrationBody.length() > 50) {
    reason = "Registration Body must be between 1 and 50 characters long."
  }

  // Check Contact Person
  if (contactPerson.empty() || contactPerson.length() > 50) {
    reason = "Contact Person must be between 1 and 50 characters long."
  }

  // Check Designation
  if (designation.empty() || designation.length() > 50) {
    reason = "Designation must be between 1 and 50 characters long."
  }

  // Check Contact No
  if (contactNo.empty() || contactNo.length() > 20) {
    reason = "Contact No must be between 1 and 20 characters long."
  }

  // Check Email ID
  if (emailId.empty() || emailId.length() > 100) {
    reason = "Email ID must be between 1 and 100 characters long."
  }

  // Check Status
  if (status.empty() || status.length() > 10) {
    reason = "Status must be between 1 and 10 characters long."
  }

  // Return result
  return reason.has_value() ? std::nullopt : std::make_optional(reason.value());
}

struct VSPMaster {
  std::string vspCode;
  std::string providersName;
  std::string physicalAddress;
  std::string communicationAddress;
  std::string healthSubDistrict;
  std::string localityLevel;
  std::string facilityType;
  std::string registrationBody;
  std::string contactPerson;
  std::string designation;
  std::string contactNo;
  std::string emailId;
  std::string status;
};

std::optional<VSPMaster> createVSPMaster(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrict, const std::string& localityLevel, const std::string& facilityType, const std::string& registrationBody, const std::string& contactPerson, const std::string& designation, const std::string& contactNo, const std::string& emailId, const std::string& status) {
  auto reason = validateVSPMasterInfo(vspCode, providersName, physicalAddress, communicationAddress, healthSubDistrict, localityLevel, facilityType, registrationBody, contactPerson, designation, contactNo, emailId, status);
  if (reason.has_value()) {
    return std::nullopt;
  }

  VSPMaster vspMaster = {
    vspCode,
    providersName,
    physicalAddress,
    communicationAddress,
    healthSubDistrict,
    localityLevel,
    facilityType,
    registrationBody,
    contactPerson,
    designation,
    contactNo,
    emailId,
    status
  };

  return vspMaster;
}

bool updateVSPMaster(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrict, const std::string& localityLevel, const std::string& facilityType, const std::string& registrationBody, const std::string& contactPerson, const std::string& designation, const std::string& contactNo, const std::string& emailId, const std::string& status) {
  auto reason = validateVSPMasterInfo(vspCode, providersName, physicalAddress, communicationAddress, healthSubDistrict, localityLevel, facilityType, registrationBody, contactPerson, designation, contactNo, emailId, status);
  if (reason.has_value()) {
    return std::nullopt;
  }

  // Update the VSP master in the system

  return std::make_optional(VSPMaster(vspCode, providersName, physicalAddress, communicationAddress, healthSubDistrict, localityLevel, facilityType, registrationBody, contactPerson, designation, contactNo, emailId, status));
}

bool deleteVSPMaster(const std::string& vspCode) { if (vspCode.empty()) { return false; } // Attempt to delete the VSP master from the system return true; }

struct VSPMaster { std::string vspCode; std::string providersName; std::string physicalAddress; std::string communicationAddress; std::string healthSubDistrict; std::string localityLevel; std::string facilityType; std::string registrationBody; std::string contactPerson; std::string designation; std::string contactNo; std::string emailId; std::string status; }; std::optional<VSPMaster> getVSPMaster(const std::string& vspCode) { if (vspCode.empty()) { return std::nullopt; } // Retrieve the VSP master from the system // Return the VSP master if found, otherwise return a reason for failure return std::make_optional(VSPMaster(vspCode, "", "", "", "", "", "", "", "", "", "", "", "Active")); }

