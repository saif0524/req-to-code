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

double measure_response_time(double start_time, double timeout);
double average_response_time(std::vector<double> responses);
void store_response_times(std::vector<double> &response_times);
void reset_response_timer();
void log_response_time(double time, const std::string &message);

double average_response_time(std::vector<double> responses) {
  if (responses.empty()) {
    return 0.0;
  }
  double sum = 0.0;
  for (double r : responses) {
    sum += r;
  }
  return sum / responses.size();
  }

double average_response_time(std::vector<double> responses) {
    if (responses.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (double r : responses) {
        sum += r;
    }
    return sum / responses.size();
    }

void store_response_times(std::vector<double> &response_times) {
  for (double time : response_times) {
    response_times.push_back(time);
  }
}

void reset_response_timer() {
  return; }

double log_response_time(double time, const std::string &message) {
    static std::vector<double> responses;
    if (responses.empty()) {
        responses.push_back(time);
    }
    return "Log completed successfully";
    }

