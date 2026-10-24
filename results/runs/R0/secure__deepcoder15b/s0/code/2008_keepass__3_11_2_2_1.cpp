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

string&* current_password;
string&* current_password, string&* repeated_password bool* result;
string* message;

string&* current_password(string* current_password_value) {
  bool is_correct = (current_password_value == repeated_password);
  if (!is_correct) {
    *message = 

string&* current_password(string* current_password_value, string* repeated_password, bool* result) {
  bool is_correct = (current_password_value == repeated_password);
  if (!is_correct) {
    result = false;
    *message = "the repeated password must be identical with the password";
  } else {
    result = true;
  }
  return current_password_value;
}

string* message() {
  current_password(current_password_value, repeated_password, result);
  if (!result) {
    *message = "the repeated password must be identical with the password";
  } else {
    *message = "";
  }
  return current_password_value;
}

