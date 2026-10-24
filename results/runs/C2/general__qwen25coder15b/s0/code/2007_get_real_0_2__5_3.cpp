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

void track_hit(const std::string& student_id, const std::string& content_id);
void evaluate_hits(const std::string& student_id);
int get_hit_count(const std::string& student_id);
int get_total_hit_count();
double get_average_hit_rate();

void track_hit(const std::string& student_id, const std::string& content_id) {  hit_counts[student_id][content_id]++; }

void evaluate_hits(const std::string& student_id) {
  int total_hits = get_total_hit_count();
  int hit_count = get_hit_count(student_id);
  double average_hit_rate = static_cast<double>(hit_count) / total_hits;

  if (average_hit_rate < 0.5) {
    // Suggest content changes
    // Suggest design improvements
    // Suggest navigation adjustments
  } else if (average_hit_rate > 0.8) {
    // Suggest no changes or minimal changes
  } else {
    // Suggest moderate changes
  }
}

struct HitCount {  int count(const std::string& content_id) const { return inner_map.count(content_id); }  private:  std::map<std::string, int> inner_map; };

struct HitCount {  int count(const std::string& content_id) const { return inner_map.count(content_id); }  private:  std::map<std::string, int> inner_map; };

double get_average_hit_rate() {  int total_hits = get_total_hit_count();  int total_students = hit_counts.size();  if (total_students == 0) {    return 0.0;  }  return static_cast<double>(total_hits) / total_students; }

