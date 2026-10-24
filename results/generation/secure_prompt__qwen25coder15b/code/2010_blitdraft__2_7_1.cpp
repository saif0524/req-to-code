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

void createHelpLink(const std::string& systemName, const std::string& helpTopic);
void displayHelpTopic(const std::string& systemName, const std::string& helpTopic);
void updateHelpLink(const std::string& systemName, const std::string& helpTopic);
void handleHelpClick(const std::string& systemName, const std::string& helpTopic);

void createHelpLink(const std::string& systemName, const std::string& helpTopic) {
  std::string url = systemName + '/' + helpTopic;
  // Create the hypertext link using the URL
}

void displayHelpTopic(const std::string& systemName, const std::string& helpTopic) {
  std::string url = systemName + '/' + helpTopic;
  createHelpLink(systemName, helpTopic);
  // Display the content of the specified Help topic in a pop-up window
}

void updateHelpLink(const std::string& systemName, const std::string& helpTopic) {
  std::string url = systemName + '/' + helpTopic;
  createHelpLink(systemName, helpTopic);
}

void handleHelpClick(const std::string& systemName, const std::string& helpTopic) {
  std::string url = systemName + '/' + helpTopic;
  createHelpLink(systemName, helpTopic);
  displayHelpTopic(systemName, helpTopic);
}

