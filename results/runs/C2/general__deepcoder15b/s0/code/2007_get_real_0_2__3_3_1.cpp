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

global_time is a static double type variable.
Note: The vector usage has been corrected to use double variables.

vector<string> project_scores, double& total_time, double& average_score;
vector<int> current_location, int direction, vector<int>& new_location;
vector<double> activity_scores, double total_score;
double prev_progress, double activity, double& new_progress;

vector<int> current_location, int direction, vector<int>& new_location

together; // Do not use global mutable state unless the requirement forces it
// Step 1: Initialize current_location to empty
vector<int> current_location, int direction, vector<int>& new_location

// Step 2: Create a new location vector
vector<int> new_location_current;

// Step 3: For each element in current_location, apply the direction
for (int i = 0; i < new_location_current.size(); i++) {
  if (direction == 1) {
    new_location_current[i] = new_location_current[i] + 1;
  } else if (direction == -1) {
    new_location_current[i] = new_location_current[i] - 1;
  } else {
    new_location_current[i] = new_location_current[i];
  }
}

// Step 4: Assign new_location_current to new_location
new_location = new_location_current;

// Step 5: Return new_location
return new_location;

vector<double> activity_scores, double total_score:
// Calculate total score based on activity scores
// Initialize activity_scores to empty
vector<double> activity_scores, double total_score
{
// Calculate total score based on activity scores
// Initialize activity_scores to empty
vector<double> activity_scores, double total_score
{
// Step 1: Initialize total_score to 0
double total_score = 0.0;
// Step 2: Iterate through each element in activity_scores\n// Step 3: Add each element to total_score\n// Step 4: Return total_score\nreturn {total_score};}
vector<double> activity_scores, double total_score:\n// Calculate total score based on activity scores\n// Initialize activity_scores to empty\nvector<double> activity_scores, double total_score\n{
// Step 1: Initialize total_score to 0\ndouble total_score = 0.0;
// Step 2: Iterate through each element in activity_scores\n// Step 3: Add each element to total_score\n// Step 4: Return total_score\nreturn {total_score};}
vector<double> activity_scores, double total_score:\n// Calculate total score based on activity scores\n// Initialize activity_scores to empty\nvector<double> activity_scores, double total_score\n{
// Step 1: Initialize total_score to 0\ndouble total_score = 0.0;
// Step 2: Iterate through each element in activity_scores\n// Step 3: Add each element to total_score\n// Step 4: Return total_score\nreturn {total_score};}

double prev_progress(double prev_progress, double activity, double& new_progress) {
    new_progress = prev_progress + activity;
    return new_progress;
}

