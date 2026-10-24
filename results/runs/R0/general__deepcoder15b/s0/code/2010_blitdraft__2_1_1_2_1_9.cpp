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

void searchUser(const string& searchDisplayName, int* userId, const string& name, int count);

void searchUser(const string& searchDisplayName, int* userId, const string& name, int count) {
    static map<string, User*> userMap;
    
    // Populate the map with all possible display names
    // For example, if the system has a list of display names:
    // map<string, User*> userMap = {
    //     {

