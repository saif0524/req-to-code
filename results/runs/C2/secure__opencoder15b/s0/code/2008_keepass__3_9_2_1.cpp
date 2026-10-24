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

Database& database, const std::vector<std::string>& fieldsToReturn
std::vector<std::pair<std::string, std::string>> dataFlow;
std::vector<std::pair<std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >

void findGroupSubgroup(const std::string& searchWord, const std::vector<std::string>& fieldsToSearch, const std::vector<std::string>& fieldsToReturn, bool caseSensitive, bool wholeWordsOnly);
std::vector<std::pair<std::string, std::string>> getStimulusResponseSequences();
std::vector<std::pair<std::string, std::string>> getBasicDataFlow();

void findGroupSubgroup(const std::string& searchWord, const std::vector<std::string>& fieldsToSearch, const std::vector<std::string>& fieldsToReturn, bool caseSensitive, bool wholeWordsOnly) {
   std::vector<std::pair<std::string, std::string>> results;
   for (const auto& entry : database.getEntries()) {
     for (const auto& field : fieldsToSearch) {
       if (entry[field] == searchWord) {
         std::vector<std::pair<std::string, std::string>>::iterator it;
         for (const auto& returnField : fieldsToReturn) {
           it = std::find(results.begin(), results.end(), returnField);
           if (it == results.end()) {
             results.push_back({returnField, entry[field]});
           } else {
             it->second = entry[field];
           }
         }
       }
     }
   }
}

std::vector<std::pair<std::string, std::string>> getStimulusResponseSequences() {
     std::vector<std::pair<std::string, std::string>> sequences;
     for (const auto& entry : database.getEntries()) {
         for (const auto& field : fieldsToReturn) {
             sequences.push_back({field, entry[field]});
         }
     }
     return sequences;
}

std::vector<std::pair<std::string, std::string>> getBasicDataFlow(Database& database, const std::vector<std::string>& fieldsToReturn) {
     std::vector<std::pair<std::string, std::string>> dataFlow;
     for (const auto& entry : database.getEntries()) {
        for (const auto& field : fieldsToReturn) {
           dataFlow.push_back({field, entry[field]});
        }
     }
     return dataFlow;
}

