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

using SettingsMaster = std::vector<SettingsMaster>;
struct VoucherStock { int id; std::string batch_no; std::string voucher_no; std::string validity_date; };

std::vector<DistributorMaster> get_distributor_master();
std::vector<SalesManMaster> get_sales_man_master();
std::vector<SettingsMaster> get_settings_master();
std::vector<VoucherStock> get_available_voucher_stock();
std::string get_distribution_invoice_no();

struct DistributorMaster { int id; std::string name; };

struct SalesManMaster { int id; std::string name; };

using SettingsMaster = std::vector<SettingsMaster>; std::vector<SettingsMaster> get_settings_master() { std::vector<SettingsMaster> settings_master_records; std::vector<VoucherStock> voucher_stock_records = get_available_voucher_stock(); for (const auto& voucher_stock : voucher_stock_records) { if (voucher_stock.distributor_id != 0) { settings_master_records.push_back(voucher_stock.distributor); } } return settings_master_records; }

struct VoucherStock { int id; std::string batch_no; std::string voucher_no; std::string validity_date; }; std::vector<VoucherStock> get_available_voucher_stock() { std::vector<VoucherStock> distributor_master_records; std::vector<VoucherStock> voucher_stock_records = get_available_voucher_stock(); for (const auto& voucher_stock : voucher_stock_records) { if (voucher_stock.distributor_id != 0) { distributor_master_records.push_back(voucher_stock.distributor); } } return distributor_master_records; }

std::string get_distribution_invoice_no() {
  static int invoice_counter = 0;
  std::string invoice_number = "DISTRIBUTOR-SALESMAN-DIST-" + std::to_string(current_date.year()) + std::to_string(current_date.month()) + std::to_string(current_date.day()) + std::to_string(invoice_counter++);
  return invoice_number;
}

