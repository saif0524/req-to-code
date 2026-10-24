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

struct VideoResult { std::string website; std::string video_name; std::string length; std::string date_posted; };

void start_search(const std::string& search_term);
void query_video_sites(const std::string& search_term);
void query_link_sites(const std::string& search_term);
void display_results(const std::vector<VideoResult>& results);
void sort_results(std::vector<VideoResult>& results, const std::string& column_name, bool ascending);

void start_search(const std::string& search_term) {
  std::vector<VideoResult> video_results = query_video_sites(search_term);
  std::vector<VideoResult> link_results = query_link_sites(search_term);
  std::vector<VideoResult> combined_results = video_results + link_results;
  display_results(combined_results);
  sort_results(combined_results, "length", true);
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

struct VideoResult { std::string website; std::string video_name; std::string length; std::string date_posted; };

struct VideoResult { std::string website; std::string video_name; std::string length; std::string date_posted; };

