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

string get_acm(string organizationName): string;
string get_IEEE(string organizationName): string;
string get_subgroup(string organizationName, string ACMLink, string IEEELink): string;

string get_acm(string organizationName): string 
    { 
        // Assuming the ACM link is always ACM-XXXX, where XXXX is a number.
        // For example, ACM-2023
        return "ACM-2023"
    }

string get_IEEE(string organizationName): string 
 
  // Check if the organization name ends with ' Engineers' 
  if (organizationName.endsWith(

string get_subgroup(string organizationName, string ACMLink, string IEEELink): string {
    size_t acm_minus_pos = ACMLink.find('-');
    string acm_part = ACMLink.substr(0, acm_minus_pos);
    size_t ieeelink_minus_pos = IEEELink.find('-');
    string ieeelink_substring = IEEELink.substr(ieelink_minus_pos + 1);
    return acm_part + '-' + ieeelink_substring;
}

