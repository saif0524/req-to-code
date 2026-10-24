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
bool check_ous_domain(const std::string& domain);
std::string get_real_url();
std::string get_real_server();
bool check_google_hits(const std::string& domain);

std::string get_real_domain() { return "getreal.ous.edu"; }

bool check_ous_domain(const std::string& domain) { return domain.compare("ous.edu") == 0; }

std::string get_real_url() { return get_real_domain() + '/'; }

std::string get_real_server() { return "ous.edu"; }

bool check_google_hits(const std::string& domain) { return check_ous_domain(domain); }

