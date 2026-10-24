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

vector<string> options, int& current_index;
vector<string> options;

vector<string> options, int& current_index;

vector<string> select_option(const vector<string>& options) {
  ClickEvent ce;
  current_index = -1;
  detect_click(options, &ce);
  if (ce.cuts on an element) {
    if (current_index == -1) {
      options.push_back(ce.element);
      current_index = 0;
    }
    return options;
  }
  return vector<string>{};
}

vector<string> select_option(const vector<string>& options) {
  vector<string> selected;
  for (const string& option : options) {
    if (options.find(option) != -1) {
      selected.push_back(option);
    }
  }
  return selected;
}

