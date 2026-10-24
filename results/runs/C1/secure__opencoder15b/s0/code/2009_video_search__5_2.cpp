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

void search_website(const std::string& url, std::vector<std::string>& results);

std::vector<std::string> search_website(const std::string& url) {
   std::vector<std::string> results;
   CURL *curl = curl_easy_init();
   curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, &results);
   curl_easy_perform(curl);
   curl_easy_cleanup(curl);
   return results;
}

