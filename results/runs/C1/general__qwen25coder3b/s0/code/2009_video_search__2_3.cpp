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

std::string getUserType();
bool canEditSites(const std::string& userType);
bool isSiteSafe(const std::string& siteUrl);
bool isSiteCompatible(const std::string& siteUrl);
bool isSiteFast(const std::string& siteUrl);

std::string getUserType(const std::string& userType) {
  if (userType == "general") {
    return "general";
  } else if (userType == "developer") {
    return "developer";
  } else {
    return "";
  }
}

bool canEditSites(const std::string& userType) { return userType == "developer"; }

bool isSiteSafe(const std::string& siteUrl) { std::regex unsafePattern(R"(malicious|unsafe|phishing|malware|blacklisted)"s); return std::regex_search(siteUrl, unsafePattern); }

bool isSiteCompatible(const std::string& siteUrl) { static const std::vector<std::string> compatibleSites = {"site1.com", "site2.com", "site3.com"}; return std::find(compatibleSites.begin(), compatibleSites.end(), siteUrl) != compatibleSites.end(); }

bool isSiteFast(const std::string& siteUrl) { return true; }

