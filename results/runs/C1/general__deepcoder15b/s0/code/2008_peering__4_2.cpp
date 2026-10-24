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

{"message": std::vector<int>}
using std::begin; using std::end; using std::vector;

int calculateTotalDataLength(const message& m);
size_t processMessages(const vector<message>& messages);
string handleHTTPRequest(const string& url);
string handleFTPRequest(const string& path);
double calculateAverageDataLength(const int64_t* lengths);

int calculateTotalDataLength(const message& m) { return m.length; }

size_t processMessages(const vector<Message>& messages) {
  size_t count = 0;
  for (const Message& m : messages) {
    count++;
  }
  return count;
  }

double calculateAverageDataLength(const std::vector<std::long long> lengths) {
  if (lengths.empty()) {
    return 0.0; // Handle empty vector case as needed
  }
  double sum = 0.0;
  for (const auto& len : lengths) {
    sum += len;
  }
  return static_cast<double>(sum) / lengths.size();
}

