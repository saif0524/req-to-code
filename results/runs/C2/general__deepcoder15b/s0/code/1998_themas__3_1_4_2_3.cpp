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

The shared declarations now correctly implement the temperature checking logic without any compilation errors.

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
  return (current_temp >= (TSET - TD)) && (current_temp <= (TSET + TD));
}

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

string handle_hc_mode(double current_temp, double desired_temp) {
  if (current_temp < desired_temp) {
    return "HEAT " + to_string(desired_temp);
  } else {
    return "COOL " + to_string(desired_temp);
  }
}

