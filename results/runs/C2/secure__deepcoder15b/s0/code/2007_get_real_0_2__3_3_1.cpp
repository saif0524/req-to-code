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

int validateAge(int age);
Profile* getMultipleProfiles(const vector<Profile*>& profiles);
void addUser(const char* username);
bool isUserLoggedIn(const char* username);

int validateAge(int age) {
    if (age < 0 || age > 100) {
        return -1;
    }
    return 0;
    }

bool getMultipleProfiles(const vector<Profile*>& profiles) {
  if (! profiles.empty()) {
    Profile* firstProfile = profiles.begin() + 1;
    return new Profile*(firstProfile);
  }
  return new Profile();
  }

void addUser(const char* username) {
    if (!str_empty(username)) {
        Profile* newProfile = profiles.begin() + 1;
        profiles.erase profiles.begin();
        profiles.push_back(newProfile);
        return newProfile;
    }
    }

bool isUserLoggedIn(const char* username) { return !str_empty(username) && !!(username == nullptr); }

