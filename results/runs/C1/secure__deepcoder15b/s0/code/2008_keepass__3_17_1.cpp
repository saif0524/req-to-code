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

std::pair<std::string, std::string> is not declared in this scope. You'll need to include <utility> and use std::pair.

bool is_unlocked(const std::string& master_key, const std::string& key_file);
void unlock_database(const std::string& master_key, const std::string& key_file);
void save_database(const std::string& master_key, const std::string& key_file);
std::string getMasterKey(std::shared_ptr<std::pair<std::string, std::string>> database);
void validateMasterKey(const std::string& master_key);

bool is_unlocked(const std::string& master_key, const std::string& key_file) {
  return (master_key != std::string()) && (key_file != std::string());
  }

bool unlock_database(const std::string& master_key, const std::string& key_file) {
  return (master_key != std::string() && key_file != std::string());
  }

class KeePassDatabase:
  public:
    using master_key = std::string;
    using key_file = std::string;

    master_key getMasterKey(std::shared_ptr<pair< master_key, key_file>>> database) {
      return std::pair< master_key, key_file> database->get_first_element().first;
    }

    void validateMasterKey(const master_key& master_key) {
      // implementation
    }
    std::string getMasterKey(std::shared_ptr< pair< master_key, key_file>>> database {
      return std::pair< master_key, key_file> database->get_first_element().first;
    }
  }

