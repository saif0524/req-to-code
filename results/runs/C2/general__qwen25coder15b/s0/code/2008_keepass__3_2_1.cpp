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

using PasswordPrompter = /* include the actual header file */;

void openDatabase(const std::string& databasePath, const std::string& masterPassword);
std::string findDatabase(const std::string& databasePath);
std::string promptForMasterPassword(const std::string& databaseName);
void unlockDatabase(const std::string& databaseName, const std::string& masterPassword);

void openDatabase(const std::string& databasePath, const std::string& masterPassword) {
  navigateToDocumentsFolder();
  navigateToDatabase(databasePath);
  promptForMasterPassword(databaseName);
  unlockDatabase(databaseName, masterPassword);
}

std::string findDatabase(const std::string& databasePath) {  return databasePath.substr(databasePath.rfind('/') + 1); }

void promptForMasterPassword(const std::string& databaseName) {  return PasswordPrompter::promptForPassword(databaseName); }

void unlockDatabase(const std::string& databaseName, const std::string& masterPassword) {
  PasswordPrompter::promptForPassword(databaseName);
  PasswordPrompter::unlockDatabase(databaseName, masterPassword);
}

