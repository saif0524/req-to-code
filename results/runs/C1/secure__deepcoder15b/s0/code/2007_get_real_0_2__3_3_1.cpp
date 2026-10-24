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
    return new Profile*( profiles.begin() + 1 );
  }
  return new Profile();
  }
  "reasoning": "The function getMultipleProfiles was not correctly handling the Profile type. Since Profile is likely a struct, the function was trying to pass Profile instead of a pointer to Profile. We need to ensure that we pass a pointer to Profile* instead of the struct type. The corrected function creates a new Profile pointer based on the input vector."
  

void addUser(const char* username) {
    if (!str_empty(username)) {
        Profile* newProfile = profiles.begin() + 1;
        profiles.erase profiles.begin();
        profiles.push_back(newProfile);
        return newProfile;
    }
    }

bool isUserLoggedIn(const char* username) { return !str_empty(username); }

