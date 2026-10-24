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

get_data(const std::string& key);
set_data(const std::string& key, const std::string& value);
remove_data(const std::string& key);
clear_database();
get_shared_declarations();

std::string get_data(const std::string& key) {
     auto it = get_shared_declarations().find(key);
     if (it != get_shared_declarations().end()) {
         return it->second;
     } else {
         return "Key not found";
     }
}

std::string set_data(const std::string& key, const std::string& value) {
     auto it = get_shared_declarations().find(key);
      if (it != get_shared_declarations().end()) {
         it->second = value;
         return "Data updated";
     } else {
         get_shared_declarations()[key] = value;
         return "Data set";
     }
}

std::string remove_data(const std::string& key) {
     auto it = get_shared_declarations().find(key);
      if (it != get_shared_declarations().end()) {
         get_shared_declarations().erase(it);
         return "Data removed";
     } else {
         return "Key not found";
     }
}

void clear_database() {
     shared_declarations.clear();
}

std::map<std::string, std::string> get_shared_declarations() {
     return shared_declarations;
}

