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

string;
string;
string;
string;
string;

string generateReport(const vector<string>& buildReports) {
  string result;
  for (const string& report : buildReports) {
    result += report;
  }
  return make_json(result);
}

string collectBuildData(const vector<string>& parts) {
    string result;
    for (const string& part : parts) {
        result += part;
    }
    return { "reasoning": "Collect all parts into a single string" } result }

string sendEmail(const vector<string>& buildReports) {
  if (buildReports.empty()) {
    return; // No reports to email
  }
  string emailSubject = 

string generateReport(const vector<string>& buildReports) {
  string result;
  for (const string& report : buildReports) {
    result += report;
  }
  return make_json(result);
}

string sendEmail(const vector<string>& buildReports) {
  if (buildReports.empty()) {
    return;
  }
  // Email content
  string emailSubject = "Build X completed";
  string emailBody = "Build reports generated successfully after each build step.\nAppend the generated report to the email body for future review."
  return JSON.stringify({ emailSubject, emailBody });
}

