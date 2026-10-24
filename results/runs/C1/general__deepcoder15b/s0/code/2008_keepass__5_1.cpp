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

int manageStoredPassword(int currentTime, const struct ExpiredPasswordData &data);
int handlePastedPassword(int currentTime, const struct ExpiredPasswordData &data);
int manageCurrentTime(int currentTime);

int manageStoredPassword(int currentTime, const struct ExpiredPasswordData &data);
int handlePastedPassword(int currentTime, const struct ExpiredPasswordData &data);
int manageCurrentTime(int currentTime);

int manageStoredPassword(int currentTime, const struct ExpiredPasswordData &data) {
  static int current_time = 0; // Assuming it's a static variable from manageCurrentTime
  int stored_time = data.stored_time;
  int current_diff = currentTime - stored_time;
  if (current_diff <= 10) {
    data.update_password(data->password);
  } else {
    data.erase_password(data->password);
  }
  return 0;
  }
  

int handlePastedPassword(int currentTime, const struct ExpiredPasswordData &data) {
    int stored_time = data.stored_time;
    int expiration_time = stored_time + 10;
    int current_time = currentTime;

    if (current_time <= expiration_time) {
        data.current_time = current_time;
        data.is_present = true;
        return 1;
    } else {
        data.is_present = false;
        return 0;
    }
    }
    

int manageCurrentTime(int currentTime) {
    static int current_time = 0;
    if (current_time <= currentTime) {
        current_time ++;
    }
    return current_time;
    }

