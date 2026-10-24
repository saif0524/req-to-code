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

bool validateStaffName(const std::string& name);
std::string createStaffCode(const std::string& vspCode, const std::string& staffType);
bool validateStaffType(const std::string& staffType);
bool createStaff(const std::string& name, const std::string& staffType, const std::string& qualification);
bool processClaimEntry(const std::string& staffName, const std::string& staffType, const std::string& qualification);

static std::vector<std::string> staffNames;
bool validateStaffName(const std::string& name) {
  if (std::find(staffNames.begin(), staffNames.end(), name) != staffNames.end()) {
    return false;
  }
  return true;
}

std::string createStaffCode(const std::string& vspCode, const std::string& staffType) {
  static std::vector<std::string> staffCodes;
  static int counter = 0;

  std::string suffix = std::to_string(counter++);
  while (staffCodes.size() > 0 && staffCodes.back().find(vspCode + staffType + suffix) != std::string::npos) {
    suffix = std::to_string(counter++);
  }

  staffCodes.push_back(vspCode + staffType + suffix);

  return vspCode + staffType + suffix;
}

bool validateStaffType(const std::string& staffType) {
  static std::vector<std::string> staffTypes;

  return std::find(staffTypes.begin(), staffTypes.end(), staffType) != staffTypes.end();
}

bool createStaff(const std::string& name, const std::string& staffType, const std::string& qualification) {
  if (!validateStaffName(name)) {
    return false;
  }

  std::string staffCode = createStaffCode("", staffType);

  if (!validateStaffType(staffType)) {
    return false;
  }

  // Assuming 'staffs' is a list to store staff information
  staffs.push_back({name, staffType, qualification, staffCode});

  return true;
}

bool processClaimEntry(const std::string& staffName, const std::string& staffType, const std::string& qualification) {
  if (!validateStaffName(staffName)) {
    return false;
  }

  std::string staffCode = createStaffCode("", staffType);

  if (!validateStaffType(staffType)) {
    return false;
  }

  // Assuming 'staffs' is a list to store staff information
  staffs.push_back({staffName, staffType, qualification, staffCode});

  return true;
}

