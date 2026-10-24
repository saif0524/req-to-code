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

std::string generateGlossary(const std::vector<std::pair<std::string, std::string>>& terms);
std::string formatGlossary(const std::string& glossary);
void displayGlossary(const std::string& formattedGlossary);
std::string generateHelpContent(const std::string& glossary);
void updateHelpTool(const std::string& helpContent);

std::string generateGlossary(const std::vector<std::pair<std::string, std::string>>& terms) {
  std::string glossary;
  for (const auto& [term, definition] : terms) {
    glossary += "- " + term + ": " + definition + "\n";
  }
  return glossary;
}

std::string formatGlossary(const std::string& glossary) {
  std::string formattedGlossary;
  std::istringstream iss(glossary);
  std::string line;
  while (std::getline(iss, line)) {
    if (!line.empty()) {
      line.erase(0, 1); // Remove the leading dash
      formattedGlossary += "- " + line + "\n";
    }
  }
  return formattedGlossary;
}

void displayGlossary(const std::string& formattedGlossary) {
  std::cout << formattedGlossary << std::endl;
}

std::string generateHelpContent(const std::string& glossary) {
  std::string helpContent = "\nGlossary:\n";
  helpContent += glossary;
  return helpContent;
}

void updateHelpTool(const std::string& helpContent) {
  std::cout << helpContent << std::endl;
}

