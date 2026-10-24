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
bool validate_claim_entry(std::string date, std::string vsp_name, std::vector<int> available_forms, std::vector<int> claimed_forms);
void print_receipt(std::string vsp_name, std::string date, int claimed_forms, int available_forms);

std::string get_current_date() {
  auto now = std::chrono::system_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  return std::ctime(&time);
}

std::string get_vsp_name() {  return shared_data.vsp_master[vsp_name]; }

std::vector<int> get_available_forms() {  return shared_data.vsp_master[vsp_name]; }

bool validate_claim_entry(std::string date, std::string vsp_name, std::vector<int> available_forms, std::vector<int> claimed_forms) {
  if (date != get_current_date()) {
    return false; // Date mismatch
  }
  if (vsp_name.empty()) {
    return false; // VSP name is empty
  }
  if (!std::all_of(available_forms.begin(), available_forms.end(), [](int form) { return std::isdigit(form); })) {
    return false; // Available forms are not numeric
  }
  if (claimed_forms.size() != available_forms.size()) {
    return false; // Number of claimed forms does not match available forms
  }
  return true; // All checks pass
}

void print_receipt(std::string vsp_name, std::string date, int claimed_forms, int available_forms) {
  if (date != get_current_date()) {
    return;
  }
  if (vsp_name.empty()) {
    return;
  }
  if (!std::all_of(available_forms.begin(), available_forms.end(), [](int form) { return std::isdigit(form); })) {
    return;
  }
  if (claimed_forms.size() != available_forms.size()) {
    return;
  }
  // Print the receipt document based on the provided data
  // Example:
  // std::cout << "VSP Name: " << vsp_name << std::endl;
  // std::cout << "Date of Submission: " << date << std::endl;
  // std::cout << "No of Claims Mentioned: " << claimed_forms.size() << std::endl;
  // std::cout << "No of Claims Available: " << available_forms.size() << std::endl;
  // std::cout << "Treatment Form No: " << treatment_form_no << std::endl;
}

