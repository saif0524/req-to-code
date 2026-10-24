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

string video_name string host string date string show_name string result vector<Result> get_search_results(string video_name, string host, string date, string show_name);
string result vector<Result> toggle_include_category(string include_category);
string result vector<Result> sort_search_results(string sort_by, string sort_order);
string result vector<Result> display_results;

string video_name string host string date string show_name string result vector<Result> get_search_results(string video_name, string host, string date, string show_name)  // Retrieves search results from both video hosting and video linking sites.
    // Parameters: video_name, host, date, show_name
    // Returns: A vector of Result objects containing search results
    // Example: get_search_results(

string result vector<Result> toggle_include_category(string include_category)  // Toggles the inclusion of search categories.
  // Parameters: include_category (string) - The category to toggle.
  // Returns: A vector of Result objects containing the updated search results.
  // Example: toggle_include_category(

vector<Result> sort_search_results(string sort_by, string sort_order) {
  sort(results.begin(), results.end(), [](const Result& a, const Result& b) {
    if (sort_by == 

string result vector<Result> display_results(string results, string sort_by, string sort_order) {
    string json_result[] = {
      {
        "id": "123456789", "category": "video_host", "name": "Video A", "length": "120min", "date": "2023-10-01", "links": {
{
"url": "https://example.com/videoA", \n            "page": "1" \n          },\n          {\n"url": "https://example.com/videoB", \n            "page": "2" \n          }\n},\n{
"id": "987654321", "category": "video_link", "name": " episode C", "length": "45min", "date": "2023-10-02", "links": {
{
"url": "https://example.com/episodeC", \n            "page": "1" \n          },\n          {\n"url": "https://example.com/episodeD", \n            "page": "2" \n          }\n}\n};
      
      string result_str[] = {
"results": {
{
"sort_by": sort_by, "sort_order": sort_order \n          },\n          "total_results": results.size(),\n          "reasoning": "The results are displayed in a structured format with each result containing its details and sorting based on specified criteria.\n          "code": "[results]",\n          "reasoning": "The results are displayed in a structured format with each result containing its details and sorting based on specified criteria.
        }
};
      
      string final_json[] = {
"content": JSON.stringify({
"reasoning": "The results are displayed in a structured format with each result containing its details and sorting based on specified criteria.\n"code": display_results(results, sort_by, sort_order),\n          "reasoning": "The results are displayed in a structured format with each result containing its details and sorting based on specified criteria.
        }),\n        "reasoning": "The results are displayed in a structured format with each result containing its details and sorting based on specified criteria.\n"code": "[results]"\n}\n};
    return JSON.stringify({
"reasoning": "The results are displayed in a structured format with each result containing its details and sorting based on specified criteria.\n"code": display_results(results, sort_by, sort_order),\n      "reasoning": "The results are displayed in a structured format with each result containing its details and sorting based on specified criteria.
    });
  }
};

