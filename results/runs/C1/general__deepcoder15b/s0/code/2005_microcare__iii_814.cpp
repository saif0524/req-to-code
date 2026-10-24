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

The function correctly counts the number of alphabetic characters in the input string.

string;
string;
int;
int;

string get_vsp_name(const string& input) {
  string vsp_name;
  for (char c : input) {
    if (isalpha(c)) {
      vsp_name = to_string(c);
      break;
    }
  }
  return vsp_name;
  }

string get_submission_date(const string& input) {
  size_t space_pos = input.find('');
  string date = input.substr(space_pos + 1, 1);
  return date;
  }
  

int get_number_of_mentioned_forms(const string& input) {
  int count = 0;
  for (int i = 0; i < input.length(); i++) {
    if (isdigit(input[i])) {
      count += 1;
    }
  }
  return count;
  }
  

int get_number_of_available_forms(const string& input) {
  int count = 0;
  for (char c : input) {
    if (isalpha(c)) {
      count++;
    }
  }
  return count;
  }

