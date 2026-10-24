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

bool validateClaimInput(const std::string& code, const std::string& name, double price);
bool validateSyndromeInput(const std::string& code, const std::string& description);
bool validateExamInput(const std::string& code, const std::string& description);
bool validateDiagnosisInput(const std::string& code, const std::string& description);
bool validateLabTestInput(const std::string& code, const std::string& name);

bool validateClaimInput(const std::string& code, const std::string& name, double price) {
  if (code.empty() || name.empty()) {
    return false;
  }
  if (!std::isgreater(price, 0.0)) {
    return false;
  }
  return true;
}

bool validateSyndromeInput(const std::string& code, const std::string& description) {
  if (code.empty() || description.empty()) {
    return false;
  }
  return true;
}

bool validateExamInput(const std::string& code, const std::string& description) {
  if (code.empty() || description.empty()) {
    return false;
  }
  return true;
}

bool validateDiagnosisInput(const std::string& code, const std::string& description) {
  if (code.empty() || description.empty()) {
    return false;
  }
  return true;
}

bool validateLabTestInput(const std::string& code, const std::string& name) {
  if (code.empty() || name.empty()) {
    return false;
  }
  return true;
}

