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

get_reports_details() should be declared in the shared declarations;
convert_to_json() should be declared in the shared declarations;
Reports_details should be declared as a struct, enum, using alias or constant.

void submit_defect(const std::string& description, const std::string& priority, const std::string& status);
void track_defect(const std::string& id);
void send_alert(const std::string& id);
void view_reports();
void view_defects();

void submit_defect(const std::string& description, const std::string& priority, const std::string& status) {
    // Create a new defect object
    Defect new_defect(description, priority, status);
    // Store the new defect object in a database or file system
    store_defect(new_defect);
    // Return a JSON string with the details of the new defect
    return convert_to_json(new_defect);
}

void track_defect(const std::string& id) {
    // Retrieve the details of the defect or enhancement request from the database or file system
    std::string defect_details = get_defect_details(id);
    // Convert the defect details to JSON format
    std::string defect_json = convert_to_json(defect_details);
    // Return the JSON defect
    return defect_json;
}

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

