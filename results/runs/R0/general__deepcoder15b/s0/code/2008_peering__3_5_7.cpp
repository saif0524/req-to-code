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

bool has_enough_resources(const bool &has_enough);
void deploy_policy(int policy_type, int threshold);
bool check_sla_status(const int target_status, int current_status);
void handle_peering(const peer_object &peer);

bool has_enough_resources(const bool &current_status, int threshold) {
    if (current_status >= threshold) {
        return true;
    } else {
        return false;
    }
    }

bool deploy_policy(int policy_type, int threshold) {
    if (current_status < threshold) {
        return true;
    } else {
        return false;
    }
    }

bool check_sla_status(int target_status, int current_status) {
    if (current_status < target_status) {
        return true;
    } else {
        return false;
    }
    }

bool handle_peering(const peer_object &peer) {
  if (is_valid(peer)) {
    if (check_sla_status(current_status, threshold)) {
      return true;
    } else {
      return false;
    }
  }
  return false;
  },
  

