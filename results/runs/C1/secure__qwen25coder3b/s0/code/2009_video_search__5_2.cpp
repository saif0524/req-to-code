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
  std::regex urlPattern(R"(https?://[a-zA-Z0-9.-]+(:[0-9]+)?(/.*)?)");\nif (!std::regex_match(url, urlPattern)) {\nlogWebsiteCheck(url, false);\nreturn false;
  }
  std::string content = fetchWebsiteContent(url);
  if (content.empty()) {
    logWebsiteCheck(url, false);
    return false;
  }
  logWebsiteCheck(url, true);
  return true;
}

std::string fetchWebsiteContent(const std::string& url) {
  std::string command = "curl -s \"" + url + "\"";
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

bool checkForIllegalContent(const std::string& content, const std::string& url) {
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
  std::ofstream logFile("website_check.log", std::ios::app);
  if (logFile.is_open()) {
    logFile << url << ": " << (result ? "Passed" : "Failed") << std::endl;
    logFile.close();
  } else {
    std::cerr << "Error opening log file" << std::endl;
  }
}

void investigateWebsite(const std::string& url) {
  if (!validateWebsite(url)) {
    logWebsiteCheck(url, false);
    return;
  }
  std::string content = fetchWebsiteContent(url);
  if (checkForIllegalContent(content)) {
    logWebsiteCheck(url, false);
    return;
  }
  logWebsiteCheck(url, true);
  return;
}

