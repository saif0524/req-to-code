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

initializeOvertempValues(std::string filePath);

std::vector<int> overtempValues;

ifstream file(filePath);
if (file.is_open()) {
     std::string line;
     while (std::getline(file, line)) {
         overtempValues.push_back(std::stoi(line));
     }
     file.close();
}

return toJson(overtempValues);

