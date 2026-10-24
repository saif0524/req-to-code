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

vector<string> video_list(const vector<string>&) { return video_list; }

string search_key => vector<string> search_result;
vector<string> video_list => vector<string> video_list;
int current_section => int swap_to_section;

vector<string> search_key(string keyword) {
    vector<string> result;
    for (const string& url : video_list) {
        if (url.find(keyword) != string::npos) {
            result.push_back(url);
        }
    }
    return result;
}

vector<string> video_list(const vector<string>& video_list) { return video_list; }

int swap_to_section(int target_section) { return target_section; }

