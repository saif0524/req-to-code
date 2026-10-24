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

void updateOnlineStatus(int delta);
void countdown();
void handle_downtime(int time);

void updateOnlineStatus(int delta) {
    if (_online) {
        _online = _online + delta;
    }
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
    if (!_online) {
        _online = std::max(0, _online - time);
    }
    }

