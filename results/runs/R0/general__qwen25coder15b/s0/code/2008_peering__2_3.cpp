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

std::string get_user_type(const User& user);
std::string get_user_class(const User& user);
std::string get_user_qos(const User& user);

std::string get_user_type(const User& user) {
  if (user.is_primary_cdn()) {
    return "Primary CDN";
  } else if (user.is_peering_cdn()) {
    return "Peering CDN";
  } else if (user.is_content_provider()) {
    return "Content Provider";
  } else if (user.is_end_user()) {
    return "End User";
  } else if (user.is_short_term_peering()) {
    return "Short-term Peering";
  } else if (user.is_long_term_peering()) {
    return "Long-term Peering";
  } else if (user.has_preferred_treatment()) {
    return "Preferred Treatment";
  } else if (user.has_user_qos()) {
    return "User QoS";
  } else {
    return "Unknown";
  }
}

std::string get_user_class(const User& user) {
  if (user.is_primary_cdn()) {
    return "Primary CDN";
  } else if (user.is_peering_cdn()) {
    return "Peering CDN";
  } else if (user.is_content_provider()) {
    return "Content Provider";
  } else if (user.is_end_user()) {
    return "End User";
  } else if (user.is_short_term_peering()) {
    return "Short-term Peering";
  } else if (user.is_long_term_peering()) {
    return "Long-term Peering";
  } else if (user.has_preferred_treatment()) {
    return "Preferred Treatment";
  } else if (user.has_user_qos()) {
    return "User QoS";
  } else {
    return "Unknown";
  }
}

std::string get_user_qos(const User& user) {
  if (user.is_content_provider()) {
    return user.get_content_provider_qos();
  } else if (user.is_end_user()) {
    return user.get_end_user_qos();
  } else if (user.is_short_term_peering()) {
    return user.get_short_term_peering_qos();
  } else if (user.is_long_term_peering()) {
    return user.get_long_term_peering_qos();
  } else if (user.has_preferred_treatment()) {
    return user.get_preferred_treatment_qos();
  } else if (user.has_user_qos()) {
    return user.get_user_qos();
  } else {
    return "Unknown";
  }
}

