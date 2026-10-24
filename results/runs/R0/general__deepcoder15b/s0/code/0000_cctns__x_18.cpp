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

bool check_system_available(int start, int end, int week, int month);

bool check_system_available(int start, int end, int week, int month) {
    if (start > end) return false;
    for (int day = 0; day < (week * 6 + month); day++) {
        if (day >= (week * 6 + month)) break;
        if (days[day].start > days[day].end) return false;
    }
    return true;
    }
    

