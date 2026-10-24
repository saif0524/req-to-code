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

string enteredPassword, string repeatedPassword -> bool 
    char c : enteredPassword ; 
    char c : repeatedPassword ; 
    int hash1 = 0; 
    for (char c : enteredPassword) { hash1 += static_cast<int>(c); } 
    int hash2 = 0; 
    for (char c : repeatedPassword) { hash2 += static_cast<int>(c); } 
    return hash1 == hash2;

int hash1 = 0, hash2 = 0;
for (char c : enteredPassword) {
    hash1 += static_cast<int>(c);
}
for (char c : repeatedPassword) {
    hash2 += static_cast<int>(c);
}
return (hash1 == hash2);

bool compareHashes(const std::string& password1, const std::string& password2) {
  int hash1 = 0; for (char c : password1) { hash1 += static_cast<int>(c); } int hash2 = 0; for (char c : password2) { hash2 += static_cast<int>(c); } return hash1 == hash2; }

