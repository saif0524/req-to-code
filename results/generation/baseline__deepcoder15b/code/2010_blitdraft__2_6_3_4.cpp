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

string generateReport(const vector<string>& buildReports) {
  vector<string> reportStrings;
  for (const string& report : buildReports) {
    reportStrings.push_back(report);
  }
  string result = join(reportStrings, newline);
  return { "reasoning": "The function generates a report after each system build to the staging environment by collecting all reports into a single string and returning it in JSON format.", "code": result }
}

string collectBuildData(const vector<string>& parts) {
    string result =;
    for (const string& part : parts) {
        result += part;
    }
    return { "reasoning": "Collect all parts into a single string" } result }

string sendEmailAfterReportGenerate(const string& report) {
    return { "reasoning": "After each report generate", "code": report } }

