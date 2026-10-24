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

bool detectMaliciousRequests(const std::vector<std::string>& requests);
void rejectMaliciousRequests(const std::vector<std::string>& requests);
bool isReplicatedContent(const std::string& contentId);
void considerRequests(const std::vector<std::string>& requests);
std::string formatServiceInfo(const std::vector<std::string>& requests);

bool detectMaliciousRequests(const std::vector<std::string>& requests) {
  for (const auto& request : requests) {
    if (isMalicious(request)) {
      return true;
    }
  }
  return false;
}

void rejectMaliciousRequests(const std::vector<std::string>& requests) {
  for (const auto& request : requests) {
    if (detectMaliciousRequests({request})) {
      return;
    }
  }
}

bool isReplicatedContent(const std::string& contentId) {
  static std::vector<bool> replicatedContent;
  if (contentId >= replicatedContent.size()) {
    replicatedContent.resize(contentId + 1, false);
  }
  return replicatedContent[contentId];
}

void considerRequests(const std::vector<std::string>& requests) { for (const auto& request : requests) { } }

std::string formatServiceInfo(const std::vector<std::string>& requests) {
  std::string formattedInfo;
  for (const auto& request : requests) {
    formattedInfo += request + "\n";
  }
  return formattedInfo;
}

