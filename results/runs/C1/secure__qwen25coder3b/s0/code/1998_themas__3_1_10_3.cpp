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

void generateOperationalHistoryReport(const std::string& reportPath);
void generateStatisticalReport(const std::string& reportPath, const std::string& month);
void selectReportType(int& reportType);
std::vector<std::string> getAvailableMonths();
void calculateStatistics(const std::vector<Event>& events, const std::string& month, std::ofstream& reportFile);

void generateOperationalHistoryReport(const std::string& reportPath, const std::vector<Event>& events) {
  if (!std::ofstream(reportPath).is_open()) {
    throw std::runtime_error("Failed to open report file");
  }

  std::ofstream reportFile(reportPath);

  for (const auto& event : events) {
    reportFile << event.date << std::endl;
  }
}

void generateStatisticalReport(const std::string& reportPath, const std::string& month) {
  if (!std::ofstream(reportPath).is_open()) {
    throw std::runtime_error("Failed to open report file");
  }

  std::ofstream reportFile(reportPath);

  // Validate month
  if (month.empty()) {
    throw std::invalid_argument("Month is required");
  }

  // Retrieve available months if necessary
  std::vector<std::string> availableMonths = getAvailableMonths();
  if (std::find(availableMonths.begin(), availableMonths.end(), month) == availableMonths.end()) {
    throw std::invalid_argument("Invalid month");
  }

  // Calculate statistics
  std::vector<Event> events;
  // Assume events is a vector of Event objects
  for (const auto& event : events) {
    if (event.date.substr(0, 7) == month) {
      // Calculate statistics for each unit and thermometer
      // ...
    }
  }

  // Write statistics to report file
  // ...
}

void selectReportType(int& reportType) {
  std::cout << "Select report type (1: Operational History, 2: Statistical): " << std::endl;
  std::string input;
  std::cin >> input;

  if (input == "1") {
    reportType = 1;
  } else if (input == "2") {
    reportType = 2;
  } else {
    std::cout << "Invalid selection. Please try again." << std::endl;
    selectReportType(reportType);
  }
}

std::vector<std::string> getAvailableMonths() {
  std::set<std::string> months;
  std::vector<Event> events;

  // Assume events is a vector of Event objects
  for (const auto& event : events) {
    months.insert(event.date.substr(0, 7));
  }

  return std::vector<std::string>(months.begin(), months.end());
}

void calculateStatistics(const std::vector<Event>& events, const std::string& month, std::ofstream& reportFile) {
  if (month.empty()) {
    throw std::invalid_argument("Month is required");
  }

  std::map<std::string, std::map<std::string, int>> unitStats;
  std::map<std::string, int> thermometerStats;

  for (const auto& event : events) {
    if (event.date.substr(0, 7) == month) {
      // Calculate statistics for each unit and thermometer
      // ...
      unitStats[event.unit][event.type]++;
      thermometerStats[event.thermometer]++;
    }
  }

  // Write statistics to report file
  // ...
}

