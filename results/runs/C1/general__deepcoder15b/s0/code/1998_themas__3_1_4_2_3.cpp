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

You don't need to add any new declarations for this function. The main issue is in the function's condition.

double is_in_hc_mode(double current_temp, double desired_temp);
double is_in_lo_mode(double current_temp);
string generate_heating_command(double current_temp, double desired_temp);
string generate_cooling_command(double current_temp, double desired_temp);
void handle_hc_mode(double current_temp, double desired_temp);

double is_in_hc_mode(double current_temp, double desired_temp) {
  return (current_temp <= desired_temp);
  }

double is_in_lo_mode(double current_temp) 
    { 
        double TSET, TD; 
        double LT = TSET - TD; 
        double UT = TSET + TD; 
        return (current_temp >= LT) && (current_temp <= UT); 
    },
    

string generate_heating_command(double current_temp, double desired_temp) 
    { 
        if (current_temp < desired_temp) 
        { 
            return "HEAT " + to_string(desired_temp); 
        } 
        else 
        { 
            return ""; 
        } 
    }

string generate_cooling_command(double current_temp, double desired_temp) {
  if (current_temp < desired_temp) {
    return "COOL " + to_string(desired_temp);
  } else {
    return "";
  }
}

void handle_hc_mode(double current_temp, double desired_temp) {
  if (current_temp < desired_temp) {
    return generate_heating_command(current_temp, desired_temp);
  } else {
    return generate_cooling_command(current_temp, desired_temp);
  }
}

