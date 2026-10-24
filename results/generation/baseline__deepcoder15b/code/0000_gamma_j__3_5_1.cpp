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

string data;
vector<string> data;
void;

string data() {
    std::cout << std::string{} << std::endl;
    std::string response;
    std::getline(std::string{}, std::cin);
    std::cout << response << std::endl;
    close_connection();
    return response;
}

vector<string> data() {
    vector<string> result;
    while (true) {
        string response = data();
        if (response.empty()) {
            break;
        }
        result.push_back(response);
        close_connection();
    }
    return result;
}

void close_connection() {
    // Do nothing
    return;
    }

