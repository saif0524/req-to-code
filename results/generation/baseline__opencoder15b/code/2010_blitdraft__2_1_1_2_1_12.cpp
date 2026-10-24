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

void initializeTabs();
void selectTab(int tabIndex);
void createUser(User user);
void addUser(User user);
void editUser(User user);

void initializeTabs() {
  // Assuming that the default tab index is 0
  selectTab(0);
}

void selectTab(int tabIndex) {
   // Assuming that the default tab index is 0
   if (tabIndex >= 0 && tabIndex < numberOfTabs) {
       // Code to select the tab
   }
}

void createUser(User user) {
    // Initialize tabs
    initializeTabs();

    // Select the first tab
    selectTab(0);

    // Add the new user
    addUser(user);
}

void addUser(User user) {
    // Assuming that the default tab index is 0
    initializeTabs();

    // Select the first tab
    selectTab(0);

    // Add the new user
    addUser(user);
}

void editUser(User user) {
    // Initialize tabs
    initializeTabs();

    // Select the first tab
    selectTab(0);

    // Add the new user
    addUser(user);
}

