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

std::string validate_voucher_date(std::stringvoucher_validity_date);

std::string validate_voucher_date(std::string voucher_validity_date) {
  // Get current system date
  std::string current_distribution = std::to_string(std::time_t(std::local_time_t(std::system_clock::now())));
  // Parse current distribution date
  std::vector<std::string> parts;
  std::string::split(current_distribution, '-', parts);
  int year = std::stoi(parts[0]);
  int month = std::stoi(parts[1]);
  int day = std::stoi(parts[2]);

  // Calculate day count for current distribution date
  int current_day_count = 0;
  for (int y = 1970; y < year; y++) {
    current_day_count += std::iscalculate_days_in_year(y, month, day);
  }
  current_day_count += std::iscalculate_days_in_month(month, day);
  current_day_count += day;

  // Parse voucher_validity_date
  std::vector<std::string> voucher_parts;
  std::string::split(voucher_validity_date, '-', voucher_parts);
  int voucher_year = std::stoi(voucher_parts[0]);
  int voucher_month = std::stoi(voucher_parts[1]);
  int voucher_day = std::stoi(voucher_parts[2]);

  // Calculate day count for voucher's validity date
  int voucher_day_count = 0;
  for (int y = 1970; y < voucher_year; y++) {
    voucher_day_count += std::iscalculate_days_in_year(y, voucher_month, voucher_day);
  }
  voucher_day_count += std::iscalculate_days_in_month(voucher_month, voucher_day);
  voucher_day_count += voucher_day;

  // Compare
  if (current_day_count == voucher_day_count) {
    return "valid";
  } else {
    return "invalid";
  }
  }

