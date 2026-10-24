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
void selectMonth(const std::string& month);
void generateStatisticalReport(const std::string& reportFileName);
void selectReportType(const std::string& reportType);
std::string getReportFileName();

void selectMonth(const std::string& month) {
    // Update the internal state of the object to reflect the selected month.
    // For example, if the input is 'January', update the month variable to 'January'.
    this->month = month;
}

void selectReportType(const std::string& reportType) {
     // Update the internal state of the object to reflect the selected report type.
     // For example, if the input is 'Operational History', update the reportType variable to 'Operational History'.
     this->reportType = reportType;
}

std::string THEMAS::getReportFileName() {
     return reportFileName;
}

