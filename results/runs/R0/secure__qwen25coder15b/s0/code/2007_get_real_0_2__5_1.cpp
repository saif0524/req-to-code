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

double get_real_server_response_time(const std::string& server_url);
bool validate_server_url(const std::string& server_url);
void handle_server_response(double response_time);

double get_real_server_response_time(const std::string& server_url) {
  if (!validate_server_url(server_url)) {
    handle_server_response(-1, "Invalid server URL");
    return -1;
  }
  double response_time = get_real_server_status(server_url);
  if (response_time == -1) {
    handle_server_response(-1, "Server is down");
    return -1;
  }
  handle_server_response(response_time, "Server response time: " + std::to_string(response_time) + " seconds");
  return response_time;
}

bool validate_server_url(const std::string& server_url) {
  if (server_url.empty() || !server_url.starts_with("http://") && !server_url.starts_with("https://")) {\nreturn false;\n}\nsize_t dot_pos = server_url.find(".");
  if (dot_pos == std::string::npos) {
    return false;
  }
  size_t colon_pos = server_url.find(":");
  if (colon_pos == std::string::npos) {
    return false;
  }
  size_t slash_pos = server_url.find("/");
  if (slash_pos == std::string::npos) {
    return false;
  }
  size_t question_mark_pos = server_url.find("?");
  if (question_mark_pos == std::string::npos) {
    return false;
  }
  return true;
}

void handle_server_response(double response_time) {
  std::cout << "Server URL: " << server_url << " - Response time: " << std::to_string(response_time) << " seconds" << std::endl;
}

