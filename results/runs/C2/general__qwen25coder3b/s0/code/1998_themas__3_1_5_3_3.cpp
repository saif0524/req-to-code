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

std::string generateRequest(const std::string& unit, bool isOn);
void processRequest(const std::string& request);

std::string generateRequest(const std::string& unit, bool isOn) {
  std::string request;
  request += unit;
  request += ' ';
  request += (isOn ? 'ON' : 'OFF');
  return request;
}

void processRequest(const std::string& request) {
  size_t spacePos = request.find(' ');
  std::string unit = request.substr(0, spacePos);
  bool isOn = request[spacePos + 1] == 'O';
  // Control the heating or cooling unit based on the parsed information
  // Example: controlUnit(unit, isOn);
}

