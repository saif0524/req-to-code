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
string search_site: string result: vector<video_info> & error_code: int;
vector<video_info> video: vector<video_info> favorites: void;
vector<video_info> video: vector<video_info> favorites: void;

string search_type(string type, vector<video_info>& videos, error_code& error_code, vector<video_info>& result) {
  if (type == 

string search_site(string site, vector<video_info>& result, error_code& error_code) {
  // Check if the site is valid
  if (site == "invalid" || result.empty()) {
    error_code = 1;
    result.clear();
    return {"reasoning": "The site must be valid and contain videos"};
  }

  // Fetch all videos on the specified site
  result.clear();
  error_code = 0;
  vector<video_info> videos;

  // Assuming there's a shared function to fetch videos
  if (hasSharedFunctionToFetchVideos(sites, site)) {
    videos = getVideos(sites, site);
  }

  // Add videos to result
  for (auto& video : videos) {
    result.push_back(video);
  }

  return {"reasoning": "The function searches for videos on the specified site and returns the results with error code"};
  }
  

vector<video_info> video: vector<video_info> favorites: void  // Adds a video to the user's favorites by creating a new vector containing only the specified video and assigning it to the 'favorites' parameter.

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

