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

void create_tan(const std::string& title, const std::string& username, const std::string& url, const std::string& notes);
void use_tan(const std::string& title);
void update_tan(const std::string& title, const std::string& new_notes);
void delete_tan(const std::string& title);

void create_tan(const std::string& title, const std::string& username, const std::string& url, const std::string& notes) {
  Entry* entry = create_entry(title, username, url, notes);
  if (entry != nullptr) {
    set_expiration_time(entry, std::chrono::system_clock::now());
    return;
  }
  return;
}

void use_tan(const std::string& title) {
  Entry* entry = find_entry(title);
  if (entry == nullptr) {
    return;
  }
  set_expiration_time(entry, std::chrono::system_clock::now());
  return;
}

void update_tan(const std::string& title, const std::string& new_notes) {
  Entry* entry = find_entry(title);
  if (entry != nullptr) {
    set_notes(entry, new_notes);
    set_expiration_time(entry, std::chrono::system_clock::now());
  }
}

void delete_tan(const std::string& title) {
  Entry* entry = find_entry(title);
  if (entry == nullptr) {
    return;
  }
  delete_entry(entry);
}

