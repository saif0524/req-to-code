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
string handleVideoTags(string videoContent): vector<string>;
string handleVideoMetadata(string videoMetadata): VideoMetadata;

string parseVideoURL(string url): VideoDetails {
  if (!url.empty() && url.find(

string parseVideoMetadata(string videoStream): VideoMetadata {
  if (videoStream.empty() || !is_valid_string(videoStream)) {
    return VideoMetadata{};
  }
  // Split the string into parts
  vector<string> parts;
  for (char c : videoStream) {
    if (isalnum(c) || isdigit(c)) {
      parts.push_back(c);
    }
  }
  // Extract metadata fields
  map<string, string> metadata;
  parts[0] = 

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
  vector<string> parts;
  for (char c : videoMetadata) {
    if (isalnum(c) || isdigit(c)) {
      parts.push_back(c);
    }
  }
  map<string, string> metadata;
  for (string part : parts) {
    if (part.empty()) continue;
    if (part == 

