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

VSP_ERROR_NAME

string get_vsp_name(const claim &claim);
int get_staff_code(const claim &claim);
string get_staff_name(const claim &claim);
string get qualification(const claim &claim);

string get_vsp_name(const claim &claim) {
  string name = claim.data;
  if (name.empty() || !is_valid_string(name)) {
    return "VSP Name is invalid."
  }
  return name;
  }
  

int getstaff_code(const claim &claim) {
  string code = claim.data;
  if (code.empty() || !is_valid_string(code)) {
    return 

string getstaff_name(const claim &claim) {
  if (claim.data.empty() || !is_valid_string(claim.data)) {
    return 

string get qualification(const claim &claim)  // Extracts the qualification from the claim and validates it.
  if (claim.data.empty() || !is_valid_string(claim.data)) {
    return 

