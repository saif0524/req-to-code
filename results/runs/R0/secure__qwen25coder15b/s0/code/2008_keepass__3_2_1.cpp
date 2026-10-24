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

void openDatabase(const std::string& databasePath, const std::string& masterPassword);
std::string findDatabase(const std::string& databasePath);
std::string promptForMasterPassword(const std::string& databaseName);
void unlockDatabase(const std::string& databaseName, const std::string& masterPassword);

void openDatabase(const std::string& databasePath, const std::string& masterPassword) {
  // Transfer the user to the documents folder
  std::string documentsPath = getDocumentsPath();

  // Navigate to the database
  std::string databaseName = findDatabase(databasePath);

  // Prompt for the master password
  std::string masterPassword = promptForMasterPassword(databaseName);

  // Unlock the database
  unlockDatabase(databaseName, masterPassword);
}

std::string findDatabase(const std::string& databasePath) {
  std::filesystem::path documentsPath = getDocumentsPath();
  std::filesystem::path databasePath = documentsPath / databasePath;
  return databasePath.filename().string();
}

std::string promptForMasterPassword(const std::string& databaseName) {
  std::cout << "Enter the master password for the database "

void unlockDatabase(const std::string& databaseName, const std::string& masterPassword) {
  DatabaseManager::unlockDatabase(databaseName, masterPassword);
}

