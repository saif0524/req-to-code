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

struct User {
  bool is_primary_cdn() const;
  bool is_peering_cdn() const;
  bool is_content_provider() const;
  bool is_end_user() const;
  bool is_short_term_peering() const;
  bool is_long_term_peering() const;
  bool has_preferred_treatment() const;
  bool has_user_qos() const;
  std::string get_content_provider_qos() const;
  std::string get_end_user_qos() const;
  std::string get_short_term_peering_qos() const;
  std::string get_long_term_peering_qos() const;
  std::string get_preferred_treatment_qos() const;
  std::string get_user_qos() const;
};

std::string get_user_type(const User& user);
std::string get_user_class(const User& user);
std::string get_user_qos(const User& user);

std::string get_user_type(User& user) {
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

std::string get_user_class(User& user) {
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

std::string User::get_user_qos() const {
  if (is_content_provider()) {
    return get_content_provider_qos();
  } else if (is_end_user()) {
    return get_end_user_qos();
  } else if (is_short_term_peering()) {
    return get_short_term_peering_qos();
  } else if (is_long_term_peering()) {
    return get_long_term_peering_qos();
  } else if (has_preferred_treatment()) {
    return get_preferred_treatment_qos();
  } else if (has_user_qos()) {
    return get_user_qos();
  } else {
    return "Unknown";
  }
}

