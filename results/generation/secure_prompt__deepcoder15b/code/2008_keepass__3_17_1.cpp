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

.cpp17 includes here... empty string

bool is_unlocked(const std::string& master_key, const std::string& key_file);
void unlock_database(const std::string& master_key, const std::string& key_file);
std::string getMasterKey(std::shared_ptr<std::pair<std::string, std::string>> database);

bool is_unlocked(const std::string& master_key, const std::string& key_file) {
  return (master_key != std::string::empty()) && (key_file != std::string::empty());
  }

bool unlock_database(const std::string& master_key, const std::string& key_file) {
  return (master_key.empty() || key_file.empty());
  }

std::string getMasterKey(std::shared_ptr<std::pair<std::string, std::string>> database) {
  return static_cast<std::string>( database->get_first_element() );
  }

