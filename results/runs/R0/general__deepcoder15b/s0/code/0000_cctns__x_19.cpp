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

int calculate_search_time(string query, vector<string> criteria, int max_cases, int max_time);
vector<case_type> retrieve_old_cases(const case_type& current_case, const vector<case_type>& all_cases);
vector<case_type> retrieve_recent_cases(const case_type& current_case, const vector<case_type>& all_cases);

int calculate_search_time(string query, vector<string> criteria, int max_cases, int max_time) {
    int num_criteria = criteria.size();
    int time = max_time - (num_criteria > 0 ? num_criteria : 0) * (max_time / num_criteria);
    if (time < 3) time = 3;
    if (time > max_time) time = max_time;
    return time;
}

vector<case_type> retrieve_old_cases(const case_type& current_case, const vector<case_type>& all_cases) {
  vector<case_type> old_cases;

  // Get the current date
  date current_date = date{current_date.year, current_date.month, current_date.day};

  // Subtract 2 months to get two_months_ago
  date two_months_ago = date(current_date.year - 2, current_date.month - 2, 0);

  // Iterate through each case and collect those added before two_months_ago
  for (const case_type& case : all_cases) {
    if (case.added_at() < two_months_ago) {
      old_cases.push_back(case);
    }
  }

  return old_cases;
  }

vector<case_type> retrieve_recent_cases(const case_type& current_case, const vector<case_type>& all_cases) {
  // Get the current date
  date current_date = date{current_date.year, current_date.month, current_date.day};

  // Calculate two months ago
  date two_months_ago = date(current_date.year - 2, current_date.month - 2, 0);

  // Collect all cases added before or on two_months_ago
  vector<case_type> recent_cases;
  for (const case_type& case : all_cases) {
    if (case.added_at() != null && case.added_at() <= two_months_ago) {
      recent_cases.push_back(case);
    }
  }

  return recent_cases;
  }
  

