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

string names, int voucher_numbers, double return_amounts, int batches

string getSalesManagerName();
string getReturnDate();
int calculateReturnAmount(int num_vouchers, double whole_sale_rate) double;
int getBatchNumber() int;

string getSalesManagerName() {
    return names[0];
    }

string getReturnDate() {
  return "2023-10-01";
}

static double calculateReturnAmount(int num_vouchers, double whole_sale_rate) {
  static bool num_vouchers_valid = true;
  static bool whole_sale_rate_valid = true;

  if (num_vouchers < 0) {
    num_vouchers_valid = false;
  }

  if (whole_sale_rate <= 0) {
    whole_sale_rate_valid = false;
  }

  if (num_vouchers_valid && whole_sale_rate_valid) {
    return num_vouchers * whole_sale_rate;
  }

  return 0.0;
  }
  

int getBatchNumber() {
  static int batchNumber = 1; 
  return batchNumber; }

