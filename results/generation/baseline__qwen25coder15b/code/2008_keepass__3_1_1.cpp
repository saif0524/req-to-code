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

void initializeDatabase(const std::string& masterPassword);
void setMasterPassword(const std::string& newPassword);
bool verifyMasterPassword(const std::string& password);
void saveDatabase(const std::string& filePath);
void loadDatabase(const std::string& filePath);

void initializeDatabase(const std::string& masterPassword) {
  // Set the master password in the database
  database.setMasterPassword(masterPassword);
}

void setMasterPassword(const std::string& newPassword) {
  // Set the new password in the database
  database.setMasterPassword(newPassword);
}

bool verifyMasterPassword(const std::string& password) {
  // Access the stored master password from the database
  std::string storedMasterPassword = database.getMasterPassword();

  // Compare the provided password with the stored master password
  if (storedMasterPassword == password) {
    return true;
  } else {
    return false;
  }
}

void saveDatabase(const std::string& filePath) {
  std::ofstream file(filePath, std::ios::binary);
  if (!file) {
    std::cerr << "Error: Unable to open file for writing" << std::endl;
    return false;
  }
  // Write the database data to the file
  file.write(reinterpret_cast<char*>(database.getData()), database.getSize());
  file.close();
  return true;
}

void loadDatabase(const std::string& filePath) {
  std::ifstream file(filePath, std::ios::binary);
  if (!file) {
    std::cerr << "Error: Unable to open file for writing" << std::endl;
    return false;
  }
  // Read the database data into a buffer
  std::vector<char> buffer(file.readAllBytes());
  // Reconstruct the database object using the buffer
  database.setData(buffer.data(), buffer.size());
  return true;
}

