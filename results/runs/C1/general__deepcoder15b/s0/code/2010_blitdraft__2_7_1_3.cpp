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

C++17 functions are used
I haven't included any new functionality in added_declarations as per the requirements.

string createHelpWindow(string title, int x, int y);
int selectTopic(int index);
void displayTopic(int index);
void manageTopic(int index);
void handleNavigation(int currentIndex);

int selectTopic(int index) {
  // Get the click position
  int pos = getClickPosition();
  // Create help window with selected title
  createHelpWindow(

void displayTopic(int index) {
  createHelpWindow(selectedIndex, output);
  return JSON::create({
    "reasoning": "Create a new help window focused on the selected topic and display its content"
  });
}

void manageTopic(int index) {
  selectedIndex = index; // Update the selected topic index
  if (selectedIndex != -1) {
    createHelpWindow(selectedIndex, output);
  }
  return;
}

void handleNavigation(int currentIndex) {
  if (currentIndex < 0 || currentIndex >= num_topics) {
    return;
  }
  currentIndex += 1;
  if (currentIndex >= num_topics) {
    currentIndex = -1;
  }
  createHelpWindow(currentIndex, output);
}

