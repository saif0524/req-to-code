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

[[Tab struct]]

int switchTab(int currentTabId)";
int defaultTab = 0;";
std::string TabMessage()";

int switchTab(int currentTabId) {
    if (currentTabId != defaultTab) {
        currentTabId = defaultTab;
        return 1;
    }
    return 0;
    }

int defaultTab() {
    if (currentTabId != defaultTab) {
        currentTabId = defaultTab;
        return 1;
    }
    return 0;
    }

std::string TabMessage() {
    static std::string defaultMessage = "Default tab message";
    static std::map<int, std::string> tabMessages = {
        {1, "Message for tab 1"},
        {2, "Message for tab 2"},
        // Add more entries as needed
    };
    if (currentTabId == defaultTab) {
        return defaultMessage;
    } else {
        return tabMessages[currentTabId];
    }
    }

