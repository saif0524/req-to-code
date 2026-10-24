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

double is_in_hc_mode(double current_temp, double desired_temp);
string generate_heating_command(double current_temp, double desired_temp);
void handle_hc_mode(double current_temp, double desired_temp);

double is_in_hc_mode(double current_temp, double desired_temp) {
  return (current_temp <= desired_temp);
  }

string generate_heating_command(double current_temp, double desired_temp) 
    { 
        if (current_temp <= desired_temp) 
        {
            return "HEAT " + to_string(desired_temp);
        }
        else 
        {
            return "";
        }
    },
    

void handle_hc_mode(double current_temp, double desired_temp)
  
  if (is_in_hc_mode(current_temp, desired_temp))
    
    if (current_temp < desired_temp)
      
      return generate_heating_command(current_temp, desired_temp)
    
    else
      
      return generate_cooling_command(current_temp, desired_temp)
  
  // other code if needed

