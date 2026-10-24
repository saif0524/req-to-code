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

VSPMasterInfo(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrict, const std::string& localityLevel, const std::string& facilityType, const std::string& registrationBody, const std::string& contactPerson, const std::string& designation, const std::string& contactNo, const std::string& emailId, const std::string& status);
std::string getVSPCode(const VSPMasterInfo& vspMaster);
std::string getProvidersName(const VSPMasterInfo& vspMaster);
std::string getPhysicalAddress(const VSPMasterInfo& vspMaster);
std::string getCommunicationAddress(const VSPMasterInfo& vspMaster);

struct VSPMasterInfo {
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

  VSPMasterInfo(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrict, const std::string& localityLevel, const std::string& facilityType, const std::string& registrationBody, const std::string& contactPerson, const std::string& designation, const std::string& contactNo, const std::string& emailId, const std::string& status)
    : vspCode(vspCode), providersName(providersName), physicalAddress(physicalAddress), communicationAddress(communicationAddress), healthSubDistrict(healthSubDistrict), localityLevel(localityLevel), facilityType(facilityType), registrationBody(registrationBody), contactPerson(contactPerson), designation(designation), contactNo(contactNo), emailId(emailId), status(status) {}
};

std::string getVSPCode(const VSPMasterInfo& vspMaster) { return vspMaster.vspCode; }

std::string getProvidersName(const VSPMasterInfo& vspMaster) { return vspMaster.providersName; }

std::string getPhysicalAddress(const VSPMasterInfo& vspMaster) { return vspMaster.physicalAddress; }

std::string getCommunicationAddress(const VSPMasterInfo& vspMaster) { return vspMaster.communicationAddress; }

