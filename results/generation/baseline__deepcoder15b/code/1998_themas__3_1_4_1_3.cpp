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

[struct TSET_OD LO_UO { static int TSET = 100; static int OD = 50; static int LO = 95; static int UO = 105; }];

bool get_over_limit_true(int T, int TSET, int OD, int LO, int UO);
bool get_over_limit_false(int T, int TSET, int OD, int LO, int UO);

bool get_over_limit_true(int T, int TSET, int OD, int LO, int UO) {
    return (T == LO) || (T == UO);
    }

bool get_over_limit_false(int T, int TSET, int OD, int LO, int UO) {
    return (T != LO && T != UO);
    }

