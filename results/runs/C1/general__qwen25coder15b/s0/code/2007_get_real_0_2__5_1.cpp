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

struct get_real_server_config { std::string host; int port; double response_time_threshold; };

std::string get_real_server_host();
int get_real_server_port();
double get_real_server_response_time();
int get_real_server_attentions_span();
double get_real_server_response_time_threshold();

std::string get_real_server_host() { return get_real_server_config().host; }

struct get_real_server_config { std::string host; int port; double response_time_threshold; }; int get_real_server_port() { return get_real_server_config().port; }

double get_real_server_response_time() {
  std::string host = get_real_server_host();
  int port = get_real_server_port();
  double threshold = get_real_server_response_time_threshold();
  std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();
  // Make a request to the server
  // Measure the time it takes for the server to respond
  std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
  double response_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
  if (response_time < threshold) {
    return "Success";
  } else {
    return "Error";
  }
}

int get_real_server_attentions_span() {  return 10; }

double get_real_server_response_time_threshold() {  return 10000.0; }

