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

using namespace std;

void build_custom_plugin(const std::string& customer_id, const std::string& plugin_name, const std::string& plugin_description);
std::optional<std::string> get_custom_plugin(const std::string& customer_id, const std::string& plugin_name);
void update_custom_plugin(const std::string& customer_id, const std::string& plugin_name, const std::string& new_description);
void delete_custom_plugin(const std::string& customer_id, const std::string& plugin_name);

void build_custom_plugin(const std::string& customer_id, const std::string& plugin_name, const std::string& plugin_description) {
  // Check if the customer exists
  if (customer_exists(customer_id)) {
    // Create the plugin
    std::string plugin = create_plugin(plugin_name, plugin_description);
    // Save the plugin
    save_plugin(customer_id, plugin);
    // Return the result
    return std::optional<std::string>::value(plugin_name);
  } else {
    // Return an error
    return std::optional<std::string>::nullopt();
  }
}

void get_custom_plugin(const std::string& customer_id, const std::string& plugin_name, const std::string& plugin_description) {
  // Check if the customer exists
  if (customer_exists(customer_id)) {
    // Create the plugin
    std::string plugin = create_plugin(plugin_name, plugin_description);
    // Save the plugin
    save_plugin(customer_id, plugin);
    // Return the result
    return std::optional<std::string>::value(plugin_name);
  } else {
    // Return an error
    return std::optional<std::string>::nullopt();
  }
}

void update_custom_plugin(const std::string& customer_id, const std::string& plugin_name, const std::string& new_description) {
  // Check if the customer exists
  if (customer_exists(customer_id)) {
    // Create the plugin
    std::string plugin = create_plugin(plugin_name, plugin_description);
    // Save the plugin
    save_plugin(customer_id, plugin);
    // Update the description of the plugin
    update_plugin(customer_id, plugin_name, new_description);
  } else {
    // Return an error
    return std::optional<std::string>::nullopt();
  }
}

void delete_custom_plugin(const std::string& customer_id, const std::string& plugin_name) {
  // Check if the customer exists
  if (customer_exists(customer_id)) {
    // Create the plugin
    std::string plugin = create_plugin(plugin_name, plugin_description);
    // Save the plugin
    save_plugin(customer_id, plugin);
    // Update the description of the plugin
    update_plugin(customer_id, plugin_name, plugin_description);
  } else {
    // Return an error
    return std::optional<std::string>::nullopt();
  }
}

