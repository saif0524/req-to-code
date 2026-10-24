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

std::pair<std::string, std::string> create_group(std::string user_id);
std::pair<std::string, std::string> get_entry(std::string user_id, std::string entry_id, std::pair<std::string, std::string> group);

std::pair<std::string, std::string> create_group(std::string user_id) {
    return std::make_pair(user_id,);
    }

std::pair<std::string, std::string> get_entry(std::string user_id, std::string entry_id, std::pair<std string, std::string> group) {
    return std::make_pair(group.first, group.second);
    }

