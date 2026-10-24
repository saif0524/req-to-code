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
bool validate_numeric_values(const std::string& value);
std::vector<std::string> list_vsp_names();
bool validate_forms(int mentioned_forms, int available_forms);
void generate_receipt(const std::string& vsp_name, const std::string& date_of_submission, int mentioned_forms, int available_forms);

std::string get_current_date() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);
  std::ostringstream oss;
  oss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
  return oss.str();
}

bool validate_numeric_values(const std::string& value) {
  std::stringstream ss(value);
  char ch;
  while (ss >> ch) {
    if (!isdigit(ch)) {
      return false;
    }
  }
  return true;
}

std::vector<std::string> list_vsp_names() { return {}; }

bool validate_forms(int mentioned_forms, int available_forms) { return mentioned_forms == available_forms; }

std::string generate_receipt(const std::string& vsp_name, const std::string& date_of_submission, int mentioned_forms, int available_forms) {
  std::ostringstream receipt;
  receipt << "VSP Name: " << vsp_name << "\n";
  receipt << "Date of Submission: " << date_of_submission << "\n";
  receipt << "No of claims mentioned: " << mentioned_forms << "\n";
  receipt << "No of claims Available: " << available_forms << "\n";
  return receipt.str();
}

