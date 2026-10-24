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

std::vector<std::string> search(const std::string& query);
std::string get_definition(const std::string& tag);
bool add_tag(const std::string& tag, const std::string& definition);
bool update_definition(const std::string& tag, const std::string& new_definition);
bool remove_tag(const std::string& tag);

std::vector<std::string> search(const std::string& query) {
  std::vector<std::string> matching_tags;
  for (const auto& tag : registry) {
    if (tag.find(query) != std::string::npos) {
      matching_tags.push_back(tag);
    }
  }
  return matching_tags;
}

std::string get_definition(const std::string& tag) {
   std::string definition = "";
   for (const auto& tag_entry : registry) {
     if (tag_entry.first == tag) {
       definition = tag_entry.second;
       break;
     }
   }
   return definition;
}

bool add_tag(const std::string& tag, const std::string& definition) {
    registry[tag] = definition;
    return true;
}

bool update_definition(const std::string& tag, const std::string& new_definition) {
    if (registry.count(tag) > 0) {
        registry[tag] = new_definition;
        return true;
    }
    return false;
}

bool remove_tag(const std::string& tag) {
    if (registry.count(tag) > 0) {
        registry.erase(tag);
        return true;
    }
    return false;
}

