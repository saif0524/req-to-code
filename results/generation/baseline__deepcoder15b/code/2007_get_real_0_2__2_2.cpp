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

double find_best_job(vector<job_offer> offers) {
  double max_salary = -infinity;
  string best_name;
  string best_location;

  for (const job_offer& offer : offers) {
    // Extract details from each offer
    string name = offer.name;
    string location = offer.location;
    double salary = offer.salary;

    // Compare salaries and update best offer
    if (salary > max_salary) {
      max_salary = salary;
      best_name = name;
      best_location = location;
    }
  }

  // Create the result JSON
  return { 
    "reasoning": [
      "Iterate through each job offer to find the one with the highest salary",
      "Compare each offer's salary with the current maximum salary",
      "Update the best offer variables when a higher salary is found",
      "Return the best offer with its details"
    },
    "code": find_best_job,
    "reasoning": [
      "Compare each job offer's salary to find the highest one",
      "Identify the job offer with the highest salary",
      "Return the details of the best job offer"
    ]
  };
}

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

vector<organization> list_organizations(string names[], string regions[])]{
  vector<organization> result;
  int n = names.size();
  int m = regions.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      result.emplace_back(names[i], regions[j]);
    }
  }
  return result;
}

