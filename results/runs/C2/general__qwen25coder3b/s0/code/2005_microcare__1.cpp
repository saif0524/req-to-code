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

std::string generate_voucher_number();
void print_barcode(const std::string& barcode);
void capture_voucher_number(const std::string& voucher_number);
bool check_validity_date(const std::string& voucher_number, const std::string& validity_date);
void generate_tear_off_slips(const std::string& voucher_number);

std::string generate_voucher_number() {
  std::string project_code = "P001";
  std::string group_batch = "GP0001";
  std::string batch_number = "01";
  std::string voucher_number = "1234567890";
  std::string security_code = "1234";

  std::string voucher_number_with_security = project_code + group_batch + batch_number + voucher_number + security_code;

  return voucher_number_with_security;
}

void print_barcode(const std::string& barcode) { std::cout << barcode << std::endl; }

void capture_voucher_number(const std::string& voucher_number) { std::cout << voucher_number << std::endl; }

bool check_validity_date(const std::string& voucher_number, const std::string& validity_date) {
  std::string date_part = voucher_number.substr(voucher_number.length() - 10);
  return date_part == validity_date;
}

void generate_tear_off_slips(const std::string& voucher_number) {
  std::string barcode = voucher_number;
  std::cout << barcode << std::endl;
  std::cout << barcode << std::endl;
  std::cout << barcode << std::endl;
}

