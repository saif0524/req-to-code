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

bool is_temperature_below_lower_limit(double temperature, double lo, double tset);
bool is_temperature_above_upper_limit(double temperature, double uo, double tset);
bool is_temperature_equal_to_set_value(double temperature, double tset);
string determine_overtemperature_status(double temperature, double tset, double lo, double uo);
string handle_both_overtemperature_conditions(double temperature, double tset, double lo, double uo);

bool is_temperature_below_lower_limit(double temperature, double lo, double tset) {
  return temperature < (tset - lo);
}

bool is_temperature_above_upper_limit(double temperature, double uo, double tset) {
  double upper_limit = tset + uo;
  return temperature > upper_limit;
}

bool is_temperature_equal_to_set_value(double temperature, double tset) {
  double upper_limit = tset;
  return temperature == upper_limit;
  }

string determine_overtemperature_status(double temperature, double tset, double lo, double uo) {
  double lower_limit = tset - uo;
  double upper_limit = tset + uo;

  if (temperature < lower_limit) {
    return 

string handle_both_overtemperature_conditions(double temperature, double tset, double lo, double uo) {
  double LO = tset - uo;
  double UO = tset + uo;
  if (temperature < LO || temperature > UO) {
    return "The temperature has met both lower and upper overtemperature conditions.\n";
  }
  return "The temperature does not exceed the set limits.\n";
}

