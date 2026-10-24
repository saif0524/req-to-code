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

void main_screen();

void main_screen() {
   // Display the main screen with a list of search results
   std::vector<Video> videos = search_videos(query);
   std::vector<std::string> results;
   for (const auto& video : videos) {
     results.push_back(video.title);
     results.push_back(video.thumbnail_url);
     results.push_back(video.description);
   }
   // Return the JSON with the search results
   return_json(results);
}

