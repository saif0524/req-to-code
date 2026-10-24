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

vector<string> select_option(vector<string> &options) {
  ClickEvent ce;
  int index;
  detect_click(options, &ce);
  if (ce clicks on an element) {
    options.push_back(ce.element);
    return options;
  }
  return vector<string>{};
}

struct ClickEvent {
  vector<string> options;
  int index;

  ClickEvent(const vector<string> &options, int &index) : options(options), index(index){}

  void detect_click() {
    if (options.empty()) return;
    int n = options.size();
    for (int i = 0; i < n; ++i) {
      if (ce.element == options[i]) {
        index = i;
        break;
      }
    }
    if (index != 0) {
      options.push_back(ce.element);
      return;
    }
    return;
  }

}

vector<string> options; // Allow multiple selections by clicking on options.

vector<string> select_option(const vector<string>& options) {
  vector<string> selected;
  for (const string& option : options) {
    if (options.find(option) != options.end()) { // Check if the option is present
    }
    // Collect all selected options
    selected.push_back(option);
  }
  return selected;
}

