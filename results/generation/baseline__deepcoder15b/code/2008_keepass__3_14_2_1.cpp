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

string showMessageForInstallation(const string& message);
vector<string> restartAfterChanges(const vector<string>& changes, bool& confirm);

string showMessageForInstallation(const string& message) {

vector<string> restartAfterChanges(const vector<string>& changes, bool& confirm)
    {
        vector<string> history;
        for (const string& change : changes)
        {
            if (currentLanguage == change[0] && databasePath == change[1])
            {
                history.push_back(change);
            }
        }
        if (confirm && history.size() > 0)
        {
            return restartAfterChanges(changes, confirm);
        }
        return changes;
    }
    

