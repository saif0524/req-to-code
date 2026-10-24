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
void send_notification(const std::string& message);
void view_defects();
void view_helpdesk();

void submit_defect(const std::string& description, const std::string& priority, const std::string& status) {
   // Create a new defect object with the provided parameters
   Defect new_defect(description, priority, status);
   // Store the defect object in the system
   store_defect(new_defect);
   // Return a JSON object with a success message
   return_json("Defect submitted successfully.");
}

void track_defect(const std::string& id) {
    // Search for the defect or enhancement request with the given id
    Defect* defect = find_defect(id);
    // Return a JSON object with the current status of the defect or enhancement request
    return_json("Defect status: " + defect->get_status());
}

void send_notification(const std::string& message) {
    // Send an email or SMS with the provided message
    send_email_or_sms(message);
    // Return a JSON object with a success message
    return_json("Notification sent successfully.");
}

void view_defects() {
    // Retrieve all the submitted defects or enhancement requests from the system
    std::vector<Defect> defects = retrieve_all_defects();
    // Prepare a JSON object with the category-wise, status-wise, and age-wise report
    std::map<std::string, std::map<std::string, std::map<std::string, std::vector<Defect>>>> report = prepare_report(defects);
    // Return the JSON object with the report
    return_json(report);
}

void view_helpdesk() {
     std::vector<Defect> defects = retrieve_all_defects();
     std::map<std::string, std::map<std::string, std::map<std::string, std::vector<Defect>>>> report = prepare_report(defects);
     return_json(report);
}

