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

bool isTanChangeable(const Entry& entry, const TAN& tan);
bool changeTan(Entry& entry, const TAN& oldTan, const TAN& newTan);
void expireTan(TAN& tan);

bool isTanChangeable(const Entry& entry, const TAN& tan) {
  if (tan.isExpired()) {
    return false;
  }
  if (entry.usernameChanged() || entry.urlChanged() || entry.titleChanged()) {
    return false;
  }
  return true;
}

bool changeTan(Entry& entry, const TAN& oldTan, const TAN& newTan) {
  if (oldTan == newTan) {
    return true;
  }
  if (oldTan.isExpired()) {
    return false;
  }
  if (entry.usernameChanged() || entry.urlChanged() || entry.titleChanged()) {
    return false;
  }
  return true;
}

void expireTan(TAN& tan) {
  tan.setExpired(true);
}

