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

bool validate_sales_return(const std::string& distributor_name, const std::string& salesman_name, const std::string& return_date);
bool check_distributor_sales(const std::string& distributor_name, const std::string& salesman_name, const std::string& return_date);
bool check_salesman(const std::string& salesman_name);
bool check_date(const std::string& return_date);
bool check_system_date(const std::string& return_date);

bool validate_sales_return(const std::string& distributor_name, const std::string& salesman_name, const std::string& return_date) {
  // Check if the salesman exists
  if (!check_salesman(salesman_name)) {
    return false;
  }

  // Checks if the returned voucher was sold to the specified distributor
  if (!check_distributor_sales(distributor_name, salesman_name, return_date)) {
    return false;
  }

  // Checks if the return date is valid
  if (!check_date(return_date)) {
    return false;
  }

  // Checks if the return date is less than or equal to the system date
  if (!check_system_date(return_date)) {
    return false;
  }

  return true;
}

bool check_distributor_sales(const std::string& distributor_name, const std::string& salesman_name, const std::string& return_date) {
  // Check if the salesman exists
  if (!check_salesman(salesman_name)) {
    return false;
  }

  // Checks if the returned voucher was sold to the specified distributor
  if (!check_distributor_sales(distributor_name, salesman_name, return_date)) {
    return false;
  }

  // Checks if the return date is valid
  if (!check_date(return_date)) {
    return false;
  }

  // Checks if the return date is less than or equal to the system date
  if (!check_system_date(return_date)) {
    return false;
  }

  return true;
}

bool check_salesman(const std::string& salesman_name) {
  // Check if the salesman exists
  if (!check_salesman(salesman_name)) {
    return false;
  }

  return true;
}

bool check_date(const std::string& return_date) {
  // Get the current system date
  std::time_t now = std::time(nullptr);

  // Convert the return date string to a tm struct
  std::tm tm_return_date;
  std::istringstream ss(return_date);
  ss >> std::get_time(&tm_return_date, "%Y-%m-%d");

  // Check if the return date is valid
  if (tm_return_date.tm_year < now / (60 * 60 * 24 * 365) || tm_return_date.tm_year > now / (60 * 60 * 24 * 365)) {
    return false;
  }

  return true;
}

bool check_system_date(const std::string& return_date) {
  std::time_t now = std::time(nullptr);
  std::tm tm_return_date;
  std::istringstream ss(return_date);
  ss >> std::get_time(&tm_return_date, "%Y-%m-%d");
  if (tm_return_date.tm_year < now / (60 * 60 * 24 * 365) || tm_return_date.tm_year > now / (60 * 60 * 24 * 365)) {
    return false;
  }
  return true;
}

