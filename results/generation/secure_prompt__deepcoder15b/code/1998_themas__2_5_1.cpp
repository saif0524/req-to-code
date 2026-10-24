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

std::pair<std::string, std::tuple<int, double>> get_target_temp(std::pair<std::string, std::tuple<int, double>> target_temp);
std::pair<std::string, std::tuple<int, double>> get_average_temp(std::pair<std::string, std::tuple<int, double>> history);
int calculate_heating需求(std::pair<std::string, std::tuple<int, double>> current_temp, std::pair<std::string, std::tuple<int, double>> target_temp);

pair<string, tuple<int, int>> get_target_temp(pair<string, tuple<int, int>> target_temp) {
  return make_pair(target_temp.first, target_temp.second);
}

std::pair<std::string, std::tuple<int, double>> get_average_temp(std::pair<std::string, std::tuple<int, double>> history) {
  int sum = 0;
  for (auto &pair : history) {
    sum += get<0>(pair);
  }
  double average = static_cast<double>(sum) / history.size();
  std::string average_str = std::to_string(average);
  return {average_str, std::make_tuple<int, double>(average)};
  }

int calculate_heating(std::pair<std::string, std::tuple<int, double>> current_temp, std::pair<std::string, std::tuple<int, double>> target_temp) { 
  double current_temp_temp = current_temp.second.get<1>(double); 
  double target_temp_temp = target_temp.second.get<1>(double); 
  double difference = target_temp_temp - current_temp_temp; 
  return static_cast<int>(difference); 
 }

