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

remove_entry(Entry* entry);
Entry* find_entry(const std::string& entry_id);

initialize();
deinitialize();
add_entry(const std::string& title, const std::string& username, const std::string& password);
edit_entry(const std::string& title, const std::string& username, const std::string& password, const std::string& entry_id);
delete_entry(const std::string& entry_id);

void add_entry(const std::string& title, const std::string& username, const std::string& password) {
     // Find an empty entry slot
     Entry* entry = find_empty_entry();

     // If an empty slot is found, initialize the entry with the new title, username, and password
     if (entry != nullptr) {
         entry->title = title;
         entry->username = username;
         entry->password = password;
     }
}

Return JSON with 'reasoning': 3 to 6 short steps saying what is wrong and how you fix it, 'code': the complete corrected function definition only (no #include lines, no main), and 'added_declarations': any struct, enum, using alias or constant your fix needs that is missing from the shared declarations, declarations only, or an empty string.

void edit_entry(const std::string& title, const std::string& username, const std::string& password, const std::string& entry_id) {
      // Find the entry with the given entry_id
      Entry* entry = find_entry(entry_id);

      // If the entry is found, update the entry with the new title, username, and password
      if (entry != nullptr) {
          entry->title = title;
          entry->username = username;
          entry->password = password;
     }
}

void delete_entry(const std::string& entry_id) {
  Entry* entry = find_entry(entry_id);
  if (entry != nullptr) {
     remove_entry(entry);
  }
}

