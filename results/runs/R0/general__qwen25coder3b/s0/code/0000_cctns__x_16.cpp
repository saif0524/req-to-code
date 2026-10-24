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

std::string generateErrorMessage(const std::string& errorCode, const std::string& errorMessage, const std::string& action);
void applyUserInterfaceRules(UserInterface& ui);
void displayEntities(const std::vector<Entity>& entities);
void configureUserInterface(UserInterface& ui, const UserPreferences& preferences);
void makeUserInterfaceAccessible(UserInterface& ui);

std::string generateErrorMessage(const std::string& errorCode, const std::string& errorMessage, const std::string& action) {
  return "Error Code: " + errorCode + ", Error Message: " + errorMessage + ", Action: " + action;
}

void applyUserInterfaceRules(UserInterface& ui) {
  ui.apply();
}

void displayEntities(const std::vector<Entity>& entities) {
  for (const auto& entity : entities) {
    std::cout << entity.display() << std::endl;
  }
}

void configureUserInterface(UserInterface& ui, const UserPreferences& preferences) {
  ui.apply(preferences);
}

void makeUserInterfaceAccessible(UserInterface& ui) {
  ui.setAccessibility(true);
}

