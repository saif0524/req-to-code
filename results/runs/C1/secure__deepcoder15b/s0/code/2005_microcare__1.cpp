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

${#include <random>}$include <random>}

int generate_voucher_number() -> int;
int validate_voucher_number(int voucher_number: int) -> int;
int generate_project_code() -> int;
int generate_group_batch_number() -> int;
int generate_batch_number() -> int;

int generate_voucher_number() -> int {
  // Generate a random number based on the required structure
  int random_num = static_cast<int>(random_device() & 0x7ff);
  // Ensure the number is exactly 10 digits
  if (random_num < 1000000000 || random_num > 9999999999) {
    return -1;
  }
  // Extract group batch number (3 digits)
  int group_batch = static_cast<int>(random_num) / 1000;
  // Extract batch number (last two digits)
  int batch = static_cast<int>(random_num) % 100;
  // Extract project code (first two digits of random_num)
  int project_code = (static_cast<int>(random_num) / 100) % 100;
  // Extract security code (last digit)
  int security_code = static_cast<int>(random_num) % 10;
  // Validate that each part is within the required range and format
  if (group_batch < 0 || group_batch > 999 || batch < 0 || batch > 99 ||
    project_code < 0 || project_code > 99 || security_code < 0 || security_code > 9) {
    return -1;
  }
  // Combine parts into the voucher number
  int voucher_number = group_batch * 100000000 + batch * 1000000 + project_code * 1000 + security_code * 100 + group_batch * 10000 + batch * 1000 + project_code * 100 + security_code * 10 + group_batch * 100000 + batch * 100000 + project_code * 100000 + security_code * 1000000; 
  // Ensure the voucher number is at least 10 digits and free format
  if (voucher_number < 1000000000 || voucher_number > 9999999999) {
    return -1;
  }
  // Return the voucher number
  return voucher_number;
  }
  

int validate_voucher_number(int voucher_number) -> int {
  // Check if the voucher number is exactly 10 digits
  if (voucher_number < 1000000000 || voucher_number > 9999999999) {
    return -1;
  }
  
  // Extract and validate project code (first two digits)
  string projectCodeStr = to_string(voucher_number);
  int projectCode = stoi(projectCodeStr.substr(0, 2));
  if (projectCode < 0 || projectCode > 99) {
    return -1;
  }
  
  // Extract and validate group batch number (next three digits)
  string groupBatchStr = to_string(voucher_number).substr(2, 3);
  int groupBatch = stoi(groupBatchStr);
  if (groupBatch < 0 || groupBatch > 999) {
    return -1;
  }
  
  // Extract and validate batch number (last two digits)
  string batchStr = to_string(voucher_number).substr(voucher_number.size() - 2, 2);
  int batch = stoi(batchStr);
  if (batch < 0 || batch > 99) {
    return -1;
  }
  
  // Extract and validate security code (last digit)
  int securityCode = voucher_number % 10;
  if (securityCode < 0 || securityCode > 9) {
    return -1;
  }
  
  // All checks passed
  return 0;
  }
  "reasoning": [
    "Check voucher number is exactly 10 digits",
    "Extract and validate project code (first two digits)",
    "Extract and validate group batch number (next three digits)",
    "Extract and validate batch number (last two digits)",
    "Extract and validate security code (last digit)",
    "All checks passed"
  ]}
  

int generate_project_code() -> int {
  int groupBatch = static_cast<int>(generate_voucher_number());
  int projectCode = groupBatch / 10;
  return projectCode;
  }

int generate_group_batch_number() -> int {
  int random_num = static_cast<int>(random_device() & 0x7ff);
  return random_num % 100;
  }

int generate_batch_number() -> int {
  // Generate a number between 0 and 99 using a random device
  int random_num = static_cast<int>(random_device() & 0x7ff);
  // Ensure the number is within the required range
  return random_num % 100;
}

