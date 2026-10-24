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

.cpp17
std::string
createHelpWindow is a function that creates UI elements for the help window, which is already provided in the shared declarations.

string createHelpWindow(string title, int x, int y);
int selectTopic(int index);
void displayTopic(int index);
void manageTopic(int index);
void handleNavigation(int currentIndex);

int selectTopic(int index) {
    return index;
}

void displayTopic(int index) \n  if (index == -1) return JSON::create({"reasoning": 'No topic selected'"\n"code": ''});\ncreateHelpWindow(index, output);\nreturn JSON::create({"reasoning": "Display the selected help topic content"});

void manageTopic(int index) {
  selectedIndex = index; // Update the selected topic index
  if (selectedIndex != -1) {
    createHelpWindow(selectedIndex, output);
  }
  return;
}

void handleNavigation(int currentIndex) 
  if (currentIndex < 0 || currentIndex >= num_topics) 
    return;
  currentIndex += 1;
  if (currentIndex >= num_topics) 
  {
    currentIndex = -1;
    return;
  }
  createHelpWindow(currentIndex, output);

