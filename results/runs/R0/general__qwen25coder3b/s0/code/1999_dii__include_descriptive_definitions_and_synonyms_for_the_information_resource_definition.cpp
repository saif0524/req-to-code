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

std::vector<std::string> generateExpressiveTerms(const std::string& description);
std::string findDesirableTag(const std::vector<std::string>& expressiveTerms, const std::string& registeredTag);
void registerTagAndDescription(const std::string& registeredTag, const std::string& description);

std::vector<std::string> generateExpressiveTerms(const std::string& description) {
  std::istringstream iss(description);
  std::vector<std::string> words;
  std::string word;

  // Split the description into words
  while (iss >> word) {
    words.push_back(word);
  }

  // Define a set of common stop words
  std::unordered_set<std::string> stopWords = {
    "the", "and", "is", "in", "to", "a", "of", "for", "on", "with", "by", "at", "as", "an", "this", "that", "it", "or", "but", "if", "so", "not"
  };

  // Define a set of predefined keywords
  std::unordered_set<std::string> keywords = {
    "natural", "concept", "term", "definition", "expressive", "find", "register", "tag", "description"
  };

  // Filter out stop words and identify expressive terms
  std::vector<std::string> expressiveTerms;
  for (const auto& w : words) {
    if (stopWords.find(w) == stopWords.end() && keywords.find(w) != keywords.end()) {
      expressiveTerms.push_back(w);
    }
  }

  return expressiveTerms;
}

std::string findDesirableTag(const std::vector<std::string>& expressiveTerms, const std::string& registeredTag) {
  if (std::find(expressiveTerms.begin(), expressiveTerms.end(), registeredTag) != expressiveTerms.end()) {
    return registeredTag;
  }

  std::unordered_map<std::string, int> termFrequency;
  for (const auto& term : expressiveTerms) {
    termFrequency[term]++;
  }

  std::string desirableTag;
  int maxFrequency = 0;
  for (const auto& pair : termFrequency) {
    if (pair.second > maxFrequency) {
      maxFrequency = pair.second;
      desirableTag = pair.first;
    }
  }

  return desirableTag;
}

void registerTagAndDescription(const std::string& registeredTag, const std::string& description) {
  std::vector<std::string> expressiveTerms = generateExpressiveTerms(description);
  std::string desirableTag = findDesirableTag(expressiveTerms, registeredTag);
  // Store the tag and description in a data structure or database
  // Example: std::map<std::string, std::string> registry;
  // registry[registeredTag] = description;
}

