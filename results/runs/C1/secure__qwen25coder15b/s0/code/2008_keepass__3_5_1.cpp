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

void searchDatabase(const std::string& searchTerm) {
  std::vector<DataItem> filteredData = filterData(data, searchTerm);
  displayResults(filteredData);
}

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
    if (item.username.find(searchTerm) != std::string::npos ||
        item.group.find(searchTerm) != std::string::npos ||
        item.password.find(searchTerm) != std::string::npos ||
        item.url.find(searchTerm) != std::string::npos ||
        item.note.find(searchTerm) != std::string::npos ||
        item.title.find(searchTerm) != std::string::npos) {
      filteredData.push_back(item);
    }
  }
  return filteredData;
}

void displayResults(const std::vector<DataItem>& results) {
  for (const auto& item : results) {
    std::cout << "Username: " << item.username << std::endl;
    std::cout << "Group: " << item.group << std::endl;
    std::cout << "Password: " << item.password << std::endl;
    std::cout << "URL: " << item.url << std::endl;
    std::cout << "Note: " << item.note << std::endl;
    std::cout << "Title: " << item.title << std::endl;
    std::cout << std::endl;
  }
}

void updateDatabase(const std::vector<DataItem>& updatedData) {
  std::vector<DataItem> filteredData = filterData(data, searchTerm);
  displayResults(filteredData);
}

