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

C++17 is supported.

string url -> vector<string> video_urls;
string site -> vector<string> search_sites;
string video_url vector<string> sites -> vector<string> search_results;
vector<string> results -> string html_string;
string html -> string send_string;

vector<string> url_to_video_urls(string url) {
  vector<string> result;
  regex pattern = "(?:(?:\w+\.)\.?\b)/\b";
  sregex_iterator iter(url.begin(), url.end(), pattern);
  sregex_iterator end_iter;
  for (sregex iter; iter != end_iter; ++iter) {
    smatch match(*iter, pattern);
    string video = match[1].str();
    result.push_back(video);
  }
  return result;
  }
  "

vector<string> search_sites(string site) {
  return vector<string>();
}

vector<string> results_to_html(vector<string> video_urls) {
string html_string;
for (string url : video_urls) {
html_string +=="<video" + url + ">";
}
return html_string;
}

string results_to_html(vector<string> results) {
  string html_string;
  for (string result : results) {
    html_string += "<video" + result +">";
  }
  return html_string;
  }

string send_string(const vector<string>& results) {
  string send_str;
  for (size_t i = 0; i < results.size(); ++i) {
    send_str += f'<video>{results[i]}</video>;
  }
  return send_str;
  }

