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

struct MyStruct;
enum MyEnum;
using MyUsingAlias = int;
const int MyConstant = 42;

std::vector<std::string> search(std::string query, int max_results);
void download(std::string video_url, std::string save_path);
void stream(std::string video_url);
std::vector<std::string> parse(std::string html_content);
std::map<std::string, std::string> get_video_info(std::string video_url);

std::string download(std::string video_url, std::string save_path) {
    CURL *curl = curl_easy_init();
    if(curl) {
        FILE *fp = fopen(save_path.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, video_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 0);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_URL, video_url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 0);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_URL, video_url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 0);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        int res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            return "Error: " + curl_easy_strerror(res);
        }
        fclose(fp);
        curl_easy_cleanup(curl);
        return "Download successful";
    }
    return "Error: Unable to initialize curl";
}

std::string stream(std::string video_url) {
     CURL *curl = curl_easy_init();
     if(curl) {
         FILE *fp = fopen("video.mp4", "wb");
         curl_easy_setopt(curl, CURLOPT_URL, video_url.c_str());
         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
         curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
         curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
         curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
         curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
         curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
         curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
         curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
         curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
         curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
         curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
         curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
         curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
         curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 0);
         curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
         curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);
         curl_easy_setopt(curl, CURLOPT_HEADERDATA, NULL);
         curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
         curl_easy_setopt(curl, CURLOPT_URL, video_url.c_str());
         curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
         curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
         curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
         curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
         curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
         curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
         curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
         curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
         curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
         curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
         curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
         curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 0);
         curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
         curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);
         curl_easy_setopt(curl, CURLOPT_HEADERDATA, NULL);
         curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
         int res = curl_easy_perform(curl);
         if(res != CURLE_OK) {
             return "Error: " + curl_easy_strerror(res);
         }
         fclose(fp);
         curl_easy_cleanup(curl);
         return "Stream successful";
     }
     return "Error: Unable to initialize curl";
}

std::vector<std::string> parse(std::string html_content) {
     std::regex pattern(R"(<a href="(.*?)">(.*?)</a>)" );
     std::sregex_iterator it(html_content.begin(), html_content.end(), pattern);
     std::sregex_iterator end;

     std::vector<std::string> video_urls;
     for (; it != end; ++it) {
         video_urls.push_back(it->str(1));
     }

     return video_urls;
}

std::vector<std::string> parse(std::string html_content) {
     std::regex pattern(R"(<a href="(.*?)">(.*?)</a>)" );
     std::sregex_iterator it(html_content.begin(), html_content.end(), pattern);
     std::sregex_iterator end;

     std::vector<std::string> video_urls;
     for (; it != end; ++it) {
         video_urls.push_back(it->str(1));
     }

     return video_urls;
}

std::map<std::string, std::string> get_video_info(std::string video_url) {
     CURL *curl = curl_easy_init();
     if(curl) {
         std::string response = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE);
         if(response == "200") {
             std::string html_content = curl_easy_perform(curl);
             std::vector<std::string> video_urls = parse(html_content);
             std::map<std::string, std::string> video_info;
             video_info["title"] = video_urls[0];
             video_info["description"] = video_urls[1];
             return video_info;
         }
     }
     return std::map<std::string, std::string>();
}

