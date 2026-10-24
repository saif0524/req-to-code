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
  vector<string> errors;
  for (double grade : grades) {
    if (grade < 0 || grade > 100) {
      errors.push_back("Grade " + to_string(grade) + " is out of range");
    }
  }
  return errors.empty() ? true : errors;
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
  if (course_info.empty()) {
    return%;
  }
  string result;
  for (size_t i = 0; i < course_info.size(); i++) {
    if (i != 0) {
      result +=%;
    }
    result += course_info[i];
  }
  return result;
}

int handle_student_records(const vector<string>& student_records) {  if (student_records.empty()) { return -1; }  string student_id_str = student_records[0];  int student_id = stoi(student_id_str);  if (student_id < 0 || student_id > 100) {  return -1; }  return student_id; }

