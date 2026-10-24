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

string enteredPassword, string repeatedPassword -> bool;
string enteredPassword -> string;
string enteredPassword, string repeatedPassword -> bool;

bool comparePasswords(string enteredPassword, string repeatedPassword) {
  return enteredPassword == repeatedPassword;
}

std::string computeHash(const std::string& password) {
  int hash = 0;
for (char c : password) {
hash += static_cast<int>(c);
}
return std::to_string(hash);
}

bool compareHashes(const std::string& enteredPassword, const std::string& repeatedPassword) {
  int hash1 = 0; for (char c : enteredPassword) { hash1 += static_cast<int>(c); }
  int hash2 = 0; for (char c : repeatedPassword) { hash2 += static_cast<int>(c); }
  return hash1 == hash2;
}

