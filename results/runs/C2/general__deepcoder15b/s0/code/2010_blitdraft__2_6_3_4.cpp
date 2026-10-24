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

Your code will include necessary headers and declarations.
string

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

string generateReport(const vector<string>& buildReports) {
  string result;
  for (const string& report : buildReports) {
    result += report;
  }
  return JSON.stringify({ result });

  string generateReason(const vector<string>& report) {
    string reason =;
    for (const string& part : report) {
      if (!part.empty()) {
        reason += part;
        if (part.size() > 1) reason += " ";
      }
    }
    return JSON.stringify({ reason });

  string sendEmail(const vector<string>& buildReports) {
    if (buildReports.empty()) return;
    string emailSubject = "Build X completed";
    string emailContent = "Build reports generated successfully after each build step.\nAppend the generated report to the email body for future review.\nReason:\n" + generateReason(buildReports);
    return JSON.stringify({ emailSubject, emailContent });
}

string updateReport(const vector<string>& buildReports, const string& existingReport) {
  string reason = generateReason(buildReports);
  existingReport += " " + reason + " \n"
  return JSON.stringify({ report: existingReport });
}
```json {

string sendEmail(const vector<string>& buildReports) { 
  if (buildReports.empty()) { 
    return; 
  } 
  string emailSubject = "Build X completed"; 
  string emailContent = "Build reports generated successfully after each build step. Append the generated report to the email body for future review. " + generateReason(buildReports) + "\n"; 
  return JSON.stringify({ emailSubject, emailContent }); 
 }

string sendEmail(const vector<string>& buildReports) { 
  if (buildReports.empty()) { 
    return; 
  } 
  
  string emailSubject = 

