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

You may need to include <string>

void isSystemOnline();
void updateOnlineStatus(int delta);
void countdown();
void handle_downtime(int time);
void log_error(bool error);

bool isSystemOnline() {
    return _online;
    }

class MMPC {
    bool _online;
    void updateOnlineStatus(int delta) {
        if (_online) {
            _online = _online + delta;
        }
    }
    // ... rest of the class logic ...
}

void countdown() {
  if (_online) {
    _online--; 
    if (_online < 0) {
      _online = 0; 
    }
  }
  }

void handle_downtime(int time) {
    _online = std::max(0, _online - time);
    }

void log_error(bool error) {
  if (!isSystemOnline() && error) {
    log(error);
  }

  // Ensure online status remains valid
  if (_online) {
    _online--; // Subtract the time
    if (_online < 0) {
      _online = 0; // Ensure online status is not negative
    }
  }
  }
  return error;
  }

