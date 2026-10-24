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

double calculate_salary(int experience, double base);
job_offer array find_best_job(job_offer array offers);
bool is_woman_eligible(string name, int years);
double calculate_grade(vector<double> assignments, double participation);
vector<organization> list_organizations(string names[], string regions[])];

double calculate_salary(int experience, double base) \
{ \
 return base * (experience + 1); \
 }

double find_best_job(vector<vector<double>> offers) {
  double max_salary = -infinity;
  string best_name;
  string best_location;

  for (const auto& offer : offers) {
    // Extract details from each offer
    // Assuming each job_offer has a 'salary' member
    double salary = offer[0];

    // Compare salaries and update best offer
    if (salary > max_salary) {
      max_salary = salary;
      best_name = offer[1].name;
      best_location = offer[1].location;
    }
  }

  // Create the result JSON
  return { 
    

bool is_woman_eligible(string name, int years) { 
  bool is_woman = false; 
  if (name[0] == 'W' || name[0] == 'w') { 
    is_woman = true; 
  } 
  return is_woman && (years >= 5); 
 }

double calculate_grade(vector<double> assignments, double participation) {
  double sum = 0.0;
  int n = assignments.size();
  for (double a : assignments) {
    sum += a;
  }
  double average = sum / n;
  return average * participation;
  }

vector<organization> list_organizations(const std::array<string, 2>& names, const std::array<string, 2>& regions) {
  vector<organization> list_;
  int n = names.size();
  int m = regions.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      list_.emplace_back(names[i], regions[j]);
    }
  }
  return list_;
  }

