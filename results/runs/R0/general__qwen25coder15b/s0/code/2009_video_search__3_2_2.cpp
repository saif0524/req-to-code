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

void start_search(const std::string& search_term);
void query_video_sites(const std::string& search_term);
void query_link_sites(const std::string& search_term);
void display_results(const std::vector<VideoResult>& results);
void sort_results(std::vector<VideoResult>& results, const std::string& column_name, bool ascending);

void start_search(const std::string& search_term) {
  query_video_sites(search_term);
  query_link_sites(search_term);
  display_results(query_video_sites(search_term) + query_link_sites(search_term));
  sort_results(query_video_sites(search_term) + query_link_sites(search_term), "length", true);
}

void query_video_sites(const std::string& search_term) {
  std::vector<VideoResult> video_results = query_video_sites(search_term);
  std::vector<VideoResult> link_results = query_link_sites(search_term);
  std::vector<VideoResult> combined_results = video_results + link_results;
  display_results(combined_results);
}

void query_link_sites(const std::string& search_term) {
  std::vector<VideoResult> video_results = query_video_sites(search_term);
  std::vector<VideoResult> link_results = query_video_sites(search_term);
  std::vector<VideoResult> combined_results = video_results + link_results;
  display_results(combined_results);
}

void display_results(const std::vector<VideoResult>& results) {
  // Display the search results in the video stream tab
  for (const auto& result : results) {
    // Display the website, full video name, length, and date posted
    std::cout << result.website << '	' << result.video_name << '	' << result.length << '	' << result.date_posted << std::endl;
  }
}

void sort_results(std::vector<VideoResult>& results, const std::string& column_name, bool ascending) {
  std::sort(results.begin(), results.end(), [&](const VideoResult& a, const VideoResult& b) {
    if (column_name == "website") {
      return ascending ? a.website < b.website : a.website > b.website;
    } else if (column_name == "video_name") {
      return ascending ? a.video_name < b.video_name : a.video_name > b.video_name;
    } else if (column_name == "length") {
      return ascending ? a.length < b.length : a.length > b.length;
    } else if (column_name == "date_posted") {
      return ascending ? a.date_posted < b.date_posted : a.date_posted > b.date_posted;
    }
    return false;
  });
}

