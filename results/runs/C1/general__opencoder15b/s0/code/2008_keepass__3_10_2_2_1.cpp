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

void checkPasswords(const std::string& password, const std::string& repeatedPassword);

json j;

bool checkPasswords(const std::string& password, const std::string& repeatedPassword) {
   if (password != repeatedPassword) {
     j = {"reason": "The repeated password must be identical with the password"};
     return false;
   }
   return true;
}

