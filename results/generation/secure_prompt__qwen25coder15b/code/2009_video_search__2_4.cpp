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

std::string detect_os();
std::string detect_hardware();

std::string detect_os() {
  OSVERSIONINFOEXW osInfo;
  osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);
  if (GetVersionExW(&osInfo)) {
    if (osInfo.dwMajorVersion == 5 && osInfo.dwMinorVersion == 1) {
      return "Windows XP";
    } else if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 0) {
      return "Windows Vista";
    } else if (osInfo.dwMajorVersion == 7 && osInfo.dwMinorVersion == 0) {
      return "Windows 7";
    } else if (osInfo.dwMajorVersion == 8 && osInfo.dwMinorVersion == 0) {
      return "Windows 8";
    } else if (osInfo.dwMajorVersion == 9 && osInfo.dwMinorVersion == 0) {
      return "Windows 8.1";
    } else if (osInfo.dwMajorVersion == 10 && osInfo.dwMinorVersion == 0) {
      return "Windows 10";
    } else {
      return "Unknown";
    }
  } else {
    return "Unknown";
  }
}

std::string detect_hardware() {
  SYSTEM_INFO sysInfo;
  GetSystemInfo(&sysInfo);
  return {
    "processor": "

