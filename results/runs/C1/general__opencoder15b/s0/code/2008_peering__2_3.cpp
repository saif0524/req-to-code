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

IdentifyUser(const std::string& user_id);
GetUserMembership(const std::string& user_id);
GetUserContributions(const std::string& user_id);
GetUserPurpose(const std::string& user_id);
GetUserQoS(const std::string& user_id);

std::string IdentifyUser(const std::string& user_id) {
   // Retrieve the user's information from a user database.
   User user = user_database[user_id];

   // Return the user's information in a JSON object.
   return user.ToJson();
}

std::string GetUserMembership(const std::string& user_id) {
    User user = user_database[user_id];
    if (user.IsExplicitMember()) {
       return user.ToJson();
    }
    return "User is not an explicit member of the CDN.";
}

std::string GetUserContributions(const std::string& user_id) {
     User user = user_database[user_id];
     if (user.IsExplicitMember()) {
         return user.ToJson();
     }
     return "User is not an explicit member of the CDN.";
}

std::string GetUserPurpose(const std::string& user_id) {
     User user = user_database[user_id];
     if (user.IsExplicitMember()) {
         return user.ToJson();
     }
     return "User is not an explicit member of the CDN.";
}

std::string GetUserQoS(const std::string& user_id) {
     User user = user_database[user_id];
     if (user.IsExplicitMember()) {
         return user.ToJson();
     }
     return "User is not an explicit member of the CDN.";
}

