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

void createHelpWindow(const std::vector<std::string>& topics, const std::vector<std::string>& links);
void populateLeftFrame(const std::vector<std::string>& topics, const std::vector<std::string>& links);
void handleLinkSelection(const std::string& selectedLink);
void displayHelpContent(const std::string& helpContent);
void updateHelpWindow(const std::vector<std::string>& topics, const std::vector<std::string>& links);

void createHelpWindow(const std::vector<std::string>& topics, const std::vector<std::string>& links) {
  populateLeftFrame(topics, links);
}

void populateLeftFrame(const std::vector<std::string>& topics, const std::vector<std::string>& links) {
  std::ostringstream leftFrameContent;
  for (size_t i = 0; i < topics.size(); ++i) {
    leftFrameContent << topics[i] << " : " << links[i] << "\n";
  }
  // Display the content in the left frame
  std::cout << leftFrameContent.str() << std::endl;
}

void handleLinkSelection(const std::string& selectedLink) {
  std::string helpContent;
  // Logic to find the help content based on the selected link
  // For example, if 'selectedLink' is 'topic1', find the corresponding help content
  // and store it in 'helpContent'
  displayHelpContent(helpContent);
}

void displayHelpContent(const std::string& selectedLink) {
  std::map<std::string, std::string> helpContentMap = {
    {"topic1", "Content for topic1"},
    {"topic2", "Content for topic2"},
    // Add more topics and their content as needed
  };

  auto it = helpContentMap.find(selectedLink);
  if (it != helpContentMap.end()) {
    std::cout << it->second << std::endl;
  } else {
    std::cout << "Help content not found" << std::endl;
  }
}

void updateHelpWindow(const std::vector<std::string>& topics, const std::vector<std::string>& links) {
  // Clear the current content of the left frame
  std::cout << "\n"; // Add a newline to clear the previous content

  // Repopulate the left frame with the new list of topics and links
  populateLeftFrame(topics, links);
}

