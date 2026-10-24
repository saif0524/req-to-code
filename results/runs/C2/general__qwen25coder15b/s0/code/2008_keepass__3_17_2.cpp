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

struct Database; // Include the Database class definition
using namespace std::filesystem;

bool check_master_password(const std::string& password);
bool check_key_file(const std::string& key_file_path);
bool verify_composite_key(const std::string& master_password, const std::string& key_file_path);
bool unlock_database(const std::string& master_password, const std::string& key_file_path);
void handle_lost_password(const std::string& key_file_path);

bool check_master_password(const std::string& password, const std::string& stored_master_password) { return password == stored_master_password; }

bool check_key_file(const std::string& key_file_path) { return std::filesystem::exists(key_file_path); }

bool verify_composite_key(const std::string& master_password, const std::string& key_file_path) {
  if (!check_master_password(master_password)) {
    return false;
  }
  if (!check_key_file(key_file_path)) {
    return false;
  }
  return unlock_database(master_password, key_file_path);
}

bool unlock_database(const std::string& master_password, const std::string& key_file_path) { Database::unlock_database(master_password, key_file_path); }

void handle_lost_password(const std::string& key_file_path) {
  if (!check_key_file(key_file_path)) {
    return false;
  }
  if (!check_master_password(stored_master_password)) {
    return false;
  }
  return unlock_database(stored_master_password, key_file_path);
}

