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

string password: string result: string;
string password: string result: bool;
string password: string result: string;
string password: string result: bool;
string password: string result: bool;

string savePassword(string originalPassword) {
    string encrypted = encrypt(originalPassword);
    return encrypted;
  }

bool passwordValidation(string password) {
    set<char> allowed = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
    string lowerPassword;
    for (char c : password) {
      lowerPassword += tolower(c);
    }
    if (lowerPassword.length() < 8) {
      return false;
    }
    for (char c : lowerPassword) {
      if (allowed.find(c) == string::npos) {
        return false;
      }
    }
    return true;
  }
  

string encrypt(string password) {
string encrypted = encrypt(originalPassword);
return encrypted;
}

bool resetPassword(string originalPassword) {
    string newPassword;
    for (char &c : originalPassword) {
        int offset = c - 'a';
        c = (offset + 10) % 26 + 'a';
        newPassword += c;
    }
    return (newPassword == originalPassword);
}

