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

string startLanguageChange(string currentLanguage, string databasePath);
string selectLanguageFromList(string currentLanguage, vector<string> languages, int& index);
string showMessageForInstallation(const string& message);
vector<string> restartAfterChanges(const vector<string>& changes, bool& confirm);
string unlockDatabase(const string& masterPassword);

string selectLanguageFromList(string currentLanguage, vector<string> languages, int& index) {
    for (int i = 0; i < languages.size(); i++) {
        if (currentLanguage == languages[i]) {
            index = i;
            return languages[i];
        }
    }
    // Handle case where no language matches currentLanguage
    return currentLanguage;
}

vector<string> restartAfterChanges(const vector<string>& changes, bool& confirm)
  {
    if (changes.empty())
      return changes;
    
    vector<string> history;
    for (const string& change : changes)
    {
      if (change starts with 

