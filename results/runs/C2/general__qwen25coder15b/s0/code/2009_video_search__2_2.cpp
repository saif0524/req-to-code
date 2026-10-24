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

struct Video {
  std::string name;
  std::string size;
  std::string site;
  std::string age_filter;
  std::string content;
};
struct Video;

void search_videos(const std::string& query, const std::string& category, const std::string& age_filter, const std::string& website_filter);
void display_results(const std::vector<Video>& results);
void filter_results(std::vector<Video>& results, const std::string& content_filter);
void save_favorite_video(const Video& video);
std::vector<Video> load_favorite_videos();

void search_videos(const std::string& query, const std::string& category, const std::string& age_filter, const std::string& website_filter) {
  VideoSearchEngine::search_videos(query, category, age_filter, website_filter);
  VideoSearchEngine::display_results(VideoSearchEngine::search_videos(query, category, age_filter, website_filter));
  VideoSearchEngine::filter_results(VideoSearchEngine::search_videos(query, category, age_filter, website_filter), content_filter);
  VideoSearchEngine::save_favorite_video(VideoSearchEngine::search_videos(query, category, age_filter, website_filter)[0]);
  VideoSearchEngine::load_favorite_videos();
}

void display_results(const std::vector<Video>& results) {
  std::cout << std::setw(20) << std::left << "Name" << std::setw(20) << std::left << "Size" << std::setw(20) << std::left << "Site" << std::setw(20) << std::left << "Age Filter" << std::endl;
  for (const auto& video : results) {
    std::cout << std::setw(20) << std::left << video.name << std::setw(20) << std::left << video.size << std::setw(20) << std::left << video.site << std::setw(20) << std::left << video.age_filter << std::endl;
  }
}

void filter_results(const std::vector<Video>& results, const std::string& content_filter) {
  std::vector<Video> filtered_results;
  for (const auto& video : results) {
    if (video.content.find(content_filter) != std::string::npos) {
      filtered_results.push_back(video);
    }
  }
  return filtered_results;
}

void save_favorite_video(const Video& video) {
  std::ofstream file("favorites.txt", std::ios::app);
  if (file.is_open()) {
    file << video.name << ',' << video.size << ',' << video.site << ',' << video.age_filter << ',' << video.content << '
';
    file.close();
  } else {
    std::cerr << "Unable to open favorites.txt" << std::endl;
  }
}

void load_favorite_videos() {
  std::ifstream file("favorites.txt", std::ios::app);
  if (file.is_open()) {
    std::vector<Video> favorite_videos;
    std::string line;
    while (std::getline(file, line)) {
      std::istringstream iss(line);
      std::string name, size, site, age_filter, content;
      iss >> name >> size >> site >> age_filter >> content;
      favorite_videos.push_back(Video(name, size, site, age_filter, content));
    }
    file.close();
    return favorite_videos;
  } else {
    std::cerr << "Unable to open favorites.txt" << std::endl;
    return std::vector<Video>();
  }
}

