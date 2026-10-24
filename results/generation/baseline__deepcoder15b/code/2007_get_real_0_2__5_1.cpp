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
void log_response_time(double time, const std::string &message);

double double measure_response_time(double start_time, double timeout) { return timeout; }

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

double log_response_time(double time, const std::string &message) {
    // Open the file for writing
    file_open(

