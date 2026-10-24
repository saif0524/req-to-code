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

void saveData(std::shared_ptr[DataItem> data, std::string& file_path, int& start_time, int& end_time);

void saveData(std::shared_ptr<DataItem> data, std::string& file_path, int& start_time, int& end_time) {
  // Open the selected file (already done)
  // Read all data from the file
  std::vector<DataItem> data_list;
  int current_line = 0;
  std::string line;

  // Read each line and extract data
  while (std::getline(file_path, line, '
')) {
    DataItem item = DataItem();
    // Add each item's properties to data_list
    data_list.push_back(item);
  }

  // Create the return pair
  return {file_path, std::shared_ptr<DataItem>(data_list[0])};
}

