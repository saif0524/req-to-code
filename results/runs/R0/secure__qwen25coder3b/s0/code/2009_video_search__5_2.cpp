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

bool validateWebsite(const std::string& url);
std::string fetchWebsiteContent(const std::string& url);
bool checkForIllegalContent(const std::string& content);
void logWebsiteCheck(const std::string& url, bool result);
void investigateWebsite(const std::string& url);

bool validateWebsite(const std::string& url) {
  if (url.find("http://") == std::string::npos && url.find("https://") == std::string::npos) {\nlogWebsiteCheck(url, false);\nreturn false;\n}
  std::string command = "curl -s "

std::string fetchWebsiteContent(const std::string& url) {
  std::string command = "curl -s " + url;
  std::string content;
  std::ifstream stream(command);
  if (stream.is_open()) {
    std::getline(stream, content);
    stream.close();
    logWebsiteCheck(url, true);
    return content;
  } else {
    logWebsiteCheck(url, false);
    return "Error fetching content";
  }
}

bool checkForIllegalContent(const std::string& content) {
  std::regex illegalPattern(R"(\b(forbidden|illegal|harmful|malicious|spam)\b)");
  if (std::regex_search(content, illegalPattern)) {
    logWebsiteCheck(url, false);
    return true;
  } else {
    logWebsiteCheck(url, true);
    return false;
  }
}

void logWebsiteCheck(const std::string& url, bool result) {
  std::string logMessage = "Website check for 

void investigateWebsite(const std::string& url) {
  if (!validateWebsite(url)) {
    logWebsiteCheck(url, false);
    return false;
  }
  std::string content = fetchWebsiteContent(url);
  if (checkForIllegalContent(content)) {
    logWebsiteCheck(url, false);
    return false;
  }
  logWebsiteCheck(url, true);
  return true;
}

