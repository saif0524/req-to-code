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

vector<double> validate_grades(vector<double> grades);
double calculate_average_grade(vector<double> grades);
int handle_student_id(string student_id);
string process_course_info(const vector<string>& course_info);
string handle_student_records(const vector<string>& student_records);

vector<double> validate_grades(vector<double> grades) {
  for (double grade : grades) {
    if (grade < 0 || grade > 100) {
      return "Grade X is out of range" where X is grade;
    }
  }
  return true;
}

double calculate_average_grade(vector<double> grades) {
  if (grades.empty()) {
    return 0.0;
  }
  double sum = 0.0;
  for (double grade : grades) {
    sum += grade;
  }
  double average = sum / grades.size();
  return average;
  }
  "reasoning": "The function calculates the average grade by summing all grades and dividing by the number of grades. It handles empty vectors by returning 0.0.", "code": "double calculate_average_grade(vector<double> grades) {\nif (grades.empty()) {\nreturn 0.0;\n}
double sum = 0.0;
for (double grade : grades) {
sum += grade;
}
double average = sum / grades.size();
return average;
}"}.

int handle_student_id(string student_id) {
  if (student_id.empty()) {
    return -1;
  }
  try {
    int id = stoi(student_id);
    return id;
  } catch (...) {
    return -1;
  }
}

string process_course_info(const vector<string>& course_info) { 
    for (const auto& s : course_info) { 
        if (s.find(

string handle_student_records(const vector<string>& student_records) {
  if (student_records.empty()) {
    return;
  }
  string student_id_str = student_records[0];
  int student_id = handle_student_id(student_id_str);
  return to_string(student_id);
}

