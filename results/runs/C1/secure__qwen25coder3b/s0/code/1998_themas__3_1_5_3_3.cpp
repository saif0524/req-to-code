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
  if (unit.empty()) {
    return "Invalid unit";
  }
  std::string request;
  request += "Turn " + (isOn ? "on" : "off") + " ";
  request += unit;
  request += "\n";
  return request;
}

void processRequest(const std::string& request) {
  if (request.empty()) {
    std::cerr << "Invalid request" << std::endl;
    return;
  }
  std::string unit = request.substr(0, request.find(' '));
  bool isOn = request.substr(request.find(' ') + 1) == "on";
  std::cout << "Processing request to 

