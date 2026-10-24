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

void searchDatabase(const std::string& searchTerm);
std::vector<DataItem> filterData(const std::vector<DataItem>& data, const std::string& searchTerm);
void displayResults(const std::vector<DataItem>& results);
void updateDatabase(const std::vector<DataItem>& updatedData);

struct DataItem {
  std::string username;
  std::string group;
  std::string password;
  std::string url;
  std::string note;
  std::string title;
};

std::vector<DataItem> filterData(const std::vector<DataItem>& data, const std::string& searchTerm) {
  std::vector<DataItem> filteredData;
  for (const auto& item : data) {
    if (item.contains(searchTerm)) {
      filteredData.push_back(item);
    }
  }
  return filteredData;
}

void displayResults(const std::vector<DataItem>& results) {
  for (const auto& item : results) {
    std::cout << item << std::endl;
  }
}

void searchDatabase(const std::string& searchTerm) {
  std::vector<DataItem> filteredData = filterData(data, searchTerm);
  displayResults(filteredData);
}

using namespace std;

std::vector<DataItem> filterData(const std::vector<DataItem>& data, const std::string& searchTerm) {
  std::vector<DataItem> filteredData;
  for (const auto& item : data) {
    if (item.contains(searchTerm)) {
      filteredData.push_back(item);
    }
  }
  return filteredData;
}

void displayResults(const std::vector<DataItem>& results) {
  for (const auto& item : results) {
    std::cout << item << std::endl;
  }
}

void updateDatabase(const std::vector<DataItem>& updatedData) {
  std::vector<DataItem> filteredData = filterData(data, searchTerm);
  for (const auto& item : filteredData) {
    for (const auto& existingItem : data) {
      if (existingItem.username == item.username && existingItem.group == item.group && existingItem.password == item.password && existingItem.url == item.url && existingItem.note == item.note && existingItem.title == item.title) {
        existingItem = item;
        break;
      }
    }
  }
}

