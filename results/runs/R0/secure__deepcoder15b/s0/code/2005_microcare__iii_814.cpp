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

string get_vsp_name(const db &db);
string get_submission_date(const db &db, string date_format);
int64 get_mentioned_forms_count(const db &db);
int64 get_available_forms_count(const db &db);
bool compare_claim_with_processed(const claim &current, const claim &processed);

string get_vsp_name(const db &db) {
    if (db.is_null() || db.is_invalid()) {
        return 

string get_submission_date(const db &db, string date_format) {
  if (db.is_null() || db.is_invalid()) {
    return 

int64 get_mentioned_forms_count(const db &db) \ \ \ \ \ \ \ \ \ \ \ \ \ \ return (int64)db.get_mentioned_forms_count();

int64 get_available_forms_count(const db &db) {
    if (db.is_null() || db.is_invalid()) {
        return 0;
    }
    int64 count = (int64)db.get_available_forms_count();
    return count;
    }

bool compare_claim_with_processed(const claim &current, const claim &processed) {
  // Check if both claims are valid
  if (!current || !processed) return false;

  // Get necessary data from both claims
  int64 vsp_name_current = get_vsp_name(current.db);
  int64 vsp_name_processed = get_vsp_name(processed.db);
  string date_format_current = get_submission_date(current.db, 

