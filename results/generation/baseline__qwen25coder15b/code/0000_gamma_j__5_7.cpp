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

void load_plugin(const std::string& plugin_name);
void update_site(const std::string& fix);
void log_change(const std::string& change);
void upgrade_system(const std::string& patch);

void load_plugin(const std::string& plugin_name) {
  plugins::load_plugin(plugin_name);
}

void update_site(const std::string& fix) {
  plugins::load_plugin("fix_plugin");
  shared::update_site(fix);
  shared::log_change("Updated site with fix: " + fix);
  shared::upgrade_system("patch");
}

void log_change(const std::string& change) {
  plugins::load_plugin("fix_plugin");
  shared::update_site(change);
  shared::log_change("Updated site with change: " + change);
  shared::upgrade_system("patch");
}

void upgrade_system(const std::string& patch) {
  plugins::load_plugin(patch);
  shared::update_site(patch);
  shared::log_change("Updated site with patch: " + patch);
  shared::upgrade_system(patch);
}

