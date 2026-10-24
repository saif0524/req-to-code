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
  // Open a pop-up window displaying information about the specific page along with links to supporting help topics.
  // This is a stub implementation. In a real-world scenario, you would use a library or API to open the pop-up window.
  std::cout << "Opening help popup: " << helpTopic << std::endl;
}

