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

.cpp

std::pair<bool, std::pair<std::string, std::string>> validate_username_password(std::string username, std::string password, std::string url);

pair<bool, pair<string, string>> validate_username_password(string username, string password, string url) {
    if (invalid_username(username)) return make_pair(false, make_pair(0, 0));
    if (invalid_password(password, url)) return make_pair(false, make_pair(0, 0));
    return make_pair(true, make_pair(password, url));
}

