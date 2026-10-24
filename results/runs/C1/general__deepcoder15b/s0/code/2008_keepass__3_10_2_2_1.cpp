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
  user->password = password;  // Ensure that the password is correctly stored in the user's password field.
  }

void enterPassword(UserPassword&) {
    string actual = user->password;
    if (actual != enteredPassword) {
        compareAndDisplayError(actual, enteredPassword);
    }
}

