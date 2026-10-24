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

std::string processPhpRequest(const std::string& phpRequest);
bool validatePhpRequest(const std::string& phpRequest);
std::map<std::string, std::string> extractQueryParameters(const std::string& phpRequest);
std::string constructServerUrl(const std::string& serverName, const std::string& queryParameters);
std::string sendHttpRequest(const std::string& url);

std::string processPhpRequest(const std::string& phpRequest) {
  if (!validatePhpRequest(phpRequest)) {
    return "Invalid request";
  }

  std::map<std::string, std::string> queryParameters = extractQueryParameters(phpRequest);
  std::string serverUrl = constructServerUrl("example.com", queryParameters);

  std::string response = sendHttpRequest(serverUrl);

  return response;
}

bool validatePhpRequest(const std::string& phpRequest) {
  if (phpRequest.find('<?php') == std::string::npos || phpRequest.find('?>') == std::string::npos) {
    return false;
  }

  size_t openTagCount = 0;
  size_t closeTagCount = 0;

  for (char ch : phpRequest) {
    if (ch == '<') {
      if (phpRequest.substr(openTagCount, 5) == '<?php') {
        openTagCount += 5;
      }
    } else if (ch == '>') {
      if (phpRequest.substr(closeTagCount, 2) == '?>') {
        closeTagCount += 2;
      }
    }
  }

  return openTagCount > 0 && closeTagCount > 0 && openTagCount == closeTagCount;
}

std::map<std::string, std::string> extractQueryParameters(const std::string& phpRequest) {
  std::map<std::string, std::string> queryParameters;

  size_t start = phpRequest.find('?') + 1;
  size_t end = phpRequest.find('?>');

  std::string queryString = phpRequest.substr(start, end - start);

  size_t pos = 0;
  while (pos != std::string::npos) {
    size_t nextPos = queryString.find('&', pos);
    std::string param = nextPos == std::string::npos ? queryString.substr(pos) : queryString.substr(pos, nextPos - pos);

    size_t equalsPos = param.find('=');
    if (equalsPos != std::string::npos) {
      std::string key = param.substr(0, equalsPos);
      std::string value = param.substr(equalsPos + 1);

      queryParameters[key] = value;
    }

    pos = nextPos == std::string::npos ? std::string::npos : nextPos + 1;
  }

  return queryParameters;
}

std::string constructServerUrl(const std::string& serverName, const std::string& queryParameters) {
  std::string url = serverName;

  if (!queryParameters.empty()) {
    url.append('?').append(queryParameters);
  }

  return url;
}

std::string sendHttpRequest(const std::string& url) {
  std::unique_ptr<std::string> response = std::make_unique<std::string>();

  std::ostringstream request;
  request << "GET "

