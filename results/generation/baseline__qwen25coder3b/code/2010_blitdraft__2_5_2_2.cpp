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

void adjustSourceCodeForLogging(std::string& sourceCode, const std::string& logFilePath);
bool checkIfSourceCodeRequiresAdjustment(const std::string& sourceCode, const std::string& requirement);
std::string generateLoggingFunctionality(const std::string& logFilePath);
std::string mergeSourceCodeAndLogging(const std::string& sourceCode, const std::string& loggingFunctionality);
void applyLoggingToSourceCode(std::string& sourceCode, const std::string& logFilePath);

void adjustSourceCodeForLogging(std::string& sourceCode, const std::string& logFilePath) {
  std::string loggingFunctionality = generateLoggingFunctionality(logFilePath);
  sourceCode = mergeSourceCodeAndLogging(sourceCode, loggingFunctionality);
}

bool checkIfSourceCodeRequiresAdjustment(const std::string& sourceCode, const std::string& requirement) {
  if (sourceCode.find("log") == std::string::npos) {
    if (requirement.find("logging") != std::string::npos) {
      return true;
    }
  }
  return false;
}

std::string generateLoggingFunctionality(const std::string& logFilePath) {
  if (logFilePath.empty()) {
    return "// No logging functionality\n";\n}\nreturn "#include <iostream>\n#include <fstream>\n\nvoid log(const std::string& message) {\nstd::ofstream logFile("" + logFilePath);
if (logFile.is_open()) {
logFile << message << std::endl;
logFile.close();
} else {
std::cerr << "Failed to open log file: " << logFilePath << std::endl;
}
}
";\n}

std::string mergeSourceCodeAndLogging(const std::string& sourceCode, const std::string& loggingFunctionality) {
  size_t insertPosition = sourceCode.find("// No logging functionality");\nif (insertPosition == std::string::npos) {\ninsertPosition = sourceCode.find("// Logging functionality");\n}
  if (insertPosition == std::string::npos) {
    insertPosition = sourceCode.find("// No logging functionality");\n}\nreturn sourceCode.substr(0, insertPosition) + loggingFunctionality + sourceCode.substr(insertPosition);\n}

void applyLoggingToSourceCode(std::string& sourceCode, const std::string& logFilePath) {
  if (checkIfSourceCodeRequiresAdjustment(sourceCode, "logging")) {
    std::string loggingFunctionality = generateLoggingFunctionality(logFilePath);
    sourceCode = mergeSourceCodeAndLogging(sourceCode, loggingFunctionality);
  }
}

