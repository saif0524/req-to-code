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

void createNewStaff(std::string staffName, std::string staffType, std::string staffCode, std::string staffQualification);
std::string generateStaffCode(std::string staffCodePrefix, std::string staffType, int staffNumber);
bool validateStaffName(std::string staffName);
bool validateStaffType(std::string staffType);
bool validateStaffQualification(std::string staffQualification);

void createNewStaff(std::string staffName, std::string staffType, std::string staffCode, std::string staffQualification) {
  // Implementation of the function 'createNewStaff' using the planned functions and local variables.
}

std::string generateStaffCode(std::string staffCodePrefix, std::string staffType, int staffNumber) {
   if (!validateStaffName(staffName) || !validateStaffType(staffType)) {
      return "Staff name or staff type is not unique or available";
   }
   std::string staffCode = staffCodePrefix + staffType + std::to_string(staffNumber);
   return staffCode;
}

bool validateStaffName(std::string staffName) {
    // Implementation of the function 'validateStaffName' using the planned functions and local variables.
}

bool validateStaffType(std::string staffType) {
    // Implementation of the function 'validateStaffType' using the planned functions and local variables.
}

bool validateStaffQualification(std::string staffQualification) {
    // Implementation of the function 'validateStaffQualification' using the planned functions and local variables.
}

