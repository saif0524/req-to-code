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

string getReportType(string type) {
  if (type == 

string generateOperationalReport(string type, string databaseHandle) {
  if (type != 0 && type != 1) {
    return "Error: Invalid report type. Must be 0 (operational) or 1 (statistical).";
  }

  if (databaseHandle == null || databaseHandle.empty()) {
    return "Error: Database handle must not be null or empty.";
  }

  // Use a lock to ensure thread safety
  lock_guard<string> lock;
  thread::lock(&lock);

  // Get all events from the database
  vector<string> events;
  if (databaseHandle != null) {
    // Assume databaseHandle has a method to retrieve events
    events = getDatabaseEvents(databaseHandle);
  }

  if (events.empty()) {
    return "Error: No events found in the database.";
  }

  // Sort events by date and time
  sort(events.begin(), events.end(), [](const string& a, const string& b) {
    // Compare based on date and time
    // Assuming a is in the format 

string generateStatisticalReport(string month, string databaseHandle) {
  if (databaseHandle == null || databaseHandle.empty()) {
    return "Error: Database handle must not be null or empty.\n"
  }

  vector<string> events;
  if (databaseHandle != null) {
    events = getDatabaseEvents(databaseHandle);
  }

  if (events.empty()) {
    return "Error: No events found in the database.\n"
  }

  lock_guard<string> lock;
  thread::lock(&lock);

  sort(events.begin(), events.end(), [](const string& a, const string& b) {
    // Compare based on date and time
    // Assuming a is in the format "dd-MMM-YYYY HH:mm:ss"
    // and b is similarly formatted
    // This is a simplified example
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

    // Calculate percentages for heating and cooling units
    for (size_t i = 0; i < count; ++i) {
      string event = day[i];
      string time = extract_time(event);
      string dayParts = extract_day_parts(time);

      // Assuming the data structure has fields like heating, cooling, etc.
      // For example:
      // string data[3] = { ... };

      // Placeholder for actual logic
      stats[

string handleReportFiles(string fileName, string directory) {
  // Check if the directory exists
  if (!exist(directory)) {
    mkdir(directory, 0, 0);
  }

  // Read the report file name
  string reportFileName = fileName;
  string monthStream = 

