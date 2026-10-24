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

void track_hit(const std::string& student_id, int hit_count);
void evaluate_hits(const std::string& student_id);
std::string get_student_id();
int get_hit_count();
int get_time_spent();

void track_hit(const std::string& student_id, int hit_count) {
  shared->hit_count[student_id] += hit_count;
  return json("hit tracked successfully");
}

void evaluate_hits(const std::string& student_id) {
  if (shared->hit_count.find(student_id) == shared->hit_count.end()) {
    return json("student ID not found");
  }
  int total_hit_count = 0;
  for (const auto& hit : shared->hit_count[student_id]) {
    total_hit_count += hit.second;
  }
  if (total_hit_count > 100) {
    // Make changes to the website's content, design, and navigation
    return json("changes made successfully");
  } else {
    return json("no changes made");
  }
}

std::string get_student_id() { return shared->student_id; }

int get_hit_count() { return shared->hit_count[get_student_id()]; }

int get_time_spent() { return shared->time_spent[get_student_id()]; }

