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

std::string get_real_site_url();
bool check_ous_domain(const std::string& domain);
std::vector<std::string> get_osu_servers();
std::string construct_site_url(const std::string& domain, const std::vector<std::string>& servers);
bool validate_site_url(const std::string& url);

std::string get_real_site_url() {
  std::string domain = "getreal.ous.edu";
  std::vector<std::string> servers = get_osu_servers();
  std::string url = construct_site_url(domain, servers);
  if (!validate_site_url(url)) {
    throw std::runtime_error("Invalid site URL");
  }
  return url;
}

bool check_ous_domain(const std::string& domain) {
  return domain == "getreal.ous.edu";
}

static std::vector<std::string> get_osu_servers() { static std::vector<std::string> servers = {"server1.osu.edu", "server2.osu.edu", "server3.osu.edu"}; return servers; }

std::string construct_site_url(const std::string& domain, const std::vector<std::string>& servers) {
  if (domain != "getreal.ous.edu") {
    throw std::runtime_error("Invalid domain");
  }
  std::string url = domain;
  for (const auto& server : servers) {
    url += "/" + server;
  }
  if (!validate_site_url(url)) {
    throw std::runtime_error("Invalid site URL");
  }
  return url;
}

bool validate_site_url(const std::string& url) {
  std::string domain = "getreal.ous.edu";
  if (url.substr(0, domain.length()) != domain) {
    return false;
  }
  size_t pos = url.find_first_of('/');
  if (pos == std::string::npos || pos == url.length() - 1) {
    return false;
  }
  std::regex url_regex("^https?://" + domain + "/[a-zA-Z0-9-]+(/[a-zA-Z0-9-]+)*$");\nreturn std::regex_match(url, url_regex);\n}

