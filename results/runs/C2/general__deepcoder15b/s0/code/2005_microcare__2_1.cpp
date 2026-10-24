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

We are using C++17 features, so no additional declarations are needed.

vector<voucher> VoucherList(const vector<voucher>&>& v);
void AddVoucher(voucher& v);
void RemoveVoucher(int id);
void UpdateVoucher(int id, double price, double quantity);
double CalculateTotal(const vector<voucher>& v);

vector<voucher> VoucherList(const vector<voucher>&>& v) \
{ \
  vector<voucher> result(v.begin(), v.end()); \
  return result; \
 }\

using namespace std; // Use std::string, etc. as std::string

double CalculateTotal(const vector<voucher>&& v) {
    double total = 0.0;
    for (const auto& voucher : v) {
        total += voucher.price;
    }
    return total;

}

vector<voucher> AddVoucher(voucher& v) {
    vector<voucher> result;
    result.push_back(v);
    return result;

}

vector<voucher> RemoveVoucher(int id, const vector<voucher>&& v) {
    vector<voucher> result;
    for (const auto& v : v) {
        if (v.id != id) {
            result.push_back(v);
        }
    }
    return result;

}

void UpdateVoucher(int id, double new_price, double new_quantity) {
    vector<voucher> updated_vouchers;
    for (const auto& v : VoucherList(v)) {
        if (v.id == id) {
            vector<voucher> temp_vouchers(v.begin(), v.end());
            temp_vouchers[0].price = new_price;
            temp_vouchers[0].quantity = new_quantity;
            updated_vouchers.push_back(temp_vouchers);
        }
    }
    return updated_vouchers;

}

vector<voucher> VoucherList(const vector<voucher>&& v) {
    vector<voucher> result(v.begin(), v.end());
    return result;

}

// Reasoning section:

vector<voucher> RemoveVoucher(int id, const vector<voucher>&& v) \
{ \
 vector<voucher> result; \
 for (const auto& v : v) \
 { \
 if (v.id != id) \
 { \
 result.push_back(v); \
 } \
 } \
 return result; \
 }

vector<voucher> VoucherList(const vector<voucher>&>& v) 
{ 
  return vector<voucher>(v.begin(), v.end()); 
 }

double CalculateTotal(const vector<voucher>&& v) 
{ 
  double total = 0.0;
  for (const auto& voucher : v)
  { 
    total += voucher.price;
  }
  return total;
 }

vector<voucher> UpdateVoucher(int id, double new_price, double new_quantity)
{ 
  vector<voucher> temp_vouchers(v.begin(), v.end());
  temp_vouchers[0].price = new_price;
  temp_vouchers[0].quantity = new_quantity;
  return temp_vouchers;
 }

double CalculateTotal(const vector<voucher>& v) 
{ 
  double total = 0.0; 
  for (const auto& voucher : v) 
  { 
    total += voucher.price; 
  } 
  return total; 
} 

