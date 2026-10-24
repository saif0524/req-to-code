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

vector<video_data> getVideoData(const string& video_name, vector<video_data>& videos);
vector<video_data> filterVideos(const vector<video_data>& videos, string search_term);
vector<video_data> sortVideos(const vector<video_data>& filtered_videos);
string handleSearchTerm(string search_term);
string nextPageResults(int current_page);

vector<video_data> getVideoData(const string& video_name, vector<video_data>& videos) {
  vector<video_data> result;
  VideoData data;
  if (video_name.find(

vector<video_data> filterVideos(const vector<video_data>& videos, string search_term) {
    vector<video_data> result;
    for (const auto& video : videos) {
        if (video.title == search_term) {
            result.push_back(video);
        }
    }
    return result;
}

vector<video_data> getVideoData(const string& video_name, vector<video_data>& videos) {
  vector<video_data> result;
  VideoData data;
  if (video_name.find(
    vector<video_data> filterVideos(const vector<video_data>& videos, string search_term) {
    vector<video_data> result;
    for (const auto& video : videos) {
      if (video.title == search_term) {
        result.push_back(video);
      }
    }
    return result;
  }

  vector<video_data> sortVideos(const vector<video_data>& filtered_videos) {
    sort(filtered_videos.begin(), filtered_videos.end(), [](const video_data& a, const video_data& b) {
      return a.name < b.name;
    });
    return filtered_videos;
  }

  string handleSearchTerm(string search_term) {
    vector<video_data> filtered = filterVideos(getVideoData(search_term, videos), search_term);
    vector<video_data> sorted = sortVideos(filtered);
    return "Click on the sorted results below to view the videos by their names. The results are sorted in ascending order based on video names.\nClick to view the sorted results."
  }

string handleSearchTerm(string search_term) {
  vector<video_data> matching_videos;
  for (const auto& video : videos) {
    if (video.title == search_term) {
      matching_videos.push_back(video);
    }
  }
  sort(matching_videos.begin(), matching_videos.end(), [](const video_data& a, const video_data& b) {
    return a.name < b.name;
  });
  return "The results are sorted in ascending order based on video names. Click to view the sorted results.";
}

string nextPageResults(int current_page) { vector<video_data> current_results = filterVideos(getVideoData(search_term, videos), search_term); sort(current_results.begin(), current_results.end(), [](const video_data& a, const video_data& b) { return a.name < b.name; }); vector<video_data> next_results = current_results; next_results.erase(next_results.begin() + current_page + 1, next_results.end()); return "The next set of results starts from page " + to_string(current_page + 1) + ". These results are sorted by name and displayed below. Click to view them.\

