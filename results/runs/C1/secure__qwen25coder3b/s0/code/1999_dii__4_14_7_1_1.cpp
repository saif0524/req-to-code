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

std::vector<std::string> getExternalInterfaces();
std::string getDetailedInterfaceInfo(const std::string& interfaceName);
bool validateInterfaceName(const std::string& interfaceName);
std::string fetchDetailedInfo(const std::string& interfaceName);
void processDetailedInfo(const std::string& detailedInfo);

std::vector<std::string> getExternalInterfaces() { return {"interface1", "interface2", "interface3"}; }

std::string getDetailedInterfaceInfo(const std::string& interfaceName) {
  if (!validateInterfaceName(interfaceName)) {
    return "Invalid interface name";
  }

  std::string detailedInfo = fetchDetailedInfo(interfaceName);

  return detailedInfo;
}

bool validateInterfaceName(const std::string& interfaceName) {
  if (interfaceName.empty()) {
    return false;
  }

  for (char c : interfaceName) {
    if (!std::isalnum(c) && c != '_') {
      return false;
    }
  }

  return true;
}

std::string fetchDetailedInfo(const std::string& interfaceName) {
  if (!validateInterfaceName(interfaceName)) {
    return "Invalid interface name";
  }

  // Simulate fetching detailed information from a data source
  std::string detailedInfo = "{\"reasoning\": \"This is a placeholder for detailed information\", \"data\": {\"key1\": \"value1\", \"key2\": \"value2\"}}";

  return detailedInfo;
}

void validateDetailedInfo(const std::string& detailedInfo) { return true; }

