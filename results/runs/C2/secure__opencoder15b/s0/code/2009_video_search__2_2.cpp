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
    return search_results;
}

std::vector<SearchResult> get_results() { 
     // Implementation goes here 
     return search_results; 
 }

void save_video(const Video& video) {
     // Implementation goes here
     auto it = std::find(search_results.begin(), search_results.end(), video);
      if (it != search_results.end()) {
         search_results.erase(it);
     }
     favorites.push_back(video);
}

std::vector<Video> get_favorites() { 
    // Implementation goes here 
    return search_results; 
}

void remove_video(const Video& video) {
     // Implementation goes here
     auto it = std::find(search_results.begin(), search_results.end(), video);
      if (it != search_results.end()) {
         search_results.erase(it);
     }
     auto it_fav = std::find(favorites.begin(), favorites.end(), video);
      if (it_fav != favorites.end()) {
         favorites.erase(it_fav);
     }
}

