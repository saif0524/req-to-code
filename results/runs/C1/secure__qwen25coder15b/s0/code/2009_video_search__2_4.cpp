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

using OSVERSIONINFOEXW = struct { DWORD dwOSVersionInfoSize; WORD dwMajorVersion; WORD dwMinorVersion; WORD dwBuildNumber; WORD dwPlatformId; DWORD szCSDVersion[16]; DWORD wServicePackMajor; DWORD wServicePackMinor; DWORD wSuiteMask; DWORD wProductType; DWORD wReserved; }; using SYSTEM_INFO = struct { WORD dwOSVersionInfoSize; WORD dwMajorVersion; WORD dwMinorVersion; WORD dwBuildNumber; WORD dwPlatformId; WORD dwReserved1; WORD dwReserved2; DWORD dwProcessorArchitecture; DWORD dwProcessorLevel; DWORD dwProcessorRevision; DWORD wReserved3; }; using DWORD = unsigned int; using WORD = unsigned short; using BYTE = unsigned char;
using SYSTEM_INFO = struct { WORD dwOSVersionInfoSize; WORD dwMajorVersion; WORD dwMinorVersion; WORD dwBuildNumber; WORD dwPlatformId; WORD dwReserved1; WORD dwReserved2; DWORD dwProcessorArchitecture; DWORD dwProcessorLevel; DWORD dwProcessorRevision; DWORD wReserved3; }; using DWORD = unsigned int; using WORD = unsigned short; using BYTE = unsigned char; using OSVERSIONINFOEXW = struct { DWORD dwOSVersionInfoSize; WORD dwMajorVersion; WORD dwMinorVersion; WORD dwBuildNumber; WORD dwPlatformId; WORD dwReserved; DWORD szCSDVersion[16]; DWORD wServicePackMajor; DWORD wServicePackMinor; DWORD wSuiteMask; DWORD wProductType; DWORD wReserved; };

std::string detect_os();
std::string detect_browser();
std::string detect_hardware();

std::string detect_os() {
  SYSTEM_INFO sysInfo;
  GetSystemInfo(&sysInfo);
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

std::string detect_browser() {
  SYSTEM_INFO sysInfo;
  GetSystemInfo(&sysInfo);
  OSVERSIONINFOEXW osInfo;
  osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);
  if (GetVersionExW(&osInfo)) {
    if (osInfo.dwMajorVersion == 5 && osInfo.dwMinorVersion == 1) {
      return "Internet Explorer";
    } else if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 0) {
      return "Firefox";
    } else if (osInfo.dwMajorVersion == 7 && osInfo.dwMinorVersion == 0) {
      return "Safari";
    } else if (osInfo.dwMajorVersion == 8 && osInfo.dwMinorVersion == 0) {
      return "Internet Explorer";
    } else if (osInfo.dwMajorVersion == 9 && osInfo.dwMinorVersion == 0) {
      return "Internet Explorer";
    } else if (osInfo.dwMajorVersion == 10 && osInfo.dwMinorVersion == 0) {
      return "Internet Explorer";
    } else {
      return "Unknown";
    }
  } else {
    return "Unknown";
  }
}

std::string detect_hardware() {  SYSTEM_INFO sysInfo;  GetSystemInfo(&sysInfo);  return {    "processor": "

