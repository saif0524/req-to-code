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

void disband_peering(std::vector<std::string> &peering_arrangement);
void rearrange_peering(std::vector<std::string> &peering_arrangement);

void disband_peering(std::vector<std::string> &peering_arrangement) {
  // Your implementation here
}

void rearrange_peering(std::vector<std::string> &peering_arrangement) {
  std::sort(peering_arrangement.begin(), peering_arrangement.end());
  for (int i = 0; i < peering_arrangement.size(); i++) {
    for (int j = i + 1; j < peering_arrangement.size(); j++) {
      if (peering_arrangement[i] > peering_arrangement[j]) {
        std::swap(peering_arrangement[i], peering_arrangement[j]);
      }
    }
  }
}

