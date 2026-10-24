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

create_voucher(description: string, amount: int, status: int) -> voucher_type;
process_voucher(voucher: voucher_type) -> processed_voucher;
return_voucher(processed_voucher: processed_voucher) -> voucher_type;
feedback_message() -> string;
get_user_access(voucher: voucher_type, user_id: int) -> bool;

process_voucher(voucher: voucher_type) -> processed_voucher:
  let amount = (voucher.amount != null) ? voucher.amount : 0;
  if (amount != null) {
    voucher.type.amount = voucher.type.amount - amount;
  } else {
    voucher.type.amount = null;
  }
  processed_voucher = voucher;
  return processed_voucher;
  "reasoning": [
    "Check if a voucher has an amount associated with it.\n"If it does, subtract the amount from the voucher's amount.
    "If it doesn't, mark the voucher as paid.\n"Return the processed voucher as the result.
    ],
  "reasoning": [
    "Check if a voucher has an amount associated with it.\n"If it does, subtract the amount from the voucher's amount.
    "If it doesn't, mark the voucher as paid.\n"Return the processed voucher as the result.
    ],
  

return_voucher(processed_voucher: processed_voucher) -> voucher_type {
    let amount = processed_voucher.amount != null ? processed_voucher.amount : null;
    let new_voucher_type: voucher_type = {
      ...: processed_voucher.amount != null ? processed_voucher.amount : null;
      status: ...;
      // fill in the rest based on the voucher_type structure
    };
    

