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

using std::vector;

void display_main_screen();
void update_video_list(const std::vector<std::string>& videos);
void handle_video_selection(const std::string& video_id);
void display_video_details(const std::string& video_id);
void handle_search_query(const std::string& query);

void display_main_screen() {
  using std::vector;

  // Display the videos that the user is currently searching for
  vector<std::string> videos = get_current_search_results();

  // Display the search query
  std::string query = get_current_search_query();

  // Display the number of videos found
  int num_videos = get_num_videos_found();

  // Display the options for the user to interact with the search engine
  display_search_options();
}

void update_video_list(const std::vector<std::string>& videos) {
  // Retrieve the current search results and query
  std::vector<std::string> current_search_results = get_current_search_results();

  // Retrieve the current search query
  std::string current_search_query = get_current_search_query();

  // Retrieve the number of videos found
  int num_videos_found = get_num_videos_found();

  // Display the search options
  display_search_options();

  // Update the video list to display the results of the search
  update_video_list(current_search_results);

  // Display the selected video details
  display_video_details(current_search_query);
}

void handle_video_selection(const std::string& video_id) {
  // Retrieve the current search results and query
  std::vector<std::string> videos = get_current_search_results();
  std::string query = get_current_search_query();

  // Retrieve the number of videos found
  int num_videos = get_num_videos_found();

  // Display the search options
  display_search_options();

  // Display the selected video details
  display_video_details(video_id);

  // Return the selected video ID
  return video_id;
}

void display_video_details(const std::string& video_id) {
  // Retrieve the current search results and query
  std::vector<std::string> videos = get_current_search_results();
  std::string query = get_current_search_query();

  // Retrieve the number of videos found
  int num_videos = get_num_videos_found();

  // Display the search options
  display_search_options();

  // Display the selected video details
  display_video_details(video_id);

  // Return the selected video ID
  return video_id;
}

void handle_search_query(const std::string& query) {
  // Retrieve the current search results and query
  std::vector<std::string> videos = get_current_search_results();
  std::string current_query = get_current_search_query();

  // Update the video list to display the results of the search
  update_video_list(videos);

  // Display the search options
  display_search_options();

  // Display the selected video details
  display_video_details(current_query);

  // Return the selected video ID
  return video_id;
}

