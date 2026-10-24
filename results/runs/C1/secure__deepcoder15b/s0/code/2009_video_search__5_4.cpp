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

string parseVideoURL(string url): VideoDetails;
string parseVideoMetadata(string videoStream): VideoMetadata;
string searchVideos(string url): vector<string>;
string handleVideoTags(string videoContent): vector<string>;
string handleVideoMetadata(string videoMetadata): VideoMetadata;

string parseVideoURL(string url): VideoDetails {
  if (!is_valid_string(url)) {
    return VideoDetails{};
  }
  const string pattern = ^https?://;
  const regex = std::regex(pattern);
  if (!std::regex_match(url, regex)) {
    return VideoDetails{};
  }
  const string videoPart = url.substr(8);
  const string titlePart = videoPart.find_first_of(

string parseVideoMetadata(string videoStream): VideoMetadata {
  if (videoStream.empty() || !is_valid_string(videoStream)) {
    return VideoMetadata{};
  }
  map<string, string> metadata;
  for (char c : videoStream) {
    if (isalnum(c) || isdigit(c)) {
      metadata[c] = string{};
    }
  }
  return VideoMetadata(metadata);
  }
  

string search Videos(string url): vector<string> " // Extract the query from the given URL\nstring query = url.substr(0, url.find('?')).substr(0, 50);\n// Split into key-value pairs\nstring::size_type queryPos = query.find('?');
    string::size_type queryTokenPos = queryPos > string::npos ? queryPos : queryPos + 1;
    string::size_type queryTokenLength = queryTokenPos > string::npos ? queryTokenPos : queryTokenPos + 1;
    string::size_type tokenCount = 0;
    string::size_type tokenPos = 0;
    string::map<string, string> keyValuePairs;

    // Process each token
    while (tokenPos < queryTokenLength && !isalnum(query.substr(tokenPos))) {
        tokenPos++;
        if (tokenPos >= queryTokenLength) break;
        string token = query.substr(tokenPos, string::npos - tokenPos);
        if (!token.empty()) {
            string key = token.find_first_of(

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
  if (videoMetadata.empty()) {
    return VideoMetadata{};
  }
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

