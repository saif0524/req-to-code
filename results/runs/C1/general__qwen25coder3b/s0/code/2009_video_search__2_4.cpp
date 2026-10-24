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

bool checkOperatingSystem(const std::string& os);
bool checkBrowser(const std::string& browser);
bool checkHardware();
bool isSupported(const std::string& os, const std::string& browser);
bool checkInternetConnection();

int convertToInteger(const std::string& str) { return std::stoi(str); }

bool checkOperatingSystem(const std::string& os) {
  switch (convertToInteger(os)) {
    case 1: // Windows XP
    case 2: // Windows Vista
    case 3: // Mac OS X
    case 4: // Linux
      return true;
    default:
      return false;
  }
}

bool checkBrowser(const std::string& browser) {
  return checkOperatingSystem(convertToInteger(browser));
}

bool checkHardware() { return checkInternetConnection(); }

bool isSupported(const std::string& os, const std::string& browser) { return checkOperatingSystem(os) && checkBrowser(browser); }

bool checkInternetConnection() { return checkHardware(); }

