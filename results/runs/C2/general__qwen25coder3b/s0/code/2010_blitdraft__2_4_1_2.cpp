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

void scheduleUAT(const std::string& projectID, const std::string& startDate, const std::string& endDate);
bool checkUATStatus(const std::string& projectID);
void notifyTeam(const std::string& projectID, const std::string& message);
void deployProduct(const std::string& projectID);
bool validateUATDate(const std::string& startDate, const std::string& endDate);

void scheduleUAT(const std::string& projectID, const std::string& startDate, const std::string& endDate) { std::map<std::string, std::pair<std::string, std::string>> uatSchedules; if (uatSchedules.find(projectID) == uatSchedules.end()) { uatSchedules[projectID] = {startDate, endDate}; } else { uatSchedules[projectID] = {startDate, endDate}; } }

bool checkUATStatus(const std::string& projectID) { if (uatSchedules.find(projectID) != uatSchedules.end()) { std::string startDate = uatSchedules[projectID].first; std::string endDate = uatSchedules[projectID].second; std::time_t now = std::time(nullptr); std::tm* tmNow = std::localtime(&now); std::tm tmEndDate = {}; std::strptime(endDate.c_str(), "%Y-%m-%d", &tmEndDate); tmEndDate.tm_hour = 23; tmEndDate.tm_min = 59; tmEndDate.tm_sec = 59; if (std::mktime(&tmEndDate) <= std::mktime(tmNow)) { return true; } } return false; }

void notifyTeam(const std::string& projectID, const std::string& message) { bool isCompleted = checkUATStatus(projectID); std::string statusMessage = isCompleted ? "Completed" : "Pending"; std::string notification = "UAT for project " + projectID + " is " + statusMessage + "."; // Add logic to send the notification to the project team, e.g., using a logging mechanism or an email service. }

void deployProduct(const std::string& projectID) { bool isCompleted = checkUATStatus(projectID); if (isCompleted) { // Add logic to deploy the product to the production environment return true; } else { notifyTeam(projectID, "UAT for project " + projectID + " is pending. Deployment cannot proceed."); return false; } }

bool validateUATDate(const std::string& startDate, const std::string& endDate) { std::tm tmStartDate = {}; std::tm tmEndDate = {}; std::strptime(startDate.c_str(), "%Y-%m-%d", &tmStartDate); std::strptime(endDate.c_str(), "%Y-%m-%d", &tmEndDate); if (tmStartDate.tm_year < tmEndDate.tm_year || (tmStartDate.tm_year == tmEndDate.tm_year && (tmStartDate.tm_mon < tmEndDate.tm_mon || (tmStartDate.tm_mon == tmEndDate.tm_mon && tmStartDate.tm_mday < tmEndDate.tm_mday)))) { return true; } else { return false; } }

