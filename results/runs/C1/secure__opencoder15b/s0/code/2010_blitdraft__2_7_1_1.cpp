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

void showHelpPopup(const std::string& helpTopic);

void showHelpPopup(const std::string& helpTopic) {
  // Open a pop-up window displaying information about the specified help topic.
  // The actual implementation of this function would involve creating a new window or using an existing window to display the help topic.
  // This is a simplified example and does not include any error checking or resource management.
  std::cout << "Help topic: " << helpTopic << std::endl;
}

