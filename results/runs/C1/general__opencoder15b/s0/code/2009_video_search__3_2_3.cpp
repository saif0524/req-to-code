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

void updateDatabase();
void includeVideoHostSearch(bool include);
void includeVideoLinkSearch(bool include);
std::vector<VideoHost> searchVideoHosts(std::string query);
std::vector<VideoLink> searchVideoLinks(std::string query);

