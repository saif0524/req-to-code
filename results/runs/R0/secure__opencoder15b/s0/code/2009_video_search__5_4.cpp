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

void validate_input(const std::string& input);
bool is_valid_url(const std::string& url);
void download_video(const std::string& url, const std::string& output_path);
std::vector<std::string> parse_video_links(const std::string& html_content);
std::string get_video_info(const std::string& video_link);

bool validate_input(const std::string& input) {
  for (char c : input) {
    if (!std::isalnum(c) && c != '-' && c != '_' && c != '.') {
      return false;
    }
  }
  return true;
}

bool is_valid_url(const std::string& url) {
  if (!url.starts_with("http://") && !url.starts_with("https://")) {\nreturn false;\n}\nfor (char c : url) {
    if (!std::isalnum(c) && c != '-' && c != '_' && c != '.' && c != '/') {
      return false;
    }
  }
  std::string extension = url.extract_extension();
  if (!extension.ends_with(".mp4", ".avi", ".mkv")) {
    return false;
  }
  return true;
}

bool download_video(const std::string& url, const std::string& output_path) {
  std::string command = "wget -O " + output_path + " "

std::vector<std::string> parse_video_links(const std::string& html_content) {
  std::vector<std::string> video_links;
  std::string::size_type start_pos = 0;
  std::string::size_type end_pos = 0;
  while ((end_pos = html_content.find("<a href="", start_pos)) != std::string::npos) {\nstart_pos = end_pos + 1;\nend_pos = html_content.find("">", start_pos);
    std::string link = html_content.substr(start_pos, end_pos - start_pos);
    link = link.substr(1, link.size() - 2);
    video_links.push_back(link);
  }
  return video_links;
}

std::string get_video_info(const std::string& video_link) {
  std::string command = "youtube-dl -J " + video_link;
  std::string output = execute_command(command);
  std::string json_output = "{";
  json_output += "title": extract_json_field(output, "title"),
  json_output += "duration": extract_json_field(output, "duration"),
  json_output += "size": extract_json_field(output, "size"),
  json_output += "url": video_link;
  return json_output;
}

