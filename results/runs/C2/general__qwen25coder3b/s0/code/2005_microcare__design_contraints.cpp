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
std::string generateStaffCode(const std::string& vspCode, const std::string& staffType);
bool createStaff(const std::string& name, const std::string& qualification, const std::string& staffType);
void handleDuplicateName(const std::string& name);
void navigateToStaffTypeMaster(const std::string& staffType);

bool staffNameExists(const std::string& name) { return false; } bool validateStaffName(const std::string& name) { if (staffNameExists(name)) { return false; } return true; }

std::string generateStaffCode(const std::string& vspCode, const std::string& staffType) { static int counter = 0; std::string suffix = 'SC' + std::to_string(counter++); return vspCode + suffix; }

bool createStaff(const std::string& name, const std::string& qualification, const std::string& staffType, const std::string& vspCode) { if (name.empty() || qualification.empty() || staffType.empty()) { return false; } if (!validateStaffName(name)) { handleDuplicateName(name); return false; } std::string staffCode = generateStaffCode(vspCode, staffType); std::cout << "Creating staff: " << name << ", Qualification: " << qualification << ", Staff Type: " << staffType << ", Staff Code: " << staffCode << std::endl; return true; }

void handleDuplicateName(const std::string& name) {
  if (!validateStaffName(name)) {
    std::cout << "Error: Staff name already exists. Please choose a different name." << std::endl;
  }
}

bool staffTypeExists(const std::string& staffType) { return false; } void navigateToStaffTypeMaster(const std::string& staffType) { if (!staffTypeExists(staffType)) { std::cout << "Navigating to staff type master screen for: " << staffType << std::endl; } }

