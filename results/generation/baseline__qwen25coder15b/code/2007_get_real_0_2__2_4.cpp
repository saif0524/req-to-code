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

std::string get_real_domain();
std::string get_real_osu_server();
std::string get_real_ous_domain();
std::string get_real_site_url();
std::string get_real_site_extension();

std::string get_real_domain() { return "getreal.ous.edu"; }

std::string get_real_osu_server() { return get_real_domain(); }

std::string get_real_ous_domain() { return get_real_domain(); }

std::string get_real_site_url() { return get_real_ous_domain() + get_real_site_extension(); }

std::string get_real_site_extension() { return ".html"; }

