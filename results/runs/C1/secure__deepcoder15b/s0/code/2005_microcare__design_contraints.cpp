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

{"include": "#include <object}"

std::string generate_staffCode(const std::string& vspCode, int sc);
std::object createNewStaff(const std::string& name, const std::string& qualification);
bool isValidNewStaff(const std::string& name, const std::string& qualification);
void saveNewStaffIfRequired(const std::string& name, const std::string& qualification);
void initializeStaffMaster();

std::string generateStaffCode(const std::string& vspCode, int sc) {
  std::string suffix = std::to_string(sc).substr(0, 3);
  return vspCode + suffix;
  }

const std::string name; // Name of the new staff
const std::string qualification; // Qualification for the new staff
std::object createNewStaff(const std::string& name, const std::string& qualification) {
  // Check if qualification is valid
  if (!isValidNewStaff(name, qualification)) {
    return false; // Or handle error as needed
  }

  // Create a new staff object
  const std::string& type = getStaffType(name);
  return std::make_object<CreateStaff>(name, qualification, type);
}

bool isValidNewStaff(const std::string& name, const std::string& qualification) {
  if (qualification.empty()) {
    return false; 
  }
  const std::set<std::string> allowedQualifications = { "Q1", "Q2" }; // Replace with actual allowed qualifications
  if (allowedQualifications.find(qualification) == allowedQualifications.end()) {
    return false; 
  }
  if (name.empty()) {
    return false; 
  }
  return true; 
  }
  

bool saveNewStaffIfRequired(const std::string& name, const std::string& qualification) {
  createNewStaff(name, qualification);
  initializeStaffMaster();
  return true;
  }

void initializeStaffMaster() {
  static const std::string name = "New Staff";
  static const std::string qualification = "Q1";
  return createNewStaff(name, qualification);
  }

