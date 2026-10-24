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

vector<int> test_function(vector<int> data, bool condition);
void demonstration_function(int x, int y);
vector<int> analysis_function(vector<int> data);
bool inspection_function(vector<int> data);

vector<int> test_function(vector<int> data, bool condition) { 
  vector<int> collected; 
  for (int num : data) { 
    if (condition(num)) { 
      collected.push_back(num); 
    } 
  } 
  if (collected.empty()) { 
    return true; 
  } 
  for (int num : collected) { 
    if (num % 2 != 0) { 
      return false; 
    } 
  } 
  return true; 
 }

void demonstration_function(int x, int y) { 
  int result = x + y; 
  if (result == 0) { 
    return true; 
  } 
  return false; 
  }

vector<int> analysis_function(vector<int> data) 
    { 
        vector<int> result; 
        int sum = 0; 
        for (int num : data) 
        { 
            sum += num; 
        } 
        result.push_back(sum); 
        return result; 
    }

bool inspection_function(vector<int> data) {
  if (data.empty()) return true; 
  int min = *min_element(data.begin(), data.end()); 
  int max = *max_element(data.begin(), data.end()); 
  for (int num : data) {
    if (num < min || num > max) {
      return false;
    }
  }
  return true;
  }
  

