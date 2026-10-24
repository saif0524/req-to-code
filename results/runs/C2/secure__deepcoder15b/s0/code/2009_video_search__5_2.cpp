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

reference as const reference string
The only missing part is the definition of 'HARMFUL CONTENTS' as a const array. However, this is a separate issue and should be handled by the user.

string url, const reference databaseHandle;
string url, const reference content;

bool url(const std::string& url) {
  // Check if the URL starts with http:// or https://
  if (!url.empty() && (url[0] == 'http' && url[1] == '/') || (url[0] == 'https' && url[1] == '/')) {
    size_t http_pos = url.find('http://');
    if (http_pos != std::string::npos && (url[0] == 'http' && url[1] == '/')) {
      size_t path_start = http_pos + 4;
      size_t path_end = url.find('://', path_start);
      std::string path = url.substr(path_start, path_end - path_start);
      if (path.empty() || path == '/') {
        return true;
      } else {
        return false;
      }
    }
    // Handle other valid protocols
  }

  // Check for fragments and query parameters
  size_t fragment_pos = url.find('!');
  size_t query_pos = url.find('&');
  if (fragment_pos != std::string::npos || query_pos != std::string::npos) {
    return false;
  }

  return true;
  }

bool check_content(const std::string& content) {
  if (!check_url(content)) return false;
  
  return false;
  }

