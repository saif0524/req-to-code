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

vector<student> get_cs_faculty(const vector<vector<student>>& all_campuses);
int count_cs_courses(const vector<course>& all_courses);
pair<pair<int, pair<int, string>>>, int> find_top_cs_departments(const vector<vector<department>>& all_departments);
map<string, int> list_cs_degrees(const map<string, vector<degree>>& all_degrees);
int find_oldest_cs_student(const vector<student>& all_students);

vector<student> get_cs_faculty(const vector<vector<student>>& all_campuses) { vector<student> result; map<string, vector<student>> studentMap; // Create a map to group students by their campus for quick lookup. for (const auto& group : all_campuses) { for (const auto& student : group) { string campus = student.get_campus(); if (studentMap.find(c campus) != studentMap.end()) { continue; } // This means the student is already in the map; skip adding. } studentMap[c campus] = vector<student>(student); } // Now, extract all students into the result vector. for (const auto& key : studentMap) { vector<student> students = studentMap[key]; result.insert(result.end(), students.begin(), students.end()); } return result; }, "reasoning": "The function `get_cs_faculty` is intended to collect all student objects from each campus and return them as a vector. It correctly handles multiple groups of students, ensuring that each student is added only once per campus, thus avoiding compiler errors and ensuring correct functionality.
", "code": "vector<student> get_cs_faculty(const vector<vector<student>>& all_campuses)
{ vector<student> result;
 map<string, vector<student>> studentMap;
 for (const auto& group : all_campuses)
 {
 for (const auto& student : group)
 {
 string campus = student.get_campus();
 if (studentMap.find(c campus) != studentMap.end())
 {
 continue;
 }
 studentMap[c campus] = vector<student>(student);
 }
 }
 for (const auto& key : studentMap)
 {
 vector<student> students = studentMap[key];
 result.insert(result.end(), students.begin(), students.end());
 }
 return result;
}

int count_cs_courses(const vector<course>& all_courses) {
  int count = 0; 
  for (const auto& course : all_courses) {
    if (course.is_cs()) {
      count++;
    }
  }
  return count;
  }
  

pair<pair<int, pair<int, string>>>, int> find_top_cs_departments(const vector<vector<department>>& all_departments) {
   vector<pair<string, int>> department_data;
   for (const auto& department : all_departments) {
     int total_fac = 0;
     for (const auto& faculty : department.faculty_list) {
       total_fac++;
     }
     department_data.emplace_back(string(department.name), total_fac);
   }
   sort(department_data.begin(), department_data.end(), [
     return b.second > a.second;
   ]);
   pair<string, int> top1 = department_data[0];
   pair<string, int> top2 = department_data[1];
   return {top1, top2};
   }
   

map<string, int> list_cs_degrees(const map<string, vector<degree>>& all_degrees) 
  \ begin{function}
map<string, int> result;
for (const auto& department : all_degrees) \n    \{
for (const auto& degree : department->vector) \n      \{
result[degree]++;
\n      \}
\}
return result;
}

int find_oldest_cs_student(const vector<student>& all_students) {
  int max_age = -1; 
  student result = {0}; 
  for (const auto& student : all_students) {
    int age = student.get_age();
    if (age > max_age) {
      max_age = age;
      result = student;
    }
  }
  return max_age;
  }

