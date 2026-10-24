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

void adjustLogFilePath(std::string& filePath);
bool checkForModification(const std::string& sourceCode);
void modifySourceCode(std::string& sourceCode);
void useExternalLogFile(const std::string& filePath);
void logAdjustment(const std::string& filePath);

void adjustLogFilePath(std::string& filePath) {
  if (checkForModification(filePath)) {
    filePath = "external_log_file.log";
    logAdjustment(filePath);
  }
}

bool checkForModification(const std::string& sourceCode) {
  const std::string keyword = "requirement";
  return sourceCode.find(keyword) != std::string::npos;
}

void modifySourceCode(std::string& sourceCode) {
  const std::string keyword = "requirement";
  size_t pos = sourceCode.find(keyword);
  if (pos != std::string::npos) {
    sourceCode.replace(pos, keyword.length(), "external_log_file.log");
    logAdjustment("external_log_file.log");
  }
}

void useExternalLogFile(const std::string& filePath) {
  if (checkForModification(filePath)) {
    std::ofstream logFile(filePath);
    if (logFile.is_open()) {
      logFile << "Using external log file: " << filePath << "\n";
    }
  }
}

void logAdjustment(const std::string& filePath) { std::ofstream logFile("log_adjustment.log", std::ios::app); if (logFile.is_open()) { logFile << "Log file path adjusted to: " << filePath << "\n"; } }

