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

double getRealResponseTime();

double getRealResponseTime() {
     auto start = std::chrono::system_clock::now();
     // Connect to Get Real server and send a request here
     auto end = std::chrono::system_clock::now();
     std::chrono::duration<double> elapsed_seconds = end - start;
     return elapsed_seconds.count() * 1.0; // Convert to milliseconds
}

