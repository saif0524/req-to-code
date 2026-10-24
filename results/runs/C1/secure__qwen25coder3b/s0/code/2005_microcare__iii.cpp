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

void capture_voucher_details(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price, std::string& invoice_amount, std::string& mode_of_payment);
void allocate_vouchers(int no_of_vouchers, int stock, std::vector<int>& voucher_numbers, std::vector<int>& batch_numbers);
void generate_report(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price, std::string& invoice_amount, std::string& mode_of_payment);
bool validate_input(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price);
std::string calculate_invoice_amount(int no_of_vouchers, int wholesale_price);

void capture_voucher_details(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price, std::string& invoice_amount, std::string& mode_of_payment) {
  if (!validate_input(distributor_name, salesman_name, distribution_date, no_of_vouchers, wholesale_price)) {
    invoice_amount = "Invalid input";
    mode_of_payment = "Invalid input";
    return;
  }

  invoice_amount = std::to_string(no_of_vouchers * wholesale_price);
  mode_of_payment = "Cash";
}

void allocate_vouchers(int no_of_vouchers, int stock, std::vector<int>& voucher_numbers, std::vector<int>& batch_numbers) {
  if (no_of_vouchers > stock) {
    no_of_vouchers = stock;
  }

  for (int i = 0; i < no_of_vouchers; ++i) {
    voucher_numbers.push_back(i + 1);
    batch_numbers.push_back(i + 1);
  }
}

std::string generate_report(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price, std::string& invoice_amount, std::string& mode_of_payment) {
  std::string report = "{\n"distributor_name": \"" + distributor_name + "\",\n  \"salesman_name": \"" + salesman_name + "\",\n  \"distribution_date": \"" + distribution_date + "\",\n  \"no_of_vouchers": " + std::to_string(no_of_vouchers) + "\",\n  \"wholesale_price": " + std::to_string(wholesale_price) + "\",\n  \"invoice_amount": \"" + invoice_amount + "\",\n  \"mode_of_payment": \"" + mode_of_payment + "\"\n}";
  return report;
}

bool validate_input(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price) {
  if (distributor_name.empty() || salesman_name.empty()) {
    return false;
  }

  // Simple date validation, assumes YYYY-MM-DD format
  if (distribution_date.size() != 10 || distribution_date[4] != '-' || distribution_date[7] != '-') {
    return false;
  }

  if (no_of_vouchers <= 0 || wholesale_price <= 0) {
    return false;
  }

  return true;
}

std::string calculate_invoice_amount(int no_of_vouchers, int wholesale_price) {
  return std::to_string(no_of_vouchers * wholesale_price);
}

