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

std::vector<std::string> filter_function(std::vector<std::string> results);
void display_function(std::vector<std::string> links);
void add_link_function(std::string link);

std::vector<std::string> filter_function(std::vector<std::string> results) {
    std::vector<std::string> filtered;
    const int target_length = 10; // Assume we want URLs of exactly 10 characters
    for (const std::string& url : results) {
        if (url.length() == target_length) {
            filtered.push_back(url);
        }
    }
    return filtered;
}

void display_function(std::vector<std::string> links) {
  std::string result = "";
  for (const std::string& url : links) {
    if (url.empty()) {
      continue;
    }
    std::string formatted_url;
    // Remove any leading or trailing whitespace
    size_t start = url.find first not of [\t]/&;
    size_t end = url.find last not of [\t]/&;
    if (start == std::string::npos) {
      formatted_url = url;
    } else {
      formatted_url = url.substr(start, url.length() - start);
    }
    result += "https://example.com" + formatted_url + "";\n}\nreturn { "reasoning": [ \n"Check each link in the filtered list", 
    "Format each URL by trimming whitespace", 
    "Build the displayed URL string", 
    "Return the formatted JSON result" },
    result
  };
}

void add_link_function(std::string link) {
  if (search_function().empty()) {
    std::vector<std::string> new_vector;
    new_vector.push_back(link);
    return new_vector;
  }
  std::vector<std::string> existing_vector = search_function().get();
  existing_vector.push_back(link);
  return existing_vector;
}

