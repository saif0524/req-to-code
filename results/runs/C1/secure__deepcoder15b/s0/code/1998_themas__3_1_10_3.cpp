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

string reportFileName, string monthStream

string getReportType(string type): string;
string generateOperationalReport(string type, string databaseHandle): string;
string generateStatisticalReport(string month, string databaseHandle): string;
string handleReportFiles(string fileName, string directory): string;

string getReportType(string type): string \n{
if (type == 0) \n    return "operational report";
} else if (type == 1) \n    return "statistical report";
return "Error: Invalid report type.";
}

string generateOperationalReport(string type, string databaseHandle) {
  if (type != 0 && type != 1) {
    return "Error: Invalid report type. Must be 0 (operational) or 1 (statistical).";
  }

  if (databaseHandle == null || databaseHandle.empty()) {
    return "Error: Database handle must not be null or empty.\n";
  }

  // Use a lock to ensure thread safety
  lock_guard<string> lock;
  thread::lock(&lock);

  // Get all events from the database
  vector<string> events;
  if (databaseHandle != null) {
    events = getDatabaseEvents(databaseHandle);
  }

  if (events.empty()) {
    return "Error: No events found in the database.\n";
  }

  // Sort events by date and time
  sort(events.begin(), events.end(), [](const string& a, const string& b) {
    return compare_date(a, b);
  });

  // Group events by day
  map<string, vector<string>> dayEvents;
  for (string event : events) {
    string time = extract_time(event);
    string day = extract_day(time);
    dayEvents[day].push_back(event);
  }

  // Calculate statistics
  map<string, string> stats;
  for (auto& day : dayEvents) {
    int count = day.size();
    if (count == 0) continue;

    string dayName = extract_day_name(day[0]);
    string total = count;

    stats["heating" + day[0]] = (count > 0) ? (count / total * 100) : 0;
    stats["cooling" + day[0]] = (count > 0) ? (count / total * 100) : 0;

    // Calculate ratio for heating and cooling
    if (count > 0) {
      stats["heating_ratio" + day[0]] = (count / total * 100);
      stats["cooling_ratio" + day[0]] = (count / total * 100);
    }

    // Placeholder for actual logic to calculate percentages
    // This is a simplified example
  }

  // Generate the report string
  string reportContent;
  for (auto& entry : stats) {
    if (entry.first == "heating") {
      reportContent += "Heating: " + string(entry.second/100) + "%\n";
    } else if (entry.first == "cooling") {
      reportContent += "Cooling: " + string(entry.second/100) + "%\n";
    } else if (entry.first == "heating_ratio" && entry.second > 0) {
      reportContent += "Heating Ratio: " + string(entry.second/100) + "%\n";
    } else if (entry.first == "cooling_ratio" && entry.second > 0) {
      reportContent += "Cooling Ratio: " + string(entry.second/100) + "%\n";
    }
  }

  // Create the report file path
  string reportFileName = reportFileName;
  string monthStream = string(4, 'M');

  // Write the report content
  string output = reportContent + monthStream + ( reportFileName != "" ? "" : reportFileName );;
  // Replace "" with newline character
  output += string(1, '
');

  // Close the file
  open(reportFileName, 

string generateStatisticalReport(string month, string databaseHandle) {
  if (databaseHandle == null || databaseHandle.empty()) {
    return "Error: Database handle must not be null or empty.\n"
  }

  vector<string> events;
  if (databaseHandle != null) {
    events = getDatabaseEvents(databaseHandle);
  }

  if (events.empty() || month.empty()) {
    return "Error: No events found in the database or invalid month.\n"
  }

  string reportFileName = month;
  string reportBasePath = reportFileName + (reportFileName != "" ? "" : ";\nstring fullReportPath = reportBasePath + (reportFileName != "" ? "" : ";

  // ... [rest of the function implementation] ...
  return reportContent + fullReportPath;
}

string handleReportFiles(string fileName, string directory) {
  // Check if the directory exists
  if (!exist(directory)) {
    mkdir(directory, 0, 0);
  }

  // Read the report file name
  string reportFileName = fileName;
  string monthStream = 

