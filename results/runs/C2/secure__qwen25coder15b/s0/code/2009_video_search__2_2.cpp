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

struct Video; using VideoSearchEngine = /* your namespace */;
struct VideoSearchEngine;

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
  for (const auto& video : results) {
    std::cout << video.title << '
';
    std::cout << video.size << '
';
    std::cout << video.site << '
';
    std::cout << video.age_filter << '
';
    std::cout << video.website_filter << '
';
    std::cout << std::endl;
  }
}

struct Video { std::string title; std::string size; std::string site; std::string age_filter; std::string website_filter; std::string content; };

void save_favorite_video(const Video& video) { VideoSearchEngine::save_favorite_video(video); }

struct VideoSearchEngine { static std::vector<Video> load_favorite_videos(); };

