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

This code doesn't show any global variables or structs needed, so no additions are needed.

std::pair<bool, std::pair<std::string, std::string>> validate_username_password(std::string username, std::string password, std::string url);
std::pair<std::string, std::pair<std::string, std::string>> expire_session(std::string username, std::string password, std::string url, std::long long expiration_time);
void invalidate_session(std::string username, std::string password, std::string url, std::long long expiration_time);

pair<bool, pair<string, string>> validate_username_password(std::string username, std::string password, std::string url) {
  bool username_valid = is_username_valid(username);
  bool password_valid = is_password_valid(password, url);
  return make_pair(username_valid, make_pair(password_valid, url));
}

pair<string, pair<string, string>> expire_session(string username, string password, string url, long long expiration_time) {
    string message = "TAN session expired at time " + to_string(expiration_time) + " at URL " + url;
    return make_pair(message, make_pair(expiration_time, url));
}

void invalidate_session(std::string username, std::string password, std::string url, std::long long expiration_time) { 
  std::string message = "TAN session invalid at time " + std::to_string(expiration_time) + " at URL " + url; 
  return { std::make_pair(expiration_time, url), message }; 
}

