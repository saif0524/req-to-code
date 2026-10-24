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
void process_voucher_sale(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price);

void capture_voucher_details(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price, std::string& invoice_amount, std::string& mode_of_payment) {
  // Calculate invoice amount
  invoice_amount = std::to_string(no_of_vouchers * wholesale_price);

  // Set mode of payment
  mode_of_payment = "Cash";
}

void allocate_vouchers(int no_of_vouchers, int stock, std::vector<int>& voucher_numbers, std::vector<int>& batch_numbers) {
  if (no_of_vouchers > stock) {
    // Handle error: not enough stock
    return;
  }

  for (int i = 0; i < no_of_vouchers; ++i) {
    // Generate unique voucher number and batch number
    voucher_numbers.push_back(i + 1);
    batch_numbers.push_back(stock - i);
  }
}

void generate_report(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price, std::string& invoice_amount, std::string& mode_of_payment) {
  std::ostringstream report;
  report << "{\n"distributor_name": \"" << distributor_name << "\",\n  \"salesman_name": \"" << salesman_name << "\",\n  \"distribution_date": \"" << distribution_date << "\",\n  \"no_of_vouchers": " << no_of_vouchers << ",\n  \"wholesale_price": " << wholesale_price << ",\n  \"invoice_amount": \"" << invoice_amount << "\",\n  \"mode_of_payment": \"" << mode_of_payment << "\n}";
  invoice_amount = report.str();
}

void process_voucher_sale(const std::string& distributor_name, const std::string& salesman_name, const std::string& distribution_date, int no_of_vouchers, int wholesale_price, int stock) {
  std::string invoice_amount, mode_of_payment;

  // Capture voucher details
  capture_voucher_details(distributor_name, salesman_name, distribution_date, no_of_vouchers, wholesale_price, invoice_amount, mode_of_payment);

  // Allocate vouchers
  std::vector<int> voucher_numbers, batch_numbers;
  allocate_vouchers(no_of_vouchers, stock, voucher_numbers, batch_numbers);

  // Generate report
  generate_report(distributor_name, salesman_name, distribution_date, no_of_vouchers, wholesale_price, invoice_amount, mode_of_payment);
}

