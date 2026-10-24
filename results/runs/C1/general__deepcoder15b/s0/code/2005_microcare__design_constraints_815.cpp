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

string get_vsp_name(string vsp_name);
string get_date(string input_date);
int get_num_claims(string input_num_claims);
int get_num_available_forms(vector<string> mentioned_forms);
string generate_receipt(string vsp_name, string input_date, int input_num_claims, int input_num_available_forms);

string get_vsp_name(string vsp_name) {
    return vsp_name;
    }

    

string get_date(string input_date) {
  size_t dot_pos = input_date.find('-');
  string date_str = input_date.substr(0, dot_pos + 1);

  size_t month_pos = date_str.find('/');
  string year_str = date_str.substr(0, month_pos);
  string month_str = date_str.substr(month_pos + 1, 2);
  string day_str = date_str.substr(month_pos + 3);

  int year = stoi(year_str);
  int month = stoi(month_str);
  int day = stoi(day_str);

  if (month < 1 || month > 12) {
    return "Invalid date"
  }

  switch (month) {
    case 1: // January
      if (day < 31) return "Invalid date"
      else return "Valid date"
    case 2: // February
      if (day < 29) return "Invalid date"
      else return "Valid date"
    case 3: // March
      if (day < 31) return "Invalid date"
      else return "Valid date"
    case 4: // April
      if (day < 30) return "Invalid date"
      else return "Valid date"
    case 5: // May
      if (day < 31) return "Invalid date"
      else return "Valid date"
    case 6: // June
      if (day < 30) return "Invalid date"
      else return "Valid date"
    case 7: // July
      if (day < 31) return "Invalid date"
      else return "Valid date"
    case 8: // August
      if (day < 31) return "Invalid date"
      else return "Valid date"
    case 9: // September
      if (day < 30) return "Invalid date"
      else return "Valid date"
    case 10: // October
      if (day < 31) return "Invalid date"
      else return "Valid date"
    case 11: // November
      if (day < 30) return "Invalid date"
      else return "Valid date"
    case 12: // December
      if (day < 31) return "Invalid date"
      else return "Valid date"
  }

  return date_str
  }

string get_vsp_name(string vsp_name) {
  return vsp_name;
  }

int get_num_available_forms(vector<string> mentioned_forms) {
  return mentioned_forms.size();
}

