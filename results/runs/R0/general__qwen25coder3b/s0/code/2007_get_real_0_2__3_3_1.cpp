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

std::vector<std::string> fetchVideoDownloads();
std::vector<std::string> parseVideoLinks(const std::string& html);
std::vector<std::string> validateVideoLinks(const std::vector<std::string>& links);
void displayVideoLinks(const std::vector<std::string>& links);
void processVideoProfiles();

std::vector<std::string> fetchVideoDownloads() {
  std::vector<std::string> urls;
  std::string url = "http://www.cs.washington.edu/education/ugrad/prospective/download.html";\n// Fetch the HTML content of the video downloads page\nstd::string html = fetchHtmlContent(url);\n// Parse the HTML content to extract video download links
  urls = parseVideoLinks(html);
  // Validate the video download links
  urls = validateVideoLinks(urls);
  return urls;
}

std::vector<std::string> parseVideoLinks(const std::string& html) {
  std::vector<std::string> links;
  std::regex videoLinkRegex(R"(<a\s+href\s*=[\"']([^\"']+)[\"'].*?>.*?</a>)");
  std::smatch match;
  std::string::const_iterator searchStart(html.begin());
  while (std::regex_search(searchStart, html.end(), match, videoLinkRegex)) {
    links.push_back(match[1].str());
    searchStart = match.suffix().first;
  }
  return links;
}

std::vector<std::string> validateVideoLinks(const std::vector<std::string>& links) {
  std::vector<std::string> validLinks;
  for (const auto& link : links) {
    if (isVideoFile(link)) {
      validLinks.push_back(link);
    }
  }
  return validLinks;
}

bool isVideoFile(const std::string& url) {
  std::string extension = getFileExtension(url);
  std::vector<std::string> validExtensions = {".mp4", ".avi", ".mkv", ".mov", ".wmv"};
  for (const auto& ext : validExtensions) {
    if (extension == ext) {
      return true;
    }
  }
  return false;
}

std::string getFileExtension(const std::string& url) {
  size_t pos = url.find_last_of(".");
  if (pos != std::string::npos) {
    return url.substr(pos);
  }
  return "";
}

void displayVideoLinks(const std::vector<std::string>& links) {
  for (const auto& link : links) {
    std::cout << link << std::endl;
  }
}

void processVideoProfiles() {
  std::vector<std::string> links = fetchVideoDownloads();
  links = parseVideoLinks(links);
  links = validateVideoLinks(links);
  displayVideoLinks(links);
}

