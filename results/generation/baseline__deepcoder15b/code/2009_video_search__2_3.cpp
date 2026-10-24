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

string url -> vector<string> video_urls;
string video_url vector<string> sites -> vector<string> search_results;
vector<string> results -> string html_string;
string html -> string send_string;

vector<string> url_to_video_urls(string url) {
  vector<string> result;
  regex pattern = "(?:(?:\w+\.))/)?([^\/.]+\.\w+);\nsregex_iterator it(url.begin(), url.end(), regex_iterator::all);\nsregex_iterator end;\nfor (sregex iter(it); iter != end; ++iter) {
    smatch match(*iter, pattern);
    string video = match[1].str();
    result.push_back(video);
  }
  return result;
  }
  "

vector<string> search_results(string video_url, vector<string> sites) {
  vector<string> results;
  for (string video : video_url) {
    for (string site : sites) {
      if (video == site) {
        results.push_back(video);
      }
    }
    // If no matches found, return an empty vector
    if (results.empty()) {
      return results;
    }
  }
  return results;
  }
  

vector<string> results_to_html(vector<string> results) {
  string html_string;
  for (string result : results) {
    html_string +=="<video>" + result +="</video>";
  }
  return html_string;
}

string send_string(const vector<string>& results) {
  string send_str;
  for (size_t i = 0; i < results.size(); ++i) {
    if (i != 0) {
      send_str += 

