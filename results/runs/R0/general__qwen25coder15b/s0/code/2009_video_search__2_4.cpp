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

bool is_portable();
bool is_compatible_with_browser(const std::string& browser);
std::string get_hardware_requirements();

bool is_portable() {
  // Check if the system is compatible with different web browsers
  if (!is_compatible_with_browser("Internet Explorer")) return false;
  if (!is_compatible_with_browser("Firefox")) return false;
  if (!is_compatible_with_browser("Safari")) return false;

  // Check if the system is connected to the internet via a modem
  if (!is_connected_to_internet()) return false;

  // Check if the system is reasonably up-to-date
  if (!is_hardware_up_to_date()) return false;

  return true;
}

bool is_compatible_with_browser(const std::string& browser) {
  // Check if the system is compatible with the specified browser
  if (!is_compatible_with_browser(browser)) return false;

  // Check if the system is connected to the internet via a modem
  if (!is_connected_to_internet()) return false;

  // Check if the system is reasonably up-to-date
  if (!is_hardware_up_to_date()) return false;

  return true;
}

std::string get_hardware_requirements() {
  return "A reasonably up-to-date computer that is connected to the internet via a modem";
}

