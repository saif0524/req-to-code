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

// Added: This function now returns a vector<string> instead of VideoDetails or vector<string>
using map;

string parseVideoURL(string url): VideoDetails;
string parseVideoMetadata(string videoStream): VideoMetadata;
string searchVideos(string url): vector<string>;
string handleVideoTags(string videoContent): vector<string>;
string handleVideoMetadata(string videoMetadata): VideoMetadata;

string parseVideoURL(string url): VideoDetails {
  if (!is_valid_string(url)) {
    return VideoDetails{};
  }
  const string videoPart = url.substr(8);
  const string titlePart = videoPart.find_last_of(':');
  const string details = VideoDetails{};
  if (titlePart != string::npos) {
    details.title = titlePart;
    details.url = url;
    details.content = videoPart;
  }
  return details;
  }
  "}\n``` line 1 is the first line of the function, which is a syntax error. It should be 

string parseVideoMetadata(string videoStream): VideoMetadata {
  if (videoStream.empty() || !is_valid_string(videoStream)) {
    return VideoMetadata{};
  }
  VideoMetadata metadata;
  for (char c : videoStream) {
    if (isalnum(c) || isdigit(c)) {
      metadata[c] = string{};
    }
  }
  return metadata;
  }
  

string searchVideos(string url): vector<string> {
    if (!is_valid_string(url)) {
        return vector<string>();
    }
    string query = url.substr(0, url.find('?')).substr(0, 50);
    string::map<string, string> keyValuePairs;
    string::size_type queryPos = query.find('?');
    string::size_type queryTokenPos = queryPos > string::npos ? queryPos : queryPos + 1;
    string::size_type queryTokenLength = queryTokenPos > string::npos ? queryTokenPos : queryTokenPos + 1;
    string::size_type tokenCount = 0;
    string::size_type tokenPos = 0;
    string::map<string, string> keyValuePairs;

    // Process each token in the query string
    while (tokenPos < queryTokenLength && !isalnum(query.substr(tokenPos))) {
        tokenPos++;
        if (tokenPos >= queryTokenLength) break;
        string token = query.substr(tokenPos);
        if (!token.empty() && isvalid_url_token(token)) {
            keyValuePairs.insert(token, token);
        }
    }

    return vector<string>(keypointPairs.begin(), keyValuePairs.end());
    return vector<string>();
    }
  }
}

string handleVideoTags(string videoContent): vector<string> {
  set<string> tags; 
  vector<string> tokens = split videoContent into tokens; 
  for each token in tokens {
    if token is a valid tag {
      tags.insert(token);
    }
  }
  vector<string> result(tags.begin(), tags.end());
  return result;
  }
  

string handleVideoMetadata(string videoMetadata): VideoMetadata {
  map<string, string> metadata;
  for (string part : videoMetadata) {
    if (!part.empty()) {
      for (char c : part) {
        metadata[c] = string{};
      }
    }
  }
  return VideoMetadata(metadata);
  }

