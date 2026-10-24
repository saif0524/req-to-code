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

struct VideoResult;
struct VideoStreamTab;

void start_search(const std::string& search_term);
void query_video_sites(const std::string& search_term);
void query_link_sites(const std::string& search_term);
void display_results(const std::vector<VideoResult>& results);
void sort_results(std::vector<VideoResult>& results, const std::string& column_name, bool ascending);

void start_search(const std::string& search_term) {

  std::vector<VideoResult> video_results = query_video_sites(search_term);
  std::vector<VideoResult> link_results = query_link_sites(search_term);

  std::vector<VideoResult> combined_results = video_results + link_results;

  VideoStreamTab::display_results(combined_results);

  VideoStreamTab::sort_results(combined_results, "length", true);
}

void query_video_sites(const std::string& search_term) {
  std::vector<VideoResult> video_results = query_video_sites(search_term);
  display_results(video_results);
}

using namespace std;

struct VideoResult {
  std::string website;
  std::string video_name;
  int length;
  std::string date_posted;
};

void query_link_sites(const std::string& search_term) {
  std::vector<VideoResult> video_results = query_link_sites(search_term);
  display_results(video_results);
}

void display_results(const std::vector<VideoResult>& results) {
  VideoStreamTab::display_results(results);
  VideoStreamTab::sort_results(results, "length", true);
}

void sort_results(std::vector<VideoResult>& results, const std::string& column_name, bool ascending) {
  std::sort(results.begin(), results.end(), [column_name, ascending](const VideoResult& a, const VideoResult& b) {
    if (ascending) {
      return a.length < b.length;
    } else {
      return a.length > b.length;
    }
  });
}

