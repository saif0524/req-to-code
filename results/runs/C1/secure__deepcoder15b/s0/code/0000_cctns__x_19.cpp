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

string search(string search_terms, vector<string> results);
string retrieve_past_cases(string time_limit);
string retrieve_old_cases(string time_limit);
string handle_search(string search_term, vector<string> search_terms);
string handle_retrieval(string time_limit);

string search(string search_terms, vector<string> results) {
    // Convert results to a set for efficient lookups
    set<string> result_set(results.begin(), results.end());
    vector<string> result_list;
    if (search_terms.empty()) {
        return result_list;
    }
    for (string term : search_terms) {
        if (result_set.find(term) != result_set.end()) {
            result_list.push_back(term);
        }
    }
    return result_list;
}

string search(string search_terms, vector<string> results) { // Convert results to a set for efficient lookups.
  set<string> result_set(results.begin(), results.end());
  vector<string> result_list;
  for (const string& term : search_terms) {
    if (result_set.find(term) != result_set.end()) {
      result_list.push_back(term);
    }
  }
  return result_list;
 } 

string retrieve_old_cases(string time_limit) {
  int time_limit_in_seconds;
  if (time_limit.empty()) {
    return -1;
  }
  
  int days = stoi(time_limit.substr(0, 2));
  int hours = stoi(time_limit.substr(1, 2));
  int minutes = stoi(time_limit.substr(2, 2));
  int seconds = stoi(time_limit.substr(3, 2));
  
  time_limit_in_seconds = days * 86400 + hours * 3600 + minutes * 60 + seconds;

  for (const auto& case : cases) {
    if (case.last_accessed_time > time_limit_in_seconds) {
      return case;
    }
  }
  
  return -1;
  }
  

string handle_retrieval(string time_limit) {
  // Convert time_limit from string to seconds
  int time_limit_in_seconds;
  if (time_limit.empty()) {
    return -1;
  }
  // Assuming time_limit is in days
  int days = stoi(time_limit.substr(0, 2));
  int hours = stoi(time_limit.substr(1, 2));
  int minutes = stoi(time_limit.substr(2, 2));
  int seconds = stoi(time_limit.substr(3, 2));
  time_limit_in_seconds = days * 86400 + hours * 3600 + minutes * 60 + seconds;

  // Iterate through all cases
  for (const auto& case : cases) {
    if (case.last_accessed_time <= time_limit_in_seconds) {
      return case.case_number;
    }
  }

  // If no cases found
  return -1;
  }
  "

