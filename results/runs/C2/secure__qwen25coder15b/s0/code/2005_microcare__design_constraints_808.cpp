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

using SettingsMaster = std::vector<std::string>; using VoucherStock = std::vector<std::string>; 

std::vector<DistributorMaster> get_distributor_master();
std::vector<SalesManMaster> get_sales_man_master();
std::vector<SettingsMaster> get_settings_master();
std::vector<VoucherStock> get_available_voucher_stock();
bool validate_distribution_date(const std::string& date);

using DistributorMaster = std::vector<std::string>;

std::vector<DistributorMaster> get_distributor_master() {
  // Fetches all distributors from the distributor master table
  std::vector<DistributorMaster> distributors = get_available_distributor_master();

  // Return the list of distributors fetched from the distributor master table
  return distributors;
}

using SalesManMaster = std::vector<std::string>;

std::vector<SalesManMaster> get_sales_man_master() {
  // Fetches all sales men from the sales man master table
  std::vector<SalesManMaster> sales_men = get_available_sales_man_master();

  // Return the list of sales men fetched from the sales man master table
  return sales_men;
}

std::vector<SettingsMaster> get_settings_master() {
  // Fetches all settings from the settings master table
  std::vector<SettingsMaster> settings = get_available_settings_master();

  // Return the list of settings fetched from the settings master table
  return settings;
}

std::vector<VoucherStock> get_available_voucher_stock() {
  // Fetches all available voucher stock from the voucher stock table
  std::vector<VoucherStock> available_voucher_stock = get_available_voucher_stock_from_database();

  // Return the list of available voucher stock fetched from the voucher stock table
  return available_voucher_stock;
}

bool validate_distribution_date(const std::string& date) {
  if (date.empty() || date == nullptr) {
    return false; // Invalid date
  }

  std::istringstream iss(date);
  std::tm tm;
  if (!(iss >> std::get_time(&tm, "%Y-%m-%d"))) {
    return false; // Invalid date format
  }

  std::time_t now = std::time(nullptr);
  std::tm now_tm = *std::localtime(&now);

  if (std::mktime(&tm) < std::mktime(&now_tm)) {
    return true; // Date is in the past
  } else {
    return false; // Date is not in the past
  }
}

