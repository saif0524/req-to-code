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
int manageCurrentTime(int currentTime);
int handlePastedPassword(int currentTime, const struct ExpiredPasswordData &data);
int manageStoredPassword(int currentTime, const struct ExpiredPasswordData &data);

int manageStoredPassword(int currentTime, const struct ExpiredPasswordData &data);
int handlePastedPassword(int currentTime, const struct ExpiredPasswordData &data);
int manageCurrentTime(int currentTime);

int manageStoredPassword(int currentTime, const struct ExpiredPasswordData &data) {
  static int current_time = 0;
  int stored_time = data.stored_time;
  int current_diff = currentTime - stored_time;
  if (current_diff <= 10) {
    data.update_password(data->password);
  } else {
    data.erase_password(data->password);
  }
  return (current_diff <= 10);
  }
  

int handlePastedPassword(int currentTime, const struct ExpiredPasswordData &data) { int expiration_time = data.stored_time + 10; int current_time = currentTime; if (current_time <= expiration_time) return 1; else return 0; }

int manageCurrentTime(int currentTime) {
    static int current_time = 0;
    if (current_time <= currentTime) {
        current_time ++;
    }
    return current_time;
    }

