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

void update_password(double password);
bool compare_passwords(double stored, double repeat);
void display_message(bool is_correct);

void update_password(double password) {
    double stored = password;
    return;
    }

bool compare_passwords(double stored, double repeat) {
  return stored == repeat;
  }

void display_message(bool is_correct) {
  bool is_match = compare_passwords(...);
  if (!is_match) {
    return std::to_string("the repeated password must be identical with the password");
  } else {
    return std::to_string("password matches");
  }
}

