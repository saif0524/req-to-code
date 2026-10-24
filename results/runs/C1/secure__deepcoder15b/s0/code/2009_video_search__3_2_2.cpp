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

Using the greater function for descending order sorting.

string search_term;
string streaming_link;
vector<string> get_search_sites(string database_query);
vector<string> filter_results(const vector<string>& search_results, string filter);
vector<string> sort_results(const vector<string>& search_results);

string search_term(string input) {
  if (!is_string(input)) {
    return string();
  }
  return input.empty() ? string() : input;
  }

string streaming_link(string database_query) {
  vector<string> search_results = get_search_sites(database_query);
  vector<string> filtered = filter_results(search_results, database_query);
  vector<string> sorted = sort_results(filtered);
  vector<string> final_links;
  for (auto& link : sorted) {
    if (contains(link, 

vector<string> get_search_sites(string database_query) \
    { \
      if (string::empty(database_query)) \
      { \
        return vector<string>(); \
      } \
      vector<string> result; \
      string[] parts = split(database_query, '/'); \
      if (parts.empty()) \
      { \
        return result; \
      } \
      for (int i = 1; i < parts.size(); i++) \
      { \
        string part = parts[i]; \
        if (!part.empty() && part.size() > 0) \
        { \
          result.push_back(part); \
        } \
      } \
      return result; \
    }

vector<string> filter_results(const vector<string>& search_results, string filter) {
  vector<string> result;
  for (string s : search_results) {
    if (tolower(s) == tolower(filter)) {
      result.push_back(s);
    }
  }
  return result;
  }

vector<string> sort_results(const vector<string>& search_results) \\ \ 
  vector<string> result; \\ \ \ \n  if (search_results.empty()) \\ \ \n  \ { \\ \n  \ \ \ \ return result; \\ \n } \\ \n \\ \n  sort(result.begin(), result.end(), greater<string>()); \\ \n  return result; \\ \n }

