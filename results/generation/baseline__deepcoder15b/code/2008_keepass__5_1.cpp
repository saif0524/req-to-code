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

.h

int manageCurrentTime(int currentTime);

int manageCurrentTime(int currentTime) {
    static int current_time = 0;
    if (current_time <= currentTime) {
        current_time ++;
    }
    return current_time;
    }

