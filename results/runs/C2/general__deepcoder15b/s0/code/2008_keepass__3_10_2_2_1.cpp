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

void savePassword(UserPassword& user, const string& password);
void enterPassword(UserPassword& user);
void compareAndDisplayError(const string& actualPassword, const string& enteredPassword);

void savePassword(UserPassword& user, const string& password) {
  user->password = password;
}

void enterPassword(UserPassword&) {
  string actual = user->password;
  if (actual != user->password) {
    compareAndDisplayError(actual, user->password);
  }
}

void compareAndDisplayError(const string& actualPassword, const string& enteredPassword) {
  const static std::string errorMessage = "The repeated password must be identical with the actual password. Please enter the correct password.\n"; 
  if (actualPassword != enteredPassword) {
    std::cout << errorMessage << std::endl;
  }
  }

