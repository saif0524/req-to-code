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

bool getMasterPassword(const std::string& masterPassword);
bool hasKeyFile(const std::string& keyFile);
bool hasCompositeKey(const std::string& masterPassword, const std::string& keyFile);
bool checkDatabaseUnlocked(const std::string& masterPassword, const std::string& keyFile);
bool handleDatabaseUnlock(const std::string& masterPassword, const std::string& keyFile);

bool getMasterPassword(const std::string& masterPassword) {
    if (masterPassword.empty()) {
        return false;
    }
    return true;
    }

bool hasKeyFile(const std::string& keyFile) {
    if (keyFile.empty()) {
        return false;
    }
    return true;
    }

bool hasCompositeKey(const std::string& masterPassword, const std::string& keyFile) {
    return (getMasterPassword(masterPassword) && hasKeyFile(keyFile));
    }

bool checkDatabaseUnlocked(const std::string& masterPassword, const std::string& keyFile) {
  return getMasterPassword(masterPassword) || hasKeyFile(keyFile);
}

bool handleDatabaseUnlock(const std::string& masterPassword, const std::string& keyFile) {
  if (hasCompositeKey(masterPassword, keyFile)) {
    return true;
  } else if (hasKeyFile(keyFile)) {
    return true;
  } else {
    return false;
  }
}

