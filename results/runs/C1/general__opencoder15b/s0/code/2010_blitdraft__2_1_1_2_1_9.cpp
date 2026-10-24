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

std::vector<User> searchUser(std::string searchTerm);

std::vector<User> searchUser(std::string searchTerm) {
   std::vector<User> users;
   // Assuming that the user tables are stored in a vector of User objects
   for (const auto& user : userTables) {
     if (user.displayName.find(searchTerm) != std::string::npos || user.username.find(searchTerm) != std::string::npos) {
       users.push_back(user);
     }
   }
   return users;
}

