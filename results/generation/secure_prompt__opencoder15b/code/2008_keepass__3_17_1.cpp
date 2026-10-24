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

create_master_key(const std::string& master_password, const std::string& key_file_path);
get_master_key() const;
set_master_key(const std::string& master_password, const std::string& key_file_path);
is_master_key_set() const;
unlock_database();

std::string create_master_key(const std::string& master_password, const std::string& key_file_path) {
  // Create a master key from the given master password and key file path.
  // This function should only use the shared declarations, the planned functions and local variables.
  // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, and 'code': the complete function definition only.
}

std::string get_master_key() const { return master_key; }

std::string set_master_key(const std::string& master_password, const std::string& key_file_path) {
  // Set the master key from the given master password and key file path.
  master_key = create_master_key(master_password, key_file_path);
  return master_key;
}

bool is_master_key_set() const { return master_key != ""; }

std::string unlock_database() { 
   // Unlocks the database using the master key. 
   // This function should only use the shared declarations, the planned functions and local variables. 
   // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, and 'code': the complete function definition only. 
}

