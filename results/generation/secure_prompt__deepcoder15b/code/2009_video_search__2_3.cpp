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

struct Database { vector<string> videos; }

bool login(string username, string password);
vector<string> search(string query, string region);
string get_video(int video_id);
bool timer();

bool login(string username, string password) {
    if (Database_videos.find(username) == Database_videos.end()) {
        return false;
    }
    if (password == "password") {
        return true;
    }
    Database_videos[username] = "token";
    return true;
}

vector<string> search(string query, string region) {
  string prefix = query + (

string get_video(int video_id) {
  int found_id = -1;
  for (int i = 0; i < videos.size(); i++) {
    if (videos[i] == video_id) {
      found_id = i;
      break;
    }
  }
  if (found_id != -1) {
    return videos[found_id];
  }
  return 

bool timer(string username) {
  bool is_valid = true; 
  if (Database_videos.find(username) != Database_videos.end()) {
    is_valid = false; 
  }
  return is_valid; }

