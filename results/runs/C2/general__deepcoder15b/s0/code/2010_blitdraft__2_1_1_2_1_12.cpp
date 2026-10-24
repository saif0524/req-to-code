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

defaultTab = "Default Tab"; std::string TabMessage()

int switchTab(int currentTabId)";
void addData(int currentTabId, std::string data)";
int defaultTab = 0;";
std::string TabMessage()";

int switchTab(int currentTabId) {
    if (currentTabId != defaultTab) {
        currentTabId = defaultTab;
        return 1;
    }
    return 0;
    }

void addData(int currentTabId, std::string data) {
  if (currentTabId == defaultTab) {
    return "Default message" + data;
  } else {
    return tabMessages[currentTabId] + data;
  }
  }

int defaultTabId(int currentTabId) { if (currentTabId != defaultTab) { currentTabId = defaultTab; return 1; } return 0; }

std::string TabMessage() {
if (currentTabId == defaultTab) {
return "Default message";
}
return std::to_string(currentTabId) + " message";
}

