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

string account_type = "customer";

string account_name, string email -> bool;
string account_name, string profile -> bool;
string account_name, string contact -> bool;
string account_name -> bool;
string account_name, string order -> bool;

bool account_name(string account_name, string email) { return false; }

bool account_name(string account_name) { return false; }

bool account_name(string account_name, string email) {
    string account_number = "1234567890";
    string account_balance = "123456789";
    string account_order = "123456789";
    string account_order_status = "pending";
    return true;
}

bool account_name(string account_name) { return false; }

bool account_name(string account_name, string order) {
  bool exists = existsAccount(account_name);
  if (exists) {
    return false;
  }
  bool account_created = createAccount(account_name, order, "1234567890", "123456789", "123456789", "pending");
  return account_created;
}
  

