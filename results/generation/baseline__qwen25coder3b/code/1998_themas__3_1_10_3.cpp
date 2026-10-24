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
void generateStatisticalReport(const std::string& reportPath, const std::string& selectedMonth);
void selectReportType(int& reportType);
std::vector<std::string> getAvailableMonths();
void calculateStatistics(const std::vector<Event>& events, const std::string& selectedMonth, std::ofstream& reportFile);

void generateOperationalHistoryReport(const std::string& reportPath) {
  std::ofstream reportFile(reportPath);
  if (!reportFile.is_open()) {
    std::cerr << "Error: Unable to open file "

void generateStatisticalReport(const std::string& reportPath, const std::string& selectedMonth) {
  std::vector<std::string> availableMonths = getAvailableMonths();
  if (std::find(availableMonths.begin(), availableMonths.end(), selectedMonth) != availableMonths.end()) {
    std::ofstream reportFile(reportPath);
    if (!reportFile.is_open()) {
      std::cerr << "Error: Unable to open file 

void selectReportType(int& reportType) {
  std::string choice;
  while (true) {
    std::cout << "Select report type (1: Operational History, 2: Statistical Report): " << std::endl;
    std::cin >> choice;
    if (choice == "1") {
      reportType = 1;
      break;
    } else if (choice == "2") {
      reportType = 2;
      break;
    } else {
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  }
}

std::vector<std::string> getAvailableMonths() {
  std::vector<std::string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  return months;
}

void calculateStatistics(const std::vector<Event>& events, const std::string& selectedMonth, std::ofstream& reportFile) {
  std::map<std::string, std::map<std::string, int>> unitUsage;
  std::map<std::string, std::map<std::string, int>> deniedRequests;

  for (const auto& event : events) {
    if (event.getMonth() == selectedMonth) {
      unitUsage[event.getUnit()][event.getDate()]++;
      if (event.isGranted()) {
        deniedRequests[event.getUnit()][event.getDate()]++;
      }
    }
  }

  for (const auto& [unit, dailyUsage] : unitUsage) {
    for (const auto& [date, usage] : dailyUsage) {
      int totalRequests = usage + deniedRequests[unit][date];
      if (totalRequests > 0) {
        double percentage = static_cast<double>(usage) / totalRequests * 100;
        reportFile << unit << 

