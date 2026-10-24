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

std::string search_term(const std::string& term);
std::vector<std::string> fetch_urls(const std::vector<std::string>& sites);
void display_url(std::string url);
void exit_or_enter();

std::string search_term(const std::string& term) {
  return term + '%' + term;
  }

vector<string> fetch_urls(const vector<string>& sites) {
  vector<string> result;
  for (const string& site : sites) {
    string query = search_term(site);
    string path = query.substr(0, query.find('%') + 1);
    string url = "https://example.com/something" + path;\nresult.push_back(url);\n}\nreturn result;
  }
  

void display_url(std::string url) {
  // Split URL into components
  size_t hostname_pos = url.find('://');
  if (hostname_pos == std::string::npos) {
    std::string cleaned = url;
    return;
  }
  size_t protocol_pos = url.find('/');
  if (protocol_pos == std::string::npos) {
    std::string cleaned = url;
    return;
  }
  size_t path_pos = url.find('>');
  if (path_pos == std::string::npos) {
    std::string cleaned = url;
    return;
  }

  std::string hostname = url.substr(0, hostname_pos);
  std::string protocol = url.substr(hostname_pos, protocol_pos - hostname_pos);
  std::string path = url.substr(path_pos);

  // Clean each component
  auto clean = [](std::string &s) {
    s.erase(s.begin(), s.find(' ') | s.find('%') | s.find('/'));
  };

  std::vector<std::string> components = {
    {clean(hostname), "Hostname"},
    {clean(protocol), "Protocol"},
    {clean(path), "Path"}
  };

  // Combine components
  std::string result = components[0].second;
  for (size_t i = 1; i < components.size(); ++i) {
    result += " \n" + components[i].second;
  }

  return result;
  }

static void exit_or_enter() {
  if (std::cout->find('Enter') != std::string::npos) {
    handle_search();
  }
}

