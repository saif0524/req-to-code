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

void selectEntry(Entry* entry);
void updatePassword(Entry* entry, const std::string& newPassword);

void selectEntry(Entry* entry) { entry->selected = true; }

void updatePassword(Entry* entry, const std::string& newPassword) {
  if (entry && !newPassword.empty()) {
    entry->password = newPassword;
    entry->repeatPassword = newPassword;
  }
}

