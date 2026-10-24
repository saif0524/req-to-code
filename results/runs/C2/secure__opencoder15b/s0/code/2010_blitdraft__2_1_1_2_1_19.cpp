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

bool validate_user_input(const User& user);

bool validate_user_input(const User& user) { 
    if (user.name.empty()) { 
     return false; 
    } 
    if (user.email.empty()) { 
     return false; 
    } 
    if (user.password.empty()) { 
     return false; 
    } 
    return true; 
}

