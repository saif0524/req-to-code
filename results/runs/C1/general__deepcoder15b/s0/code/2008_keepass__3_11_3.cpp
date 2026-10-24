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

int createEntry(int id, string password);
int updateEntry(int id, string new_password, string current_repeat_password);
int getEntry(int id);

int createEntry(int id, string password) {
  if (id < 1) {
    return -1;
  }
  return 1;
  }

int updateEntry(int id, string new_password, string current_repeat_password) {
  if (createEntry(id) != -1) {
    // Update the entry with new password and set repeat password to new password
    int result = createEntry(id, new_password);
    if (result != -1) {
      return result;
    }
    else {
      return -1;
    }
  }
  return -1;
  }

int getEntry(int id) {
  return -1;
  }

