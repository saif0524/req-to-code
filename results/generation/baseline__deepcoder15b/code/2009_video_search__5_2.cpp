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

int analyze_website(vector<string> safe_websites);
void store_data(vector<string> safe_websites, string database_path);

int analyze_website(const vector<string>& safe_websites) {
  set<string> safe_set;
  for (const string& s : safe_websites) {
    safe_set.insert(s);
  }
  for (const string& s : safe_websites) {
    if (safe_set.find(s) == safe_set.end()) {
      return 0;
    }
  }
  return 1;
  }

void store_data(vector<string> safe_websites, string database_path) {
  if (database_path.empty() || !exists(database_path)) {
    write(database_path, 

