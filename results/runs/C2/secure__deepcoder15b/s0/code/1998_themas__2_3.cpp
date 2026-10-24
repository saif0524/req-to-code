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

struct event { string name; }
The function generate alert uses to_string, which requires <string>, but it's not included in the shared declarations. We need to add it.

int read_sensor(int type, int reading);
int calculate_temp(vector<int> readings);
string generate alert(int current, int threshold);
string generate_report(const vector<event>& data);
void update_status(const vector<event>& data);

int read_sensor(int type, int reading) {
  if (type < 1 || type > 2) {
    return -1;
  }
  if (reading < 0 || reading > 100) {
    return -1;
  }
  return reading;
  }
  

int calculate_temp(vector<int> readings) {
  if (readings.empty()) {
    return 0;
  }
  int sum = 0;
  for (int reading : readings) {
    sum += reading;
  }
  double average = static_cast<double>(sum) / readings.size();
  return static_cast<int>(average);
}

string generate alert(int current, int threshold) { if (current > threshold) { return "Current temperature "+to_string(current)+" exceeds the threshold "+to_string(threshold); } return; }

string generate_report(const vector<event>& data) 
    { 
        string report; 
        for (const event& e : data) 
        { 
            report += to_string(e.name); 
        } 
        return report; 
    }

void update_status(const vector<event>& data) { string report; for (const event& e : data) { report += to_string(e.name); } return; }

