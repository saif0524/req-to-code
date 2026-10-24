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

void logRequest(const std::string& requestType, const std::string& description);
void sendAlert(const std::string& user, const std::string& message);
void trackRequest(const std::string& requestId);
void viewReports(const std::string& category, const std::string& status, const std::string& age);
void accessSupport(const std::string& user, const std::string& request);

void logRequest(const std::string& requestType, const std::string& description) { accessSupport("logRequest", "Logging request type: " + requestType + ", description: " + description); }

void sendAlert(const std::string& user, const std::string& message) {
  std::string preference = accessSupport(user, "getAlertPreference");
  if (preference == "email") {
    sendEmail(user, message);
  } else if (preference == "sms") {
    sendSMS(user, message);
  }
}

void trackRequest(const std::string& requestId) {
  std::string status = accessSupport(requestId, "getTrackStatus");
  return {"status": status};
}

void viewReports(const std::string& category, const std::string& status, const std::string& age) {
  std::string reportData = accessSupport("viewReports", "category: " + category + ", status: " + status + ", age: " + age);
  return {"reports": reportData};
}

void accessSupport(const std::string& user, const std::string& request) { logRequest("accessSupport", "Accessing support system by user: " + user + ", request: " + request); }

