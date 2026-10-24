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

void submit_defect(const std::string& description, const std::string& priority, const std::string& status);
void track_defect(const std::string& id);
void send_alert(const std::string& id);
void view_reports();
void view_defects();

void send_alert(const std::string& id) {
  // Get the details of the alert
  std::string alert_details = track_defect(id);
  // Send an alert to the user
  send_user_alert(alert_details);
}

void view_reports() {
    // Get the details of the reports
    std::vector<std::string> reports_details = get_reports_details();
    // Convert the reports details to JSON format
    std::string reports_json = convert_to_json(reports_details);
    // Return the JSON report
    return reports_json;
}

void view_defects() {
    // Get the details of the reports
    std::vector<std::string> reports_details = get_reports_details();
    // Convert the reports details to JSON format
    std::string reports_json = convert_to_json(reports_details);
    // Return the JSON report
    return reports_json;
}

