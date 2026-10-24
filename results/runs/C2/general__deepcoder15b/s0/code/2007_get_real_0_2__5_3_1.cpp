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

int count_bugs_reported(std::vector<std::string>& bugs);
long long average_time_to_fix(std::vector<std::string>& bugs, std::long long total_time);
int all_bugs_fixed(std::vector<std::string>& bugs);
int unique_bugs(std::vector<std::string>& bugs);
int all_bugs_fixed_by_time(std::vector<std::string>& bugs, std::long long time_limit);

int count_bugs_reported(std::vector<std::string>& bugs) {
    std::set<std::string> unique_bugs;
    for (const std::string& bug : bugs) {
        unique_bugs.insert(bug);
    }
    return unique_bugs.size();
    }

long long average_time_to_fix(std::vector<std::string>& bugs, std::long long total_time) {
  int num_bugs = bugs.size();
  if (num_bugs == 0) {
    return 0;
  }
  return static_cast<long long>(total_time) / num_bugs;
  }

int all_bugs_fixed(std::vector<std::string>& bugs) { std::set<std::string> fixed_bugs; for (const std::string& bug : bugs) { if (fixed_bugs.find(bug) == fixed_bugs.end()) return 0; } return 1; }

int unique_bugs(std::vector<std::string>& bugs) {
    std::set<std::string> unique_bugs_set;
    for (const std::string& bug : bugs) {
        unique_bugs_set.insert(bug);
    }
    return unique_bugs_set.size();
    }

int all_bugs_fixed_by_time(std::vector<std::string>& bugs, std::long long time_limit) {
  int num_bugs = bugs.size();
  if (num_bugs == 0) {
    return true; // Assuming all bugs (none) are fixed
  }
  double average_time = static_cast<double>(time_limit) / num_bugs;
  return average_time <= time_limit;
  }

