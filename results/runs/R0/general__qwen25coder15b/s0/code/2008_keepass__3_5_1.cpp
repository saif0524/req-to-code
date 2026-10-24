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
  for (const auto& item : updatedData) {
    // Add the new data item to the existing database
  }
}

