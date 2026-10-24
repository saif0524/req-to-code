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

vector<string> VideoDelete(const vector<string>& videos, int index) : void

vector<string> VideoList(const vector<string>& videos);
string VideoSelect(const vector<string>& videos, int index);
bool VideoPlay(const vector<string>& videos, int index);
void VideoDelete(const vector<string>& videos, int index);
void VideoInfo(const vector<string>& videos, int index);

vector<string> VideoList(const vector<string>& videos) 
    { 
        vector<string> result; 
        for (const string& s : videos) 
        { 
            result.push_back(s); 
        } 
        return result; 
    }

string VideoSelect(const vector<string>& videos, int index)
    { 
      if (index < 0 || index >= videos.size()) 
      {
        return string();
      }
      string videoInfo = VideoInfo(videos, index);
      return videoInfo;
    },
    

vector<string> VideoDelete(const vector<string>& videos, int index) { const vector<string>& temp = videos; for (size_t i = 0; i < temp.size(); ++i) { if (i != index) { temp[i] = 0; } } return temp; }

bool VideoInfo(const vector<string>& videos, int index) {
  if (index < 0 || index >= videos.size()) {
    return true; // Assuming true indicates the video is available
  }
  return false; // Or adjust based on requirements
}

