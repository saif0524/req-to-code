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

std::string get_user_type() const;
void set_user_type(std::string type);
std::vector<std::string> get_search_sites() const;
void set_search_sites(const std::vector<std::string>& sites);
double get_site_speed() const;

std::string VideoSearchEngine::get_user_type() const { return user_type; }

void VideoSearchEngine::set_user_type(std::string type) { if (type != "general" && type != "developer") { return; } user_type = type; }

std::vector<std::string> VideoSearchEngine::get_search_sites() const { return search_sites; }

void VideoSearchEngine::set_search_sites(const std::vector<std::string>& sites) { if (!sites.empty()) { search_sites = sites; } }

double VideoSearchEngine::get_site_speed() const { return site_speed; }

