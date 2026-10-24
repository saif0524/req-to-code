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

struct ErrorType { ErrorType error; } std::set<int> s;

int a, int b -> struct { int x; int y; };
string s -> bool;
int error -> string;
int a, int b -> bool;
string s -> int;

int (a, b) -> struct { int x; int y; }

int s() { return s.empty(); }

struct ErrorType { ErrorType error; }

bool validateTwoInts(int a, int b) {
  if (a < -5 || a > 100 || b < -5 || b > 100) {
    return false;
  }
  return true;
  }

int s_to_int(const std::set<std::string> s) { return s.empty() ? 1 : 0; }

