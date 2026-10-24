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

{#include <vector>}

string get_vsp_name(const claim &claim);
int get_staff_code(const claim &claim);
string get_staff_name(const claim &claim);
string get_staff_type(const claim &claim);
string get qualification(const claim &claim);

string get_vsp_name(const claim &claim) {
  string name = claim.data;
  if (name.empty() || !is_valid_string(name)) {
    return "VSP Name is invalid."
  }
  return name;
  }
  

int getstaff_code(const claim &claim) { size_t codeSize = claim.data.size(); if (codeSize == 0) return 0; string code = claim.data.substr(0, codeSize); if (!is_valid_string(code)) return -1; return code.size() != 0 ? code.size() : 0; }

string getstaff_name(const claim &claim) {
  string name = claim.data;
  if (!is_valid_string(name)) {
    return 

