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

struct userData { string username; string email; string password; bool valid; };

std::bool validateUserID(std::string id);
std::bool validateLogin(std::string username, std::string password);
std::bool validatePassword(std::string password);
std::bool validateEmail(std::string email);
std::bool validateLoginAndPassword(std::string username, std::string password, std::string email);

bool validateUserID(std::string id) {
  if (id.empty()) {
    return false;
  }
  bool has_letter = false;
  for (char c : id) {
    if (isalpha(c)) {
      has_letter = true;
      break;
    }
  }
  if (!has_letter) {
    return false;
  }
  return true;
}

bool validateLogin(std::string username, std::string password) {
  if (username.empty()) {
    return false;
  }
  for (char c : username) {
    if (!isalpha(c)) {
      return false;
    }
  }
  if (password.length() < 6) {
    return false;
  }
  for (char c : password) {
    if (!isalpha(c) && !isnumeric(c)) {
      return false;
    }
  }
  return true;
  }
  

bool validatePassword(std::string password) {
    if (password.length() < 8) {
        return false;
    }
    for (char c : password) {
        if (!isalnum(c)) {
            return false;
        }
    }
    return true;
    },
    

bool validateEmail(std::string email) { if (email == std::string::npos || email.empty()) return false; size_t local_start = email.find('@'); std::string local_part = (local_start != std::string::npos) ? email.substr(local_start + 1) : email; if (local_part.empty()) return false; for (char c : email) if (std::isalpha(c)) return true; return false; }

bool validateLoginAndPassword(std::string username, std::string password, std::string email) {
  if (!validateUserID(username)) return false;
  if (!validatePassword(password)) return false;
  if (!validateEmail(email)) return false;
  return true;
  }
  

