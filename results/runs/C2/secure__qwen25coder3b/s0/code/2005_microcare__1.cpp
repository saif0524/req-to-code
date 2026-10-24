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

std::string generate_voucher_number(const std::string& project_code, const std::string& group_batch_code, const std::string& batch_number);
void print_barcode(const std::string& barcode);
bool validate_voucher_date(const std::string& voucher_number, const std::string& validity_date);
void create_voucher_slips(const std::string& voucher_number, const std::string& client_id, const std::string& partner_id);
void print_voucher_slips(const std::string& voucher_number, const std::string& client_id, const std::string& partner_id);

std::string generate_voucher_number(const std::string& project_code, const std::string& group_batch_code, const std::string& batch_number) {
  // Include the random number generation header

  // Generate a unique voucher number using a secure random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1000000000, 9999999999);
  std::string voucher_number = project_code + group_batch_code + batch_number + std::to_string(dis(gen));

  // Format the voucher number as a string with the required structure
  voucher_number = project_code + '-' + group_batch_code + '-' + batch_number + '-' + voucher_number;

  return voucher_number;
}

void print_barcode(const std::string& barcode) {
  std::cout << barcode << std::endl;
}

bool validate_voucher_date(const std::string& voucher_number, const std::string& validity_date) {
  std::istringstream iss(voucher_number);
  std::string part;
  std::vector<std::string> parts;
  while (std::getline(iss, part, '-')) {
    parts.push_back(part);
  }
  if (parts.size() != 4) return false;
  return parts[3] == validity_date;
}

void create_voucher_slips(const std::string& voucher_number, const std::string& client_id, const std::string& partner_id) {
  std::string slip1 = voucher_number + '-' + client_id + '-' + partner_id;
  std::string slip2 = voucher_number + '-' + client_id + '-' + partner_id;
  std::string slip3 = voucher_number + '-' + client_id + '-' + partner_id;

  print_voucher_slips(slip1, client_id, partner_id);
  print_voucher_slips(slip2, client_id, partner_id);
  print_voucher_slips(slip3, client_id, partner_id);
}

void print_voucher_slips(const std::string& voucher_number, const std::string& client_id, const std::string& partner_id) {
  std::cout << voucher_number << '-' << client_id << '-' << partner_id << std::endl;
  std::cout << voucher_number << '-' << client_id << '-' << partner_id << std::endl;
  std::cout << voucher_number << '-' << client_id << '-' << partner_id << std::endl;
}

