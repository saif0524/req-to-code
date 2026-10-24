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

std::int64_t convert_to_int(std::string s);
std::vector<std::object> process_nested(std::vector<std::object> data);
void send_data(std::vector<std::object> to);
std::string handle_error(std::string message);

int64_t convert_to_int(string s) {
  try {
    int64_t num = stol(s);
    return num;
  } catch (const exception& e) {
    return -1;
  }
  }

vector<string_object> process_nested(vector<string_object> data) {
  vector<string_object> result;
  for (auto& element : data) {
    string_object converted;
    if (convert_string(element) != -1) {
      converted = convert_to_int(element);
    } else {
      converted = string_object();
    }
    result.push_back(converted);
  }
  return result;
}

void send_data(std::vector<std::object> to) {
  std::vector<std::object> result;
  for (auto& elem : to) {
    int64_t num = std::convert_to_int(elem);
    result.push_back(num);
  }
  to = result;
  }

std::string handle_error(std::string message) {
  try {
    return message;
  } catch (const std::exception& e) {
    return "Error occurred: " + e.what();
  }
  }

