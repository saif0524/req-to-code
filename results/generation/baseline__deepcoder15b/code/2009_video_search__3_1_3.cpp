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

int AddTorrent(int index, string title, string description, int size, string date, string link);
void DisplayResults(vector<Result> results);
vector<string> SearchQuery(string query);
void SortResults(vector<Result> results);

int AddTorrent(int index, string title, string description, int size, string date, string link) {
  struct torrent {
    string title;
    string description;
    int size;
    string date;
    string link;
    bool added;
  } new torrent;

  new torrent.title = title;
  new torrent.description = description;
  new torrent.size = size;
  new torrent.date = date;
  new torrent.link = link;
  new torrent.added = true;

  return new torrent;
  }
  

vector<string> DisplayResults(vector<Result> results) {
  vector<string> output;
  for (const auto& result : results) {
    string json;
    json += "{\n";
    for (int i = 0; i < result.size; i++) {
      string key = i + 1;
      string value = result[i];
      if (i == 0) {
        json += key;
        json += ":\n";
      } else {
        json += key;
        json += (value.empty() ? "null" : string(value.begin(), value.end()));
        json += (value.empty() ? ";\n" : ";\n}\n}
    json += "};\noutput.push_back(json);\n}\nreturn output;
}
}:

vector<string> SearchQuery(string query) { vector<string> resultTitles; for (const auto& result : results) { string title = result.title; if (title == query) { resultTitles.push_back(title); } } return resultTitles; }

vector<string> SortResults(vector<Result> results) {
    vector<string> sortedResults;
    if (results.empty()) {
        return sortedResults;
    }
    // Determine the sorting criteria
    string criteria = "title";
    if (searchQuery(query).size() > 0) {
        criteria = "size";
    }
    if (date >= 0) {
        criteria = "date";
    }
    if (link != null && link.length() > 0) {
        criteria = "link";
    }
    // Extract data for sorting
    vector<string> titleData;
    vector<string> sizeData;
    vector<string> dateData;
    vector<string> linkData;
    for (const auto& result : results) {
        titleData.push_back(result.title);
        sizeData.push_back(string(result.size, ' '));
        dateData.push_back(result.date);
        linkData.push_back(result.link);
    }
    // Sort based on criteria
    if (criteria == "title") {
        sort(titleData.begin(), titleData.end(), [](const string& a, const string& b) {
            return a != null ? a : b < string(0, ' ') < string(0, ' ') ? string(0, ' ') : b;
        });
    } else if (criteria == "size") {
        sort(sizeData.begin(), sizeData.end(), [](const string& a, const string& b) {
            return a != null ? a : b;
        });
    } else if (criteria == "date") {
        sort(dateData.begin(), dateData.end(), [](const string& a, const string& b) {
            return a != null ? a : b;
        });
    } else if (criteria == "link") {
        sort(linkData.begin(), linkData.end(), [](const string& a, const string& b) {
            return a != null ? a : b;
        });
    }
    // Create a combined key for sorting
    vector<string> combinedKeys;
    for (size_t i = 0; i < results.size(); i++) {
        if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], " " + sizeData[i] + " " + dateData[i] + " " + linkData[i]));
        } else if (titleData[i] != null && sizeData[i] != null && dateData[i] != null && linkData[i] != null) {
            combinedKeys.push_back(string(titleData[i], 

