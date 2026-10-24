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

struct thirdPartyService { static bool validate(const std::string& cardNumber, const std::string& cvv, const std::string& expirationDate); };

bool validateCreditCard(const std::string& cardNumber, const std::string& cvv, const std::string& expirationDate);
void encryptSensitiveInfo(std::string& data);
void encryptCustomerData(std::string& data);
bool detectIPDOSAttack(const std::string& ipAddress);
bool detectConsecutiveFailedLoginAttempts(const std::string& username, int attempts);

struct thirdPartyService { static bool validate(const std::string& cardNumber, const std::string& cvv, const std::string& expirationDate); }; bool validateCreditCard(const std::string& cardNumber, const std::string& cvv, const std::string& expirationDate) { return thirdPartyService::validate(cardNumber, cvv, expirationDate); }

void encryptCustomerData(std::string& data) { encryptSensitiveInfo(data); }

bool detectIPDOSAttack(const std::string& ipAddress) {
  static std::map<std::string, int> failedAttempts;
  failedAttempts[ipAddress]++;
  if (failedAttempts[ipAddress] >= 5) {
    // Block the IP
    return true;
  }
  return false;
}

bool detectConsecutiveFailedLoginAttempts(const std::string& username, int attempts) {
  static std::map<std::string, int> failedAttempts;
  failedAttempts[username] += attempts;
  return failedAttempts[username] >= 5;
}

