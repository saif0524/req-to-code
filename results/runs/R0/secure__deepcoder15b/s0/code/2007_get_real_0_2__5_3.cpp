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

hit_counter uses int, performance_eval uses pair<int, double>, and any constants like M_PI are declared.

int hit_counter(int total_hits);

int hit_counter(int total_hits) {
  if (total_hits < 0) total_hits = 0;
  if (total_hits > INT_MAX) total_hits = INT_MAX;
  int counter = 0;
  while (counter < total_hits) {
    counter++;
  }
  return counter;
  }
  

