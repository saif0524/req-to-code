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

bool checkBrowserCompatibility(const std::string& browserVersion);
bool checkOperatingSystemCompatibility(const std::string& osVersion);
bool checkDatabaseCompatibility(const std::string& databaseType);
bool checkHardwareCompatibility(const std::string& hardwareType);
bool checkUSBInterfaceCompatibility(const std::string& usbInterfaceType);

bool checkBrowserCompatibility(const std::string& browserVersion) {
  if (browserVersion == "Microsoft Internet Explorer version 6" ||
      browserVersion == "Microsoft Internet Explorer version 7" ||
      browserVersion == "Netscape Communicator Version 4" ||
      browserVersion == "Netscape Communicator Version 5") {
    return true;
  }
  return false;
}

bool checkOperatingSystemCompatibility(const std::string& osVersion) {
  if (osVersion == "Intel based system with Slackware Linux 2.6" ||
      osVersion == "Apache Web Server") {
    return true;
  }
  return false;
}

bool checkDatabaseCompatibility(const std::string& databaseType) {
  if (databaseType == "SQL based database") {
    return true;
  }
  return false;
}

bool checkHardwareCompatibility(const std::string& hardwareType) {
  std::vector<std::string> supportedHardware = {"Intel based system with Slackware Linux 2.6", "Apache Web Server", "USB interface and divers provided by Yoggie Corporation"};
  for (const auto& supported : supportedHardware) {
    if (hardwareType == supported) {
      return true;
    }
  }
  return false;
}

bool checkUSBInterfaceCompatibility(const std::string& usbInterfaceType) {
  std::vector<std::string> supportedHardware = {"Intel based system with Slackware Linux 2.6", "Apache Web Server", "USB interface and divers provided by Yoggie Corporation"};
  for (const auto& supported : supportedHardware) {
    if (usbInterfaceType == supported) {
      return true;
    }
  }
  return false;
}

