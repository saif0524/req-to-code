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

string VideoSearch Video* const VideoSearch (string search_type, string filter_type, bool sort_by, vector<string>) -> vector<Video> *;
string VideoFilter Video* const VideoFilter (string filter_type, string content, bool sort_by, bool ascending, bool descending) -> vector<Video> *;
string VideoSort Video* const VideoSort (string key, bool sort_order, bool ascending, bool descending) -> vector<Video> *;

string VideoSearch Video* const VideoSearch (string search_type, string filter_type, bool sort_by, vector<string>) -> vector<Video> *  // Search for videos based on specified types and filters.

  // Determine which types are being searched
  struct SearchState {
    bool has_type1; 
    bool has_type2; 
  };

  // Check if a video matches the search criteria
  bool MatchesSearch(const Video& video, const SearchState& state) {
    if (!state.has_type1 && !state.has_type2) return false;

    // Check type1
    if (state.has_type1 && !video.type1) return false;
    if (state.has_type2 && !video.type2) return false;

    // Check filter
    if (state.filter_type != 

string VideoFilter Video* const VideoFilter (string filter_type, string content, bool sort_by, bool ascending, bool descending) -> string * {
    struct SearchState {
        bool has_type1; 
        bool has_type2; 
    };

    // Create a vector to hold the filtered videos
    vector<Video> filtered;

    // Iterate through each video in the search result
    for (Video* video : searchResult) {
        bool matches = false;

        if (filter_type == 'all') {
            matches = true;
        } else if (filter_type == 'type1') {
            if (video.type1 != 'null' && video.type1 != filter_type) {
                matches = true;
            }
        } else if (filter_type == 'type2') {
            if (video.type2 != 'null' && video.type2 != filter_type) {
                matches = true;
            }
        } else {
            matches = false;
        }

        // Check if the video's title contains the content
        if (matches && (video.title.find(content) != string::npos)) {
            filtered.push_back(video);
        }
    }

    // Sort the filtered videos based on the criteria
    vector<string> sorted;

    if (sort_by == 

string VideoSort Video* const VideoSort (string key, bool sort_order, bool ascending, bool descending) -> vector<Video> * {
    vector<string> key_values;
    for (Video* video : searchResult) {
        string key_value;
        if (key == 

