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

void showHelpTopic(int topicId);
void hideHelpTopic();
void nextHelpTopic();
void previousHelpTopic();
int getHelpTopicId();

void showHelpTopic(int topicId) {
  // Implementation of the function
}

void hideHelpTopic() {
   helpWindow.hide();
}

void nextHelpTopic() {
    int currentTopic = getHelpTopicId();
    if (currentTopic < getNumberOfHelpTopics() - 1) {
        hideHelpTopic();
        showHelpTopic(currentTopic + 1);
    }
}

void previousHelpTopic() {
     int currentTopic = getHelpTopicId();
     if (currentTopic > 0) {
         hideHelpTopic();
         showHelpTopic(currentTopic - 1);
     }
}

int getHelpTopicId() {
    return helpWindow.getCurrentTopicId();
}

