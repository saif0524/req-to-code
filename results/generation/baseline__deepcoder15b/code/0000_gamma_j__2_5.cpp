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

-> connection;
row -> data;
object formData -> data;

string connection(string driver, string database) {
  string conn = establish_connection(driver, database);
  return conn;
  }

string row_data(string key, string database) {
    return key + "_" + database;
    }

string formData(string formData) {
  vector<string> extracted;
  for (string s : formData) {
    if (s == 

