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
  // Generate a key from the master password and key file path.
  std::string master_key = generate_key(master_password, key_file_path);
  return master_key;
}

std::string Database::get_master_key() const { return master_key; }

std::string set_master_key(const std::string& master_password, const std::string& key_file_path) {
   // Set the master key from the given master password and key file path.
   master_key = create_master_key(master_password, key_file_path);
   return master_key;
}

bool is_master_key_set() const { return master_key != ""; }

std::string unlock_database() { 
    if (!is_master_key_set()) { 
        std::string master_password; 
        std::string key_file_path; 
        std::cout << "Enter master password:"; 
        std::cin >> master_password; 
        std::cout << "Enter key file path:"; 
        std::cin >> key_file_path; 
        set_master_key(master_password, key_file_path); 
    } 
    std::string decrypted_database = decrypt_database(get_master_key()); 
    unlock_database(decrypted_database); 
    return decrypted_database; 
}

