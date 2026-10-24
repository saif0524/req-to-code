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
  if (user.membership == 'primary_cdn') {
    return 'primary_cdn';
  } else if (user.contributions == 'explicit') {
    return 'explicit_member';
  } else if (user.contributions == 'dynamic_qos') {
    return 'dynamic_qos';
  } else if (user.contributions == 'implicit') {
    return 'implicit_member';
  } else {
    return 'unknown';
  }
}

std::string get_user_class(const User& user) {
  if (user.membership == 'primary_cdn') {
    return 'primary_cdn';
  } else if (user.contributions == 'explicit') {
    return 'explicit_member';
  } else if (user.contributions == 'dynamic_qos') {
    return 'dynamic_qos';
  } else if (user.contributions == 'implicit') {
    return 'implicit_member';
  } else if (user.contributions == 'unknown') {
    return 'unknown';
  } else if (user.purpose == 'short_term') {
    return 'short_term';
  } else if (user.purpose == 'long_term') {
    return 'long_term';
  } else if (user.size == 'small') {
    return 'small';
  } else if (user.size == 'medium') {
    return 'medium';
  } else if (user.size == 'large') {
    return 'large';
  } else if (user.scope == 'local') {
    return 'local';
  } else if (user.scope == 'national') {
    return 'national';
  } else if (user.scope == 'global') {
    return 'global';
  } else if (user.duration == 'short') {
    return 'short';
  } else if (user.duration == 'medium') {
    return 'medium';
  } else if (user.duration == 'long') {
    return 'long';
  } else {
    return 'unknown';
  }
}

std::string get_user_qos(const User& user) {  return user.user_qos; }

