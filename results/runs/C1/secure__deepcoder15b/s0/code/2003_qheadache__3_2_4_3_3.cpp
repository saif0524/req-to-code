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

The code uses DataItem and other custom structs which are defined in the shared declarations. No additional declarations are needed.

std::string fileDialog() -> std::string;
std::pair<std::string, std::shared_ptr[DataItem]> readFile() -> std::pair<std::string, std::shared_ptr[DataItem]};
void saveData(std::shared_ptr[DataItem> data, std::string& file_path, int& start_time, int& end_time);

void readFile(std::string file_path, std::pair<std::string, std::shared_ptr[DataItem>>& result) {
  std::vector<DataItem> data_list;
  std::string current_line;

  std::istringstream file_stream(file_path);
  std::string line;

  while (std::getline(file_stream, line, ' ')) {
    std::istringstream line_stream(line);
    std::string item_name;
    std::vector<std::string> item_components;

    std::getline(line_stream, item_name, ' ');
    if (!item_name.empty()) {
      data_list.push_back(DataItem(item_name, std::make_shared<std::vector<std::string>>{}));
    }

    std::split(line, line_stream);
    if (!line.empty()) {
      std::vector<std::string> components;
      for (std::string comp : line) {
        components.push_back(std::make_shared<std::string>(comp));
      }
      data_list.back() = DataItem{};
    }
  }

  result.first = current_line;
  result.second = std::make_shared<std::vector<DataItem>>(data_list);
  }
}

void saveData(std::shared_ptr<DataItem> data, std::string& file_path, int& start_time, int& end_time) { 
  pair<string, shared_ptr[DataItem]] result; 
  result.first = file_path; 
  result.second = data; 
  return result; 
}

