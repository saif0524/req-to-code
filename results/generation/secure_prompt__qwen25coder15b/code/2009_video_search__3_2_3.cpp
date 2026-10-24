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

void update_video_database(const std::string& url);
std::vector<VideoResult> search_video_hosting(const std::string& query);
std::vector<VideoResult> search_video_links(const std::string& query);
void display_results(const std::vector<VideoResult>& results);
void sort_results(std::vector<VideoResult>& results);

void update_video_database(const std::string& url) {
  std::mutex mtx;
  mtx.lock();

  CURL* curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &video_database);

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      std::cerr << 

std::vector<VideoResult> search_video_hosting(const std::string& query) {
  std::vector<VideoResult> results;

  CURL* curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/video_database.json");\ncurl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);\ncurl_easy_setopt(curl, CURLOPT_WRITEDATA, &video_database);\n
    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      std::cerr << "Error fetching video database: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  // Perform the search on the video hosting sites
  results = VideoSearchEngine::search_video_hosting(query);

  return results;
}

std::vector<VideoResult> search_video_links(const std::string& query) {
  std::vector<VideoResult> results;

  CURL* curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/video_database.json");\ncurl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);\ncurl_easy_setopt(curl, CURLOPT_WRITEDATA, &video_database);\n
    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      std::cerr << "Error fetching video database: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  // Perform the search on the video hosting sites
  results = VideoSearchEngine::search_video_hosting(query);

  // Filter the results to only include those from video link sites
  for(auto& result : results) {
    if(result.site == "video_link_site") {
      results.push_back(result);
    }
  }

  return results;
}

void display_results(const std::vector<VideoResult>& results) {
  if(results.empty()) {
    std::cout << "No results were found for this search." << std::endl;
    return;
  }

  std::cout << "Results:\n" << std::endl;

  std::cout << std::setw(20) << "Title" << std::setw(10) << "Length" << std::setw(15) << "Date" << std::setw(30) << "Link" << std::endl;

  for(const auto& result : results) {
    std::cout << std::setw(20) << result.title << std::setw(10) << result.length << std::setw(15) << result.date << std::setw(30) << result.link << std::endl;
  }
}

void sort_results(std::vector<VideoResult>& results) {
  std::sort(results.begin(), results.end(), [](const VideoResult& a, const VideoResult& b) {
    if(a.length != b.length) {
      return a.length < b.length;
    }
    if(a.date != b.date) {
      return a.date < b.date;
    }
    return a.title < b.title;
  });
}

