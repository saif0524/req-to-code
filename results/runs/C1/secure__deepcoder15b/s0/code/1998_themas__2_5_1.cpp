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

std::pair<int, double> get_current_temp(std::pair<std::string, std::tuple<int, double>> current_temp);
std::pair<std::string, std::tuple<int, double>> set_target_temp(std::pair<std::string, std::tuple<int, double>> target_temp);
std::pair<std::string, std::tuple<int, double>> get_target_temp(std::pair<std::string, std::tuple<int, double>> target_temp);
std::pair<std::string, std::tuple<int, double>> get_average_temp(std::pair<std::string, std::tuple<int, double>> history);
int calculate_heating需求(std::pair<std::string, std::tuple<int, double>> current_temp, std::pair<std::string, std::tuple<int, double>> target_temp);

pair<int, double> get_current_temp(pair<string, tuple<int, double>> current_temp) {
  if (current_temp.empty() || current_temp.first.empty() || current_temp.second.empty()) {
    return {0, 0.0};
  }
  int temp = static_cast<int>(current_temp.second.get<1>(double));
  return {0, temp};
}

pair<string, tuple<int, double>> set_target_temp(pair<string, tuple<int, double>> target_temp) {
  pair<string, tuple<int, double>> result = make_pair(target_temp.first, make_pair(target_temp.second.first, target_temp.second.second));
  return result;
}

pair<string, tuple<int, int>> get_target_temp(pair<string, tuple<int, int>> target_temp) {
  return make_pair(target_temp.first, target_temp.second);
}

pair<string, tuple<int, double>> get_average_temp(pair<string, tuple<int, double>> history) {
  int sum = 0;
  for (auto &pair : history) {
    sum += get<0>(pair);
  }
  double average = static_cast<double>(sum) / history.size();
  double average_str = std::to_string(average);
  return {average_str, std::make_tuple<int, double>(average)};
  }
  

int calculate_heating(std::pair<std::string, std::tuple<int, double>> current_temp, std::pair<stdstring, std::tuple<int, double>> target_temp) { 
  double current_temp_temp = static_cast<double>(current_temp.second[1]); 
  double target_temp_temp = static_cast<double>(target_temp.second[1]); 
  double difference = target_temp_temp - current_temp_temp; 
  return static_cast<int>(difference); 
  }

