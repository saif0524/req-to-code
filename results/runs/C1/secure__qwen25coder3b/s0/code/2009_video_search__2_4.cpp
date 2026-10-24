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
bool checkInternetConnection();
bool checkSystemRequirements(const std::string& os, const std::string& browser);

bool checkOperatingSystem(const std::string& os) {
  std::vector<std::string> supportedOSes = {"Windows XP", "Windows Vista", "Mac OS X", "Linux"};
  for (const auto& supportedOS : supportedOSes) {
    if (os == supportedOS) {
      return true;
    }
  }
  return false;
}

bool checkBrowser(const std::string& browser) {
  std::vector<std::string> supportedBrowsers = {"Internet Explorer", "Firefox", "Safari"};
  for (const auto& supportedBrowser : supportedBrowsers) {
    if (browser == supportedBrowser) {
      return true;
    }
  }
  return false;
}

bool checkHardware() {
  std::string ramOutput;
  std::string diskOutput;
  std::string cpuOutput;

  // Check RAM
  ramOutput = std::system("free -h | grep Mem | awk '{print $2}'");
  if (std::stoi(ramOutput.substr(0, ramOutput.find(

bool checkInternetConnection() {
  std::string command = "ip link show";
  if (std::system(command.c_str()) == 0) {
    command = "nslookup google.com";
    if (std::system(command.c_str()) == 0) {
      return true;
    }
  }
  return false;
}

bool checkSystemRequirements(const std::string& os, const std::string& browser) {
  std::string reason = "All system requirements are met";

  if (!checkOperatingSystem(os)) {
    reason = "Operating system not supported";
  }

  if (!checkBrowser(browser)) {
    reason = "Web browser not supported";
  }

  if (!checkHardware()) {
    reason = "Hardware requirements not met";
  }

  if (!checkInternetConnection()) {
    reason = "Internet connection not available";
  }

  return reason;
}

