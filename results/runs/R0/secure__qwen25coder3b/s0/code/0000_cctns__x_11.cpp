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

std::string generateHelpContent(const std::string& action, const std::string& scenario);
void displayHelp(const std::string& helpContent);
std::string getHelpForAction(const std::string& action);
std::string getHelpForScenario(const std::string& scenario);
std::string combineHelpContent(const std::string& actionHelp, const std::string& scenarioHelp);

std::string generateHelpContent(const std::string& action, const std::string& scenario) {
  if (action.empty() || scenario.empty()) {
    return "";
  }
  // Detailed context-sensitive help content generation logic goes here
  // For example:
  // return "Help content for action: " + action + " and scenario: " + scenario;
  return "Help content generated for action: " + action + " and scenario: " + scenario;
}

void displayHelp(const std::string& helpContent) {
  if (!helpContent.empty()) {
    std::cout << helpContent << std::endl;
  }
}

std::string getHelpForAction(const std::string& action) {
  return generateHelpContent(action, "");
}

std::string getHelpForScenario(const std::string& scenario) {
  return generateHelpContent("", scenario);
}

std::string combineHelpContent(const std::string& actionHelp, const std::string& scenarioHelp) {
  if (actionHelp.empty() || scenarioHelp.empty()) {
    return "";
  }
  return actionHelp + scenarioHelp;
}

