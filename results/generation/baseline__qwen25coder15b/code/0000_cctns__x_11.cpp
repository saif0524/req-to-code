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

void display_help(const std::string& action, const std::string& scenario);
void update_help(const std::string& action, const std::string& scenario, const std::string& help_text);
std::string generate_help(const std::string& action, const std::string& scenario);
void load_help(const std::string& action, const std::string& scenario);
void save_help(const std::string& action, const std::string& scenario, const std::string& help_text);

void display_help(const std::string& action, const std::string& scenario) {
  std::string help_text = generate_help(action, scenario);
  load_help(action, scenario, help_text);
  save_help(action, scenario, help_text);
  display_help(action, scenario);
}

void update_help(const std::string& action, const std::string& scenario, const std::string& help_text) {
  std::string help_text = generate_help(action, scenario);
  load_help(action, scenario, help_text);
  save_help(action, scenario, help_text);
}

std::string generate_help(const std::string& action, const std::string& scenario) {
  std::string help_text = generate_help(action, scenario);
  load_help(action, scenario, help_text);
  save_help(action, scenario, help_text);
  return help_text;
}

void load_help(const std::string& action, const std::string& scenario) {
  std::string help_text = generate_help(action, scenario);
  load_help(action, scenario, help_text);
  save_help(action, scenario, help_text);
}

void save_help(const std::string& action, const std::string& scenario, const std::string& help_text, const std::string& file_path) {
  std::string help_text = generate_help(action, scenario);
  load_help(action, scenario, help_text);
  save_help(action, scenario, help_text, file_path);
}

