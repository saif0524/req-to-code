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

std::string get_default_help_topic();
void display_help_topic(const std::string& topic);
void initialize_help_system();
void handle_help_link_click();
void update_help_topic(const std::string& new_topic);

std::string get_default_help_topic() { return "[system name] Overview"; }

void display_help_topic(const std::string& topic) { std::cout << topic << std::endl; }

void initialize_help_system() { std::string default_topic = get_default_help_topic(); display_help_topic(default_topic); }

void handle_help_link_click() { std::string new_topic = get_default_help_topic(); display_help_topic(new_topic); }

void update_help_topic(const std::string& new_topic) {
  std::string current_topic = get_default_help_topic();
  std::string updated_topic = new_topic;
  display_help_topic(updated_topic);
}

