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

std::vector<std::string> extractKeywords(const std::string& description);
std::vector<std::string> findMatchingTags(const std::vector<std::string>& keywords, const std::vector<std::string>& tags);
std::vector<std::string> generateTags(const std::vector<std::string>& keywords);
bool validateDescription(const std::string& description);
void registerTag(const std::string& tag, const std::string& description);

std::vector<std::string> extractKeywords(const std::string& description) {
  std::vector<std::string> keywords;
  std::istringstream stream(description);
  std::string word;

  while (stream >> word) {
    if (word.length() >= 3 && word.length() <= 15 && std::all_of(word.begin(), word.end(), ::isalnum)) {
      keywords.push_back(word);
    }
  }

  return keywords;
}

std::vector<std::string> findMatchingTags(const std::vector<std::string>& keywords, const std::vector<std::string>& tags) {
  std::vector<std::string> matchingTags;

  for (const auto& keyword : keywords) {
    if (std::find(tags.begin(), tags.end(), keyword) != tags.end()) {
      matchingTags.push_back(keyword);
    }
  }

  return matchingTags;
}

std::vector<std::string> generateTags(const std::vector<std::string>& keywords) {
  std::vector<std::string> tags;

  for (size_t i = 0; i < keywords.size(); ++i) {
    for (size_t j = i + 1; j < keywords.size(); ++j) {
      std::string tag = keywords[i] + "_" + keywords[j];
      if (tag.length() <= 20) {
        tags.push_back(tag);
      }
    }
  }

  return tags;
}

bool validateDescription(const std::string& description) {
  if (description.empty() || description.length() > 200) {
    return false;
  }

  std::istringstream stream(description);
  std::string word;

  while (stream >> word) {
    if (word.length() >= 3 && word.length() <= 15 && std::all_of(word.begin(), word.end(), ::isalnum)) {
      return true;
    }
  }

  return false;
}

static std::vector<std::string> tags;
static std::map<std::string, std::string> descriptions;

void registerTag(const std::string& tag, const std::string& description) {
  if (!validateDescription(description)) {
    return;
  }

  if (std::find(tags.begin(), tags.end(), tag) != tags.end()) {
    return;
  }

  tags.push_back(tag);
  descriptions[tag] = description;

  std::cout << "Tag registered successfully: " << tag << std::endl;
}

