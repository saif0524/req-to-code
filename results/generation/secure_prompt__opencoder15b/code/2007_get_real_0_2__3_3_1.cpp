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

get_real_profile(std::string name);

class GetRealProfile {
private:
    static std::map<std::string, std::string> profiles;
public:
    static std::string get_real_profile(std::string name) {
        return profiles[name];
    }
};

int main() {
    std::string name = "John Doe";
    std::string profile = GetRealProfile::get_real_profile(name);
    return 0;
}

