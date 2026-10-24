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

void NewDatabase(const std::string& masterPassword);
void SetMasterPassword(const std::string& masterPassword);
std::string GetMasterPassword() const;
bool IsMasterPasswordSet() const;
bool IsDatabaseLocked() const;

void NewDatabase(const std::string& masterPassword) {
  // Implementation steps
  // 1. Check if the database is already locked. If it is, unlock it.
  if(IsDatabaseLocked()){
    UnlockDatabase();
  }
  // 2. Create a new database object with the given master password.
  Database db(masterPassword);
  // 3. Set the master password for the database.
  SetMasterPassword(masterPassword);
  // 4. Store the database object in a shared state.
  SetDatabase(db);
}

void SetMasterPassword(const std::string& masterPassword) {
  // Implementation steps
  // 1. Check if the database is already locked. If it is, unlock it.
  if(IsDatabaseLocked()){
    UnlockDatabase();
  }
  // 2. Create a new database object with the given master password.
  Database db(masterPassword);
  // 3. Set the master password for the database.
  SetMasterPassword(masterPassword);
  // 4. Store the database object in a shared state.
  SetDatabase(db);
}

std::string GetMasterPassword() const {
  return sharedState_->GetMasterPassword();
}

bool IsMasterPasswordSet() const {
  return sharedState_->IsMasterPasswordSet();
}

bool IsDatabaseLocked() const {
  if (IsDatabaseLocked()) {
    UnlockDatabase();
  }
  return sharedState_->IsMasterPasswordSet();
}

