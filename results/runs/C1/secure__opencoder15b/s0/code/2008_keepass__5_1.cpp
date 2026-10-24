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

void copy_password(const std::string& password);

void copy_password(const std::string& password) {
   // Copy the password to the clipboard
   if (!set_clipboard(password)) {
     // If the clipboard is not writable, copy the password again
     set_clipboard(password);
   }
   // Wait for 10 seconds
   std::this_thread::sleep_for(std::chrono::seconds(10));
   // Clear the clipboard
   clear_clipboard();
}

