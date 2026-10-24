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

void findGroupSubgroup(const std::string& searchWord, const std::vector<std::string>& fieldsToSearch, const std::vector<std::string>& fieldsToReturn, bool caseSensitive, bool wholeWordsOnly);
std::vector<std::pair<std::string, std::string>> getStimulusResponseSequences();
std::vector<std::pair<std::string, std::string>> getBasicDataFlow();

void findGroupSubgroup(const std::string& searchWord, const std::vector<std::string>& fieldsToSearch, const std::vector<std::string>& fieldsToReturn, bool caseSensitive, bool wholeWordsOnly) {
  // Your implementation here
}

void findGroupSubgroup(const std::string& searchWord, const std::vector<std::string>& fieldsToSearch, const std::vector<std::string>& fieldsToReturn, bool caseSensitive, bool wholeWordsOnly) {
  // Your implementation here
}

std::vector<std::pair<std::string, std::string>> getStimulusResponseSequences() {
  // Your implementation here
}

std::vector<std::pair<std::string, std::string>> getBasicDataFlow() {
  // Your implementation here
}

std::vector<std::pair<std::string, std::string>> getBasicDataFlow() {
   std::vector<std::pair<std::string, std::string>> dataFlow;
   for (const auto& entry : database.getEntries()) {
      for (const auto& field : fieldsToReturn) {
         dataFlow.push_back({field, entry[field]});
      }
   }
   return dataFlow;
}

