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

void updatePassword(const std::string& newPassword, const std::string& repeatPassword);
bool validatePassword(const std::string& password, const std::string& repeatPassword);

void updatePassword(const std::string& newPassword, const std::string& repeatPassword) {
  if (!validatePassword(newPassword, repeatPassword)) {
    return false;
  }
  password = newPassword;
  return true;
}

bool validatePassword(const std::string& password, const std::string& repeatPassword) {
  if (!updatePassword(password, repeatPassword)) {
    return false;
  }
  return password == repeatPassword;
}

