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

size_t write_callback(void* ptr, size_t size, size_t nmemb, void* userp) {
  std::vector<char>* buffer = static_cast<std::vector<char>*>(userp);
  buffer->insert(buffer->end(), static_cast<char*>(ptr), size * nmemb);
  return size * nmemb;
}
using namespace std; #include <curl/curl.h>

void search_videos(const std::string& query);
void display_results(const std::vector<std::string>& results);
void download_video(const std::string& video_url);
void stream_video(const std::string& video_url);

void search_videos(const std::string& query) {
  VideoSearchEngine::search_videos(query);
  display_results(VideoSearchEngine::search_videos(query));
}

void display_results(const std::vector<std::string>& results) {
  for (const auto& result : results) {
    std::cout << result << std::endl;
  }
}

void download_video(const std::string& video_url) {
  CURL* curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, video_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
}

void stream_video(const std::string& video_url) {
  CURL* curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, video_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
}

