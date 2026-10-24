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

std::vector<std::string> search_videos(std::string search_term);
std::vector<std::string> sort_results(std::vector<std::string> results, std::string sort_column);
std::vector<std::string> filter_websites(std::vector<std::string> results, std::vector<std::string> selected_websites);
std::vector<std::string> next_page(std::vector<std::string> results);
std::string get_stream_url(std::string video_url);

std::vector<std::string> sort_results(std::vector<std::string> results, std::string sort_column) {
    for (int i = 0; i < results.size(); i++) {
        for (int j = i + 1; j < results.size(); j++) {
            if (results[j] < results[i]) {
                std::swap(results[i], results[j]);
            }
        }
    }
    return results;
}

std::vector<std::string> filter_websites(std::vector<std::string> results, std::vector<std::string> selected_websites) {
    std::vector<std::string> filtered_results;
    for (const auto& result : results) {
        for (const auto& website : selected_websites) {
            if (result.find(website) != std::string::npos) {
                filtered_results.push_back(result);
                break;
            }
        }
    }
    return filtered_results;
}

std::vector<std::string> next_page(std::vector<std::string> results) {
    std::vector<std::string> filtered_results;
    for (const auto& result : results) {
        bool is_next_page = true;
        for (const auto& website : selected_websites) {
            if (result.find(website) == std::string::npos) {
                is_next_page = false;
                break;
            }
        }
        if (is_next_page) {
            filtered_results.push_back(result);
        }
    }
    return filtered_results;
}

std::string get_stream_url(std::string video_url) {
    for (const auto& result : results) {
        if (result.find(video_url) != std::string::npos) {
            return result;
        }
    }
    return "";
}

std::vector<std::string> sort_results(std::vector<std::string> results, std::string sort_column) {
    for (int i = 0; i < results.size(); i++) {
        for (int j = i + 1; j < results.size(); j++) {
            if (results[j] < results[i]) {
                std::swap(results[i], results[j]);
            }
        }
    }
    return results;
}

std::vector<std::string> filter_websites(std::vector<std::string> results, std::vector<std::string> selected_websites) {
     std::vector<std::string> filtered_results;
     for (const auto& result : results) {
         bool is_next_page = true;
         for (const auto& website : selected_websites) {
             if (result.find(website) == std::string::npos) {
                 is_next_page = false;
                 break;
             }
         }
         if (is_next_page) {
             filtered_results.push_back(result);
         }
     }
     return filtered_results;
}

std::vector<std::string> next_page(std::vector<std::string> results) {
     std::vector<std::string> filtered_results;
     for (const auto& result : results) {
         bool is_next_page = true;
         for (const auto& website : selected_websites) {
             if (result.find(website) == std::string::npos) {
                 is_next_page = false;
                 break;
             }
         }
         if (is_next_page) {
             filtered_results.push_back(result);
         }
     }
     return filtered_results;
}

std::vector<std::string> next_page(std::vector<std::string> results) {
     std::vector<std::string> filtered_results;
     for (const auto& result : results) {
         bool is_next_page = true;
         for (const auto& website : selected_websites) {
              if (result.find(website) == std::string::npos) {
                 is_next_page = false;
                 break;
             }
         }
         if (is_next_page) {
             filtered_results.push_back(result);
         }
     }
     return filtered_results;
}

std::string get_stream_url(std::string video_url) {
     for (const auto& result : results) {
         if (result.find(video_url) != std::string::npos) {
             return result;
         }
     }
     return "";
}

