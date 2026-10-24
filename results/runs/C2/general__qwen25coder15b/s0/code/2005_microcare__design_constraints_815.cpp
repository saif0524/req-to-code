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

std::string get_current_date();
std::string get_vsp_name();
std::vector<int> get_available_forms();
bool validate_claim_entry(const std::string& date, const std::string& vsp_name, const std::vector<int>& available_forms, const std::vector<int>& claimed_forms);
void print_receipt(const std::string& vsp_name, const std::string& date, int claimed_forms, int available_forms);

std::string get_current_date() {
  return std::chrono::system_clock::now().time_since_epoch().count() / 86400000000ULL + '0000-01-01';
}

std::string get_vsp_name() {  return "VSP Master Name"; }

std::vector<int> get_available_forms() {  return {1, 2, 3, 4, 5}; }

bool validate_claim_entry(const std::string& date, const std::string& vsp_name, const std::vector<int>& available_forms, const std::vector<int>& claimed_forms) {
  if (date != get_current_date()) {
    return false; // Date mismatch
  }
  if (vsp_name != get_vsp_name()) {
    return false; // VSP name mismatch
  }
  if (available_forms.size() < claimed_forms.size()) {
    return false; // Available forms are less than claimed forms
  }
  if (available_forms.size() > claimed_forms.size()) {
    return false; // Available forms are more than claimed forms
  }
  return true; // All checks pass
}

void print_receipt(const std::string& vsp_name, const std::string& date, int claimed_forms, int available_forms) {
  if (date != get_current_date() || vsp_name != get_vsp_name()) {
    std::cerr << "Error: Date and VSP name mismatch" << std::endl;
    return;
  }
  std::cout << "VSP Name: " << vsp_name << std::endl;
  std::cout << "Date of Submission: " << date << std::endl;
  std::cout << "No of Claims Mentioned: " << claimed_forms << std::endl;
  std::cout << "No of Claims Available: " << available_forms << std::endl;
}

