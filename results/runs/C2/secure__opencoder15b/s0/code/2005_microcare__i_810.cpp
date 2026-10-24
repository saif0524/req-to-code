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

std::string getVSPMasterInfo();
bool updateVSPMasterInfo(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrictLocal, const std::string& facilityType, const std::string& registrationBodyContactPerson, const std::string& contactNo, const std::string& emailId);
std::string getVSPMasterInfoJSON();
bool isValidVSPCode(const std::string& vspCode);
bool isValidProvidersName(const std::string& providersName);

std::string VoucherServiceProviderMaster::getVSPMasterInfo() {
    std::string json = "{\nVSPCode":"" + vspCode + "", + "ProvidersName":"" + providersName + "", + "PhysicalAddress":"" + physicalAddress + "", + "CommunicationAddress":"" + communicationAddress + "", + "HealthSubDistrictLocal":"" + healthSubDistrictLocal + "", + "FacilityType":"" + facilityType + "", + "RegistrationBodyContactPerson":"" + registrationBodyContactPerson + "", + "ContactNo":"" + contactNo + "", + "EmailId":"" + emailId + "", + "Status":"" + status + "" + "}";
return json;
}

bool updateVSPMasterInfo(const std::string& vspCode, const std::string& providersName, const std::string& physicalAddress, const std::string& communicationAddress, const std::string& healthSubDistrictLocal, const std::string& facilityType, const std::string& registrationBodyContactPerson, const std::string& contactNo, const std::string& emailId) {
    std::string json = "{\nVSPCode":"" + vspCode + "", + "ProvidersName":"" + providersName + "", + "PhysicalAddress":"" + physicalAddress + "", + "CommunicationAddress":"" + communicationAddress + "", + "HealthSubDistrictLocal":"" + healthSubDistrictLocal + "", + "FacilityType":"" + facilityType + "", + "RegistrationBodyContactPerson":"" + registrationBodyContactPerson + "", + "ContactNo":"" + contactNo + "", + "EmailId":"" + emailId + "", + "Status":"" + status + "" + "}";
return json;
}

std::string VoucherServiceProviderMaster::getVSPMasterInfoJSON() {
     std::string json = "{\nVSPCode":\"" + vspCode + "\", + "ProvidersName":\"" + providersName + "\", + "PhysicalAddress":\"" + physicalAddress + "\", + "CommunicationAddress":\"" + communicationAddress + "\", + "HealthSubDistrictLocal":\"" + healthSubDistrictLocal + "\", + "FacilityType":\"" + facilityType + "\", + "RegistrationBodyContactPerson":\"" + registrationBodyContactPerson + "\", + "ContactNo":\"" + contactNo + "\", + "EmailId":\"" + emailId + "\", + "Status":\"" + status + "\" + "\n}";
     return json;
}

bool isValidVSPCode(const std::string& vspCode) {
    if (vspCode.empty()) {
        return false;
    }
    // Add more validation logic as needed
    return true;
}

bool isValidProvidersName(const std::string& providersName) {
    if (providersName.empty()) {
        return false;
    }
    // Add more validation logic as needed
    return true;
}

