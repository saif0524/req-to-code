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

std::pair<std::case, void> removeCase(std::case case);

pair<case, void> removeCase(const case& c) {
    for (auto& elem : cases) {
        if (elem == c) {
            elem = cases.erase(elem);
            return make_pair(cases, void());
        }
    }
    return make_pair(cases, void());
}

