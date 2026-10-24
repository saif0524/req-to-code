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

string connection_string; return connection_object;
vector<string> tables;

string create_connection_string(const string& keywords) {
  size_t pos = keywords.find(':', 0);
  if (pos != string::npos) {
    return keywords.substr(0, pos);
  }
  return string();
}

vector<string> create_connection_string(const string& keywords) {
  vector<string> valid_tables;
  istringstream iss(kkeywords);
  string keyword;
  while (iss >> keyword) {
    if (isalpha(keyword[0]) || isalpha(keyword[0]).islower()) {
      valid_tables.push_back(keyword);
    }
  }
  return valid_tables;
}

