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

hit_counter is a function that takes an int and returns an int. It should count the number of hits. It should be adjusted to handle cases where total_hits is negative.
performance_eval is a function that returns a pair of int and double. It should calculate the average time based on the hits. It should be adjusted to handle cases where average_time is negative.
M_PI should be declared as a const double at the top level. It should be declared as const double pi = M_PI; to make it accessible.
Each function should handle null cases by checking if the input is null before using it.
If invalid input is provided, an exception should be thrown.

int hit_counter(int total_hits);
pair<int, double> performance_eval() return (int total_hits, double average_time);
void content_change(int total_hits);

int hit_counter(int total_hits) {
  if (total_hits < 0) total_hits = 0;  if (total_hits > INT_MAX) total_hits = INT_MAX;  int counter = 0;  while (counter < total_hits) {    counter++;  }  return counter; }

void content_change(int total_hits) { 
  if (total_hits < 0) total_hits = 0; 
  else if (total_hits > INT_MAX) total_hits = INT_MAX; 
  std::ostringstream oss; 
  if (total_hits == 0) { 
    oss << 

