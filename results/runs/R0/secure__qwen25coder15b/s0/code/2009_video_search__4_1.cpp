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

void display_main_screen(const std::vector<Video>& videos);
void handle_video_selection(const std::vector<Video>& videos);
void update_video_list(const std::vector<Video>& videos);
void display_video_details(const Video& video);
void handle_video_search(const std::string& query);

void display_main_screen(const std::vector<Video>& videos) {
  // Display the list of videos
  for (const auto& video : videos) {
    std::cout << video.title << std::endl;
  }
}

void handle_video_selection(const std::vector<Video>& videos) {
  for (const auto& video : videos) {
    std::cout << video.title << std::endl;
  }
}

void update_video_list(const std::vector<Video>& videos) {
  for (const auto& video : videos) {
    std::cout << video.title << std::endl;
  }
}

void display_video_details(const Video& video) {
  std::cout << "Title: " << video.title << std::endl;
  std::cout << "Description: " << video.description << std::endl;
  std::cout << "Duration: " << video.duration << std::endl;
  std::cout << "Rating: " << video.rating << std::endl;
}

void handle_video_search(const std::string& query) {
  std::vector<Video> matching_videos;
  for (const auto& video : videos) {
    if (video.title.find(query) != std::string::npos || video.description.find(query) != std::string::npos) {
      matching_videos.push_back(video);
    }
  }
  return matching_videos;
}

