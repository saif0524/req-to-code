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

void build_custom_plugin(const std::string& customer_id, const std::string& plugin_name, const std::string& plugin_description);
std::optional<std::string> get_custom_plugin(const std::string& customer_id, const std::string& plugin_name);
void update_custom_plugin(const std::string& customer_id, const std::string& plugin_name, const std::string& plugin_description);
void delete_custom_plugin(const std::string& customer_id, const std::string& plugin_name);

std::optional<std::string> get_custom_plugin(const std::string& customer_id, const std::string& plugin_name) {
  return get_custom_plugin(customer_id, plugin_name);
}

void update_custom_plugin(const std::string& customer_id, const std::string& plugin_name, const std::string& plugin_description) {
  std::optional<std::string> current_plugin = get_custom_plugin(customer_id, plugin_name);
  if (current_plugin.has_value()) {
    current_plugin.value() = plugin_description;
  } else {
    return "Plugin not found";
  }
}

void delete_custom_plugin(const std::string& customer_id, const std::string& plugin_name) {
  std::optional<std::string> current_plugin = get_custom_plugin(customer_id, plugin_name);
  if (current_plugin.has_value()) {
    current_plugin.value() = "";
  } else {
    return "Plugin not found";
  }
}

