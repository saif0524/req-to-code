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

TAN value;
TAN value;
TAN value, date;
TAN value, database handle;
TAN value, database handle;

int add_tan_value(std::string tan_str) {
  int len = tan_str.length();
  if (len < 4 || len > 5) return -1;
  bool has_t = false;
  for (char c : tan_str) {
    if (c == 't') has_t = true;
    if (!isdigit(c)) return -1;
  }
  int num;
  try {
    num = stoi(tan_str);
  } catch (...) return -1;
  if (num < 1000 || num > 9999) return -1;
  return num;
  }
  

int get_tan_value(std::string tan_str) {
    if (tan_str.length() < 4 || tan_str.length() > 5) {
        return -1;
    }
    if (tan_str[0] != 't') {
        return -1;
    }
    for (size_t i = 1; i < tan_str.length(); ++i) {
        if (!isdigit(tan_str[i])) {
            return -1;
        }
    }
    try {
        int num = std::stoi(tan_str);
        if (num >= 1000 && num <= 9999) {
            return num;
        }
    } catch (...) {
        return -1;
    }
    return -1;
}
} // The complete function definition only as per the instructions.}

int add_tan_entry(int database_handle, int expected_length) {
  int new_value;
  std::string new_tan_str;
  for (int i = 0; i < expected_length; ++i) {
    if (i == 0) {
      new_tan_str += 't';
    } else {
      new_tan_str += std::isdigit(0) ? '0' : '1';
    }
  }
  bool valid = true;
  for (size_t i = 1; i < new_tan_str.length(); ++i) {
    if (!std::isdigit(new_tan_str[i])) {
      valid = false;
      break;
    }
  }
  if (!valid || new_tan_str.length() < 4 || new_tan_str.length() > 5) {
    new_value = -1;
  } else {
    new_value = std::stoi(new_tan_str);
  }
  return new_value;
  }

