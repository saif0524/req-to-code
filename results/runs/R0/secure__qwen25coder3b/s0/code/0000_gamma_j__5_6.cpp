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

void displayHelpBubble(const std::string& message, const std::string& targetElementId);
std::string locateButton(const std::string& buttonName);
void promptError(const std::string& errorMessage);
void useConsistentSymbolsAndColors();

void displayHelpBubble(const std::string& message, const std::string& targetElementId) {
  static std::unique_ptr<HTMLDivElement> helpBubble;

  if (!helpBubble) {
    helpBubble = std::make_unique<HTMLDivElement>();
    helpBubble->classList.add('help-bubble');
    document.body.appendChild(helpBubble.get());
  }

  if (message.empty()) return;

  const auto targetElement = document.getElementById(targetElementId);
  if (!targetElement) return;

  helpBubble->textContent = message;
  helpBubble->style.position = 'absolute';
  helpBubble->style.left = targetElement.offsetLeft + 'px';
  helpBubble->style.top = targetElement.offsetTop + targetElement.offsetHeight + 'px';
  helpBubble->style.display = 'block';
}

std::string locateButton(const std::string& buttonName) {
  for (const auto& element : document.querySelectorAll('*')) {
    if (element.classList.contains(buttonName)) {
      return element.id;
    }
  }
  return "";
}

void promptError(const std::string& errorMessage) {
  alert(errorMessage);
}

static std::map<std::string, std::pair<std::string, std::string>> notificationSymbolsAndColors = {
  {"info", {"info-symbol", "info-color"}},
  {"warning", {"warning-symbol", "warning-color"}},
  {"error", {"error-symbol", "error-color"}}
};

void useConsistentSymbolsAndColors(const std::string& notificationType) {
  auto it = notificationSymbolsAndColors.find(notificationType);
  if (it != notificationSymbolsAndColors.end()) {
    const auto& [symbol, color] = it->second;
    // Use the symbol and color for the notification
  }
}

