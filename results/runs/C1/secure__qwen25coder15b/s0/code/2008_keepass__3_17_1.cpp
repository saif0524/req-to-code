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

void create_master_key(std::string& master_key);
bool load_key_file(const std::string& key_file_path, std::string& key);
bool verify_key_compatibility(const std::string& master_key, const std::string& key);
bool unlock_database(const std::string& master_key, const std::string& key);

void create_master_key(std::string& master_key) {
  std::string salt = generate_salt();
  std::string hashed_key = hash_key(master_key + salt);
  master_key.resize(hashed_key.size());
  master_key = hashed_key;
}

bool load_key_file(const std::string& key_file_path, std::string& key) {
  std::ifstream file(key_file_path, std::ios::binary);
  if (!file.is_open()) {
    key = "Failed to load key file";
    return false;
  }
  file.seekg(0, std::ios::end);
  size_t size = file.tellg();
  file.seekg(0, std::ios::beg);
  key.resize(size);
  file.read(key.data(), size);
  file.close();
  return true;
}

bool verify_key_compatibility(const std::string& master_key, const std::string& key) {
  std::ifstream file(key_file_path, std::ios::binary);
  if (!file.is_open()) {
    key = "Failed to load key file";
    return false;
  }
  file.seekg(0, std::ios::end);
  size_t size = file.tellg();
  file.seekg(0, std::ios::beg);
  key.resize(size);
  file.read(key.data(), size);
  file.close();

  std::string salt = generate_salt();
  std::string hashed_key = hash_key(master_key + salt);

  std::string hashed_key_file = hash_key(key_file);

  if (hashed_key_file == hashed_key) {
    return true;
  } else {
    key = "Key file is not compatible";
    return false;
  }
}

bool unlock_database(const std::string& master_key, const std::string& key, const std::string& key_file_path) {
  std::string salt = generate_salt();
  std::string hashed_key = hash_key(master_key + salt);

  std::string hashed_key_file = hash_key(key_file);

  if (hashed_key_file == hashed_key) {
    return load_key_file(key_file_path, key);
  } else {
    key = "Key file is not compatible";
    return false;
  }
}

