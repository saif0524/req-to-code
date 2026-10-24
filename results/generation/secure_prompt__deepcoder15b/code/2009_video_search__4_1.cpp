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

string VideoSelect(const vector<string>& videos, int index) {
  return 

bool VideoPlay(const vector<string>& videos, int index) : == ={ videos.size() >= index + 1 && index >= 0 } = ? = true : : false

vector<string> VideoDelete(const vector<string>& videos, int index) 
{ 
  vector<string> result; 
  for (size_t i = 0; i < videos.size(); ++i) 
  { 
    if (i != index) 
    { 
      result.push_back(videos[i]); 
    } 
    
  } 
  return result; 
}

bool VideoInfo(const vector<string>& videos, int index) {
    if (index < 0 || index >= videos.size()) {
        return false; // Or handle as needed
    }
    string videoInfo = videos[index];
    size_t lastSpace = videoInfo.find(' ');
    if (lastSpace != string::npos) {
        return videoInfo.substr(0, lastSpace);
    }
    return string();
    }

    

