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

struct DatabasePath {};

std::string validate_database_path(const std::string& path);
std::vector<std::string> parse_command_line_options(int argc, char* argv[]);

std::vector<std::string> validate_database_path(const std::string& path) {
  std::vector<std::string> options;
  for (int i = 1; i < argc; ++i) {
    std::string option = argv[i];
    if (option.find(' ') != std::string::npos) {
      if (option.empty() || option.size() > 255) {
        return std::vector<std::string>{};
      }
      // Add quotes around the path if it contains a space
      options.push_back("

std::vector<std::string> parse_command_line_options(int argc, char* argv[]) {
  std::vector<std::string> options;
  for (int i = 1; i < argc; ++i) {
    std::string option = argv[i];
    if (option.find(' ') != std::string::npos) {
      if (option.empty() || option.size() > 255) {
        return std::vector<std::string>{};
      }
      // Add quotes around the path if it contains a space
      options.push_back("

