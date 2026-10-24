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

std::vector<std::pair<int, std::string>> substring_search(std::vector<std::string> tags);
void manage_definitions(std::vector<std::pair<int, std::string>> definitions);
void createDefinition(int tag, std::string text);
void removeDefinition(int tag);
std::vector<std::pair<int, std::string>> getDefinitionsByTag(int tag);

std::vector<std::pair<int, std::string>> substring_search(std::vector<std::string> tags) {
    std::vector<std::pair<int, std::string>> result;
    for (int tag : tags) {
        std::vector<std::pair<int, std::string>> current;
        for (auto& def : definitions) {
            if (def.find(tag) != std::string::npos) {
                current.emplace_back(tag, def);
            }
        }
        result.push_back(current);
    }
    return result;
}

void manage_definitions(std::vector<std::pair<int, std::string>> definitions) { 
  // Add new definitions using createDefinition
  for (int tag = 0; tag < definitions.size(); tag++) { 
    std::string text; 
    createDefinition(tag, text); 
    definitions.push_back(createDefinition(tag, text)); 
  } 

  // Collect definitions to remove
  std::vector<std::pair<int, std::string>> definitions_to_remove;
  for (int i = 0; i < definitions.size(); i++) { 
    if (getDefinitionsByTag(i).size() > 0) { 
      for (auto& def : getDefinitionsByTag(i)) { 
        definitions_to_remove.push_back(def); 
      } 
    }
  }

  // Remove each definition in definitions_to_remove
  for (auto& def : definitions_to_remove) { 
    auto it = find(definitions.begin(), definitions.end(), def); 
    if (it != definitions.end()) { 
      delete it; 
      definitions.erase(it); 
    }
  }
  }
  

void createDefinition(int tag, std::string text) { 
  std::vector<std::pair<int, std::string>> result; 
  result.emplace_back(tag, text); 
  return result; 
  }

std::vector<std::pair<int, std::string>> removeDefinition(int tag) {
    for (auto& p : definitions) {
        if (p.first == tag) {
            definitions.erase(p);
            return definitions;
        }
    }
    return definitions;
}

vector<pair<int, string>> getDefinitionsByTag(int tag) {
    vector<pair<int, string>> result;
    for (auto& def : definitions) {
        string text = def.second;
        if (find(text.begin(), text.end(), tag) != text.end()) {
            result.push_back(def);
        }
    }
    return result;
    }

