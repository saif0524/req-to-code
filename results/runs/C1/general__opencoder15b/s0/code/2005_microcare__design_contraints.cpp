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
  if (!validateStaffName(staffName) || !validateStaffType(staffType)) {
    return "Staff name or staff type is not unique or available";
  }
  std::string staffCode = staffCodePrefix + staffType + std::to_string(staffNumber);
  // Create a new staff object with the given name, staff type, staff code, and qualification
  return "Staff created successfully";
}

std::string generateStaffCode(std::string staffCodePrefix, std::string staffType, int staffNumber) {
    if (!validateStaffName(staffName) || !validateStaffType(staffType)) {
       return "Staff name or staff type is not unique or available";
    }
    std::string staffCode = staffCodePrefix + staffType + std::to_string(staffNumber);
    return staffCode;
}

bool validateStaffName(std::string staffName) {
   for (Staff staff : staffList) {
      if (staff.getName() == staffName) {
         return false;
      }
   }
   return true;
}

bool validateStaffType(std::string staffType) {
    for (Staff staff : staffList) {
       if (staff.getType() == staffType) {
         return false;
       }
    }
    return true;
}

