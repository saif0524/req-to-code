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

The code does not require any additional declarations beyond what is provided in the answer.

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
size_t first_space = input.find('');
if (first_space != string::npos) {
string date = input.substr(first_space + 1);
return date;
} else {
return "Invalid input";
}
}

int get_number_of_mentioned_forms(const string& input) {
  if (input.empty()) {
    return 0;
  }
  int count = 0;
  for (char c : input) {
    if (isalpha(c)) {
      count += 1;
    }
  }
  return count;
  },
  

int get_number_of_available_forms(const string& input) {
  int count = 0;
  for (char c : input) {
    count++;
  }
  return count;
  }

