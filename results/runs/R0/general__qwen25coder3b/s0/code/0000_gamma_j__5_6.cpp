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

void displayHelpBubble(const std::string& message, const std::string& position);
std::string locateButton(const std::string& buttonName);
void promptError(const std::string& errorMessage);
void useConsistentSymbols(const std::string& symbol, const std::string& color);

void displayHelpBubble(const std::string& message, const std::string& position) { displayHelpBubble(message, position); }

std::string locateButton(const std::string& buttonName) { for (const auto& button : buttons) { if (button.name == buttonName) { return button.position; } } return ""; }

void promptError(const std::string& errorMessage) { displayHelpBubble(errorMessage, locateButton("errorButton")); }

void useConsistentSymbols(const std::string& symbol, const std::string& color) { consistentSymbols[symbol] = color; }

