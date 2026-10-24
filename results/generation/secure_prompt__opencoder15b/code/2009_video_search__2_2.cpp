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

void search(const std::string& query, const std::vector<std::string>& types, bool only_youtube, bool adult_content, bool only_specific_websites);
std::vector<SearchResult> get_results();
void save_video(const Video& video);
std::vector<Video> get_favorites();
void remove_video(const Video& video);

void search(const std::string& query, const std::vector<std::string>& types, bool only_youtube, bool adult_content, bool only_specific_websites) {
  // Implementation goes here
}

std::vector<SearchResult> get_results() { 
   // Implementation goes here 
   return search_results; 
}

void save_video(const Video& video) {
    // Implementation goes here
}

std::vector<Video> get_favorites() { 
    // Implementation goes here 
    return search_results; 
}

void remove_video(const Video& video) {
    // Implementation goes here
    search_results.erase(std::remove(search_results.begin(), search_results.end(), video), search_results.end());
}

