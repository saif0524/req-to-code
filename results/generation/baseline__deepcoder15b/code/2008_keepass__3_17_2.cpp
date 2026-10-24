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

bool is_composite_key_valid(const bool &compositeMasterPassword, const bool &keyFile);
bool is_database_unlocked(const bool &compositeMasterPassword, const bool &keyFile);
bool check_master_password(const bool &compositeMasterPassword);
bool check_key_file(const bool &compositeMasterPassword);

bool is_composite_key_valid(const bool &compositeMasterPassword, const bool &keyFile) {
  return compositeMasterPassword && keyFile;
}

bool is_database_unlocked(const bool &compositeMasterPassword, const bool &keyFile) {
  return is_composite_key_valid(compositeMasterPassword, keyFile);
}

bool check_master_password(const bool &compositeMasterPassword) {
  return compositeMasterPassword;
}

bool check_key_file(const bool &compositeMasterPassword) {
  return (bool)compositeMasterPassword;
}

