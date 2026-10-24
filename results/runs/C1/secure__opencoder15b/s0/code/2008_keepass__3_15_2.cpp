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

void autoType(std::string_view text, int length);
void autoType(std::string_view text, int length, bool caseSensitive);
void autoType(std::string_view text, int length, bool caseSensitive, bool smartQuotes);
void autoType(std::string_view text, int length, bool caseSensitive, bool smartQuotes, bool smartDashes);
void autoType(std::string_view text, int length, bool caseSensitive, bool smartQuotes, bool smartDashes, bool smartCaps);

