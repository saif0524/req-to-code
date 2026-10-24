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

std::vector<double> readCurrentPositions(std::vector<double> &currentPositions);
std::vector<double> readPreviousPositions(std::vector<double> &previousPositions);
int calculateMovements(std::vector<double> currentPositions, std::vector<double> previousPositions);

std::vector<double> readCurrentPositions(std::vector<double> &currentPositions) {
    return currentPositions;
}

vector<double> readPreviousPositions(vector<double> &previousPositions) {
    return vector<double>(previousPositions.begin(), previousPositions.end());
    }

int calculateMovements(std::vector<double> currentPositions, std::vector<double> previousPositions) {
  int count = 0;
for (size_t i = 0; i < currentPositions.size(); ++i) {
if (currentPositions[i] != previousPositions[i]) {
count++;
}
}
  return count;
}

