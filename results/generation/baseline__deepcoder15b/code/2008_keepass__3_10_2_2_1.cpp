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

void enterPassword(UserPassword& user) {
    string actual = user->password;
    if (actual != enteredPassword) {
        compareAndDisplayError(actual, enteredPassword);
    }
}

void compareAndDisplayError(const string& actualPassword, const string& enteredPassword) {
    if (actualPassword.size() != enteredPassword.size()) {
        return 

