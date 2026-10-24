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

bool include_search;
void process_data(int size, string& date, string& file_size, string& link);
void search(int seed, int peer, string file_path);

bool include_search(int include_search) {
  if (include_search) {
    reference_count++;
  } else {
    reference_count--;;
  }
  return include_search;
  }

void process_data(int size, string& date, string& file_size, string& link) {
  vector<string> data = {date, file_size, link};
  sort(data.begin(), data.end());
  return make_json(

void search(int seed, int peer, string file_path) {
  vector<string> temp;
  string search_term;
  
  search_term = to_string(seed) + 

