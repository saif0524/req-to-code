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

std::pair<std::case, void> addCase(std::case case);
std::pair<std::case, void> removeCase(std::case case);
void displayCases();
void changeDisplayColumns(int columns);
void changeColumnColors(int column, std::array<std::string, 3> colors);

std::pair<std::case, void> addCase(std::case case) {
    // Create a new case
    // Insert it into the cases vector
    // Return it as the first element of the pair
    return std::make_pair(cases.begin() + 1, "added case");
}

std::pair<std::case, void> removeCase(const case& c) {
  auto it = std::find(cases.begin(), cases.end(), c);
  if (it != cases.end()) {
    cases.erase(it);
  }
  return std::make_pair(cases, void());
}

void displayCases() {
    vector<case> cases;
    for (auto case : cases) {
      string reason = "Case: " + to_string(case);
      cases.push_back({"case": case, "reason": reason});
    }
    return {"reasoning": "Display the current list of cases by iterating through the cases vector and printing each case's identifier.\ncode": vector<case>{"case": cases} };
}

void changeDisplayColumns(int columns) {
    if (columns < 3) {
        columns = 3;
    }
    if (columns > 6) {
        columns = 6;
    }
    return columns;
}

void changeColumnColors(int column, std::array<std::string, 3> colors) {
  if (column < 0 || column >= 3) {
    return;
  }
  if (column >= 3 && column < 6) {
    column = 3;
  }
  std::vector<std::string> new_colors(3);
  new_colors[column] = colors[0];
  return new_colors;
  }
  

