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

bool validateMasterPassword(const std::string& masterPassword);
bool validateKeyFile(const std::string& keyFilePath);
bool checkCompositeKey(const std::string& masterPassword, const std::string& keyFilePath);
void lockDatabase(const std::string& masterPassword, const std::string& keyFilePath);
void handleLostCredentials(const std::string& masterPassword, const std::string& keyFilePath);

bool validateMasterPassword(const std::string& masterPassword) {
  if (masterPassword.empty()) {
    return false;
  }
  return true;
}

bool validateKeyFile(const std::string& keyFilePath) {
  if (keyFilePath.empty()) {
    return false;
  }
  std::ifstream file(keyFilePath);
  if (!file.is_open()) {
    return false;
  }
  file.close();
  return true;
}

bool checkCompositeKey(const std::string& masterPassword, const std::string& keyFilePath) {
  if (!validateMasterPassword(masterPassword) || !validateKeyFile(keyFilePath)) {
    return false;
  }
  return true;
}

void lockDatabase(const std::string& masterPassword, const std::string& keyFilePath) {
  if (!validateMasterPassword(masterPassword) || !validateKeyFile(keyFilePath)) {
    std::cout << "Database locked due to invalid credentials." << std::endl;
    std::cout << "Reason: Either master password or key file is invalid." << std::endl;
    std::cout << "No recovery is available." << std::endl;
    std::cout << "No backdoor or key that unlocks all databases is available." << std::endl;
  }
}

void handleLostCredentials(const std::string& masterPassword, const std::string& keyFilePath) {
  if (!validateMasterPassword(masterPassword) || !validateKeyFile(keyFilePath)) {
    std::cout << "Database locked due to lost credentials." << std::endl;
    std::cout << "Reason: Either master password or key file is lost." << std::endl;
    std::cout << "No recovery is available." << std::endl;
    std::cout << "No backdoor or key that unlocks all databases is available." << std::endl;
  }
}

