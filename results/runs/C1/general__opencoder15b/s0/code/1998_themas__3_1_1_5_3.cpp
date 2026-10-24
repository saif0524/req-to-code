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

void initializeOvertempValues(std::string filePath) {
     std::ifstream file(filePath);
     std::string line;
     while (std::getline(file, line)) {
         float value = std::stof(line);
         overtempValues.push_back(value);
     }
}

