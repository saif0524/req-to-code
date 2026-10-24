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
std::string getPreferredTreatment(const std::string& businessLogic);
std::string getDynamicQoS(const std::vector<std::string>& situations);

std::string getUserType(const std::string& membership, const std::vector<std::string>& contributions) {
  std::string userType;

  if (membership == "primary" && contributions.size() > 0) {
    userType = "Explicit Member";
  } else if (contributions.size() > 0) {
    userType = "Implicit Member";
  } else {
    userType = "Unknown";
  }

  return userType;
}

std::string getPeeringType(const std::string& purpose, size_t size, const std::string& scope, size_t duration) {
  std::string peeringType;

  if (purpose == "short-term" && duration <= 24 * 60 * 60) {
    peeringType = "Automated Short-Term Peering";
    return "{\"type\":\"Automated Short-Term Peering\", \"reasoning\": \"Short-term peering arrangements are automated and require quick reaction.\"}";
  } else if (purpose == "long-term" && duration > 24 * 60 * 60) {
    peeringType = "Human-Directed Long-Term Peering";
    return "{\"type\":\"Human-Directed Long-Term Peering\", \"reasoning\": \"Long-term peering arrangements need human-directed negotiation.\"}";
  } else {
    peeringType = "Unknown Peering Type";
    return "{\"type\":\"Unknown Peering Type\", \"reasoning\": \"Purpose, size, scope, and duration are not sufficient to classify the peering type.\"}";
  }
}

std::string getQoSType(const std::vector<std::string>& qosSpecifications) {
  std::string qosType = "Default QoS";

  if (qosSpecifications.empty()) {
    return "{type":"Default QoS", reasoning": "No QoS specifications provided."}";
  }

  for (const auto& spec : qosSpecifications) {
    if (spec == "High" || spec == "Medium" || spec == "Low") {
      qosType = spec;
      return "{type":"" + qosType + " QoS", reasoning": "QoS specifications match predefined types."}";
    }
  }

  return "{type":"Unknown QoS", reasoning": "QoS specifications do not match predefined types."}";
}

std::string getPreferredTreatment(const std::string& businessLogic) {
  std::string preferredTreatment;

  if (businessLogic == "BusinessLogic1") {
    preferredTreatment = "PreferredTreatment1";
    return "{\"type\":\"PreferredTreatment1\", \"reasoning\": \"BusinessLogic1 is a predefined value.\"}";
  } else if (businessLogic == "BusinessLogic2") {
    preferredTreatment = "PreferredTreatment2";
    return "{\"type\":\"PreferredTreatment2\", \"reasoning\": \"BusinessLogic2 is a predefined value.\"}";
  } else {
    preferredTreatment = "Unknown Treatment";
    return "{\"type\":\"Unknown Treatment\", \"reasoning\": \"BusinessLogic is not a predefined value.\"}";
  }
}

std::string getDynamicQoS(const std::vector<std::string>& situations) {
  std::string dynamicQoS = "Default QoS";

  for (const auto& situation : situations) {
    if (situation == "Situation1") {
      dynamicQoS = "High QoS";
      return "{\"type\":\"High QoS\", \"reasoning\": \"Situation1 requires high QoS.\"}";
    } else if (situation == "Situation2") {
      dynamicQoS = "Medium QoS";
      return "{\"type\":\"Medium QoS\", \"reasoning\": \"Situation2 requires medium QoS.\"}";
    } else if (situation == "Situation3") {
      dynamicQoS = "Low QoS";
      return "{\"type\":\"Low QoS\", \"reasoning\": \"Situation3 requires low QoS.\"}";
    }
  }

  return "{\"type\":\"Default QoS\", \"reasoning\": \"No matching situation found.\"}";
}

