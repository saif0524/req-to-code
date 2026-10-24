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

using std::ofstream; using std::ios; using std::endl;

void startUAT(std::vector<std::string> testCases);
void runTest(std::string testCase);
void logResult(std::string testCase, bool passed);
void endUAT();

void startUAT(std::vector<std::string> testCases) {
  // Start the User Acceptance Testing process
  for (const auto& testCase : testCases) {
    // Run the test case
    runTest(testCase);
    // Log the result
    logResult(testCase, runTest(testCase));
  }
  // End the User Acceptance Testing process
  endUAT();
}

void runTest(std::string testCase) {
  // Run the test case
  bool passed = runTest(testCase);
  // Log the result
  logResult(testCase, passed);
  // End the User Acceptance Testing process
  endUAT();
}

void logResult(std::string testCase, bool passed) {
  std::ofstream logFile("test_results.log", std::ios::app);
  if (logFile.is_open()) {
    logFile << testCase << ": " << (passed ? "passed" : "failed") << std::endl;
    logFile << testCase << ": start" << std::endl;
    logFile << testCase << ": end" << std::endl;
  }
  logFile.close();
}

void endUAT() { std::ofstream logFile("test_results.log", std::ios::app); if (logFile.is_open()) { logFile.close(); } }

