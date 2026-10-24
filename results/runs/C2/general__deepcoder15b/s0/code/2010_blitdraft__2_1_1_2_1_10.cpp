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

bool searchUserStatus(std::user* user) {
    return user->status;
    }

std::pair<std::string, std::string> getUserDetails(std::user* user)
    { 
        std::string id = user->getID();
        std::string username = user->username();
        std::string password = user->password();

        auto& details = std::make_pair(username, password);
        return std::make_pair(id, details);
    }

std::user* searchActiveDirectoryUsers(std::string userID) {
    for (auto& dir_user : activeDirectory) {
        if (dir_user->getID() == userID) {
            return dir_user;
        }
    }
    return nullptr;

bool checkUserStatus(std::user*) {
    return searchUserStatus(user*);
}

