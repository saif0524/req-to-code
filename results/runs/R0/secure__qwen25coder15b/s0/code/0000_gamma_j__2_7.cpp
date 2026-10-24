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

void receive_usb_samples(const std::vector<std::string>& sample_urls);
void freeze_baseline(const std::vector<std::string>& sample_urls);

void receive_usb_samples(const std::vector<std::string>& sample_urls) {
  std::filesystem::create_directory("/path/to/local/directory");
  for (const auto& url : sample_urls) {
    std::filesystem::copy_file(url, "/path/to/local/directory/sample_" + std::filesystem::path(url).filename());
  }
}

void freeze_baseline(const std::vector<std::string>& sample_urls) {
  std::filesystem::create_directory("/path/to/local/directory");
  for (const auto& url : sample_urls) {
    std::filesystem::copy_file(url, "/path/to/local/directory/sample_

