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

int get_user_input(int number);
std::string process_input(int number);
void display_output(std::string message);
bool validate_input(int number);
void save_data(std::string file_path);

std::string get_user_input(std::string input) {
    std::stringstream ss;
    ss << input;
    return ss.str();
    }

std::string process_input(int number) {
  return std::to_string(number);
}

void display_output(std::string message) {
    std::cout << message << std::endl;
    }

bool validate_input(int number) {
  if (number < 0) {
    return false;
  }
  int original = number;
  int reversed = 0;
  while (original > 0) {
    reversed = reversed * 10 + original % 10;
    original = original / 10;
  }
  return (reversed == original);
  }
  

std::string save_data(std::string file_path) {
    std::ofstream file_out(file_path);
    if (file_out.is_open()) {
        file_out << 

