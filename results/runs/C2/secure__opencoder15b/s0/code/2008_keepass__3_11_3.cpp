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

void updateRepeatPassword(const std::string& new_password);
bool validatePassword(const std::string& password);

void updateRepeatPassword(const std::string& new_password) { 
  std::string repeat_password; 
  // Copy the new password to the repeat password field. 
  repeat_password = new_password; 
}

bool validatePassword(const std::string& password) { 
  if (password.empty()) { 
    return false; 
  } 
  std::string repeat_password; 
  updateRepeatPassword(password); 
  return (password == repeat_password); 
}

