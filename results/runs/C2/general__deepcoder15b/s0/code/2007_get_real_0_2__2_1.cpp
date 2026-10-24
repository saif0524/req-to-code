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

function3 should return a string, so we need to add std::string as a declaration.

int function1(int a, int b) { return std::to_string(a + b); };
int function2(std::string s) { return std::stoi(s); };
int function3(int a, int b) { return a + b; };
int function4(int a, int b) { return a - b; };
int function5(int a, int b) { return a * b; };

std::string function1(int a, int b) { return std::to_string(a + b); }

int function2(std::string s) { return std::stoi(s); }

std::string function3(int a, int b) { return std::to_string(a + b); }

int function4(int a, int b) { return a - b; }

int function5(int a, int b) { return a * b; }

