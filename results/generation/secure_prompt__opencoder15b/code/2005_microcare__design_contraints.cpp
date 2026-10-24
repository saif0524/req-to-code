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

createStaff(const std::string& name, const std::string& staffTypeCode, const std::string& staffCodePrefix, const std::string& qualification);
updateStaff(const std::string& staffCode, const std::string& name, const std::string& staffTypeCode, const std::string& qualification);
generateStaffCode(const std::string& staffCodePrefix, const std::string& staffTypeCode);
getStaffTypeList();
getStaffTypeCode(const std::string& staffType);

void createStaff(const std::string& name, const std::string& staffTypeCode, const std::string& staffCodePrefix, const std::string& qualification) {
  // Implementation of the function
}

void updateStaff(const std::string& staffCode, const std::string& name, const std::string& staffTypeCode, const std::string& qualification) {
   // Implementation of the function
}

std::string generateStaffCode(const std::string& staffCodePrefix, const std::string& staffTypeCode) {
    // Implementation of the function
    // First, generate a unique staff code
    std::string staffCode = staffCodePrefix + std::to_string(getUniqueNumber());
    // Then, check if the generated staff code already exists in the system
    while (staffCodeExists(staffCode)) {
        staffCode = staffCodePrefix + std::to_string(getUniqueNumber());
    }
    // Finally, return the generated staff code
    return staffCode;
}

void createStaff(const std::string& name, const std::string& staffTypeCode, const std::string& staffCodePrefix, const std::string& qualification) {
    // Implementation of the function
}

std::string generateStaffCode(const std::string& staffCodePrefix, const std::string& staffTypeCode) {
    // Implementation of the function
    // First, generate a unique staff code
    std::string staffCode = staffCodePrefix + std::to_string(getUniqueNumber());
    // Then, check if the generated staff code already exists in the system
    while (staffCodeExists(staffCode)) {
        staffCode = staffCodePrefix + std::to_string(getUniqueNumber());
    }
    // Finally, return the generated staff code
    return staffCode;
}

std::vector<std::string> getStaffTypeList() {
    // Implementation of the function
    // First, retrieve the list of staff types from the Staff Type Master Information
    // Return the list of staff types
}

std::string getStaffTypeCode(const std::string& staffType) {
    // Implementation of the function
    // First, retrieve the list of staff types from the Staff Type Master Information
    // Return the list of staff types
}

