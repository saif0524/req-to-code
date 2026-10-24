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

void displayOverviewPage();

void displayOverviewPage() {
  std::string overviewPage = "<h1>Overview</h1><p>This is the overview page for the [system name].</p>";
  std::cout << overviewPage;
}

