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

std::string get_user_input(std::string input) {
    std::stringstream ss;
    ss << input;
    return ss.str();
    }

std::string process_input(int number) { std::string str(number); std::reverse(str.begin(), str.end()); return str; }

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
  

