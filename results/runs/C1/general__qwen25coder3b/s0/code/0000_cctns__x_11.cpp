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
std::string getHelpForActionAndScenario(const std::string& action, const std::string& scenario);

std::string generateHelpContent(const std::string& action, const std::string& scenario) {
  std::string helpContent;
  helpContent += "Help for action: " + action + " and scenario: " + scenario;
  return helpContent;
}

void displayHelp(const std::string& helpContent) { std::cout << helpContent << std::endl; }

std::string getHelpForAction(const std::string& action) {
  static std::map<std::string, std::string> helpMap = {
    {"action1", "Help content for action1"},
    {"action2", "Help content for action2"},
    {"action3", "Help content for action3"}
  };
  return helpMap[action];
}

std::string getHelpForScenario(const std::string& scenario) {
  static std::map<std::string, std::string> helpMap = {
    {"scenario1", "Help content for scenario1"},
    {"scenario2", "Help content for scenario2"},
    {"scenario3", "Help content for scenario3"}
  };
  return helpMap[scenario];
}

std::string getHelpForActionAndScenario(const std::string& action, const std::string& scenario) {
  static std::map<std::string, std::string> helpMap;
  if (helpMap.empty()) {
    helpMap = {
      {"action1", "Help content for action1"},
      {"action2", "Help content for action2"},
      {"action3", "Help content for action3"},
      {"scenario1", "Help content for scenario1"},
      {"scenario2", "Help content for scenario2"},
      {"scenario3", "Help content for scenario3"}
    };
  }
  return generateHelpContent(action, scenario);
}

