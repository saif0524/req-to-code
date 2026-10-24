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

string search_type: string result: vector<video_info> & error_code: int;
string search_type1: string search_type2: string result: vector<video_info> & error_code: int;
string search_site: string result: vector<video_info> & error_code: int;
vector<video_info> video: vector<video_info> favorites: void;
vector<video_info> video: vector<video_info> favorites: void;

string search_site(string site, vector<video_info>& result, error_code& error_code) \ 
  if (site == "invalid" || result.empty()) \  { \ n    error_code = 1; \ n    result.clear(); \ n    return "The site must be valid and contain videos"; \ n  } \ n \ n  result.clear(); \ n  error_code = 0; \ n  vector<video_info> videos; \ n \ n  if (hasSharedFunctionToFetchVideos(sites, site)) \ n  { \ n    videos = getVideos(sites, site); \ n  } \ n \n  for (auto& video : videos) \n  {
result.push_back(video);
}
\n return "The function searched for videos on the specified site and returned the results with error code";

vector<video_info> video(vector<video_info> favorites, vector<video_info> video) {
    // Check if the video is already in favorites
    for (auto& f : favorites) {
      if (f == video) {
        removeVideoFromFavorites(favorites, video);
        return;
      }
    }

    // Add the video to favorites
    addVideoToFavorites(favorites, video);
    return vector<video_info>();
  },
  

vector<video_info> video: vector<video_info> favorites: void


vector<video_info> video: vector<video_info> favorites: void


// Remove a video from the user's favorites
bool removeVideoFromFavorites(const vector<video_info>& favorites, const video_info& video)
{
  auto it = find(favorites.begin(), favorites.end(), video);
  if (it != favorites.end())
  {
    delete it;
    return true;
  }
  return false;
}

