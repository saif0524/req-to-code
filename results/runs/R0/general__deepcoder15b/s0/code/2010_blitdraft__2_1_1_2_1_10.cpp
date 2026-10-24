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

std::bool searchUserStatus(std::user* user);
std::pair<std::string, std::string, std::string> getUserDetails(std::user* user);
std::user* searchActiveDirectoryUsers(std::string userID);
std::bool checkUserStatus(std::user* user);

std::bool searchUserStatus(std::user* user)  \ \ \ return user->status == Active;

std::string id, username, password;
    if (user->id) id = user->id; else id = 0; 
    if (user->username) username = user->username; else username = 0; 
    if (user->password) password = user->password; else password = 0; 
    return {id, username, password};

std::user* searchActiveDirectoryUsers(std::string userID) => = if (user = searchUserStatus(user)) = = return user = = else return nullptr = = , where user is obtained from searchUserStatus = = and searchUserStatus is defined as above.

bool checkUserStatus(std::user* user) {
    bool status = searchUserStatus(user);
    return status;
    }
    

