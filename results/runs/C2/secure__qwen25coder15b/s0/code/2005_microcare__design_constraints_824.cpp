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

bool validate_return_voucher(const std::string& distributor_name, const std::string& sales_man_name, const std::string& return_date);
std::string get_distributor_master_sales_man_name(const std::string& distributor_name);
std::string get_sales_man_master_sales_return_date(const std::string& distributor_name);
std::string get_system_date();

bool validate_return_voucher(const std::string& distributor_name, const std::string& sales_man_name, const std::string& return_date) {
  std::string distributor_master_sales_man_name = get_distributor_master_sales_man_name(distributor_name);
  std::string distributor_master_sales_return_date = get_sales_man_master_sales_return_date(distributor_name);
  std::string system_date = get_system_date();

  if (return_date > system_date) {
    return false;
  }

  if (distributor_name == distributor_master_sales_man_name) {
    return true;
  } else {
    return false;
  }
}

std::string get_distributor_master_sales_man_name(const std::string& distributor_name) {
  return distributor_master_sales_man_name;
}

std::string get_sales_man_master_sales_return_date(const std::string& distributor_name) {
  std::string distributor_master_sales_man_name = get_distributor_master_sales_man_name(distributor_name);
  std::string system_date = get_system_date();

  if (return_date > system_date) {
    return "Return date is in the future";
  }

  if (distributor_name == distributor_master_sales_man_name) {
    return distributor_master_sales_return_date;
  } else {
    return "Return voucher was not sold to this distributor";
  }
}

std::string get_system_date() {
  return std::chrono::system_clock::now().time_since_epoch().count();
}

