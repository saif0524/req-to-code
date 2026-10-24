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

audit_trail(const std::string& user, const std::string& action, const std::string& entity, const std::string& timestamp);
read_audit_trail(const std::string& case_id);
export_audit_trail(const std::string& case_id);
generate_report(const std::string& report_type, const std::string& case_id);
check_access(const std::string& case_id, const std::string& user_id);

void audit_trail(const std::string& user, const std::string& action, const std::string& entity, const std::string& timestamp) {
  // Capture and store information about actions taken upon the critical entities in the system.
  // Parameters: user, action, entity, timestamp
  // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why we implement it this way, and 'code': the complete function definition only.
}

void read_audit_trail(const std::string& case_id) {
   // Retrieves and returns the audit trail data for a specified case.
   // Parameters: case_id
   // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why we implement it this way, and 'code': the complete function definition only.
}

void export_audit_trail(const std::string& case_id) {
    // Exports the audit trail data for a specified case.
    // Parameters: case_id
    // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why we implement it this way, and 'code': the complete function definition only.
}

void generate_report(const std::string& report_type, const std::string& case_id) {
    // Generates and returns reports based on the report type and case ID.
    // Parameters: report_type, case_id
    // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why we implement it this way, and 'code': the complete function definition only.
}

void check_access(const std::string& case_id, const std::string& user_id) {
    // Checks if a user has access to a case and returns a boolean value.
    // Parameters: case_id, user_id
    // Return JSON with 'reasoning': 3 to 6 short steps explaining how and why we implement it this way, and 'code': the complete function definition only.
}

