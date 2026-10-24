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

std::string getUserType(const std::string& membership, const std::vector<std::string>& contributions);
std::string getPeeringType(const std::string& purpose, size_t size, const std::string& scope, size_t duration);
std::string getQoSType(const std::vector<std::string>& qosSpecifications);
std::string getClassification(const std::string& userType, const std::string& peeringType, const std::string& qosType);
std::string getPreferredTreatment(const std::string& businessLogic);

std::string getUserType(const std::string& membership, const std::vector<std::string>& contributions) {
  if (membership == "primary" || membership == "cooperating") {
    return "explicit member";
  }
  if (contributions.size() > 0) {
    return "implicit member";
  }
  return "unknown";
}

std::string getPeeringType(const std::string& purpose, size_t size, const std::string& scope, size_t duration) {
  if (purpose == "short-term" || duration < 30) {
    return "short-term";
  }
  if (purpose == "long-term" || duration >= 30) {
    return "long-term";
  }
  return "unknown";
}

std::string getQoSType(const std::vector<std::string>& qosSpecifications) {
  if (qosSpecifications.empty()) {
    return "unknown";
  }
  for (const auto& spec : qosSpecifications) {
    if (spec == "low") {
      return "low";
    }
    if (spec == "medium") {
      return "medium";
    }
    if (spec == "high") {
      return "high";
    }
  }
  return "unknown";
}

std::string getClassification(const std::string& userType, const std::string& peeringType, const std::string& qosType) {
  std::string classification = userType + '_' + peeringType + '_' + qosType;
  return classification;
}

std::string getPreferredTreatment(const std::string& businessLogic) {
  int businessLogicInt = std::stoi(businessLogic);
  switch (businessLogicInt) {
    case 0:
      return "low priority";
    case 1:
      return "medium priority";
    case 2:
      return "high priority";
    default:
      return "unknown";
  }
}

