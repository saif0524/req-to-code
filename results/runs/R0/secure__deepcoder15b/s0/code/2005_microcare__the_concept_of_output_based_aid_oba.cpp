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

int id, string type, double amount, string reason -> Voucher;
return Voucher{id, type, amount, reason};
int id, string type -> string;
return;
int id, string recipient -> string;
return;
-> string;
return;
string message -> string;
return;

int id, string type, double amount, string reason -> Voucher;

    Voucher v;
    v.id = id;
    v.type = type;
    v.amount = amount;
    v.reason = reason;

    if (id <= 0 || type.empty() || type.size() == 0 || amount <= 0 || reason.empty() || reason.size() == 0) {
        return string(

string validateVoucher(int id, string type) {
  if (type != 

int id, string recipient -> string;

string distributeVoucher(int id, string recipient) {
  return "Voucher with ID ", recipient ", distributed to ", recipient \

string processInputData(Voucher v) {
  int id = v.id;
  string type = v.type;
  double amount = v.amount;
  string reason = v.reason;

  if (validateVoucher(id, type, amount, reason)) {
    return 

string message(int error_code, string reason) {
  if (!validateVoucher(error_code, reason)) {
    return 

