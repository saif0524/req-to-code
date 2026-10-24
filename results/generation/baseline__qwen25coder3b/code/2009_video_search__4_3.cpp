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

std::string sendQuery(const std::string& query, const std::string& language);
std::vector<std::string> parseResponse(const std::string& response);
std::string formatQuery(const std::string& query);
void handleError(const std::string& error);
void logRequest(const std::string& query, const std::string& language);

std::string sendQuery(const std::string& query, const std::string& language) {
  std::string response;
  sendRequest(query, language, response);
  return response;
}

std::vector<std::string> parseResponse(const std::string& response) {
  std::vector<std::string> videoUrls;
  size_t start = 0;
  size_t end = response.find('videoURL');
  while (end != std::string::npos) {
    videoUrls.push_back(response.substr(start, end - start));
    start = end + 8;
    end = response.find('videoURL', start);
  }
  return videoUrls;
}

std::string formatQuery(const std::string& query) { return query; }

void handleError(const std::string& error) { std::cout << "Error: " << error << std::endl; }

void logRequest(const std::string& query, const std::string& language) { std::cout << "Request: query = 

