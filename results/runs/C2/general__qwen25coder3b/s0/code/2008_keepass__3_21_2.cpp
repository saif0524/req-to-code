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

struct TanExpiration { std::map<std::string, std::chrono::system_clock::time_point> expirationTimes; }; struct TanUsageHistory { std::map<std::string, bool> usageHistory; };

bool validateTanEntry(const std::string& usernameOrUrl, const std::string& tan);
void expireTan(const std::string& tan);
bool updateTanEntry(const std::string& usernameOrUrl, const std::string& tan);
bool checkTanUsage(const std::string& tan);
void handleTanEntry(const std::string& usernameOrUrl, const std::string& tan);

bool validateTanEntry(const std::string& usernameOrUrl, const std::string& tan) { return false; }

void expireTan(const std::string& tan) {
  TanExpiration& tanExp = TanExpiration::expirationTimes;
  if (tanExp.find(tan) != tanExp.end()) {
    tanExp[tan] = std::chrono::system_clock::now();
  }
}

struct TanEntries { std::map<std::string, std::string> entries; }; bool updateTanEntry(const std::string& usernameOrUrl, const std::string& tan) { TanEntries& tanEntries = tanEntries; if (validateTanEntry(usernameOrUrl, tan)) { tanEntries.entries[usernameOrUrl] = tan; return true; } return false; }

bool checkTanUsage(const std::string& tan) { TanUsageHistory& tanUsageHistory = TanUsageHistory::usageHistory; return tanUsageHistory.find(tan) != tanUsageHistory.end(); }

void handleTanEntry(const std::string& usernameOrUrl, const std::string& tan) {
  if (validateTanEntry(usernameOrUrl, tan)) {
    if (updateTanEntry(usernameOrUrl, tan)) {
      expireTan(tan);
    }
  }
}

