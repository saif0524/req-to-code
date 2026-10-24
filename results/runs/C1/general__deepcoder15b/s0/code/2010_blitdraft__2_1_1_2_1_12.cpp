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

void addData(int currentTabId, std::string data)
    {
        std::map<int, std::string> tabMessages = {
            {1, "Message for tab 1"},
            {2, "Message for tab 2"},
            // Add more entries as needed
        };
        if (currentTabId == defaultTab)
        {
            return "Default message" + data;
        }
        else
        {
            return tabMessages[currentTabId] + data;
        }
    }
    

int defaultTab() { if (currentTabId != defaultTab) { currentTabId = defaultTab; return 1; } return 0; }

std::string TabMessage() { if (currentTabId == defaultTab) return "Default tab message"; else return std::map<int, std::string>::begin().search(currentTabId) ? std::map<int, std::string>[currentTabId].first : "Default tab message"; }

