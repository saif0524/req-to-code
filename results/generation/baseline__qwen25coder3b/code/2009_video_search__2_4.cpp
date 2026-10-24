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

bool checkOperatingSystem(const std::string& os) {
  switch (os) {
    case "Windows XP":
    case "Windows Vista":
    case "Mac OS X":
    case "Linux":
      return true;
    default:
      return false;
  }
}

bool checkBrowser(const std::string& browser) {
  switch (browser) {
    case "Internet Explorer":
    case "Firefox":
    case "Safari":
      return true;
    default:
      return false;
  }
}

bool checkHardware() { return checkInternetConnection(); }

bool isSupported(const std::string& os, const std::string& browser) { return checkOperatingSystem(os) && checkBrowser(browser); }

bool checkInternetConnection() { return checkHardware(); }

