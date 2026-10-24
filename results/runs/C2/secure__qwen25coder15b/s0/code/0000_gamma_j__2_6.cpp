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

void install_online_help(const std::string& url);
void deliver_manual(const std::string& manual_path);

void install_online_help(const std::string& url) {
  std::filesystem::path dir(url);

  for (const auto& entry : std::filesystem::directory_iterator(dir)) {
    if (entry.is_regular_file()) {
      std::filesystem::copy(entry.path(), entry.path() + '/');
    }
  }
}

void deliver_manual(const std::string& manual_path) {

  std::filesystem::path dir(manual_path);

  for (const auto& entry : std::filesystem::directory_iterator(dir)) {
    if (entry.is_regular_file()) {
      std::filesystem::copy(entry.path(), entry.path() + '/');
    }
  }
}

