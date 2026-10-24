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

void displayHelpBubbles(const std::vector<std::string>& helpMessages);
void locateButtons(const std::vector<std::string>& buttonNames);
void promptCustomerErrors(const std::vector<std::string>& errorMessages);
void useConsistentSymbolsAndColors(const std::vector<std::string>& symbolAndColorPairs);

void displayHelpBubbles(const std::vector<std::string>& helpMessages) {
  for (const auto& message : helpMessages) {
    std::cout << message << std::endl;
  }
}

void locateButtons(const std::vector<std::string>& buttonNames) {
  for (const auto& buttonName : buttonNames) {
    std::cout << buttonName << std::endl;
  }
}

void promptCustomerErrors(const std::vector<std::string>& errorMessages) {
  for (const auto& message : errorMessages) {
    std::cout << message << std::endl;
  }
}

void useConsistentSymbolsAndColors(const std::vector<std::string>& symbolAndColorPairs) {
  for (const auto& pair : symbolAndColorPairs) {
    std::cout << pair << std::endl;
  }
}

