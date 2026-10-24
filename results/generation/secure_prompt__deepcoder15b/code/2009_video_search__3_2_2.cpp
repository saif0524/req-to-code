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

string search_term;
string streaming_link;
vector<string> get_search_sites(string database_query);
vector<string> filter_results(const vector<string>& search_results, string filter);
vector<string> sort_results(const vector<string>& search_results);

string search_term(string input) {
  if (!is_string(input)) {
    return string();
  }
  if (input.empty()) {
    return string();
  }
  return input;
  }

string streaming_link(string database_query) {
  vector<string> search_results = get_search_sites(database_query);
  vector<string> streaming_links = search_results; // Assuming search_results contains streaming links
  return streaming_links;
  }
  

vector<string> get_search_sites(string database_query) 
    { 
        vector<string> result; 
        if (string::empty(database_query)) 
        {
            return result; 
        }
        // Split the query by '/'
        string[] parts = split(database_query, '/');
        // The first part is the search term, ignore it
        for (int i = 1; i < parts.size(); i++)
        {
            result.push_back(parts[i]);
        }
        return result;
    },
    

vector<string> filter_results(const vector<string>& search_results, string filter) {
  vector<string> result;
  for (string s : search_results) {
    string lower_s = tolower(s);
    string lower_filter = tolower(filter);
    if (lower_s == lower_filter) {
      result.push_back(s);
    }
    // Alternatively, if preserving case, could use islower or other methods
  }
  return result;
  }
  

vector<string> sort_results(const vector<string>& search_results) \ \ \ { \ \ \ \ \ \ vector<string> result; \ \ \ \ \ \ if (search_results.empty()) \ \ \ \ \ \ \ { \ \ \ \ \ \ \ return result; \ \ \ \ \ \ } \ \ \ \ \ \ \ // Sort in ascending order \ \ \ \ \ \ \ sort(result.begin(), result.end()); \ \ \ \ \ \ // Reverse to get descending order \ \ \ \ \ \ \ reverse(result.begin(), result.end()); \ \ \ \ \ \ \ return result; \ \ \ \ \ \ \ }

