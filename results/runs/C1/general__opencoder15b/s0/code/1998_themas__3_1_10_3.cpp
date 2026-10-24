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

void generateReport(const std::string& reportType, const std::string& reportFileName);
void selectReport(const std::string& reportMonth);
void generateStatisticalReport(const std::string& reportFileName);
void selectStatisticalReport(const std::string& reportMonth);
std::string getReportData();

void generateStatisticalReport(const std::string& reportFileName) {
  // Select the statistical report based on the report month provided.
  selectStatisticalReport(reportMonth);

  // Get the report data based on the report type and file name provided.
  std::string reportData = getReportData();

  // Write the report data to the file.
  std::ofstream reportFile(reportFileName);
  reportFile << reportData;
}

void selectStatisticalReport(const std::string& reportMonth) {
   // Select the statistical report based on the report month provided.
   selectReport(reportMonth);

   // Get the report data based on the report type and file name provided.
   std::string reportData = getReportData();

   // Write the report data to the file.
   std::ofstream reportFile(reportFileName);
   reportFile << reportData;
}

std::string getReportData() {
    // Select the statistical report based on the report month provided.
    selectStatisticalReport(reportMonth);

    // Get the report data based on the report type and file name provided.
    std::string reportData = getReportData();

    // Write the report data to the file.
    std::ofstream reportFile(reportFileName);
    reportFile << reportData;
}

