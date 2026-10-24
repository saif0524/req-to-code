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

std::string query;
std::string result;

void main_screen();
void display_video(const std::string& video_id);
void search_videos(const std::string& query);
void handle_user_input(const std::string& input);
void update_ui();

void main_screen() {
   std::string query = get_current_search_query();
   std::vector<std::string> videos = search_videos(query);

   // Display the main screen with the current query and videos
   display_main_screen(query, videos);
}

void display_video(const std::string& video_id) {
    std::vector<std::string> videos = search_videos(get_current_search_query());
    std::string result = "";
    for (const auto& video : videos) {
        if (video == video_id) {
            display_main_screen(get_current_search_query(), video_id);
            return;
        }
    }
    display_main_screen(get_current_search_query(), "Video not found.");
}

void search_videos(const std::string& query) {
     std::vector<std::string> videos = search_videos(get_current_search_query());
     std::string result = "";
     for (const auto& video : videos) {
         if (video.find(query) != std::string::npos) {
             result = video;
             break;
         }
     }
     if (result.empty()) {
         result = "Video not found.";
     }
     display_main_screen(get_current_search_query(), result);
}

void handle_user_input(const std::string& input) {
     std::vector<std::string> videos = search_videos(get_current_search_query());
     std::string result = "";
     for (const auto& video : videos) {
         if (video.find(input) != std::string::npos) {
             result = video;
             break;
         }
     }
     if (result.empty()) {
         result = "Video not found.";
     }
     display_main_screen(get_current_search_query(), result);
}

void update_ui() {
     std::string query = get_current_search_query();
     std::vector<std::string> videos = search_videos(query);

     // Display the main screen with the current query and videos
     display_main_screen(query, videos);
}

