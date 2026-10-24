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

no additional declarations needed

int calculate_search_time(string query, vector<string> criteria, int max_cases, int max_time);
case_type manage_latest_case(const case_type& current_case, case_type& all_cases);
vector<case_type> retrieve_old_cases(const case_type& current_case, const vector<case_type>& all_cases);
vector<case_type> retrieve_recent_cases(const case_type& current_case, const vector<case_type>& all_cases);
int case_access_count(const vector<case_type>& all_cases, int& new_cases);

int calculate_search_time(string query, vector<string> criteria, int max_cases, int max_time) {
    int num_criteria = criteria.size();
    int time = max_time - (num_criteria > 0 ? num_criteria : 0) * (max_time / num_criteria);
    if (time < 3) time = 3;
    if (time > max_time) time = max_time;
    return time;
}

int manage_latest_case(const case_type& current_case, case_type& all_cases) { return 0; }

vector<case_type> retrieve_old_cases(const case_type& current_case, const vector<case_type>& all_cases) {
  vector<case_type> old_cases;
  for (const case_type& case : all_cases) {
    if (case.added_at() <= two_months_ago) {
      old_cases.push_back(case);
    }
  }
  return old_cases;
  }

vector<case_type> retrieve_recent_cases(const vector<case_type>& all_cases) { 
    date current_date = date(get_current_date()); 
    date two_months_ago = date(current_date.year - 2, current_date.month - 2, 0); 
    vector<case_type> recent_cases; 
    for (const case_type& case : all_cases) { 
        if (case.added_at() != null && case.added_at() <= two_months_ago) { 
            recent_cases.push_back(case); 
        } 
    } 
    return recent_cases; 
  }

int case_access_count(const vector<case_type>& all_cases, int& new_cases) {
    new_cases = 0;
    for (const case_type& case : all_cases) {
    if (case.added_at() != NULL) {
    new_cases++;
    }
    }
    return new_cases;
    }
    

