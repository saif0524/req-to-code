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

void onPasswordChanged(const QString &newPassword);
void onRepeatPasswordChanged(const QString &newRepeatPassword);

void onPasswordChanged(const QString &newPassword) {
    onRepeatPasswordChanged(newPassword);
    // JSON object with 'code' key and 'Passwords are identical' value
}

void onRepeatPasswordChanged(const QString &newRepeatPassword) {
     onPasswordChanged(newRepeatPassword);
     // JSON object with 'code' key and 'Passwords are identical' value
}

