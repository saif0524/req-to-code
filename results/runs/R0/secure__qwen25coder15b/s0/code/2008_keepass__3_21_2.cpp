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

void update_tan_entry(const std::string& title, const std::string& username, const std::string& url, const std::string& tan);

void update_tan_entry(const std::string& title, const std::string& username, const std::string& url, const std::string& tan) {
  // Check if the TAN entry is already marked as used or expired
  if (is_tan_entry_used(title, username, url)) {
    return;
  }

  // Update the TAN entry with the provided title, username, URL, and TAN
  update_tan_entry_internal(title, username, url, tan);

  // Mark the TAN entry as used
  mark_tan_entry_used(title, username, url);
}

