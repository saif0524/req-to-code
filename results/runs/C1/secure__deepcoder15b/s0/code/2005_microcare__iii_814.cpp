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

The function returns int64_t instead of int64, which is necessary due to the type mismatch in the cast operation.
claim

string get_vsp_name(const db &db);
string get_submission_date(const db &db, string date_format);
int64 get_mentioned_forms_count(const db &db);
int64 get_available_forms_count(const db &db);
bool compare_claim_with_processed(const claim &current, const claim &processed);

string get_submission_date(const db &db, string date_format) {
  if (db.is_null() || db.is_invalid()) {
    return 0;
  }
  int64 submission_date = (int64)db.get_submission_date(date_format);
  return (string)submission_date;
  }
  

int64 get_mentioned_forms_count(const db &db) {
  return get_available_forms_count(db);
  }

int64_t get_available_forms_count(const db &db) {
  if (db.is_null() || db.is_invalid()) {
    return 0;
  }
  int64_t count = (int64_t)db.get_available_forms_count();
  return count;
  }

bool compare_claim_with_processed(const claim &current, const claim &processed) {
  if (!current || !processed) return false;
  int64 vsp_name_current = get_vsp_name(current.db);
  int64 vsp_name_processed = get_vsp_name(processed.db);
  string date_format_current = get_submission_date(current.db, "%m/%d");
  string date_format_processed = get_submission_date(processed.db, "%m/%d");
  int64 current_vsp_number = current.vsp_number;
  int64 processed_vsp_number = processed.vsp_number;
  int64 current_merit = current.merit;
  int64 processed_merit = processed.merit;
  return (current == processed) ? (current.merit >= processed_merit) : false;
}

